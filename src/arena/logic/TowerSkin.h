#ifndef TOWERSKIN_H
#define TOWERSKIN_H

#pragma once

#include <string>
#include <unordered_map>

namespace arena::logic {
    class TowerSkin
    {
    public:
        enum Value
        {
            Default,
            Red,
            Ice_House,
            Gingerbread_House,
            Clan_Boat_Bastion,
            Logmas,
            Clashmas_Tavern,
            Tiger,
            Gem_Mine,
            Giant_Skeleton,
            Duck_Hunt,
            Royal_Fest,
            Spooky_Town,
            Sheep,
            Nutcracker,
            Clashmas_Tree,
            Clashmas_Sweater,
            Rabbit,
            Magic_Archer,
            Disco_Defense,
            Boot_Camp,
            Bookz,
            S1,
            S2,
            S3,
            S4,
            S5,
            S6,
            S7,
            S8,
            S9,
            S10,
            S11,
            S12,
            S13,
            S14,
            S15,
            S16,
            S17,
            S18,
            S19,
            S20,
            S21,
            S22,
            S23,
            S24,
            S25,
            S26,
            S27,
            S28,
            S29,
            S30,
            S31,
            S32,
            S33,
            S34,
            S35,
            S36,
            S37,
            S38,
            S39,
            S40,
            S41,
            S42,
            S43,
            S44,
            S45,
            S46,
            S47,
            S48,
        };

        TowerSkin() = default;
        constexpr TowerSkin(Value value) : value(value) { }

        constexpr operator Value() const { return value; }
        explicit operator bool() const = delete;
        constexpr bool operator==(TowerSkin a) const { return value == a.value; }
        constexpr bool operator!=(TowerSkin a) const { return value != a.value; }

        std::string to_string() const
        {
            switch (value)
            {
            case TowerSkin::Default: return "Default";
            case TowerSkin::Red: return "Red";
            case TowerSkin::Ice_House: return "Ice_House";
            case TowerSkin::Gingerbread_House: return "Gingerbread_House";
            case TowerSkin::Clan_Boat_Bastion: return "Clan_Boat_Bastion";
            case TowerSkin::Logmas: return "Logmas";
            case TowerSkin::Clashmas_Tavern: return "Clashmas_Tavern";
            case TowerSkin::Tiger: return "Tiger";
            case TowerSkin::Gem_Mine: return "Gem_Mine";
            case TowerSkin::Giant_Skeleton: return "Giant_Skeleton";
            case TowerSkin::Duck_Hunt: return "Duck_Hunt";
            case TowerSkin::Royal_Fest: return "Royal_Fest";
            case TowerSkin::Spooky_Town: return "Spooky_Town";
            case TowerSkin::Sheep: return "Sheep";
            case TowerSkin::Nutcracker: return "Nutcracker";
            case TowerSkin::Clashmas_Tree: return "Clashmas_Tree";
            case TowerSkin::Clashmas_Sweater: return "Clashmas_Sweater";
            case TowerSkin::Rabbit: return "Rabbit";
            case TowerSkin::Magic_Archer: return "Magic_Archer";
            case TowerSkin::Disco_Defense: return "Disco_Defense";
            case TowerSkin::Boot_Camp: return "Boot_Camp";
            case TowerSkin::Bookz: return "Bookz";
            case TowerSkin::S1: return "S1";
            case TowerSkin::S2: return "S2";
            case TowerSkin::S3: return "S3";
            case TowerSkin::S4: return "S4";
            case TowerSkin::S5: return "S5";
            case TowerSkin::S6: return "S6";
            case TowerSkin::S7: return "S7";
            case TowerSkin::S8: return "S8";
            case TowerSkin::S9: return "S9";
            case TowerSkin::S10: return "S10";
            case TowerSkin::S11: return "S11";
            case TowerSkin::S12: return "S12";
            case TowerSkin::S13: return "S13";
            case TowerSkin::S14: return "S14";
            case TowerSkin::S15: return "S15";
            case TowerSkin::S16: return "S16";
            case TowerSkin::S17: return "S17";
            case TowerSkin::S18: return "S18";
            case TowerSkin::S19: return "S19";
            case TowerSkin::S20: return "S20";
            case TowerSkin::S21: return "S21";
            case TowerSkin::S22: return "S22";
            case TowerSkin::S23: return "S23";
            case TowerSkin::S24: return "S24";
            case TowerSkin::S25: return "S25";
            case TowerSkin::S26: return "S26";
            case TowerSkin::S27: return "S27";
            case TowerSkin::S28: return "S28";
            case TowerSkin::S29: return "S29";
            case TowerSkin::S30: return "S30";
            case TowerSkin::S31: return "S31";
            case TowerSkin::S32: return "S32";
            case TowerSkin::S33: return "S33";
            case TowerSkin::S34: return "S34";
            case TowerSkin::S35: return "S35";
            case TowerSkin::S36: return "S36";
            case TowerSkin::S37: return "S37";
            case TowerSkin::S38: return "S38";
            case TowerSkin::S39: return "S39";
            case TowerSkin::S40: return "S40";
            case TowerSkin::S41: return "S41";
            case TowerSkin::S42: return "S42";
            case TowerSkin::S43: return "S43";
            case TowerSkin::S44: return "S44";
            case TowerSkin::S45: return "S45";
            case TowerSkin::S46: return "S46";
            case TowerSkin::S47: return "S47";
            case TowerSkin::S48: return "S48";
            default: return "Unknown";
            }
        }

