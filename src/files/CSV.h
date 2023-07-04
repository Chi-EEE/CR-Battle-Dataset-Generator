#ifndef CSV_H
#define CSV_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "AbstractTable.h"
#include "File.h"
#include "CSVReader/CSVIterator.h"
#include "Table.h"

namespace CSV
{
    class CSV
    {
    public:
        CSV();
        CSV(CSV const&) = delete;
        CSV& operator=(CSV const&) = delete;
        static CSV& getInstance() {
            static CSV instance;
            return instance;
        }
        ~CSV();
        AbstractTable* getTable(File csvFileType);
    private:
        void addFile(File csvFileType, std::string fileName);
        bool contains(File csvFileType);
        std::unordered_map<File, AbstractTable*> tables;
    };
}

#endif