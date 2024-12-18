#define ARGUMENT_VALIDATOR_DEF
#include <argument_validator.hpp>

#include <iostream>

int main(int argc, const char* argv[]) {
  if(argc == 1)
    return -1;

  ArgumentValidator argument = ArgumentValidator("asdf");
  std::cout << argument.validate(argv[1]);
  return 0;
}
