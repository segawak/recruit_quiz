#include "exam_japanese.h"
using namespace std;

QuestionLIst CreateKanjiExam()
{
	static const struct {
		const char* kanji;		//����
		const char* reading;	//�ǂ�
		const char* meaming;	//�Ӗ�
	} data[] = {
		{"�s��","������","�l�������W�܂��ĕ�炷�Ƃ���A��"},
		{"���","�Ȃ���", "(�����Ƌ���)��ӂ���������"},
		{"���E","��������","�����C�̌��ʁA���������Ȃ邱��"},
		{"�}��","�͂�ꂢ","�{��}�\�̂͂��߂ɁA�g������񑩎����ӏ������ɂ�������"},
		{"���","�₭���傤","�񑩂��Č��߂邱�ƁA�_��"},
	};

	constexpr int quizConst = 5;
	QuestionLIst questions;
	questions.reserve(quizConst);
	for (int i = 0; i < quizConst; i++) {
		const auto& e = data[i];
		questions.push_back({
			"�u" + string(e.kanji) + "�v�̓ǂ݂��Ђ炪�Ȃœ�����",
			e.reading });
	}
	return questions;
}