#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node* next;
}LinkList;//������Ĵ洢�ṹ 
LinkList *head,*p,*r;
LinkList*CreateLinkListH()//ͷ�巨���������� 
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
void pure(LinkList *L)//ȥ���������ظ�Ԫ�� 
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
