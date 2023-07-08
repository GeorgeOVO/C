#include <stdio.h>
#include <stdlib.h>


int main(int argc,const char* argv[])
{
	if(argc!=3)
	{
		printf("User:命令 文件1 文件2");
		return 0;
	}	
	size_t ret;
	FILE* f1=fopen(argv[1],"r");
	if(NULL==f1)
	{
		printf("%s不存在!",argv[1]);
		fclose(f1);
		return 0;
	}
	char* s1=(char*)malloc(sizeof(*f1));

	FILE* f2=fopen(argv[2],"r");
	if(f2)
	{
		char k;
		printf("是否覆盖%s?(y/n)\n",argv[2]);
		scanf("%c",&k);
		if(k!='y'&&k!='Y')
		{
			printf("已取消拷贝!");
			fclose(f1);
			fclose(f2);
			return 0;
		}

		while(ret=fread(s1,1,sizeof(*f1),f1))
		{
			fwrite(s1,1,ret,f2);
			printf("新内容:\n%s",s1);
		}
		fclose(f1);
		fclose(f2);
		return 1;
	}
	return 0;
}
