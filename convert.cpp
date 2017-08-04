#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count;
	float weight;
	string metric;
	vector<pair<float, string>>input;

	cin >> count;
	if(count < 1 || count > 1000) 
	{
		return 0;
	}

	for(int i = 0; i < count; i++)
	{
		cin >> weight>> metric;
		
		if(!metric.compare("kg"))
		{
			metric = "lb";
			weight = 2.2046*weight;
		}
		else if(!metric.compare("lb"))
		{
			metric = "kg";
			weight = 0.4536*weight;
		}
		else if(!metric.compare("l"))
		{
			metric = "g";
			weight = 0.2642*weight;
		}
		else if(!metric.compare("g"))
		{
			metric = "l";
			weight = 3.7854*weight;
		}
		else
		{
			return 0;
		}
		input.push_back(make_pair(weight, metric));
	}

	vector<pair<float, string>>::iterator iter = input.begin();

	for(int i = 1; iter != input.end(); ++iter, i++)
	{
		cout.precision(0);
		cout<<i;
		cout<<fixed;
		cout.precision(4);
		cout<<" "<<iter->first<<" "<<iter->second<<endl;
	}


	return 0;
}
