#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searching(vector<pair<int,string>>vec, string word)
{
	int ret = -1;
	vector<pair<int,string>>::iterator iter = vec.begin();
	for(; iter != vec.end(); ++iter)
	{
		if(word.compare(iter->second) == 0)
		{
			ret = iter->first;
			return ret;
		}
	}
	return ret;
}
string last_checking(string str, int count, string &result)
{
	string ret = "No";
	int pos = 0;
	for(int j = 0; j < count; j++)
	{
		if(( pos = str.find(result.at(j))) != string::npos)
		{
			str.erase(pos,1);
			ret = "Yes";
		}
		else
		{
			ret = "No";
			break;
		}
	}

	return ret;
}
string sequence_checking(int val, string& result)
{
	string str = "No";

	switch(val)
	{
		case 0:
			if(result.size() == 4)
			{
				return last_checking("zero", 4, result);
			}
			break;
		case 1:	
			if(result.size() == 3)
			{
				return last_checking("one", 3, result);
			}
			break;
		case 2:
			if(result.size() == 3)
			{
				return last_checking("two", 3, result);
			}
			break;
		case 3:
			if(result.size() == 5)
			{
				return last_checking("three", 5,result);
			}
			break;
		case 4:
			if(result.size() == 4)
			{
				return last_checking("four", 4, result);
			}
			break;
		case 5:
			if(result.size() == 4)
			{
				return last_checking("five", 4, result);
			}
			break;
		case 6:
			if(result.size() == 3)
			{
				return last_checking("six", 3, result);
			}
			break;
		case 7:
			if(result.size() == 5)
			{
				return last_checking("seven", 5, result);
			}
			break;
		case 8:
			if(result.size() == 5)
			{
				return last_checking("eight", 5, result);
			}
			break;
		case 9:
			if(result.size() == 4)
			{
				return last_checking("nine", 4, result);
			}
			break;
		case 10:
			if(result.size() == 3)
			{
				return last_checking("ten", 3, result);
			}
			break;
	}
	return str;
}
string searching(vector<pair<int,string>>vec, int total, string& result)
{
	string ret = "No";
	vector<pair<int,string>>::iterator iter = vec.begin();
	for(; iter != vec.end(); ++iter)
	{
		if(total == iter->first)
		{
			return sequence_checking(iter->first, result);
		}

	}
	return ret;
}
string calcurate(string word1, string word2, string operator1, vector<pair<int,string>>vec, string& result)
{
	string output;
	int num1, num2 = 0;
	int total = 0;
	if(operator1.compare("+") == 0)
	{
		num1 = searching(vec, word1);
		num2 = searching(vec, word2);
		total = num1 + num2;
		output = searching(vec,total, result);
	}
	else if(operator1.compare("-") == 0)
	{
		num1 = searching(vec, word1);
		num2 = searching(vec, word2);
		total = num1 - num2;
		output = searching(vec,total, result);
	}
	else // *
	{
		num1 = searching(vec, word1);
		num2 = searching(vec, word2);
		total = num1 * num2;
		output = searching(vec,total, result);
	}
	return output;
}
int checking(string str, vector<pair<int,string>>vec)
{
	int ret = 0;
	vector<pair<int, string>>::iterator iter = vec.begin();
	for(; iter != vec.end(); ++iter)
	{
		if(str.compare(iter->second) == 0)
		{
			ret = 1;
			return ret;
		}
	}
	return ret;
}
int checking(string str, vector<string> vec)
{
	int ret = 0;
	vector<string>::iterator iter = vec.begin();
	for(;iter!=vec.end();++iter)
	{
		if(str.compare(*iter) == 0)
		{
			ret = 1;
			return ret;
		}
	}
	return ret;
}
int main()
{
	vector<string> oper, output;
	vector<pair<int, string>> word;
	string word1, operator1, word2,result, ecol;
	int count;
	word.push_back(make_pair(0,"zero"));
	word.push_back(make_pair(1,"one"));
	word.push_back(make_pair(2,"two"));
	word.push_back(make_pair(3,"three"));
	word.push_back(make_pair(4,"four"));
	word.push_back(make_pair(5,"five"));
	word.push_back(make_pair(6,"six"));
	word.push_back(make_pair(7,"seven"));
	word.push_back(make_pair(8,"eight"));
	word.push_back(make_pair(9,"nine"));
	word.push_back(make_pair(10,"ten"));

	oper.push_back("+");
	oper.push_back("-");
	oper.push_back("*");

	cin>>count;
	for(int i =0; i<count;i++)
	{
		cin >> word1 >> operator1 >> word2 >> ecol >>result;
/*		
		cout<<"word1 : "<<word1<<endl;
		cout<<"operator1 : "<<operator1<<endl;
		cout<<"word2 : "<<word2<<endl;
		cout<<"ecol : "<<ecol<<endl;
		cout<<"result : "<<result<<endl;
*/
		if(checking(word1,word) == 0)
		{
//			cout<<"ERROR1"<<endl;
			break;
		}
		if(checking(operator1,oper) == 0)
		{
//			cout<<"ERROR2"<<endl;
			break;
		}
		if(checking(word2,word) == 0)
		{
//			cout<<"ERROR3"<<endl;
			break;
		}
		output.push_back(calcurate(word1,word2,operator1, word, result));
	}

	vector<string>::iterator iter = output.begin();
	for(; iter != output.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
