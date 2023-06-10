#include <random>
#ifndef RANDOM_H
#define RANDOM_H

#pragma once

class Random
{
public:
    Random();
    Random(Random const&) = delete;
    Random& operator=(Random const&) = delete;
    template<class Iterator>
    void shuffle(Iterator iterator);
    int randomIntFromInterval(int min, int max);
    static Random& getInstance() {
        static Random instance;
        return instance;
    }
private:
    std::random_device random_device;
    std::mt19937 engine;
};

#endif

template<class Iterator>
inline void Random::shuffle(Iterator iterator)
{
    std::shuffle(iterator.begin(), iterator.end(), this->engine);
}