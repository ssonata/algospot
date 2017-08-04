#include <stdio.h>

int main()
{
	int N = 0;
	int count;
	scanf("%d", &N);
	if( N > 10 || N <= 0)
	{
		return 0;
	}
	for(count = 0; count < N; count++)
	{
		printf("Hello Algospot!");
		printf("\n");
	}
	return 0;
}
