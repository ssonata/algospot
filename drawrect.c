#include <stdio.h>

int main()
{
	int x1,y1,x2,y2,x3,y3;
	int T,i;
	scanf("%d",&T);

	int x4[T], y4[T];
	for(i = 0; i < T; i++)
	{
		scanf("%d %d",&x1, &y1);
		scanf("%d %d",&x2, &y2);
		scanf("%d %d",&x3, &y3);
		if(x1 == x2)
		{
			 y4[i] = y1 == y3?  y2 : y2==y3? y1:y1;
			 x4[i] = x3;
		}
		else if(x1 == x3)
		{
			y4[i] = y2 == y3?  y1 : y1 ==y2? y3:y3;
			x4[i] = x2;
		}
		else // x2 == x3
		{
			y4[i] = y1 == y3?  y2 : y1==y2? y3:y3;
			x4[i] = x1;
		}
	}

	for(i = 0; i < T; i++)
	{
		printf("%d %d", x4[i],y4[i]);
		printf("\n");
	}
	return 0;
}
