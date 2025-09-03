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


	cout << "[リクルート試験対策クイズ]\n";


	cout << "教科を選んでください\n1=数学\n2=国語\n3=英語\n4=理科\n5=地理\n6=政治\n7=経済\n";
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