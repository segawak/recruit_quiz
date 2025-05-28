#include "utility.h"
#include<random>
using namespace std;

/*
	ƒ‰ƒ“ƒ_ƒ€‚È”Ô†”z—ñ‚ğì¬‚·‚é
*/
vector<int> CreateRandomIndices(int n)
{
	vector<int>indices(n);
	for (int i = 0; i < n; i++) {
		indices[i] = i;
	}
	//”Ô†‚ğ”z—ñ‚ÉŠi”[
	random_device rd;
	mt19937 rand(rd());
	for (int i = n; i > 0; i--) {
		const int j = uniform_int_distribution<>(0, 1)(rand);
		const int tmp = indices[i];
		indices[i] = indices[j];
		indices[j] = tmp;
	}

	return indices;
}