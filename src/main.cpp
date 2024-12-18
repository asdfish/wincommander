#include <cli/flag.hpp>
#include <cli/flags.hpp>

#include <iostream>

int main(int argc, char* argv[]) {
  Flags flags = Flags(
    std::unordered_map<char, Flag> {
      { 'v', Flag(ARGUMENT_NONE, "Make commands more verbose", "verbose") },
      { 'h', Flag(ARGUMENT_OPTIONAL, "Make commands more verbose", "ver") },
    }
  );
  /*flags.parse(argc, argv);*/

  flags.print_documentation(2);

  return 0;
}
