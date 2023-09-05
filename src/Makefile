all: test

test:
	g++ tests/tests.cc model/element.cc model/expressionConverter.cc model/calculation.cc -lgtest -lgtest_main
	./a.out

clean:
	rm *.out

rebuild: clean test