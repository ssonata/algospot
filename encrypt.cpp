#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encrypt(string str)
{
	string total;
	for(int i = 0; i < str.size();i = i+2)
	{
		total += str.at(i);
	}
	for(int j = 1, r = 1; r < str.size();r = (j*2)-1)
	{
		total += str.at(r);
		j++;
	}
	return total;
}
int main()
{
	vector<string>ret;
	int count;
	cin >> count;

	if(count < 1 || count > 10)
	{
		return 0;
	}

	string str;
	for(int i = 0; i < count; i++)
	{
		cin >> str;
		if(str.size() > 100)
		{
			return 0;
		}
		ret.push_back(encrypt(str));
	}

	vector<string>::iterator iter = ret.begin();
	for(;iter != ret.end(); ++iter)
	{
		cout<<*iter<<endl;
	}

	return 0;
}
