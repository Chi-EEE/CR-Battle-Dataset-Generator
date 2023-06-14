
/**
 ********************************************************************
 *
 * WARNING! This file was automatically generated. Do not edit it, as your
 * changes will be lost. Edit scripts/generateTowerSkinEnum.py instead.
 *
 ********************************************************************
 */
#ifndef TOWERSKIN_H
#define TOWERSKIN_H
#include <ostream>
#include <vector>
#include <string>
class TowerSkin
{
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
    _Count
};
std::vector<Value> values();
std::string name(Value e);
Value valueOf(std::string str);
}
std::ostream& operator<<(std::ostream& os, const TowerSkin::Value& e);
#endif // TOWERSKIN_H
