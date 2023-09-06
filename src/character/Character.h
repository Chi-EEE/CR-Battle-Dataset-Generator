#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once

#include "../utils/Random.h"
#include "Orientation.h"

namespace character {
    class Character
    {
    public:
        Character();
        ~Character();

    private:
        Orientation orientation;
    };
}

#endif