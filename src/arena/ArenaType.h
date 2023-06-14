#ifndef ARENATYPE_H
#define ARENATYPE_H

#pragma once

#include <string>
#include <unordered_map>

class ArenaType
{
public:
    enum Value
    {
        Training,

    };

    ArenaType() = default;
    constexpr ArenaType(Value value) : value(value) { }

    constexpr operator Value() const { return value; }
    explicit operator bool() const = delete;
    constexpr bool operator==(ArenaType a) const { return value == a.value; }
    constexpr bool operator!=(ArenaType a) const { return value != a.value; }

    std::string name() const
    {
        static const std::unordered_map<Value, std::string> name_map = {

            { ArenaType::Training, "Training" },

        };

        auto it = name_map.find(value);
        if (it != name_map.end())
            return it->second;
        return "Unknown"; // Return default if no match is found
    }

    static Value valueOf(const std::string& name)
    {
        static const std::unordered_map<std::string, Value> value_map = {

            { "Training", ArenaType::Training },

        };

        auto it = value_map.find(name);
        if (it != value_map.end())
            return it->second;
        return ArenaType::Training; // Return default value if no match is found
    }

private:
    Value value;
};

#endif
