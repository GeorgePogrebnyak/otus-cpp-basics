#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }

bool table_scores(string user_name, int attempts_count) {
	const string high_scores_filename = "high_scores.txt";
	ofstream out_file{ high_scores_filename, ios_base::app };                                 // Взятие на редактирование файла рекордов
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	// Запись значений в файл рекордов
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;

	ifstream in_file{ high_scores_filename };                                                 // Сохранение файла рекордов
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	cout << "\nHigh scores table:\n";

	while (true) {                                                                            // Вывод содержимого файла в консоль
		in_file >> user_name;
		in_file >> attempts_count;
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		std::cout << user_name << '\t' << attempts_count << std::endl;
	}
	return 0;
}


bool check_number(int max_value) {
	int attempts_count = 0;
	int current_value = 0;
	string user_name;
	srand(time(nullptr));                                                                     // Использовать текущее время в качестве начального значения для генератора случайных чисел
	const int random_value = rand() % max_value;
	cout << "Hi! Enter your name, please:\n";
	cin >> user_name;
	cout << "Enter your number from 0 to " << max_value << endl;

	do {                                                                                      // Цикл угадывания числа
		cin >> current_value;

		if (current_value < 0 || current_value > max_value) {
			cout << "Number must from 0 to " << max_value << endl;
		}
		else if (current_value > random_value) {
			cout << "less than " << current_value << endl;
			attempts_count += 1;
		}
		else if (current_value < random_value) {
			cout << "greater than " << current_value << endl;
			attempts_count += 1;
		}
		else {
			attempts_count += 1;
			std::cout << "You win! attempts = " << attempts_count << std::endl;
			break;
		}

	} while (true);
	table_scores(user_name, attempts_count);
	return 0;
}

int main(int argc, char* argv[]) {
	int max_value;
	int attempts_count = 0;
	string user_name;

	if (argc == 1) {
		max_value = 100;
		check_number(max_value);
		while (cin.get() != 'Q')
		{
			continue;
		}
	}
	if (argc >= 2) {
		string arg1_value{ argv[1] };
		if (arg1_value == "-table") {
			table_scores(user_name, attempts_count);
		}
		else if (arg1_value == "-max") {
			max_value = atoi(argv[2]);
			if (max_value > 100 || max_value < 0) {
				cout << "Max value must from 0 to 100\n";
				return -1;
			}
			check_number(max_value);
		}
		else if (arg1_value == "-level") {
			int level = atoi(argv[2]);
			switch (level) {
			case 1: max_value = 10;
				break;
			case 2: max_value = 50;
				break;
			case 3: max_value = 100;
				break;
			default: 3;
			}
			check_number(max_value);
		}
		else {
			max_value = 100;
			check_number(max_value);
		}
		while (cin.get() != 'Q')
		{
			continue;
		}
	}
	return 0;
}