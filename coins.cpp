#include <iostream>
#include <vector>

using namespace std;

int totalmoney;
int money[100];
int number_of_coins;
int result[100];
int result_sum;
void start_it(int *money)
{
	for(int i = 0; i < number_of_coins; i++)
	{
		money[i]
		if(totalmoney % money[i] == 0)
		{
        result_sum++;
		}
	}
}

int main()
{
	int testcase;
	vector<int> output;

	cin >> testcase;

	if( testcase < 1 || testcase > 100)
	{
		return 0;
	}
	for(int i = 0; i < testcase ; i++)
	{
		cin >> totalmoney >> number_of_coins;
		if(totalmoney < 1 || totalmoney > 5000 || number_of_coins < 1 || number_of_coins > 100)
		{
			return 0;
		}
		for(int j = 0; j < number_of_coins; j++)
		{
			cin >> money[j];
			if(money[j] > 5000)
			{
				return 0;
			}
		}
    start_it(money)
		output.push_back(result_sum);
	}

	vector<int>::iterator iter = output.begin();
	for(; iter != output.end(); ++iter)
	{
		cout<< *iter << endl;
	}
	return 0;
}
