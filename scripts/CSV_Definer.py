import csv
import os


csv_class_h = r"""#ifndef {class_name}_H
#define {class_name}_H

#pragma once

#include <string>
#include <vector>
#include <charconv>
#include <unordered_map>

#include "toml++/toml.h"

#include "../../files/data/Data.h"
#include "../../files/csv/CSVRow.h"

using namespace csv;
using namespace data;

namespace arena::data
{{
    class {class_name} : public Data
    {{
    public:
        {class_name}(CSVRow row);
        ~{class_name}();
        
{get_methods}
    private:
{header_variables}
    }};
    typedef std::shared_ptr<{class_name}> p{class_name};
}}

#endif"""


csv_class_cpp = r"""#include "{class_name}.h"

namespace arena::data {{
    {class_name}::{class_name}(CSVRow row) : {member_initalization_list}, Data(name)
    {{

    }}

    {class_name}::~{class_name}()
    {{

    }}
}}"""


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


def generate_header_variables(headers, datatypes):
    result = ""
    for header, datatype in zip(headers, datatypes):
        result += f"\t\t{datatype} {header};\n"
    return result


def generate_get_methods(headers, datatypes):
    result = ""
    for header, datatype in zip(headers, datatypes):
        result += f"\t\tconst {datatype}& get{header}() const {{\n\t\t\treturn this->{header};\n\t\t}}\n"
    return result


def generate_variable_map(headers):
    result = ""
    for header in headers:
        result += f"\t\t\t{{\"{header}\", &this->{header}}},\n"
    return result


def make_cpp_file(class_name, headers, datatypes):
    new_file_cpp = f"scripts/out/{class_name}.cpp"
    if os.path.exists(new_file_cpp):
        os.remove(new_file_cpp)
    f = open(new_file_cpp, "a")
    f.write(
        csv_class_cpp.format(
            class_name=class_name,
            member_initalization_list= generate_member_initalization_list(headers, datatypes),
            variable_map = generate_variable_map(headers),
        )
    )


def make_h_file(class_name, headers, datatypes):
    new_file_h = f"scripts/out/{class_name}.h"
    if os.path.exists(new_file_h):
        os.remove(new_file_h)
    f = open(new_file_h, "a")
    f.write(
        csv_class_h.format(
            class_name=class_name,
            class_name_upper=class_name.upper(),
            get_methods = generate_get_methods(headers, datatypes),
            header_variables = generate_header_variables(headers, datatypes),
        )
    )


csv_datatype_to_cs_datatype = {
    "string": "std::string",
    "boolean": "bool",
    "booleanarray": "std::vector<bool>",
    "intarray": "std::vector<int>",
    "stringarray": "std::vector<std::string>",
}


def make_csv_logic_class_file(class_name, headers, datatypes):
    for i, datatype in enumerate(datatypes):
        datatype = datatype.lower()
        if csv_datatype_to_cs_datatype.get(datatype):
            datatypes[i] = csv_datatype_to_cs_datatype.get(datatype)
    make_h_file(class_name, headers, datatypes)
    make_cpp_file(class_name, headers, datatypes)

def create_class_csv_file(file_name, class_name):
    with open(file_name) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=",")
        headers = next(csv_reader)
        datatypes = next(csv_reader)
        make_csv_logic_class_file(class_name, headers, datatypes)
        
create_class_csv_file("scripts/csv/characters.csv", "EntityData")
# create_class_csv_file("scripts/csv/spells_other.csv", "SpellData")
# create_class_csv_file("scripts/csv/projectiles.csv", "ProjectileData")