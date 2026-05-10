#include "clsUtil.h"

int main()
{
	clsUtil::Srand();
	vector<string> res = clsUtil::GenerateKeys(4, clsUtil::enCharType::Mix);
	for (short i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	cout << endl;

	string array[9];
	clsUtil::FillArrayWithRandomKeys(array, 9, clsUtil::enCharType::SmallLetters);
	for (short i = 0; i < 9; i++)
	{
		cout << array[i] << endl;
	}
	cout << endl;

	string array1[9];
	clsUtil::FillArrayWithRandomWords(array1, 9, clsUtil::enCharType::CapitalLetters, 40);
	for (short i = 0; i < 9; i++)
	{
		cout << array1[i] << endl;
	}


}