BLAS_PATH = ./OpenBLAS
CXX = g++
CXXFLAGS = -I$(BLAS_PATH) -I./include
LDFLAGS = -L$(BLAS_PATH) -lopenblas -lm

TESTS_SOURCES = $(wildcard tests/*.cpp)
TEST_FUNCTIONS = $(filter-out tests/main_test.cpp, $(TESTS_SOURCES))

MAIN_TEST = tests/main_test
ROOT_TARGETS = $(wildcard *.cpp)
ROOT_TARGETS := $(ROOT_TARGETS:.cpp=)

all: $(MAIN_TEST) $(ROOT_TARGETS)

$(MAIN_TEST): tests/main_test.cpp $(TEST_FUNCTIONS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%: %.
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

run: all
	@echo "------------------------------------"
	@echo "Running main_test..."
	@LD_LIBRARY_PATH=$(BLAS_PATH) ./$(MAIN_TEST)
	@for target in $(ROOT_TARGETS); do \
		echo "------------------------------------"; \
		echo "Running $$target..."; \
		LD_LIBRARY_PATH=$(BLAS_PATH) ./$$target; \
	done

clean:
	rm -f $(MAIN_TEST) $(ROOT_TARGETS) tests/*.o *.o

.PHONY: all run clean