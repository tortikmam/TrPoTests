BLAS_PATH = ./OpenBLAS
BLAS_CHECK_FILE = $(BLAS_PATH)/Makefile

CXX = g++
CXXFLAGS = -I$(BLAS_PATH) -I./include
LDFLAGS = $(BLAS_PATH)/libopenblas.a -lpthread -lm

TESTS_SOURCES = $(wildcard tests/*.cpp)
TEST_FUNCTIONS = $(filter-out tests/main_test.cpp, $(TESTS_SOURCES))

MAIN_TEST = tests/main_test
ROOT_TARGETS = $(wildcard *.cpp)
ROOT_TARGETS := $(ROOT_TARGETS:.cpp=)

all: setup_blas $(MAIN_TEST) $(ROOT_TARGETS)

setup_blas:
	@if [ ! -f "$(BLAS_CHECK_FILE)" ]; then \
		echo "--- Submodule not found. Initializing OpenBLAS... ---"; \
		git submodule update --init --recursive; \
	fi
	@if [ ! -f "$(BLAS_PATH)/libopenblas.a" ]; then \
		echo "--- Building OpenBLAS (C only, no Fortran)... ---"; \
		$(MAKE) -C $(BLAS_PATH) NO_SHARED=1 ONLY_CBLAS=1 NOFORTRAN=1; \
	fi

$(MAIN_TEST): tests/main_test.cpp $(TEST_FUNCTIONS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%: %.cpp setup_blas
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

run: all
	@echo "------------------------------------"
	@echo "Running main_test..."
	./$(MAIN_TEST)
	@for target in $(ROOT_TARGETS); do \
		echo "------------------------------------"; \
		echo "Running $$target..."; \
		./$$target; \
	done

clean:
	rm -f $(MAIN_TEST) $(ROOT_TARGETS) tests/*.o *.o

distclean: clean
	$(MAKE) -C $(BLAS_PATH) clean
	rm -f $(BLAS_PATH)/libopenblas.a

.PHONY: all run clean setup_blas distclean