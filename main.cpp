#include <iostream>
#include "Array.h"

template<typename T>
void printArray(const Array<T>& arr) {

	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr.at(i) << " ";
	}
	std::cout << "\n";

}

int main(int argc, char** argv) {



	return 0;
}