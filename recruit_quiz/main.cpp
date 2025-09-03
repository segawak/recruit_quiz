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

	//���ȏ��f�[�^�z��
	static const struct {
		const char* name;		//���Ȗ�
		QuestionLIst(*create)();//���Ȗ�
	}subjectData[] = {
		{"���w",CreatemathematicsExam},
		{"����",CreatemathematicsExam},
		{"����",CreatemathematicsExam},
		{"�n��",CreatemathematicsExam},
		{"����",CreatemathematicsExam},
		{"�o��",CreatemathematicsExam},
	};

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	cout << "�O=�����e�X�g\n";
	cout << "���Ȃ�I��ł�������\n";
	for (int i = 0; i < size(subjectData); i++) {
		cout << i + 1 << '=' << subjectData[i].name << '\n';
	}

	vector<int>questionCounts(size(subjectData));	//�e���Ȃ̐�����
	int subject;
	cin >> subject;
	if (subject > 0 && subject <= size(subjectData)) {
		questions = subjectData[subject - 1].create();
	}
	else if (subject == 0) {
		//�����e�X�g
		questions.clear();
		for (int i = 0; i < size(subjectData); i++) {
			QuestionLIst tmp = subjectData[i].create();
			questions.insert(questions.end(), tmp.begin(), tmp.end());
			questionCounts[i] = (int)tmp.size();
		}
	}
	vector<int>correctCounts(size(subjectData));	//�e���Ȃ̐�����
	int currentSubjectNo = 0;
	int currentAnsweredCount = 0;

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
			correctCounts[currentSubjectNo]++;
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
				correctCounts[currentSubjectNo]++;
			}
			else {
				cout << "�ԈႢ! ������" << e.a << "(�܂���";
				for (auto& b : e.b) {
					cout << "�A" << b;
				}
				cout << ")\n";
			}
		}//if answer == e.a

		//�u�񓚍ςݖ�萔�v���u���Ȃ̖�萔�v�ȏ�ɂȂ�����A���̋����ɐi��
		if (subject == 0) {
			currentAnsweredCount++;
			if (currentAnsweredCount > questionCounts[currentSubjectNo]) {
				currentSubjectNo++;//���̋��Ȃɐi��
				currentAnsweredCount = 0;//�񓚍ςݖ�萔�����Z�b�g
			}
		}//if subject ==0
	} //for questions

	//���т�\��
	cout << "\n--- ���� ---\n";
	if (subject > 0 && subject <= size(subjectData)) {
		cout << subjectData[subject - 1].name << '\n'
			<< correctCounts[0] << '/' << questions.size() << '\n';
	}
	else if (subject == 0) {
		//���Ȃ��Ƃ̐��т�\�����A�������̍��v���v�Z
		size_t totalCorrectCount = 0;	//�������̍��v
		for (int i = 0; i < size(subjectData); i++) {
			cout << subjectData[i].name << ":"
				<< correctCounts[i] << '/' << questionCounts[i] << '\n';
			totalCorrectCount += correctCounts[i];
		}
		cout << "���v:" << totalCorrectCount << '/' << questions.size() << '\n';
	}
}