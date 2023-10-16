CXX = g++ -g #-fsanitize=address
WFLAGS = -std=c++17 -Wall -Werror -Wextra
CFLAGS = -c
OFLAGS = -o
COVFLAGS = -fprofile-arcs -ftest-coverage
TESTF = -lgtest -I/usr/local/include -L/usr/local/lib -pthread -lgcov #-lasan

SRCS = $(wildcard model/*.cc)
OBJS = $(SRCS:.cc=.o)

.PHONY: all clean rebuild

all: tests

gcov_report: tests
	gcov -f model/*.gcda
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=0 --no-external
	genhtml -o report test.info  --rc lcov_branch_coverage=0
	open report/index.html

tests: $(OBJS) tests/tests.o
	$(CXX) --coverage $(OFLAGS) test.out $(TESTF) $^
	./test.out

$(OBJS): %.o: %.cc
	$(CXX) $(WFLAGS) $(COVFLAGS) $(CFLAGS) -o $@ $<

tests/tests.o: WFLAGS += -Wno-unused-function

install:
	@cd SmartCalc_V2 && cmake . && make && mv -f SmartCalc_V2.app ../../build/

uninstall:
	@rm -rf ../build/SmartCalc_V2.app

dist:
	tar -czvf ../build/SmartCalc_V2.tar.gz ../build/SmartCalc_V2.app

dvi:

style:
	@cp ../materials/linters/.clang-format .
	@clang-format -i model/*.cc
	@clang-format -i model/*.h
	@clang-format -i controller/*.cc
	@clang-format -i controller/*.h
	@clang-format -i view/*.cc
	@clang-format -i view/*.h
	@clang-format -i tests/*.cc
	@clang-format -i tests/*.h
	@clang-format -i fornextbonus/*.cc
	@clang-format -i fornextbonus/*.h
	clang-format -n model/*.cc
	clang-format -n model/*.h
	clang-format -n controller/*.cc
	clang-format -n controller/*.h
	clang-format -n view/*.cc
	clang-format -n view/*.h
	clang-format -n tests/*.cc
	clang-format -n tests/*.h
	clang-format -n fornextbonus/*.cc
	clang-format -n fornextbonus/*.h
	@rm .clang-format

leaks:
	leaks -atExit -- ./test.out

open: install
	@open ../build/SmartCalc_V2.app

clean: uninstall
	@rm -f *.out model/*.o model/*.gcno tests/*.o model/*.gcda *.info
	@rm -rf report
	@rm -f *.gcov
	@rm -rf ../build/SmartCalc_V2.app
	@rm -rf ../build/SmartCalc_V2.tar.gz
	@rm -rf SmartCalc_V2/CMakeFiles
	@rm -rf SmartCalc_V2/SmartCalc_V2.app
	@rm -rf SmartCalc_V2/SmartCalc_V2_autogen
	@rm -f SmartCalc_V2/cmake_install.cmake
	@rm -f SmartCalc_V2/CMakeCache.txt
	@rm -f SmartCalc_V2/Makefile
	@rm -f ../build/SmartCalc_V2.tar.gz

rebuild: clean test