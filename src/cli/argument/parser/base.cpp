#include <cli/argument/parser/base.hpp>

#include <std/format.hpp>
#include <std/utility.hpp>

#define FAIL(ERROR, ARGUMENT_TYPE, MOVE_BOOL) \
  if(ARGUMENT_TYPE == ARGUMENT_REQUIRED)      \
    throw ERROR;                              \
  else if(argument_type == ARGUMENT_OPTIONAL) \
    MOVE_BOOL = false;
#define CREATE_PARSE_FUNCTION(ARGUMENTS, ARGUMENT_EXISTS_PREDICATE, GET_ARGUMENT)               \
void ArgumentParserBase::parse_base ARGUMENTS {                                                 \
  bool move_argument = true;                                                                    \
                                                                                                \
  if(argument_type == ARGUMENT_NONE) {                                                          \
    if(ARGUMENT_EXISTS_PREDICATE) {                                                             \
      if(argument_validator.has_value()) {                                                      \
        if(!argument_validator.value().validate(GET_ARGUMENT)) {                                \
           FAIL(std::format("Invalid argument {}", GET_ARGUMENT), argument_type, move_argument) \
        }                                                                                       \
      } else FAIL("Missing argument validator", argument_type, move_argument)                   \
    } else FAIL("Missing argument", argument_type, move_argument)                               \
  }                                                                                             \
                                                                                                \
  if(move_argument && ARGUMENT_EXISTS_PREDICATE)                                                \
    this->argument = std::optional<std::string>(std::move(GET_ARGUMENT));                       \
  else                                                                                          \
    this->argument = std::nullopt;                                                              \
                                                                                                \
  set = true;                                                                                   \
}

ArgumentParserBase::ArgumentParserBase(void):
  set(false),
  argument(std::nullopt),
  argument_type(ARGUMENT_NONE),
  argument_validator(std::nullopt) {}
ArgumentParserBase::ArgumentParserBase(
  ArgumentType input_argument_type,
  std::optional<ArgumentValidator>&& input_argument_validator
):
  argument_type(input_argument_type),
  argument_validator(std::move(input_argument_validator)) {}

CREATE_PARSE_FUNCTION((int argc, const char* argv[]), argc >= 3, argv[2]);
CREATE_PARSE_FUNCTION((std::optional<std::string>&& argument = std::nullopt), argument.has_value(), argument.value().c_str());
