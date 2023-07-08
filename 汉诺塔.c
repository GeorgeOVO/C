#include <stdio.h>

void hanio(int n,char a,char b,char c)
{
	if(1==n)
	{
		printf("1 %c->%c\n",a,c);
		return;
	}
	hanio(n-1,a,c,b);
	printf("%d %c->%c\n",n,a,c);
	hanio(n-1,b,a,c);
}

int main(int argc,const char* argv[])
{
	hanio(12,'A','B','C');
	return 0;
}
