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
        Table() {};

        void insert(std::string fileName)
		{
			std::ifstream file(fileName);
			CSVIterator csvIterator(file);
			++csvIterator;
			++csvIterator;
			for (; csvIterator != CSVIterator(); ++csvIterator)
			{
				this->entries.emplace_back(T(*csvIterator));
			}
		};

        T getData(std::string name);
    private:
        std::vector<T> entries;
    };
}

#endif
