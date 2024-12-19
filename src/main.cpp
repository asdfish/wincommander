#include <cli/argument/parser/flag.hpp>
#include <cli/flags.hpp>

#include <std/iostream.hpp>

int main(int argc, char* argv[]) {
  Flags flags = Flags(
    std::unordered_map<char, FlagParser> {
      { 'v', FlagParser("Make commands more verbose", "verbose", ARGUMENT_NONE) },
    }
  );
  /*flags.parse(argc, argv);*/

  flags.print_documentation(2);

  return 0;
}
