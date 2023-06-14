import os


def generate_cpp_class(class_name, enum_values):
    cpp_code = f'''
class {class_name}
{{
public:
  enum Value : uint8_t
  {{
'''

    # Generate enum values
    for value in enum_values:
        cpp_code += f'    {value},\n'

    cpp_code += '''
  };

  {class_name}() = default;
  constexpr {class_name}(Value aFruit) : value(aFruit) {{ }}

#if Enable switch(fruit) use case:
  // Allow switch and comparisons.
  constexpr operator Value() const {{ return value; }}

  // Prevent usage: if(fruit)
  explicit operator bool() const = delete;        
#else
  constexpr bool operator==({class_name} a) const {{ return value == a.value; }}
  constexpr bool operator!=({class_name} a) const {{ return value != a.value; }}
#endif

  constexpr bool IsYellow() const {{ return value == Banana; }}

  std::string name() const
  {{
    switch (value)
    {{
'''

    # Generate switch case for enum names
    for value in enum_values:
        cpp_code += f'      case {class_name}::{value}: return "{value}";\n'

    cpp_code += '''
      default: return "Unknown";
    }}
  }}

  static Value valueOf(const std::string& name)
  {{
    if (name == "Unknown")
      return Value(0); // Assuming the first enum value is the default/unknown value

'''

    # Generate mapping from string to enum value
    for i, value in enumerate(enum_values):
        cpp_code += f'    else if (name == "{value}")\n'
        cpp_code += f'      return {class_name}::{value};\n'

    cpp_code += '''
    return Value(0); // Return default/unknown value if no match is found
  }}

private:
  Value value;
}};
'''

    return cpp_code


# User input for class name and enum file
class_name = input("Enter the class name: ")
enum_file = input("Enter the file name with enum values: ")

try:
    with open(enum_file, 'r') as file:
        enum_values = file.readlines()
        enum_values = [value.strip() for value in enum_values if value.strip()]
except FileNotFoundError:
    print("Enum file not found.")
    exit(1)

cpp_class = generate_cpp_class(class_name, enum_values)

# Create the 'out' directory if it doesn't exist
output_directory = "out"
os.makedirs(output_directory, exist_ok=True)

# Save the generated class to a file
output_file = os.path.join(output_directory, f"{class_name}.cpp")
with open(output_file, 'w') as file:
    file.write(cpp_class)

print(f"C++ class saved to '{output_file}'")
