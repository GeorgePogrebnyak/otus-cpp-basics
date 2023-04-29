#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch;}

int main()
{
	const int max_value = 100;                                           // Max �������� ������������ �����
	srand(time(nullptr));                                                // ������������ ������� ����� � �������� ���������� �������� ��� ���������� ��������� �����
	const int random_value = std::rand() % max_value;                    // ��������� ���������� �����
	int current_value = 0;                                               // �����, ��������� �������������
	bool you_win = false;                                                // ��������� ����������
	int attempts_count = 0;                                              // ���-�� �������
	string user_name;                                                    // ��� ������������
	const string high_scores_filename = "high_scores.txt";               // ���� ������ ��������

	cout << "Hi! Enter your name, please:\n";
	cin >> user_name;
	cout << "Enter your number from 0 to 100:\n";
	//cout << random_value;
	do {                                                                 // ���� ���������� �����
		cin >> current_value;
		
		if (current_value < 0 || current_value > 100) {
			cout << "Number must from 0 to 100\n";
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
	
	ofstream out_file{ high_scores_filename, ios_base::app };             // ������ �� �������������� ����� ��������
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	                                                                      // ������ �������� � ���� ��������
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;

	ifstream in_file{ high_scores_filename};                              // ���������� ����� ��������
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}

	cout << "\nHigh scores table:\n";

	while (true) {                                                        // ����� ����������� ����� � �������
		in_file >> user_name;
		in_file >> attempts_count;
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		std::cout << user_name << '\t' << attempts_count << std::endl;
	}

	while (cin.get() != 'Q')
	{
		continue;
	}

	return 0;
}