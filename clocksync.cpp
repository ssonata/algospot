#include <iostream>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

int maxcounting = 0;
int maxing_idx = 0;

int usingidx[10] = {0,};
int temp[16] = {0,};
int temp1[16] = {0,};
int clockend[10] = {0,};
int maxsum = 0;
int searching_count = 0;
void init(map<int, vector<int>> & f)
{
	vector<int> clk;
	clk.push_back(0);
	clk.push_back(1);
	clk.push_back(2);
	f.insert(make_pair(0,clk));
	clk.clear();
	clk.push_back(3);
	clk.push_back(7);
	clk.push_back(9);
	clk.push_back(11);
	f.insert(make_pair(1,clk));
	clk.clear();
	clk.push_back(4);
	clk.push_back(10);
	clk.push_back(14);
	clk.push_back(15);
	f.insert(make_pair(2,clk));
	clk.clear();
	clk.push_back(0);
	clk.push_back(4);
	clk.push_back(5);
	clk.push_back(6);
	clk.push_back(7);
	f.insert(make_pair(3,clk));
	clk.clear();
	clk.push_back(6);
	clk.push_back(7);
	clk.push_back(8);
	clk.push_back(10);
	clk.push_back(12);
	f.insert(make_pair(4,clk));
	clk.clear();
	clk.push_back(0);
	clk.push_back(2);
	clk.push_back(14);
	clk.push_back(15);
	f.insert(make_pair(5,clk));
	clk.clear();
	clk.push_back(3);
	clk.push_back(14);
	clk.push_back(15);
	f.insert(make_pair(6,clk));
	clk.clear();
	clk.push_back(4);
	clk.push_back(5);
	clk.push_back(7);
	clk.push_back(14);
	clk.push_back(15);
	f.insert(make_pair(7,clk));
	clk.clear();
	clk.push_back(1);
	clk.push_back(2);
	clk.push_back(3);
	clk.push_back(4);
	clk.push_back(5);
	f.insert(make_pair(8,clk));
	clk.clear();
	clk.push_back(3);
	clk.push_back(4);
	clk.push_back(5);
	clk.push_back(9);
	clk.push_back(13);
	f.insert(make_pair(9,clk));
	clk.clear();

	return;
}
int howmany(int *k, int index, int size)
{
	int ret = 0;
	int sum = 0;
  int twelve_num = 0;
	for(int i = 0; i < 16; i ++)
	{
		sum += k[i];
    if(k[i] == 12)
    {
        twelve_num++;
    }
	}
	
  if(maxcounting < twelve_num)
  {
      if(usingidx[index] <= 3)
      {
          maxsum = sum;
          maxcounting = twelve_num;
          maxing_idx = index;
          ret = 1;
          cout<<"MAX COUNTING::"<<maxcounting<<"current num::"<<twelve_num<<endl;
      }
  }
  else if(maxcounting == twelve_num)
  {
      if(maxsum <= sum && usingidx[index] <= 3)
      {
          maxsum = sum;
          maxcounting = twelve_num;
          maxing_idx = index;
          ret = 1;
          cout<<"MAX COUNTING::"<<maxcounting<<"current num::"<<twelve_num<<endl;
      }
  }
	return ret;
}
int searching(int *kase, map<int, vector<int>>& f)
{
	vector<int> v;
	map<int, vector<int>>::iterator iter = f.begin();
	bool final = 0;
	for(; iter != f.end(); ++iter)
	{
		v = iter->second;
		memcpy(temp, kase, sizeof(temp));
		for(int i = 0; i != v.size(); i++)
		{
			temp[v[i]] += 3;
			if(temp[v[i]] > 12)
			{
				temp[v[i]] = 3;
			}
		}

		if(howmany(temp, iter->first, v.size()) == 0)
		{
		  	clockend[iter->first] = -1;
		}
	}
  for(int j = 0; j < 10; j++)
  {
      if(clockend[j] != -1)
      {
          final = 1;
          break;
      }
  }

  if(!final)
  {
      return -1;
  }

	memcpy(temp1,kase, sizeof(temp1));
	iter = f.begin();
	for(; iter != f.end(); ++iter)
	{
		if(iter->first == maxing_idx)
		{
			usingidx[maxing_idx]++;
			searching_count++;
			v = iter->second;
			for(int i = 0; i < v.size(); i++)
			{
				temp1[v[i]] += 3;
				if(temp1[v[i]] > 12)
				{
					temp1[v[i]] = 3;
				}
				//cout<<"temp1[1]"<<temp1[1]<<"temp1[2]"<<temp1[2]<<"temp1[3]"<<temp1[3]<<endl;
			}
      final = 0;
      for(int j = 0; j < 16; j++)
      {
          if(temp1[j] != 12)
          {
              final = 1;
              break;
          }
      }
			break;
		}
	}
	maxcounting = maxsum = maxing_idx = 0;
  if(!final)
  {
      return searching_count;
  } 
	return searching(temp1, f);
}
int main()
{
	map<int, vector<int>> factory;
	vector<int> output;
	int count;
	int kase[16];
	cin >> count;
	if(count > 30)
	{
		return 0;
	}


	init(factory);
	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			cin >> kase[j];
			if(kase[j] != 3 && kase[j] != 6 && kase[j] != 9 && kase[j] != 12)
			{
				return 0;
			}
		}
		int result = searching(kase, factory);
		output.push_back(result);
	}

	vector<int>::iterator iter = output.begin();
	for(; iter != output.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
