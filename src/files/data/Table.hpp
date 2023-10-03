#ifndef TABLE_H
#define TABLE_H

#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "AbstractTable.h"
#include "File.h"
#include "../csv/CSVIterator.h"
#include "../data/Data.h"

namespace file::data
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

		const std::vector<std::shared_ptr<T>>& getEntries() const {
			return this->entries;
		}
    protected:
		std::vector<std::shared_ptr<T>> entries;
    };
}

#endif
