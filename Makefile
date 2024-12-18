CXX ?= c++
CXXFLAGS ?= -O2 -march=native -pipe
override CXXFLAGS += -std=c++20
override CXXFLAGS += -Wall -Wextra -Wpedantic
override CXXFLAGS += -Ibuild/include -Iinclude

# uncomment/comment to enable/disable
PROCESS_HEADER_FILES := yes
PROCESSED_HEADER_FILES := $(if ${PROCESS_HEADER_FILES},$\
														$(patsubst include/%.hpp,$\
															build/include/%.hpp.gch,$\
															$(shell find include -name '*.hpp' -type f)))

OBJECT_FILES := $(patsubst src/%.cpp,$\
									build/src/%.o,$\
									$(shell find src -name '*.cpp' -type f))

WINCOMMANDER_REQUIREMENTS := ${PROCESSED_HEADER_FILES} ${OBJECT_FILES}

define COMPILE
${CXX} -c $(1) ${CXXFLAGS} -o $(2)

endef
define REMOVE
$(if $(wildcard $(1)),$\
	rm $(1))

endef
define REMOVE_LIST
$(foreach ITEM,$\
	$(1),$\
	$(call REMOVE,${ITEM}))
endef

all: wincommander

wincommander: ${WINCOMMANDER_REQUIREMENTS}
	${CXX} ${OBJECT_FILES} ${CXXFLAGS} ${LDFLAGS} -o $@

build/src/%.o: src/%.cpp
	$(call COMPILE,$<,$@)
build/include/%.hpp.gch: include/%.hpp
	$(call COMPILE,$<,$@)

clean:
	$(call REMOVE_LIST,${WINCOMMANDER_REQUIREMENTS})
	$(call REMOVE,wincommander)

.PHONY: all clean install uninstall
