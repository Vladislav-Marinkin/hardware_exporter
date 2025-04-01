#include "parser.h"

template<typename T>
inline void parser::run(string_vector& regex, string_vector& commands, T& data)
{
	string output;
#ifdef NDEBUG
	try {
		for (const string& command : commands) {
			output += runCommand(command) + "\n";
		}
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error executing the command: " << e.what() << std::endl;
	}
#else
	testData _testData;
	output += _testData.getAdaptecTestData();
	output += _testData.getFanDriveData();
	output += _testData.getLSIControllerTestData();
	output += _testData.getLSIDiskTestData();
	output += _testData.getSsacliControllerTestData();
	output += _testData.getSsacliDiskTestData();
#endif

	parse(output, regex, data);
}

template<typename T>
void parser::parse(string& output, string_vector& regex, T& data)
{

}
