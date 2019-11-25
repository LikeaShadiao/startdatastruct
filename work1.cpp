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
	p=L;
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
LinkList* Get(LinkList*head,int i)
{
	int j=0;
	LinkList*p=head;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j==i)
		return p;//因为这个前面才p->next.
	else
		return NULL;
}
void Insert(LinkList*L,ElemType x,int i)
{
	LinkList*p,*r;
	p=Get(L,i-1);
	if(p==NULL)
		printf("cannot find the node to insert");
	else
	{
		r=(LinkList*)malloc(sizeof(LinkList));
		r->data=x;
		r->next=p->next;
		p->next=r;
	}
}
void bing(LinkList *o,LinkList *m,LinkList *&n)
{
	n=(LinkList*)malloc(sizeof(LinkList));
	LinkList *p=o->next;
	while(p)
	{
		Insert(n,p->data,1);
		p=p->next;
	}
	p=m->next;
	while(p)
	{
		Insert(n,p->data,1);
		p=p->next;
	}
}
LinkList* Getv(LinkList*head,ElemType x)
{
	LinkList*p=head->next;
	while(p!=NULL&&p->data!=x)
		p=p->next;
	return p;
}
void jiao(LinkList *o,LinkList *m,LinkList *&n)
{
	n=(LinkList*)malloc(sizeof(LinkList));
	LinkList *p=o->next;
	while(p)
	{
		if(Getv(m,p->data)!=NULL)
		Insert(n,p->data,1);
		p=p->next;
	}
}
void minis(LinkList *o,LinkList *m,LinkList *&n)
{
	n=(LinkList*)malloc(sizeof(LinkList));
	LinkList *p=o->next;
	while(p)
	{
		if(Getv(m,p->data)==NULL)
		Insert(n,p->data,1);
		p=p->next;
	}
}
int main()
{
	printf("Please input two sets of number.Ensure to input the number directly.\n");
	printf("Seperate every element in a set by ' '.\n");
	printf("Seperate two sets by 'Enter'\n");
	LinkList *A=CreateLinkListH();
	LinkList *B=CreateLinkListH();
	pure(B);
	pure(A);
	printf("For the definition of set,A=");
	r=A->next;
	while(r)
	{
		if(r->data!=' ')
		printf("%d ",r->data);
		r=r->next;
	}
	printf("\n");
	printf("For the definition of set,B=");
	r=B->next;
	while(r)
	{
		if(r->data!=' ')
		printf("%d ",r->data);
		r=r->next;
	}
	printf("\n");
	LinkList *C,*D,*E;
	printf("The combination of the two sets is:");
	bing(A,B,C);
	pure(C);
	head=C->next;
	while(head)
	{
		if(head->data!=' ')
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
	printf("The intersection of the two is:");
	jiao(A,B,D);
	pure(D);
	head=D->next;
	while(head)
	{
		if(head->data!=' ')
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
	printf("The minis of the two is:");
	minis(A,B,E);
	pure(E);
	head=E->next;
	while(head)
	{
		if(head->data!=' ')
		printf("%d ",head->data-48);
		head=head->next;
	}
	return 0;
}
