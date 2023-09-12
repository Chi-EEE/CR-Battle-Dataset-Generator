import csv
import os


entity_data_constructor = r"""
EntityData::EntityData(std::string name, toml::table* tomlTable, EntityData* entity_data)
	{{
		this->Name = name;
        #pragma region Set Variable
{other_entity_setters}
        #pragma endregion
		std::unordered_map<std::string, void*> variableMap = {{
{variable_map}
		}};
		for (const auto& pair : *tomlTable) {{
			const toml::key& key = pair.first;
			const toml::node& value = pair.second;
			std::string keyValue(key.str());
			if (variableMap[keyValue] == nullptr) {{
				continue;
			}}
			if (value.is<int64_t>()) {{
				*static_cast<int*>(variableMap[keyValue]) = value.value<int64_t>().value();
			}}
			else if (value.is<std::string>()) {{
				*static_cast<std::string*>(variableMap[keyValue]) = value.value<std::string>().value();
			}}
			else if (value.is_array()) {{
				const toml::array* arrayValue = value.as_array();

				auto* arrayElement = arrayValue->get(arrayValue->size() - 1);
				if (arrayElement->is<int64_t>()) {{
					*static_cast<int*>(variableMap[keyValue]) = arrayElement->value<int64_t>().value();
				}}
				else if (arrayElement->is<std::string>()) {{
					*static_cast<std::string*>(variableMap[keyValue]) = arrayElement->value<std::string>().value();
				}}
			}}
			else {{
				std::cout << "Key: " << key << ", Value (unknown type)" << std::endl;
			}}
		}}
	}}
"""


def generate_member_initalization_list(headers, datatypes):
    def encode_argument(index, datatype):
        if datatype == "int":
            return f"to_int(row[{index}])"
        if datatype == "bool":
            return f"to_bool(row[{index}])"
        return f"row[{index}]"
    def encode(header, datatype):
        return f"{header[1]}({encode_argument(header[0], datatype)})"
    return ', '.join(map(encode, enumerate(headers), datatypes))


def generate_other_entity_setters(headers):
    result = ""
    for header in headers:
        if header != "Name":
            result += f"\t\tthis->{header} = entity_data->{header};\n"
    return result


def generate_variable_map(headers):
    result = ""
    for header in headers:
        result += f"\t\t\t{{\"{header}\", &this->{header}}},\n"
    return result


def make_constructor_method(headers, datatypes):
    new_file_cpp = f"scripts/out/constructor.cpp"
    f = open(new_file_cpp, "a")
    f.write(
        entity_data_constructor.format(
            other_entity_setters = generate_other_entity_setters(headers),
            variable_map = generate_variable_map(headers),
        )
    )


csv_datatype_to_cs_datatype = {
    "string": "std::string",
    "boolean": "bool",
    "booleanarray": "std::vector<bool>",
    "intarray": "std::vector<int>",
    "stringarray": "std::vector<std::string>",
}


def make_csv_logic_class_file(headers, datatypes):
    for i, datatype in enumerate(datatypes):
        datatype = datatype.lower()
        if csv_datatype_to_cs_datatype.get(datatype):
            datatypes[i] = csv_datatype_to_cs_datatype.get(datatype)
    make_constructor_method(headers, datatypes)

def create_class_csv_file(file_name, class_name):
    with open(file_name) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=",")
        headers = next(csv_reader)
        datatypes = next(csv_reader)
        make_csv_logic_class_file(headers, datatypes)
        
create_class_csv_file("scripts/csv/characters.csv", "EntityData")