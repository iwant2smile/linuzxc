#include <iostream>
#include <vector>
#include "Complex.h"
#include "Sort.h"

int main() {
	std::vector<Complex> numbers;
	numbers.push_back(Complex(3, 4));
	numbers.push_back(Complex(1, 1));
	numbers.push_back(Complex(0, 2));
	numbers.push_back(Complex(5, 12));

	std::cout << "До сортировки:\n";
	for (const auto& num : numbers) {
	num.print();
    }

	sortComplexNumbers(numbers);

	std::cout << "После сортировки:\n";
	for (const auto& num : numbers) {
	num.print();
    }

    return 0;
}
