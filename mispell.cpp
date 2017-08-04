#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, string>> input;
	unsigned int count;
	unsigned int deletenum;
	string word;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		cin>>deletenum>>word;
		if(deletenum > word.size() || word.size() > 80)
		{
			return 0;
		}
		word.erase(deletenum-1, 1);

		input.push_back(make_pair(deletenum, word));
	}

	vector<pair<int, string>>::iterator iter = input.begin();

	for(int i = 0; iter != input.end(); ++iter,i++)
	{
		cout<<i+1<<" "<<iter->second<<endl;
	}

	return 0;
}
