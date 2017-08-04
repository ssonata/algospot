#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

const int INF=9999, switchNum=10, clockNum = 16;
int retval = 0;
const int link[10][16] = {
//    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
 { 1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
 { 0,  0,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  0,  0,  0 },
 { 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  1 },
 { 1,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0 },
 { 0,  0,  0,  0,  0,  0,  1,  1,  1,  0,  1,  0,  1,  0,  0,  0 },
 { 1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1 },
 { 0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1 },
 { 0,  0,  0,  0,  1,  1,  0,  1,  0,  0,  0,  0,  0,  0,  1,  1 },
 { 0,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
 { 0,  0,  0,  1,  1,  1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0 }

};
//순서
//1.now값을 9까지 증가시킨다.
//2.9번 스위치부터 4번씩 돈다.
//3.4번 다 돌고나면 now값 8번째부터 다시 9번가는 루틴으로 4번 돈다.
//4. (9,9,9,9) -> (8->9,9,9,9, 8->9,9,9,9, 8->9,9,9,9 8->9,9,9,9) ->
//(7->8->9->,9,9,9, 8->9->,9,9,9 , 8->9,9,9,9 8->9,9,9,9 , 7-8->9->9,9,9 ,
//8->9->9,9,9, 8->9,9,9,9 8->9,9,9,9 8->9,9,9,9 7->8->9->9,9,9 ....) 무한반복
void push(vector<int>& clock, int now)
{
  printf("NOW[%d]\n",now);
  for (int i = 0; i < clockNum; i++)
  {
	  if (link[now][i] == 1 && clock[i] != 12)
	  {
		  clock[i] += 3;
	  }
	  else if (link[now][i] == 1 && clock[i] == 12)
	  {
		  clock[i] = 3;
	  }
  }
}

bool check(vector<int>& clock)
{
  bool result = true;
  for (int i = 0; i < clockNum; i++)
  {
     if (clock[i] != 12)
     {
       result = false;
     }
  }
  return result;
}

int solve(vector<int>& clock, int now)
{
  if (now == switchNum)
  {
	 retval++;
	 int pass = check(clock) ? 0 : INF;
	 printf("PASS[%d]\n",pass);
	 return pass;
  }

  int ret = INF;
  for (int i = 0; i < 4; i++)
  {
	 printf("first solve go now [%d] \n", now);
     ret = min(ret, i + solve(clock, now + 1));
	 printf("now:%d, i:%d, ret:%d\n",now , i , ret);
     push(clock, now);
	 if(retval == 100) break;
  }
  return ret;
}

int main()
{
  int loop;
  cin >> loop;

  vector<int> v;
  for (int c = 0; c < loop; c++)
  {
      vector<int> clock(16, 0);
      for (int i = 0; i < 16; i++)
      {
        cin >> clock[i];
      }
      int result = solve(clock, 0);

      if (result == INF)
      {
         v.push_back(-1);
      }
      else
      {
         v.push_back(result);
      }
  }
  vector<int>::iterator iter = v.begin();
  for(; iter != v.end(); ++iter)
  {
    cout<<*iter<<endl;
  }
}
