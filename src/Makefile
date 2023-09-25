all: test

test:
	clang++ tests/tests.cc model/element.cc model/expressionConverter.cc model/calculation.cc -lgtest -I/usr/local/include -L/usr/local/lib/
	./a.out

clean:
	rm *.out

rebuild: clean test