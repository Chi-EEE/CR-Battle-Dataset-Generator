#ifndef TABLE_H
#define TABLE_H

#pragma once

#include <fstream>

#include "AbstractTable.h"
#include "File.h"
#include "CSVReader/CSVIterator.h"
#include "CSVLogic/Data.h"

#include "SupercellFlash.h"

namespace CSV
{
    template<typename T>
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