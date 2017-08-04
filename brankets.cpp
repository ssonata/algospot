#include <iostream>
#include <vector>

using namespace std;

void check_brankets(string& brankets)
{
	for(int j = 0; j < brankets.size(); j++)
	{
		string tmp = brankets.at(j);
		if(!tmp.compare("["))
	}
}
int main()
{
	int count;
	string brankets;
	cin >> count;
	for(int i = 0;  i < count ; i++)
	{
		cin >> brankets;
		check_brankets(brankets);
	}
	return 0;
}
