#include"exam_science.h"
#include"utility.h"
#include<random>
using namespace std;

/*
	•¨—‚Ì–â‘è‚ğì¬‚·‚é
*/
QuestionLIst CreatePhysicsExam()
{
	QuestionLIst questions;
	questions.reserve(10);
	random_device rd;

	{//“™‘¬’¼ü‰^“®
		constexpr int divisors[] = { 1,2,3,4,5,6,10,12,15,20,30,60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(0, 10)(rd)* 60 / divisors[i];
		int t = uniform_int_distribution<>(0, 10)(rd)* divisors[i];
		questions.push_back({
			"‘¬" + to_string(v) + "km‚ÅˆÚ“®‚·‚éÔ‚ª‚ ‚éB\n‚±‚ÌÔ‚ª" + to_string(v * t / 60) + "kmˆÚ“®‚·‚é‚Ì‚É‰á‡ƒ‚éŠÔ‚ğ•ª’PˆÊ‚Å‹‚ß‚æ" + to_string(t)
			});
	}//“™‘¬’¼ü‰^“®

	return questions;
}
