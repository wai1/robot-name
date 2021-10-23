#include "robot_name.h"
#include <random>
#include <algorithm>

namespace robot_name {

	std::set<std::string> robot::names_used{};

	robot::robot() {
		robot_name = generate_name();
	}

	std::string robot::generate_name() {
		
		// Better random generator
		std::vector<uint32_t> random_data(624);
		std::random_device source;
		std::generate(random_data.begin(), random_data.end(), std::ref(source));
		std::seed_seq seeds(random_data.begin(), random_data.end());
		std::mt19937 gen(seeds);

		std::uniform_int_distribution<> alpha('A', 'Z');
		std::uniform_int_distribution<> numa('0', '9');
		std::string name_builder;

		do {
			name_builder = "";
			name_builder.push_back(alpha(gen));
			name_builder.push_back(alpha(gen));
			name_builder.push_back(numa(gen));
			name_builder.push_back(numa(gen));
			name_builder.push_back(numa(gen));
		} while (names_used.find(name_builder) != names_used.end());

		add_name(name_builder);
		return name_builder;
	}

	void robot::add_name(std::string name) {
		names_used.insert(name);
	}

	void robot::reset() {
		this->robot_name = generate_name();
	}

	std::string robot::name() const {
		return this->robot_name;
	}
} // namespace robot_name