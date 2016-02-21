#include "python_like.h"
#include <iostream>
#include <vector>

using namespace python_like;

void python_in() {
	std::vector<int> ints{1, 2, 3, 4, 5, 6, 7};
	if (5 <in> ints) {
		std::cout << "5 is in ints" << std::endl;
	}
}

void python_not_in() {
	std::vector<int> ints{1, 2, 3, 4, 5, 6, 7};
	if (20 <not_in> ints) {
		std::cout << "20 is not in ints" << std::endl;
	}
}

int main() {
	// Will print "5 is in ints"
	python_in();
	// Will print "20 is not in ints"
	python_not_in();
}