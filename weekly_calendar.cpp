#include <iostream>
#include <vector>
using namespace std;

int check_totalday(int mon)
{

	int output;
	switch(mon)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			output = 31;
			break;
		case 2 :
			output = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			output = 30;
			break;
		default:
			output = 31;
			break;
	}
	return output;
}
void calculate(vector<pair<int, int>>& vec, int case1, int day, int total, int i, int mon)
{
	int flag = 0;
	day -= case1;
	for(int j = 0; j < 7; j++)
	{
		//cout<<"Day:"<<day<<"total:"<<total<<endl;
		if(day < 1)
		{
			total = check_totalday(mon-1);
			day = total + day;
		}
		if(day+j == total)
		{
			flag = 1;
			vec.push_back(make_pair(i, total));
			continue;
		}
		if(flag)
		{
			vec.push_back(make_pair(i, day+j-total));
		}
		else
		{
			vec.push_back(make_pair(i, day+j));
		}
	}

}
int main()
{
	int count;
	int mon, day;
	int total;
	int num[7];
	int case1 = 0;
	string weekly;
	vector<pair<int, int>> vec;
	cin >> count;

	for(int i = 0; i <  count; i++)
	{
		cin >> mon >> day >> weekly;
		if(mon < 1 || mon > 12 || day < 1 || day > 31)
		{
			return 0;
		}
		total = check_totalday(mon);

		if(weekly.compare("Saturday") == 0)
		{
			case1 = 6;
		}	
		else if(weekly.compare("Sunday") == 0)
		{
			case1 = 0;
		}
		else if(weekly.compare("Monday") == 0)
		{
			case1 = 1;
		}
		else if(weekly.compare("Tuesday") == 0)
		{
			case1 = 2;
		}
		else if(weekly.compare("Wednesday") == 0)
		{
			case1 = 3;
		}
		else if(weekly.compare("Thursday") == 0)
		{
			case1 = 4;
		}
		else if(weekly.compare("Friday") == 0)
		{
			case1 = 5;
		}
		else
		{
			return 0;
		}
		calculate(vec, case1, day, total, i, mon);
	}
	int first = 0;
	vector<pair<int, int>>::iterator iter = vec.begin();
	for(; iter != vec.end(); ++iter)
	{
		if(first == iter->first)
		{
			cout<<iter->second<<" ";
		}
		else
		{
			cout<<endl;
			cout<<iter->second<<" ";
			first++;
		}
	}
	cout<<endl;
	return 0;
}
