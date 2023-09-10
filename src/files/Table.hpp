#ifndef TABLE_H
#define TABLE_H

#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "AbstractTable.h"
#include "File.h"
#include "CSVReader/CSVIterator.h"
#include "CSVLogic/Data.h"

namespace CSV
{
    template<typename T>
    class Table : public AbstractTable
    {
    public:
		static_assert(std::is_base_of<Logic::Data, T>::value, "T must be derived from Data");
		Table() {};

        void insert(std::string fileName)
		{
			std::ifstream file(fileName);
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
    private:
		std::vector<std::shared_ptr<T>> entries;
    };
}

#endif
