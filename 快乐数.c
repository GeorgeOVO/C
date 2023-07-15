#include <stdio.h>

int main(int argc,const char* argv[])
{
	int n;
	int ret=0;
	printf("请输入数字:");
	scanf("%d",&n);
	int a=n;
	for(int i=0;i<20;i++)
	{
		while(n)
		{
			ret+=(n%10)*(n%10);
			n/=10;
		}
		if(ret==1)
		{
			printf("%d是快乐数",a);
			return 0;
		}
		n=ret;
		ret=0;
	}
	printf("%d不是快乐数",a);
	return 0;
}
