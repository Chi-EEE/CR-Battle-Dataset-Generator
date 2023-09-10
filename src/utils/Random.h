#ifndef RANDOM_H
#define RANDOM_H

#pragma once

#include <random>
#include <filesystem>

#include "fmt/format.h"
#include "tl/expected.hpp"

class Random
{
public:
    Random();
    Random(Random const&) = delete;
    Random& operator=(Random const&) = delete;
    template<class Iterator>
    void shuffle(Iterator iterator);
    int random_int_from_interval(int min, int max);
    tl::expected<std::string, std::string> Random::try_get_random_file_from_directory(std::filesystem::path directory_path);
    tl::expected<std::string, std::string> try_get_random_directory_from_directory(std::filesystem::path directory_path);
    static Random& get_instance() {
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