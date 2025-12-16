#include "libutils/src/funcs.hpp"
#include "libutils/src/color.hpp"
#include "libutils/src/cliparser.hpp"
#include "libutils/src/file.hpp"

using funcs::print;

int main(int argc, char *argv[])
{
	CLIParser parser(argc, argv);

	auto printHelp = [&/*capture everything*/]() -> void {
		print /*useless comment*/ ("Usage:\n");
		print(argv[0], " ", color::TXT_CYAN, "<FILE>", color::_RESET, "\n");
	};

	if (argc != 2)
	{
		printHelp();
		return EXIT_FAILURE;
	}
	std::string filepath = parser.m_getArg(1);
	if (!File::m_isfile(filepath))
	{
		print("'", filepath, "' is not a file or doesn't exist.\n");
		return EXIT_FAILURE;
	}

	if (parser.m_hasFlag("-h"))
	{
		printHelp();
		return EXIT_SUCCESS;
	}

	std::ifstream file(filepath);
	if (!file.is_open())
	{
		print("Couldn't open file: Permission Denied.\n");
	}

	print("Enter text to find:\n> ", color::TXT_GREEN, color::_ITALIC);
	std::string to_find;
	std::getline(std::cin, to_find);
	print(color::_RESET);

	std::string line;
	uint64_t line_number = 1;
	while (std::getline(file, line))
	{
		if (funcs::hasSequence(line, to_find))
		{
			print("'", to_find, "' found on line ", color::TXT_RED, "(", line_number, ")", color::_RESET, ":\n", line, "\n\n");
		}
		line_number++;
	}
}