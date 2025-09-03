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


	////暇つぶし
	//x = uniform_int_distribution<>(1, 10)(rand);
	//y = uniform_int_distribution<>(1, 10)(rand);
	//questions.push_back({
	//to_string(x) + "X^2+" + to_string(y) + "Xを微分しなさい",
	//to_string(x*2)+"X+"+to_string(y)
	//	});

	//教科書データ配列
	static const struct {
		const char* name;		//教科名
		QuestionLIst(*create)();//教科名
	}subjectData[] = {
		{"数学",CreatemathematicsExam},
		{"国語",CreatemathematicsExam},
		{"物理",CreatemathematicsExam},
		{"地理",CreatemathematicsExam},
		{"政治",CreatemathematicsExam},
		{"経済",CreatemathematicsExam},
	};

	cout << "[リクルート試験対策クイズ]\n";

	cout << "０=総合テスト\n";
	cout << "教科を選んでください\n";
	for (int i = 0; i < size(subjectData); i++) {
		cout << i + 1 << '=' << subjectData[i].name << '\n';
	}

	int subject;
	cin >> subject;
	if (subject > 0 && subject <= size(subjectData)) {
		questions = subjectData[subject - 1].create();
	}
	else if (subject == 0) {
		//総合テスト
		questions.clear();
		for (int i = 0; i < size(subjectData); i++) {
			QuestionLIst tmp = subjectData[i].create();
			questions.insert(questions.end(), tmp.begin(), tmp.end());
		}
	}
	for (const auto& e : questions) {
		cout << e.q << "\n";
		string answer;
		cin >> answer;

		//入力された答えをSJISからASCIIに変換する
		const string ascii = ConvertSjisNumberToAscii(answer);
		//変換が成功した場合はASCII文字列に置き換える
		if (!ascii.empty()) {
			answer = ascii;
		}

		if (answer == e.a) {
			cout << "正解!\n";
		}
		else if(e.b.empty()){
			cout << "間違い!正解は" << e.a << "\n";
		}
		else {
			//答えが複数ある場合、いずれかと一致すれば正解とする
			bool isMatch = false;
			for (const auto& b : e.b) {
				if (answer == b) {
					isMatch = true;	//一致する答えが見つかった
					break;
				}
			}

			//比較結果を出力
			if (isMatch) {
				cout << "正解\n";
			}
			else {
				cout << "間違い! 正解は" << e.a << "(または";
				for (auto& b : e.b) {
					cout << "、" << b;
				}
				cout << ")\n";
			}
		}//if answer == e.a
	} //for questions
}