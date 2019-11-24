#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node* next;
}LinkList;//单链表的存储结构 
LinkList *head,*p,*r;
LinkList*CreateLinkListH()//头插法建立单链表 
{
	LinkList*head,*p;
	head=(LinkList*)malloc(sizeof(LinkList));
	char ch;
	head->next=NULL;
	while((ch=getchar())!='\n')
	{
		p=(LinkList*)malloc(sizeof(LinkList));
		p->data=ch;
		p->next=head->next;
		head->next=p;
	}
	return head;
}
void pure(LinkList *L)//去掉链表中重复元素 
{
	LinkList *p,R,*t,*n;
	p=head;
	while(p->next!=NULL)
	{
		t=p;
		n=p;
		r=p->next;
		p=p->next;
		{
			while(r!=NULL)
			{
				if(t->data==r->data)
				{
					n->next=r->next;
					r=r->next;
				}
				else
				{
					n=r;
					r=r->next;
				}
			}
		}
	}
}
int main()
{
	head=CreateLinkListH();
	pure(head);
	r=head->next;
	while(r)
	{
		if(r->data!=' ')
		printf("%d\n",r->data-48);
		r=r->next;
	}
	return 0;
}
