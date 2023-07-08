#include <stdio.h>

union Data
{
	int num;
	char ch;	
};

int main(int argc,const char* argv[])
{
	union Data d;
	d.num=0x01020304;
	if(0x04==d.ch) printf("小端系统");
	else printf("大端系统");
	return 0;
}
