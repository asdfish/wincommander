#include <cli/argument/parser/flag.hpp>

#include <std/utility.hpp>

FlagParser::FlagParser(
  std::string&& input_documentation,
  std::string&& input_id,
  ArgumentType argument_type,
  std::optional<ArgumentValidator>&& argument_validator
):
  documentation(std::move(input_documentation)),
  id(input_id) {
  this->argument_type = argument_type;
  this->argument_validator = std::move(argument_validator);
}
void FlagParser::parse(std::optional<std::string>&& argument) {
  parse_base(std::move(argument));
}
