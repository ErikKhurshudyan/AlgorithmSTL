# Project configuration
progname = SetAlgorithm
utest = utest_$(progname)
CXX = g++
HEADER_DIR = headers
SRC_DIR = sources
TEST_DIR = tests
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -I. -I../DoubleList/headers -L/usr/local/lib/

# Debug and release flags
debug:   CXXFLAGS += -g3
release: CXXFLAGS += -g0 -DNDEBUG

BUILDS = builds
ifeq ($(MAKECMDGOALS),)
    BUILD_DIR = $(BUILDS)/debug
else
    BUILD_DIR = $(BUILDS)/$(MAKECMDGOALS)
endif

SOURCES = main.cpp $(filter-out $(SRC_DIR)/Deque.cpp, $(wildcard $(SRC_DIR)/*.cpp))
PREPROCS = $(patsubst %.cpp,$(BUILD_DIR)/%.ii,$(SOURCES))
ASSEMBLES = $(patsubst %.cpp,$(BUILD_DIR)/%.s,$(SOURCES))
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEPENDS = $(patsubst %.cpp,$(BUILD_DIR)/%.d,$(SOURCES))

UTEST_SOURCES = main_utest.cpp $(filter-out $(SRC_DIR)/Deque.cpp, $(wildcard $(SRC_DIR)/*.cpp))
UTEST_PREPROCS = $(patsubst %.cpp,$(BUILD_DIR)/%.ii,$(UTEST_SOURCES))
UTEST_ASSEMBLES = $(patsubst %.cpp,$(BUILD_DIR)/%.s,$(UTEST_SOURCES))
UTEST_OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(UTEST_SOURCES))
UTEST_DEPENDS = $(patsubst %.cpp,$(BUILD_DIR)/%.d,$(UTEST_SOURCES))

TEST_INPUTS = $(wildcard $(TEST_DIR)/*.input)
TESTS = $(patsubst $(TEST_DIR)/%.input,%,$(TEST_INPUTS))

# Default build targets
debug: qa utest
release: qa utest

qa: $(BUILD_DIR) $(TESTS)

test%: $(progname)
	./$< < $(TEST_DIR)/$@.input > $(BUILD_DIR)/$(TEST_DIR)/$@.output 2>/dev/null || echo "Negative test"
	diff $(BUILD_DIR)/$(TEST_DIR)/$@.output $(TEST_DIR)/$@.expected >/dev/null && echo "$@ PASSED" || echo "$@ FAILED"

utest: $(utest)
	./$<

$(utest): $(UTEST_OBJS) | .gitignore
	$(CXX) $(CXXFLAGS) $^ -lgtest -o $@

$(progname): $(OBJS) | .gitignore
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.s
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.s: %.ii
	$(CXX) $(CXXFLAGS) -S $< -o $@

$(BUILD_DIR)/%.ii: %.cpp
	$(CXX) $(CXXFLAGS) -E $< -o $@
	$(CXX) $(CXXFLAGS) -MM $< -MT $@ > $(patsubst %.ii,%.d,$@)

$(BUILD_DIR):
	mkdir -p $@/$(TEST_DIR) $@/$(SRC_DIR)

.gitignore:
	echo $(progname) > .gitignore
	echo $(utest) >> .gitignore
	echo $(BUILDS) >> .gitignore

clean:
	rm -rf $(BUILDS) $(progname) $(utest) .gitignore

.PRECIOUS: $(PREPROCS) $(ASSEMBLES) $(UTEST_PREPROCS) $(UTEST_ASSEMBLES)
.SECONDARY: $(PREPROCS) $(ASSEMBLES) $(UTEST_PREPROCS) $(UTEST_ASSEMBLES)

sinclude $(DEPENDS) $(UTEST_DEPENDS)
