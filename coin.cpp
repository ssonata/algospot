#include <iostream>
#define MAX 5001
#define LIMIT 1000000007

using namespace std;

int main(void)
{
	int testcase;

	cin >> testcase;
	while (testcase--)
	{
		int sum, num;
		cin >> sum >> num;
		int moneyWays[MAX] = { 1,0, };		//각 금액을 구할 수 있는 경우의 수
		int coin;
	
		for (int n = 0; n < num; n++)
		{
			cin >> coin;
			for (int i = coin; i <= sum; i++)
			{
				moneyWays[i] = (moneyWays[i] + moneyWays[i - coin]) % LIMIT;
			}
		//moneyWay라는 것은 누적값이다. 해당 index에는 그만큼의 경우의수가 누적된다. moneyWays[i-coin]의 의미는 moneyWays[i]가 50원일때, 10원짜리랑 겹쳐지는 경우의 수를 찾기 위한 것이다.
		}
		cout << moneyWays[sum] << endl;
	}
	return 0;
}
