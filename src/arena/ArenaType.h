#ifndef ARENATYPE_H
#define ARENATYPE_H

#pragma once

class ArenaType
{
public:
    enum Value : uint8_t
    {
        Training,

    };

    ArenaType() = default;
    constexpr ArenaType(Value value) : value(value) { }

    constexpr operator Value() const { return value; }
    explicit operator bool() const = delete;
    constexpr bool operator==(ArenaType a) const { return value == a.value; }
    constexpr bool operator!=(ArenaType a) const { return value != a.value; }

    static std::string name(Value value)
    {
        switch (value)
        {
        case ArenaType::Training: return "Training";
        default: return "Unknown";
        }
    }

private:
    Value value;
};

#endif
