#include <deque>
#include <iostream>

int main() {
	std::deque<int> d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (size_t i = 0; i != d.size(); ++i) {
		if (i == 9) {
			std::cout << d[i];
		}
		else {
			std::cout << d[i] << ", ";
		}
	}
	
	std::cout << "\n" << d.size() << "\n";

	d.erase(d.begin() + 2);
	d.erase(d.begin() + 3);
	d.erase(d.begin() + 4);
	
	for (size_t i = 0; i != d.size(); ++i) {
		if (i == 6) {
			std::cout << d[i];
		}
		else {
			std::cout << d[i] << ", ";
		}
	}

	std::cout << "\n";

	d.insert(d.begin() + 4, 20);

	for (size_t i = 0; i != d.size(); ++i) {
		if (i == 7) {
			std::cout << d[i];
		}
		else {
			std::cout << d[i] << ", ";
		}
	}

	std::cout << "\n";

	d.push_back(30);

	for (size_t i = 0; i != d.size(); ++i) {
		if (i == 8) {
			std::cout << d[i];
		}
		else {
			std::cout << d[i] << ", ";
		}
	}

}