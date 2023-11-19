#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
	std::list<int> l = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//l.push_front(5);
	//l.push_front(0);

	//l.push_back(25);
	//l.push_back(30);

	//l.pop_front();
	//l.pop_back();

	for (int x : l) {
		if (x == 9) {
			cout << x;
		}
		else {
			cout << x << ", ";
		}
	}

	std::cout << "\n" << l.size() << "\n";
	auto pos1 = l.begin();
	auto pos2 = l.begin();
	auto pos3 = l.begin();
	advance(pos1, 2);
	advance(pos2, 4);
	advance(pos3, 6);
	l.erase(pos1);
	l.erase(pos2);
	l.erase(pos3);
	
	
	for (int x : l) {
		if (x == 9) {
			cout << x;
		}
		else {
			cout << x << ", ";
		}
	}

	std::cout << "\n";

	auto pos4 = l.begin();
	advance(pos4, 4);
	l.insert(pos4, 20);

	for (int x : l) {
		if (x == 9) {
			cout << x;
		}
		else {
			cout << x << ", ";
		}
	}
	std::cout << "\n";

	l.push_back(30);

	for (int x : l) {
		if (x == 30) {
			cout << x;
		}
		else {
			cout << x << ", ";
		}
	}
}