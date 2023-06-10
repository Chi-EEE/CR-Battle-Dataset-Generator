#include "Random.h"

Random::Random()
{
	engine = std::mt19937(this->random_device());
}

int Random::randomIntFromInterval(int min, int max)
{
    std::uniform_int_distribution<> distr(min, max);
    return distr(engine);
}