
/**
 ********************************************************************
 *
 * WARNING! This file was automatically generated. Do not edit it, as your
 * changes will be lost. Edit scripts/generateTowerSkinEnum.py instead.
 *
 ********************************************************************
 */
#include "TowerSkin.h"
class TowerSkin
{
std::vector<Value> values()
{
    static std::vector<Value> v;
    if (!v.size())
    {
        v.push_back(Default);
        v.push_back(Red);
        v.push_back(Ice_House);
        v.push_back(Gingerbread_House);
        v.push_back(Clan_Boat_Bastion);
        v.push_back(Logmas);
        v.push_back(Clashmas_Tavern);
        v.push_back(Tiger);
        v.push_back(Gem_Mine);
        v.push_back(Giant_Skeleton);
        v.push_back(Duck_Hunt);
        v.push_back(Royal_Fest);
        v.push_back(Spooky_Town);
        v.push_back(Sheep);
        v.push_back(Nutcracker);
        v.push_back(Clashmas_Tree);
        v.push_back(Clashmas_Sweater);
        v.push_back(Rabbit);
        v.push_back(Magic_Archer);
        v.push_back(Disco_Defense);
        v.push_back(Boot_Camp);
        v.push_back(Bookz);
        v.push_back(S1);
        v.push_back(S2);
        v.push_back(S3);
        v.push_back(S4);
        v.push_back(S5);
        v.push_back(S6);
        v.push_back(S7);
        v.push_back(S8);
        v.push_back(S9);
        v.push_back(S10);
        v.push_back(S11);
        v.push_back(S12);
        v.push_back(S13);
        v.push_back(S14);
        v.push_back(S15);
        v.push_back(S16);
        v.push_back(S17);
        v.push_back(S18);
        v.push_back(S19);
        v.push_back(S20);
        v.push_back(S21);
        v.push_back(S22);
        v.push_back(S23);
        v.push_back(S24);
        v.push_back(S25);
        v.push_back(S26);
        v.push_back(S27);
        v.push_back(S28);
        v.push_back(S29);
        v.push_back(S30);
        v.push_back(S31);
        v.push_back(S32);
        v.push_back(S33);
        v.push_back(S34);
        v.push_back(S35);
        v.push_back(S36);
        v.push_back(S37);
        v.push_back(S38);
        v.push_back(S39);
        v.push_back(S40);
        v.push_back(S41);
        v.push_back(S42);
        v.push_back(S43);
        v.push_back(S44);
        v.push_back(S45);
        v.push_back(S46);
        v.push_back(S47);
        v.push_back(S48);
    }
    return v;
}
std::string name(Value e)
{
    switch (e)
    {
        case Default: return "Default";
        case Red: return "Red";
        case Ice_House: return "Ice_House";
        case Gingerbread_House: return "Gingerbread_House";
        case Clan_Boat_Bastion: return "Clan_Boat_Bastion";
        case Logmas: return "Logmas";
        case Clashmas_Tavern: return "Clashmas_Tavern";
        case Tiger: return "Tiger";
        case Gem_Mine: return "Gem_Mine";
        case Giant_Skeleton: return "Giant_Skeleton";
        case Duck_Hunt: return "Duck_Hunt";
        case Royal_Fest: return "Royal_Fest";
        case Spooky_Town: return "Spooky_Town";
        case Sheep: return "Sheep";
        case Nutcracker: return "Nutcracker";
        case Clashmas_Tree: return "Clashmas_Tree";
        case Clashmas_Sweater: return "Clashmas_Sweater";
        case Rabbit: return "Rabbit";
        case Magic_Archer: return "Magic_Archer";
        case Disco_Defense: return "Disco_Defense";
        case Boot_Camp: return "Boot_Camp";
        case Bookz: return "Bookz";
        case S1: return "S1";
        case S2: return "S2";
        case S3: return "S3";
        case S4: return "S4";
        case S5: return "S5";
        case S6: return "S6";
        case S7: return "S7";
        case S8: return "S8";
        case S9: return "S9";
        case S10: return "S10";
        case S11: return "S11";
        case S12: return "S12";
        case S13: return "S13";
        case S14: return "S14";
        case S15: return "S15";
        case S16: return "S16";
        case S17: return "S17";
        case S18: return "S18";
        case S19: return "S19";
        case S20: return "S20";
        case S21: return "S21";
        case S22: return "S22";
        case S23: return "S23";
        case S24: return "S24";
        case S25: return "S25";
        case S26: return "S26";
        case S27: return "S27";
        case S28: return "S28";
        case S29: return "S29";
        case S30: return "S30";
        case S31: return "S31";
        case S32: return "S32";
        case S33: return "S33";
        case S34: return "S34";
        case S35: return "S35";
        case S36: return "S36";
        case S37: return "S37";
        case S38: return "S38";
        case S39: return "S39";
        case S40: return "S40";
        case S41: return "S41";
        case S42: return "S42";
        case S43: return "S43";
        case S44: return "S44";
        case S45: return "S45";
        case S46: return "S46";
        case S47: return "S47";
        case S48: return "S48";
        default : return "???";
    }
}
Value valueOf(std::string str)
{
switch (str) {
    case "Default": return Default;
    case "Red": return Red;
    case "Ice_House": return Ice_House;
    case "Gingerbread_House": return Gingerbread_House;
    case "Clan_Boat_Bastion": return Clan_Boat_Bastion;
    case "Logmas": return Logmas;
    case "Clashmas_Tavern": return Clashmas_Tavern;
    case "Tiger": return Tiger;
    case "Gem_Mine": return Gem_Mine;
    case "Giant_Skeleton": return Giant_Skeleton;
    case "Duck_Hunt": return Duck_Hunt;
    case "Royal_Fest": return Royal_Fest;
    case "Spooky_Town": return Spooky_Town;
    case "Sheep": return Sheep;
    case "Nutcracker": return Nutcracker;
    case "Clashmas_Tree": return Clashmas_Tree;
    case "Clashmas_Sweater": return Clashmas_Sweater;
    case "Rabbit": return Rabbit;
    case "Magic_Archer": return Magic_Archer;
    case "Disco_Defense": return Disco_Defense;
    case "Boot_Camp": return Boot_Camp;
    case "Bookz": return Bookz;
    case "S1": return S1;
    case "S2": return S2;
    case "S3": return S3;
    case "S4": return S4;
    case "S5": return S5;
    case "S6": return S6;
    case "S7": return S7;
    case "S8": return S8;
    case "S9": return S9;
    case "S10": return S10;
    case "S11": return S11;
    case "S12": return S12;
    case "S13": return S13;
    case "S14": return S14;
    case "S15": return S15;
    case "S16": return S16;
    case "S17": return S17;
    case "S18": return S18;
    case "S19": return S19;
    case "S20": return S20;
    case "S21": return S21;
    case "S22": return S22;
    case "S23": return S23;
    case "S24": return S24;
    case "S25": return S25;
    case "S26": return S26;
    case "S27": return S27;
    case "S28": return S28;
    case "S29": return S29;
    case "S30": return S30;
    case "S31": return S31;
    case "S32": return S32;
    case "S33": return S33;
    case "S34": return S34;
    case "S35": return S35;
    case "S36": return S36;
    case "S37": return S37;
    case "S38": return S38;
    case "S39": return S39;
    case "S40": return S40;
    case "S41": return S41;
    case "S42": return S42;
    case "S43": return S43;
    case "S44": return S44;
    case "S45": return S45;
    case "S46": return S46;
    case "S47": return S47;
    case "S48": return S48;
    default: return (Value)0;
}
}
}
std::ostream& operator<<(std::ostream& os, const TowerSkin::Value& e)
{
    switch (e)
    {
        case TowerSkin::Default : return os << "Default";
        case TowerSkin::Red : return os << "Red";
        case TowerSkin::Ice_House : return os << "Ice_House";
        case TowerSkin::Gingerbread_House : return os << "Gingerbread_House";
        case TowerSkin::Clan_Boat_Bastion : return os << "Clan_Boat_Bastion";
        case TowerSkin::Logmas : return os << "Logmas";
        case TowerSkin::Clashmas_Tavern : return os << "Clashmas_Tavern";
        case TowerSkin::Tiger : return os << "Tiger";
        case TowerSkin::Gem_Mine : return os << "Gem_Mine";
        case TowerSkin::Giant_Skeleton : return os << "Giant_Skeleton";
        case TowerSkin::Duck_Hunt : return os << "Duck_Hunt";
        case TowerSkin::Royal_Fest : return os << "Royal_Fest";
        case TowerSkin::Spooky_Town : return os << "Spooky_Town";
        case TowerSkin::Sheep : return os << "Sheep";
        case TowerSkin::Nutcracker : return os << "Nutcracker";
        case TowerSkin::Clashmas_Tree : return os << "Clashmas_Tree";
        case TowerSkin::Clashmas_Sweater : return os << "Clashmas_Sweater";
        case TowerSkin::Rabbit : return os << "Rabbit";
        case TowerSkin::Magic_Archer : return os << "Magic_Archer";
        case TowerSkin::Disco_Defense : return os << "Disco_Defense";
        case TowerSkin::Boot_Camp : return os << "Boot_Camp";
        case TowerSkin::Bookz : return os << "Bookz";
        case TowerSkin::S1 : return os << "S1";
        case TowerSkin::S2 : return os << "S2";
        case TowerSkin::S3 : return os << "S3";
        case TowerSkin::S4 : return os << "S4";
        case TowerSkin::S5 : return os << "S5";
        case TowerSkin::S6 : return os << "S6";
        case TowerSkin::S7 : return os << "S7";
        case TowerSkin::S8 : return os << "S8";
        case TowerSkin::S9 : return os << "S9";
        case TowerSkin::S10 : return os << "S10";
        case TowerSkin::S11 : return os << "S11";
        case TowerSkin::S12 : return os << "S12";
        case TowerSkin::S13 : return os << "S13";
        case TowerSkin::S14 : return os << "S14";
        case TowerSkin::S15 : return os << "S15";
        case TowerSkin::S16 : return os << "S16";
        case TowerSkin::S17 : return os << "S17";
        case TowerSkin::S18 : return os << "S18";
        case TowerSkin::S19 : return os << "S19";
        case TowerSkin::S20 : return os << "S20";
        case TowerSkin::S21 : return os << "S21";
        case TowerSkin::S22 : return os << "S22";
        case TowerSkin::S23 : return os << "S23";
        case TowerSkin::S24 : return os << "S24";
        case TowerSkin::S25 : return os << "S25";
        case TowerSkin::S26 : return os << "S26";
        case TowerSkin::S27 : return os << "S27";
        case TowerSkin::S28 : return os << "S28";
        case TowerSkin::S29 : return os << "S29";
        case TowerSkin::S30 : return os << "S30";
        case TowerSkin::S31 : return os << "S31";
        case TowerSkin::S32 : return os << "S32";
        case TowerSkin::S33 : return os << "S33";
        case TowerSkin::S34 : return os << "S34";
        case TowerSkin::S35 : return os << "S35";
        case TowerSkin::S36 : return os << "S36";
        case TowerSkin::S37 : return os << "S37";
        case TowerSkin::S38 : return os << "S38";
        case TowerSkin::S39 : return os << "S39";
        case TowerSkin::S40 : return os << "S40";
        case TowerSkin::S41 : return os << "S41";
        case TowerSkin::S42 : return os << "S42";
        case TowerSkin::S43 : return os << "S43";
        case TowerSkin::S44 : return os << "S44";
        case TowerSkin::S45 : return os << "S45";
        case TowerSkin::S46 : return os << "S46";
        case TowerSkin::S47 : return os << "S47";
        case TowerSkin::S48 : return os << "S48";
        default : return os << "???"; 
    }
}
