#ifndef DATA_H
#define DATA_H

#pragma once

#include <string_view>
#include <charconv>

namespace data
{
    class Data
    {
    protected:
        static int to_int(const std::string_view& input)
        {
            int out;
            const std::from_chars_result result = std::from_chars(input.data(), input.data() + input.size(), out);
            if (result.ec == std::errc::invalid_argument || result.ec == std::errc::result_out_of_range)
            {
                return 0;
            }
            return out;
        }

        static int to_bool(const std::string_view& input)
        {
            return input == "true" || input == "TRUE";
        }
    };
}

#endif