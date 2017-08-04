#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int count;
	int goal, sum;
	int hour[9];
	vector<string>str;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		sum = 0;
		cin >> goal;
		cin >> hour[0] >> hour[1] >> hour[2] >> hour[3] >> hour[4] >> hour[5] >> hour[6] >> hour[7] >> hour[8];
		for(int j = 0; j < 9; j++)
		{
			if(hour[j] < 0 || hour[j] > 1000)
			{
				return 0;
			}
			sum += hour[j];
		}
		str.push_back(goal >= sum? "YES":"NO");
	}

	vector<string>::iterator iter = str.begin();
	for(;iter!= str.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
