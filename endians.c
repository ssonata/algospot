#include <stdio.h>
#include <string.h>

int change(int num)
{
	unsigned int change_value = 0;
	change_value = (num & 0xff) << 24;
	change_value += (num >> 8 & 0xff) << 16;
	change_value += (num >> 16 & 0xff) << 8;
	change_value += (num >> 24 & 0xff);

	return change_value;
}
int main()
{
	unsigned int count;
	unsigned int i;
	unsigned int num;
	scanf("%u",&count);
	if(count < 1 || count > 10000)
	{
		return 0;
	}
	
	unsigned int ret_val[count];
	memset(ret_val, 0x00, sizeof(ret_val));
	for(i = 0; i < count ; i++)
	{
		scanf("%u", &num);
		ret_val[i] = change(num);
	}

	for(i = 0; i < count; i++)
	{
		printf("%u", ret_val[i]);
		printf("\n");
	}
	
	return 0;
}
