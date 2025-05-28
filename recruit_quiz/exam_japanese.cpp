#include "exam_japanese.h"
using namespace std;

QuestionLIst CreateKanjiExam()
{
	static const struct {
		const char* kanji;		//漢字
		const char* reading;	//読み
		const char* meaming;	//意味
	} data[] = {
		{"市井","しせい","人が多く集まって暮らすところ、町"},
		{"捺印","なついん", "(著名と共に)印鑑を押すこと"},
		{"相殺","そうさい","足し匹の結果、差が無くなること"},
		{"凡例","はんれい","本や図表のはじめに、使い方や約束事を箇条書きにしたもの"},
		{"約定","やくじょう","約束して決めること、契約"},
	};

	constexpr int quizConst = 5;
	QuestionLIst questions;
	questions.reserve(quizConst);
	for (int i = 0; i < quizConst; i++) {
		const auto& e = data[i];
		questions.push_back({
			"「" + string(e.kanji) + "」の読みをひらがなで答えよ",
			e.reading });
	}
	return questions;
}