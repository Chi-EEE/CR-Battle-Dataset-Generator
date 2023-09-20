#ifndef ENTITYEFFECT_H
#define ENTITYEFFECT_H

#pragma once

#include <string>

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

		std::string add_effect() const
		{
			switch (value)
			{
			case EntityEffect::Damage:
			{
				break;
			}
			case EntityEffect::Heal:
			{
				break; // 0, 6, 191, 0
			}
			case EntityEffect::Clone:
			{
				break;
			}
			case EntityEffect::Freeze:
			{
				break;
			}
			case EntityEffect::Rage:
			{
				break;
			}
			default:
			{
				break;
			}
			}
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
