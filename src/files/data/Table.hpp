#ifndef TABLE_H
#define TABLE_H

#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "toml++/toml.h"

#include "AbstractTable.h"
#include "File.h"
#include "../csv/CSVIterator.h"
#include "../data/Data.h"

namespace data
{
    template<typename T>
    class Table : public AbstractTable
    {
    public:
		static_assert(std::is_base_of<Data, T>::value, "T must be derived from Data");
		Table() {};

		void insertCSV(std::string filePath)
		{
			std::ifstream file(filePath);
			CSVIterator csvIterator(file);
			++csvIterator;
			++csvIterator;
			for (; csvIterator != CSVIterator(); ++csvIterator)
			{
				this->entries.push_back(std::make_shared<T>(T(*csvIterator)));
			}
		};

		void insertToml(std::string filePath)
		{
			toml::table tbl = toml::parse_file(filePath);
			for (auto pair : tbl) {
				toml::key name = pair.first;
				toml::table* table = pair.second.as_table();
				this->entries.push_back(std::make_shared<T>(T(*name, table)));
			}
		};

		const std::vector<std::shared_ptr<T>>& getEntries() const {
			return this->entries;
		}
    private:
		std::vector<std::shared_ptr<T>> entries;
    };
}

#endif
