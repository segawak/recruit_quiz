#include<iostream>
#include<string>
#include<random>
using namespace std;

// ��蕶�Ɠ������܂Ƃ߂�\����
struct Question
{
	string q;	// ��蕶
	int a;		// ����
};

int main() 
{
	Question questions[] = {
		{"13*(-5)",13 * -5},
		{"(-21)��(-3)",-21 / -3},
		{"7-(4+2)��2",7 - (4 + 2) / 2},
	};

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	for (const auto& e : questions) {
		cout << e.q << "�̓�����?\n";
		int answer;
		cin >> answer;
		if (answer == e.a) {
			cout << "����!\n";
		}
		else {
			cout << "�ԈႢ!������" << e.a << "\n";
		}
	} //for questions
}