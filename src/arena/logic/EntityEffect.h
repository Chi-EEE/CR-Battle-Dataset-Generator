#ifndef ENTITYEFFECT_H
#define ENTITYEFFECT_H

#pragma once

#include <string>
#include "core/SkBlendMode.h"
#include "core/SkColor.h"

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
			case EntityEffect::Damage:
				return "Damage";
			case EntityEffect::Heal:
				return "Heal";
			case EntityEffect::Freeze:
				return "Freeze";
			case EntityEffect::Rage:
				return "Rage";
			case EntityEffect::Clone:
				return "Clone";
            default: return "Empty";
            }
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
