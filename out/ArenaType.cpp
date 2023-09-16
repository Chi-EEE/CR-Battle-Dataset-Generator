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
    Training_Camp,
    Goblin_Stadium,
    Bone_Pit,
    Barbarian_Bowl,
    Spell_Valley,
    Builders_Workshop,
    PEKKAs_Playhouse,
    Royal_Arena,
    Frozen_Peak,
    Jungle_Arena,
    Hog_Mountain,
    Electro_Valley,
    Spooky_Town,
    Rascals_Hideout,
    Serenity_Peak,
    Miners_Mine,
    Executioners_Kitchen,
    Royal_Crypt,
    Silent_Sanctuary,
    Dragon_Spa,
    Legendary_Arena,
    Chess_Arena,
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
      case ArenaType::Training_Camp: return "Training_Camp";
      case ArenaType::Goblin_Stadium: return "Goblin_Stadium";
      case ArenaType::Bone_Pit: return "Bone_Pit";
      case ArenaType::Barbarian_Bowl: return "Barbarian_Bowl";
      case ArenaType::Spell_Valley: return "Spell_Valley";
      case ArenaType::Builders_Workshop: return "Builders_Workshop";
      case ArenaType::PEKKAs_Playhouse: return "PEKKAs_Playhouse";
      case ArenaType::Royal_Arena: return "Royal_Arena";
      case ArenaType::Frozen_Peak: return "Frozen_Peak";
      case ArenaType::Jungle_Arena: return "Jungle_Arena";
      case ArenaType::Hog_Mountain: return "Hog_Mountain";
      case ArenaType::Electro_Valley: return "Electro_Valley";
      case ArenaType::Spooky_Town: return "Spooky_Town";
      case ArenaType::Rascals_Hideout: return "Rascals_Hideout";
      case ArenaType::Serenity_Peak: return "Serenity_Peak";
      case ArenaType::Miners_Mine: return "Miners_Mine";
      case ArenaType::Executioners_Kitchen: return "Executioners_Kitchen";
      case ArenaType::Royal_Crypt: return "Royal_Crypt";
      case ArenaType::Silent_Sanctuary: return "Silent_Sanctuary";
      case ArenaType::Dragon_Spa: return "Dragon_Spa";
      case ArenaType::Legendary_Arena: return "Legendary_Arena";
      case ArenaType::Chess_Arena: return "Chess_Arena";
      default: return "Unknown";
    }
  }

  static Value from_string(const std::string& name)
  {
    static const std::unordered_map<std::string, Value> value_map = {
        { "Training_Camp", ArenaType::Training_Camp },
        { "Goblin_Stadium", ArenaType::Goblin_Stadium },
        { "Bone_Pit", ArenaType::Bone_Pit },
        { "Barbarian_Bowl", ArenaType::Barbarian_Bowl },
        { "Spell_Valley", ArenaType::Spell_Valley },
        { "Builders_Workshop", ArenaType::Builders_Workshop },
        { "PEKKAs_Playhouse", ArenaType::PEKKAs_Playhouse },
        { "Royal_Arena", ArenaType::Royal_Arena },
        { "Frozen_Peak", ArenaType::Frozen_Peak },
        { "Jungle_Arena", ArenaType::Jungle_Arena },
        { "Hog_Mountain", ArenaType::Hog_Mountain },
        { "Electro_Valley", ArenaType::Electro_Valley },
        { "Spooky_Town", ArenaType::Spooky_Town },
        { "Rascals_Hideout", ArenaType::Rascals_Hideout },
        { "Serenity_Peak", ArenaType::Serenity_Peak },
        { "Miners_Mine", ArenaType::Miners_Mine },
        { "Executioners_Kitchen", ArenaType::Executioners_Kitchen },
        { "Royal_Crypt", ArenaType::Royal_Crypt },
        { "Silent_Sanctuary", ArenaType::Silent_Sanctuary },
        { "Dragon_Spa", ArenaType::Dragon_Spa },
        { "Legendary_Arena", ArenaType::Legendary_Arena },
        { "Chess_Arena", ArenaType::Chess_Arena },
    };

    auto it = value_map.find(name);
    if (it != value_map.end())
        return it->second;
    return ArenaType::Training_Camp; // Return default value if no match is found
  }

private:
  Value value;
};
typedef std::shared_ptr<ArenaType> pArenaType;

#endif
