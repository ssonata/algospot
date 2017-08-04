#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static int total_count = 0;
int matrix[100];
int N;

bool isPromising(int cur)
{
	for(int j = 0; j < cur; j++)
	{
		if(matrix[j] == matrix[cur]) return false; //행, 열의 값이 같은지 확인
		if((abs(matrix[j] - matrix[cur])) == (abs(cur - j))) return false;		//대각선에 퀸이 있는지 확인
	}
	return true;
}
void enumerate(int cur)
{
	if(cur == N)
	{
		total_count++;
		return;
	}
	for(int i = 0; i < N; i++)
	{
		matrix[cur] = i;
		if(isPromising(cur)) // 퀸이 들어가도 되는건지 확인 안되면 빠지기
		{
			enumerate(cur+1);
		}
	}
}

int main()
{
	int count;
	vector<int> factory;
	cin >> count;
	
	for(int i = 0; i < count; i++)
	{
		cin >> N;
		enumerate(0);
		factory.push_back(total_count);
		total_count = 0;
	}

	vector<int>::iterator iter = factory.begin();
	for(; iter != factory.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
