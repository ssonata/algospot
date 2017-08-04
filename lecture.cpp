#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string sorting(string str)
{
	vector<string> two;
	string total;
	int first = 0;
	while(1)
	{
		two.push_back(str.substr(first,2));	
		first += 2;
		if(str.size() <= first)
		{
			break;
		}
	}

	sort(two.begin(), two.end());

	vector<string>::iterator iter = two.begin();
	for(int i = 0;iter != two.end(); ++iter, i++)
	{
		total.append(two[i]);
	}
	return total;

}
int main()
{
	int count,i;
	cin >> count;
	string str;
	vector<string>ret;
	for(i = 0; i < count; i++)
	{
		cin >> str;
		if(str.size() > 1000)
		{
			return 0;
		}
		ret.push_back(sorting(str));
	}
	vector<string>::iterator iter = ret.begin();
	for(; iter != ret.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
