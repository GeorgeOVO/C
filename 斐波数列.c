#include <stdio.h>

int feibo(int n) //n是第几个数
{
	if(1==n||2==n) return 1;
	return feibo(n-1)+feibo(n-2);
}

int main(int argc,const char* argv[])
{
	for(int i=1;i<10;i++)
	{
		printf("%d ", feibo(i));
	}
	return 0;
}
