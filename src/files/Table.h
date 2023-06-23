#ifndef TABLE_H
#define TABLE_H

#pragma once

#include <fstream>

#include "AbstractTable.h"
#include "File.h"
#include "CSVReader/CSVIterator.h"
#include "CSVLogic/Data.h"

template<typename T>
concept IsData = std::is_base_of_v<CSV::Logic::Data, T>;

namespace CSV
{
    template<IsData T>
    class Table : public AbstractTable
    {
    public:
        Table();

        void insert(std::string fileName);

        T getData(std::string name);
    private:
        std::vector<T> entries;
    };
}

#endif