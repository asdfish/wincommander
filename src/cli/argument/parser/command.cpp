#include <cli/argument/parser/command.hpp>

CommandParser::CommandParser(
  std::string&& input_name,
  ArgumentType argument_type,
  std::optional<ArgumentValidator>&& argument_validator
):
  name(input_name) {
  this->argument_type = argument_type;
  this->argument_validator = argument_validator;
}
void CommandParser::parse(int argc, const char* argv[]) {
  if(argc >= 2 && argv[1] == name)
    parse_base(argc, argv);
}
