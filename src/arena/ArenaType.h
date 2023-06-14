#ifndef ARENATYPE_H
#define ARENATYPE_H

#pragma once

#include <string>
#include <unordered_map>

namespace arena {
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

		std::string to_string() const
		{
			switch (value)
			{
			case ArenaType::Training: return "Training";
			default: return "Unknown";
			}
		}

		static Value from_string(const std::string& name)
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
}

#endif
