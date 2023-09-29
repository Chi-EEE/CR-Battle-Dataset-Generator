#ifndef GLOBAL_H
#define GLOBAL_H

#pragma once

#include <iostream>
#include <fstream>

#include "fmt/format.h"
#include "tl/expected.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Global {
public:
	static double scale;

	static json& get_json() {
		static json instance;
		return instance;
	}

	static tl::expected<nullptr_t, std::string> try_load_json_file(const std::string& filename) {
		std::ifstream file(filename);
		if (file) {
			try {
				json j;
				file >> j;
				get_json() = j;
				return nullptr;
			}
			catch (const std::exception& e) {
				return tl::make_unexpected(fmt::format("Error loading JSON from file: {}", e.what()));
			}
		}
		else {
			return tl::make_unexpected(fmt::format("Error opening file: {}", filename));
		}
	}
};

#endif