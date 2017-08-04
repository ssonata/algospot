#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
static char _x2c(char hex_up, char hex_low) 
{
   char digit;

	digit = 16 * (hex_up >= 'A' ? ((hex_up & 0xdf) - 'A') + 10 : (hex_up - '0'));
	digit += (hex_low >= 'A' ? ((hex_low & 0xdf) - 'A') + 10 : (hex_low - '0'));
	return (digit);
}

char *qURLdecode(char* str) 
{
	int i, j;
	for(i = j = 0; str[j]; i++, j++) 
	{
		switch(str[j]) 
		{
			case '+':
				str[i] = ' ';
				break;
			case '%':
				str[i] = _x2c(str[j + 1], str[j + 2]);
				j += 2;
				break;
			default:
				str[i] = str[j];
				break;
		}
	}
	str[i]='\0';
	return str;
}
void replacestring(string& str, string oldstring, string newstring)
{
	int pos = 0;
	while((pos = str.find(oldstring, pos)) != string::npos)
	{
		str.replace(pos, oldstring.length(), newstring);
		pos += newstring.length();
	}
}
int main()
{
	vector<string> output;
/*
	vector<pair<string, string>> factory;
	vector<string> output;
	factory.push_back(make_pair(" ", "%20"));
	factory.push_back(make_pair("!", "%21"));
	factory.push_back(make_pair("\"", "%22"));
	factory.push_back(make_pair("#", "%23"));
	factory.push_back(make_pair("$", "%24"));
	factory.push_back(make_pair("%", "%25"));
	factory.push_back(make_pair("&", "%26"));
	factory.push_back(make_pair("'", "%27"));
	factory.push_back(make_pair("(", "%28"));
	factory.push_back(make_pair(")", "%29"));
	factory.push_back(make_pair("*", "%2a"));
	factory.push_back(make_pair("+", "%2b"));
	factory.push_back(make_pair(",", "%2c"));
	factory.push_back(make_pair("-", "%2d"));
	factory.push_back(make_pair(".", "%2e"));
	factory.push_back(make_pair("/", "%2f"));
	factory.push_back(make_pair(":", "%3a"));
	factory.push_back(make_pair(";", "%3b"));
	factory.push_back(make_pair("<", "%3c"));
	factory.push_back(make_pair("=", "%3d"));
	factory.push_back(make_pair(">", "%3e"));
	factory.push_back(make_pair("?", "%3f"));
	factory.push_back(make_pair("@", "%40"));
	factory.push_back(make_pair("[", "%5b"));
	factory.push_back(make_pair("\"", "%5c"));
	factory.push_back(make_pair("]", "%5d"));
	factory.push_back(make_pair("^", "%5e"));
	factory.push_back(make_pair("_", "%5f"));
	factory.push_back(make_pair("`", "%60"));
	factory.push_back(make_pair("{", "%7b"));
	factory.push_back(make_pair("|", "%7c"));
	factory.push_back(make_pair("}", "%7d"));
	factory.push_back(make_pair("~", "%7e"));
*/
	int count;
	string str;
	cin >> count;

	if(count< 1 || count > 100) 
	{
		return 0;
	}
	for(int i = 0; i < count; i++)
	{
		cin >> str;
		if(str.size() > 80)
		{
			return 0;
		}

		output.push_back(qURLdecode((char *)str.c_str()));
/*		
		vector<pair<string,string>>::iterator iter = factory.begin();

		for(; iter != factory.end(); ++iter)
		{
			replacestring(str, iter->second, iter->first);
		}
		output.push_back(str);
	}
*/
	}
	vector<string>::iterator iter2 = output.begin();
	for(;iter2 != output.end(); ++iter2)
	{
		cout<<*iter2<<endl;
	}
	return 0;
}
