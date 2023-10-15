CXX = g++ -g -fsanitize=address
WFLAGS = -std=c++17 -Wall -Werror -Wextra
CFLAGS = -c
OFLAGS = -o
COVFLAGS = -fprofile-arcs -ftest-coverage
TESTF = -lgtest -I/usr/local/include -L/usr/local/lib -pthread -lgcov -lasan

SRCS = $(wildcard model/*.cc)
OBJS = $(SRCS:.cc=.o)

.PHONY: all clean rebuild

all: test

gcov_report: test
	gcov -f model/*.gcda
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=0
	genhtml -o report test.info  --rc lcov_branch_coverage=0
	open report/index.html

test: $(OBJS) tests/tests.o
	$(CXX) --coverage $(OFLAGS) test.out $(TESTF) $^
	./test.out

$(OBJS): %.o: %.cc
	$(CXX) $(WFLAGS) $(COVFLAGS) $(CFLAGS) -o $@ $<

tests/tests.o: WFLAGS += -Wno-unused-function

clean:
	@rm -f *.out model/*.o model/*.gcno tests/*.o model/*.gcda *.info
	@rm -rf report
	@rm -f *.gcov

rebuild: clean test