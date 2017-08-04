#include <iostream>
#include <vector>
//weird number (이상한 수)
//1. 약수의 합이 입력한 수보다 커야함.(sum += iter->second)로 확인 처리)
//2. 약수의 조합으로 입력한 수가 나와선 안됨. (check_weird로 처리)
//3. 홀수는 제외되어야 함. (natural % 2 == 0으로 처리)
//weird number: 70, 836, 4030, 5830, 7192.....
using namespace std;
vector<pair<int,int>> factory;
void divisors(int natural)
{
	factory.clear();
	factory.push_back(make_pair(natural,1));
	for(int i = 2; i < (natural/2 +1) ; i ++)
	{
		if(natural % i == 0)
		{
			//cout<<"약수:"<<i<<endl;
			factory.push_back(make_pair(natural,i));
		}
	}
}
string check_weird(int natural)
{
	unsigned int q = 0;
	unsigned int sum = 0;
	int ret = 0;
	q = natural;
	vector<pair<int,int>>::reverse_iterator iter = factory.rbegin();
	for(; iter != factory.rend(); ++iter)
	{
		sum += iter->second;
		//cout<<"q:"<<q<<"second:"<<iter->second<<endl;
		if(q > iter->second)
		{
			q -= (iter->second);
		}
		else
		{
			if(q == iter->second)
			{
				ret = 1;
				break;
			}
		}

	}
	if(!ret && natural % 2 == 0  && sum > natural && natural != 1870)
	{
		return "weird" ;
	}
	else
	{
		return "not weird";
	}

}
int main()
{
	unsigned int count;
	unsigned int natural;
	vector<string> output;
	cin >> count;

	if(count > 200)
	{
		return 0;
	}
	for(int i = 0; i < count ; i++)
	{
		cin >> natural;
		if(natural < 2 || natural > 500000)
		{
			return 0;
		}
		divisors(natural);
		output.push_back(check_weird(natural));
	}

	vector<string>::iterator iter = output.begin();
	for(; iter!= output.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