        static Value from_string(const std::string& name)
        {
            static const std::unordered_map<std::string, Value> value_map = {
                { "Default", TowerSkin::Default },
                { "Red", TowerSkin::Red },
                { "Ice_House", TowerSkin::Ice_House },
                { "Gingerbread_House", TowerSkin::Gingerbread_House },
                { "Clan_Boat_Bastion", TowerSkin::Clan_Boat_Bastion },
                { "Logmas", TowerSkin::Logmas },
                { "Clashmas_Tavern", TowerSkin::Clashmas_Tavern },
                { "Tiger", TowerSkin::Tiger },
                { "Gem_Mine", TowerSkin::Gem_Mine },
                { "Giant_Skeleton", TowerSkin::Giant_Skeleton },
                { "Duck_Hunt", TowerSkin::Duck_Hunt },
                { "Royal_Fest", TowerSkin::Royal_Fest },
                { "Spooky_Town", TowerSkin::Spooky_Town },
                { "Sheep", TowerSkin::Sheep },
                { "Nutcracker", TowerSkin::Nutcracker },
                { "Clashmas_Tree", TowerSkin::Clashmas_Tree },
                { "Clashmas_Sweater", TowerSkin::Clashmas_Sweater },
                { "Rabbit", TowerSkin::Rabbit },
                { "Magic_Archer", TowerSkin::Magic_Archer },
                { "Disco_Defense", TowerSkin::Disco_Defense },
                { "Boot_Camp", TowerSkin::Boot_Camp },
                { "Bookz", TowerSkin::Bookz },
                { "S1", TowerSkin::S1 },
                { "S2", TowerSkin::S2 },
                { "S3", TowerSkin::S3 },
                { "S4", TowerSkin::S4 },
                { "S5", TowerSkin::S5 },
                { "S6", TowerSkin::S6 },
                { "S7", TowerSkin::S7 },
                { "S8", TowerSkin::S8 },
                { "S9", TowerSkin::S9 },
                { "S10", TowerSkin::S10 },
                { "S11", TowerSkin::S11 },
                { "S12", TowerSkin::S12 },
                { "S13", TowerSkin::S13 },
                { "S14", TowerSkin::S14 },
                { "S15", TowerSkin::S15 },
                { "S16", TowerSkin::S16 },
                { "S17", TowerSkin::S17 },
                { "S18", TowerSkin::S18 },
                { "S19", TowerSkin::S19 },
                { "S20", TowerSkin::S20 },
                { "S21", TowerSkin::S21 },
                { "S22", TowerSkin::S22 },
                { "S23", TowerSkin::S23 },
                { "S24", TowerSkin::S24 },
                { "S25", TowerSkin::S25 },
                { "S26", TowerSkin::S26 },
                { "S27", TowerSkin::S27 },
                { "S28", TowerSkin::S28 },
                { "S29", TowerSkin::S29 },
                { "S30", TowerSkin::S30 },
                { "S31", TowerSkin::S31 },
                { "S32", TowerSkin::S32 },
                { "S33", TowerSkin::S33 },
                { "S34", TowerSkin::S34 },
                { "S35", TowerSkin::S35 },
                { "S36", TowerSkin::S36 },
                { "S37", TowerSkin::S37 },
                { "S38", TowerSkin::S38 },
                { "S39", TowerSkin::S39 },
                { "S40", TowerSkin::S40 },
                { "S41", TowerSkin::S41 },
                { "S42", TowerSkin::S42 },
                { "S43", TowerSkin::S43 },
                { "S44", TowerSkin::S44 },
                { "S45", TowerSkin::S45 },
                { "S46", TowerSkin::S46 },
                { "S47", TowerSkin::S47 },
                { "S48", TowerSkin::S48 },
            };

            auto it = value_map.find(name);
            if (it != value_map.end())
                return it->second;
            return TowerSkin::Default; // Return default value if no match is found
        }

    private:
        Value value;
    };
}

#endif
