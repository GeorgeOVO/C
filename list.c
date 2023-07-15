#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int 

//设计节点结构
typedef struct Node
{
	TYPE data; //节点的数据域
	struct Node* next; //节点的指针域
}Node;

//创建节点
Node* create_node(TYPE data)
{
	//申请节点内存
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//头添加
void add_head_list(Node** head,TYPE data)
{
	Node* node=create_node(data);
	node->next=*head;
	*head=node;
}

//按值删除
bool del_value_list(Node** head,TYPE data)
{
	if((*head)->data==data)
	{
		Node* temp=*head;
		*head=temp->next;
		free(temp);
		return true;
	}
	//查找待删除节点的上一个节点
	for(Node* n=*head;NULL!=n->next;n=n->next)
	{
		if(n->next->data==data)
		{
			Node* temp=n->next;
			n->next=temp->next;
			free(temp);
			return true;
		}
	}
	return false;
}

//遍历
void show_list(Node* head)
{
	for(Node* n=head;NULL!=n;n=n->next)
	{
		printf("%d ",n->data);
	}
	printf("\n");
}

//访问
bool access_list(Node* head,size_t index,TYPE* val)
{
	int i=0;
	for(Node* n=head;n;n=n->next,i++)
	{
		if(i==index)
		{
			*val=n->data;
			return true;
		}
	}
	return false;
}

//排序
void sort_list(Node* head)
{
	for(Node* n=head;NULL!=n->next;n=n->next)
	{
		for(Node* m=n->next;m;m=m->next)
		{
			if(n->data > m->data)
			{
				TYPE temp=n->data;
				n->data=m->data;
				m->data=temp;
			}
		}
	}
}

//按位置删除
bool del_index_list(Node** head,size_t index)
{
	if(0==index)
	{
		Node* temp=*head;
		*head=temp->next;
		free(temp);
		return true;
	}
	Node* n=*head;
/*	while(--index)
	{
		n=n->next;
		if(NULL==n) return false;
	}
	if(NULL==n->next) return false;
	Node* temp=n->next;
	n->next=temp->next;
	free(temp);
	return true;*/
	for(int i=1;n->next;n=n->next,i++)
	{
		if(i==index)
		{
			Node* temp = n->next;
			n->next = temp->next;
			free(temp);
			return true;
		}
	}
	return false;
}

int main(int argc,const char* argv[])
{
	Node* head = create_node(10);
	return 0;
}
