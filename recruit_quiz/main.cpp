#include "question.h"
#include "exam_mathmatics.h"
#include "exam_japanese.h"
#include "exam_english.h"
#include "exam_science.h"
#include"exam_geography.h"
#include"exam_politics.h"
#include "exam_economics.h"
#include"utility.h"
#include<iostream>
#include<string>
#include<vector>
#include<random>
using namespace std;



int main() 
{
	vector<Question> questions(3);


	////�ɂԂ�
	//x = uniform_int_distribution<>(1, 10)(rand);
	//y = uniform_int_distribution<>(1, 10)(rand);
	//questions.push_back({
	//to_string(x) + "X^2+" + to_string(y) + "X��������Ȃ���",
	//to_string(x*2)+"X+"+to_string(y)
	//	});


	cout << "[���N���[�g�����΍�N�C�Y]\n";


	cout << "���Ȃ�I��ł�������\n1=���w\n2=����\n3=�p��\n4=����\n5=�n��\n6=����\n7=�o��\n";
	int subject;
	cin >> subject;

	if (subject == 1) {
		questions = CreatemathematicsExam();
	}
	else if (subject == 2) {
		questions = CreateJapaneseExam();
	}
	else if (subject == 3) {
		questions = CreateEnglishExam();
	}
	else if (subject == 4) {
		questions = CreatePhysicsExam();
	}
	else if (subject == 5){
		questions = CreatePrefecturesExam();
	}
	else if (subject == 6) {
		questions = CreatePoliticsExam();
	}
	else if (subject == 7) {
		questions = CreateEconomicsExam();
	}

	for (const auto& e : questions) {
		cout << e.q << "\n";
		string answer;
		cin >> answer;

		//���͂��ꂽ������SJIS����ASCII�ɕϊ�����
		const string ascii = ConvertSjisNumberToAscii(answer);
		//�ϊ������������ꍇ��ASCII������ɒu��������
		if (!ascii.empty()) {
			answer = ascii;
		}

		if (answer == e.a) {
			cout << "����!\n";
		}
		else if(e.b.empty()){
			cout << "�ԈႢ!������" << e.a << "\n";
		}
		else {
			//��������������ꍇ�A�����ꂩ�ƈ�v����ΐ����Ƃ���
			bool isMatch = false;
			for (const auto& b : e.b) {
				if (answer == b) {
					isMatch = true;	//��v���铚������������
					break;
				}
			}

			//��r���ʂ��o��
			if (isMatch) {
				cout << "����\n";
			}
			else {
				cout << "�ԈႢ! ������" << e.a << "(�܂���";
				for (auto& b : e.b) {
					cout << "�A" << b;
				}
				cout << ")\n";
			}
		}//if answer == e.a
	} //for questions
}