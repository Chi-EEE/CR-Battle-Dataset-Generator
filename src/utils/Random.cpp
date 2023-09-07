#include "Random.h"

Random::Random()
{
	engine = std::mt19937(this->random_device());
}

int Random::random_int_from_interval(int min, int max)
{
	std::uniform_int_distribution<> distr(min, max);
	return distr(engine);
}

tl::expected<std::string, std::string> Random::try_get_random_file_from_directory(std::filesystem::path directory_path)
{
	if (!std::filesystem::exists(directory_path)) return tl::make_unexpected(fmt::format("Unable to find the directory path: {}", directory_path.string()));
	if (!std::filesystem::is_directory(directory_path)) return tl::make_unexpected(fmt::format("Inputted path is not a directory path: {}", directory_path.string()));
	std::string path;
	size_t n = 1;
	std::default_random_engine generator(std::random_device{}());
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
		if (!entry.is_directory()) {
			if (distribution(generator) < 1.0 / n) {
				path = entry.path().string();
			}
			n++;
		}
	}
	return path;
}
