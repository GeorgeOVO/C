#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TYPE int

//设计顺序表结构
typedef struct Array
{
	TYPE* ptr;	//存储元素的内存首地址
	size_t cal;  //表的容量
	size_t cnt;  //元素的数量
}Array;

//创建表结构
Array* create_array(size_t cal)
{
	//申请顺序表结构的内存
	Array* arr = malloc(sizeof(Array));
	//申请存储元素的连续内存
	arr->ptr = malloc(sizeof(TYPE)*cal);
	//初始化容量，数量
	arr->cal = cal;
	arr->cnt = 0;

	return arr;
}

//遍历
void show_array(const Array* arr)
{
	for(int i = 0;i < arr->cnt;i++)
	{
		printf("%d ",arr->ptr[i]);
	}
	printf("\n");
}

//插入
bool insert_array(Array* arr,size_t index,TYPE key)
{
	//判断是否满
	if(arr->cnt>=arr->cal) printf("该顺序表已满\n");

	//判断index是否能保证连续性
	if(index>arr->cnt) printf("插入失败，不能保证顺序表的连续性\n");

	//index后面的数据整体后移，再插入key
	if(index<arr->cal)
	{
		memmove(arr->ptr+index+1,arr->ptr+index,sizeof(TYPE)*(arr->cnt-index));
		arr->ptr[index]=key;
		arr->cnt++;
		return true;
	}
/*for(int i=arr->cnt;i>index;i--)
  {
  	arr->ptr[i]=arr->ptr[i-1];
  }
  arr->ptr[index]=key;
  arr->cnt++;
  return true;*/
}
//删除
bool delete_array(Array* arr,size_t index)
{
	if(index>=arr->cnt) return false;
	memmove(arr->ptr+index,arr->ptr+index+1,sizeof(TYPE)*(arr->cnt-index-1));
	arr->cnt--;
	return true;
}

//访问
bool access_array(Array* arr,size_t index,TYPE* val)  //*val是把访问的值传回去,普通变量是单向传递，指针是共享变量
{	
	if(index>=arr->cnt) return false;
	*val=arr->ptr[index];
	return true;
}

//查询
int query_array(Array* arr,TYPE val)
{
	for(int i=0;i<arr->cnt;i++)
	{
		if(val==arr->ptr[i]) return i;
	}
	return -1;
}

//修改
bool modify_array(Array* arr,size_t index,TYPE val)
{
	if(index>=arr->cnt) return false;
	arr->ptr[index]=val;
	return true;
}

//清空
void clear_array(Array* arr)
{
	arr->cnt=0;
}

//销毁
void destroy_array(Array* arr)
{
	free(arr->ptr);
	free(arr);
}

//排序
void sort_array(Array* arr)
{
	int cmp=0;
	for(int i=0;i<arr->cnt-1;i++)
	{	
		for(int j=i+1;j<arr->cnt;j++)
		{
			if(arr->ptr[i]>arr->ptr[j])
			{	
				cmp=arr->ptr[i];
				arr->ptr[i]=arr->ptr[j];
				arr->ptr[j]=cmp;
			}
		}	
	}
}

int main(int argc,const char* argv[])
{
	Array* arr = create_array(10);
//	show_array(arr);
	for(int i=0;i<10;i++)
	{
		insert_array(arr,0,i+1);
	}
	show_array(arr);
	sort_array(arr);
	show_array(arr);	
	return 0;
}
