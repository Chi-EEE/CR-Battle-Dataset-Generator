#ifndef ENTITYEFFECT_H
#define ENTITYEFFECT_H

#pragma once

#include <string>
#include <unordered_map>

namespace arena::logic {
    class EntityEffect
    {
    public:
        enum Value
        {
            Empty,
            Damage,
            Heal,
            Freeze,
            Rage,
            Clone,
        };

        EntityEffect() = default;
        constexpr EntityEffect(Value value) : value(value) { }

        constexpr operator Value() const { return value; }
        explicit operator bool() const = delete;
        constexpr bool operator==(EntityEffect a) const { return value == a.value; }
        constexpr bool operator!=(EntityEffect a) const { return value != a.value; }

        std::string to_string() const
        {
            switch (value)
            {
            case EntityEffect::Empty: return "Empty";
            case EntityEffect::Damage: return "Damage";
            case EntityEffect::Heal: return "Heal";
            case EntityEffect::Freeze: return "Freeze";
            case EntityEffect::Rage: return "Rage";
            case EntityEffect::Clone: return "Clone";
            default: return "Unknown";
            }
        }

        static Value from_string(const std::string& name)
        {
            static const std::unordered_map<std::string, Value> value_map = {
                { "Empty", EntityEffect::Empty },
                { "Damage", EntityEffect::Damage },
                { "Heal", EntityEffect::Heal },
                { "Freeze", EntityEffect::Freeze },
                { "Rage", EntityEffect::Rage },
                { "Clone", EntityEffect::Clone },
            };

            auto it = value_map.find(name);
            if (it != value_map.end())
                return it->second;
            return EntityEffect::Empty; // Return default value if no match is found
        }

        static std::vector<std::string> values() {
            return std::vector<std::string>{
                "Empty",
                    "Damage",
                    "Heal",
                    "Freeze",
                    "Rage",
                    "Clone",
            };
        }

        std::pair<SkBlendMode, SkColor> get_effect() const
        {
            switch (value)
            {
            case EntityEffect::Damage:
            {
                return std::make_pair<SkBlendMode, SkColor>(SkBlendMode::kPlus, SkColorSetARGB(255, 255, 0, 0));
            }
            case EntityEffect::Heal:
            {
                return std::make_pair<SkBlendMode, SkColor>(SkBlendMode::kPlus, SkColorSetARGB(255, 85, 255, 38));
            }
            case EntityEffect::Clone:
            {
                break;
            }
            case EntityEffect::Freeze:
            {
                return std::make_pair<SkBlendMode, SkColor>(SkBlendMode::kPlus, SkColorSetARGB(255, 0, 90, 255));
            }
            case EntityEffect::Rage:
            {
                return std::make_pair<SkBlendMode, SkColor>(SkBlendMode::kColorDodge, SkColorSetARGB(255, 155, 0, 155));
            }
            default:
            {
                break;
            }
            }
            return std::make_pair<SkBlendMode, SkColor>(SkBlendMode::kDst, SkColorSetARGB(0, 0, 0, 0));
        }
    private:
        Value value;
    };
    struct EntityEffectHasher {
        std::size_t operator()(const arena::logic::EntityEffect::Value& value) const
        {
            return std::hash<int>()(value);
        }
    };
}

#endif
