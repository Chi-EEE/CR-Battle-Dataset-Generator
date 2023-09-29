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
	static json settings;

	static const json& getSettings() {
		return settings;
	}
	
	static void setSettings(const json& newSettings) {
		settings = newSettings;
	}
};

#endif