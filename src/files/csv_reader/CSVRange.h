#ifndef CSVRANGE_H
#define CSVRANGE_H

#pragma once

#include "CSVIterator.h"

namespace CSV::Reader
{
    // https://stackoverflow.com/a/1120224
    class CSVRange
    {
        std::istream& stream;
    public:
        CSVRange(std::istream& str)
            : stream(str)
        {}
        CSVIterator begin() const { return CSVIterator{ stream }; }
        CSVIterator end()   const { return CSVIterator{}; }
    };
}

#endif