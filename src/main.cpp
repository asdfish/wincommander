#define FLAGS_DEF
#include <cli/flags.hpp>

#include <iostream>

int main(int argc, char* argv[]) {
  Flags flags = Flags(
    std::unordered_map<char, Flag> {
      { 'v', Flag(ARGUMENT_NONE, "make commands more verbose", "verbose") },
    }
  );
  flags.parse(argc, argv);

  return 0;
}
