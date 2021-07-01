#include <iostream>

int h1(int key) {
	int x = (key + 5) * (key + 5);
	x = x / 16;
	x = x + key;
	x = x % 11;
	return x;
}

int main() {
	int key;
	while (true) {
		std::cout << "Input: ";
		std::cin >> key;
		std::cout << "Output: " << h1(key) << std::endl;

	}
	return 0;
}