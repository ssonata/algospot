#include <iostream>
#include <vector>
using namespace std;
int syndrome_msg(string incorrect)
{
#define SONG(n)  (incorrect.at(n) - 48)
	unsigned int syndrome;
	syndrome =  ((SONG(0) + SONG(2) + SONG(4) + SONG(6)) % 2) ? 1 : 0;
	syndrome += ((SONG(1) + SONG(2) + SONG(5) + SONG(6)) % 2) ? 2 : 0;
	syndrome += ((SONG(3) + SONG(4) + SONG(5) + SONG(6)) % 2) ? 4 : 0;
	return syndrome;
}
int main()
{
	int count;
	unsigned int syn;
	cin >> count;
	string incorrect_bit;
	string output;
	vector<string> vec;
	for(int i = 0; i < count; i++)
	{
		output.clear();
		cin>>incorrect_bit;
		if(incorrect_bit.size() > 7)
		{
			return 0;
		}
		syn = syndrome_msg(incorrect_bit);
		if(syn != 0)
		{
			incorrect_bit.at(syn-1) = (incorrect_bit.at(syn-1) == 49)? 48 : 49;
		}
		output = incorrect_bit.at(2);
		output += incorrect_bit.at(4);
		output += incorrect_bit.at(5);
		output += incorrect_bit.at(6);
		vec.push_back(output);
	}


	vector<string>::iterator iter = vec.begin();
	for(; iter != vec.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}

