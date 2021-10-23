#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>
#include <set>

namespace robot_name {

	class robot
	{
		std::string robot_name;  // Name of new robot
		static std::set<std::string> names_used;  // Constainer used to store all robot names
		static void add_name(std::string name);  // Add name to names_used
		std::string generate_name();  // Make new name

	public:
		robot();  // No args constructor calls function to generate name
		std::string name() const;  // Returns name
		void reset();  // Calls method to replace name
	};
}

#endif // ROBOT_NAME_H


