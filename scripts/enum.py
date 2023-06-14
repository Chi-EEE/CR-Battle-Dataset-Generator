import os
from collections import defaultdict


def generate_cpp_class(class_name: str, enum_values):
    cpp_code = f'''#ifndef {class_name.upper()}_H
#define {class_name.upper()}_H

#pragma once

#include <string>
#include <unordered_map>

class {class_name}
{{
public:
  enum Value
  {{
'''

    # Generate enum values
    for value in enum_values:
        cpp_code += f'    {value},\n'

    cpp_code += f'''  }};

  {class_name}() = default;
  constexpr {class_name}(Value value) : value(value) {{ }}

  constexpr operator Value() const {{ return value; }}
  explicit operator bool() const = delete;
  constexpr bool operator==({class_name} a) const {{ return value == a.value; }}
  constexpr bool operator!=({class_name} a) const {{ return value != a.value; }}

  std::string to_string() const
  {{
    switch (value)
    {{
'''

    # Generate switch case for enum names
    for value in enum_values:
        cpp_code += f'      case {class_name}::{value}: return "{value}";\n'

    cpp_code += f'''      default: return "Unknown";
    }}
  }}

  static Value from_string(const std::string& name)
  {{
    static const std::unordered_map<std::string, Value> value_map = {{
'''

    # Generate mapping from string to enum value using unordered_map
    for value in enum_values:
        cpp_code += f'        {{ "{value}", {class_name}::{value} }},\n'

    cpp_code += f'''    }};

    auto it = value_map.find(name);
    if (it != value_map.end())
        return it->second;
    return {class_name}::{enum_values[0]}; // Return default value if no match is found
  }}

private:
  Value value;
}};

#endif
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
