#include <stdio.h>

int main(int argc,const char* argv[])
{
	int N=0;
	printf("请输入N的值:");
	scanf("%d",&N);
	int arr1[N],arr2[N];
	printf("请输入待查询数组的数据:");
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr1[i]);
		arr2[i]=0;
	}

	for(int i=0;i<N;i++)
	{
		if(1<=arr1[i]&&N>=arr1[i])
		{
			arr2[arr1[i]-1]=1;
		}
	}

	for(int i=0;i<N;i++)
	{
		if(0==arr2[i])
		{
			printf("%d\n",i+1);
			return;
		}
	}
	printf("%d\n",N+1);
	return 0;
}
