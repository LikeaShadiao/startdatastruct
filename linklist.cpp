//Are you ready?
//单链表的数据结构

typedef char ElemType;
typedef struct node{
	ElemType data;
	struct node* next;
}LinkList;
LinkList *head,*p,*r;


//建立单链表表

//头插法
LinkList*CreateLinkListH()//名字都能写错
{
	LinkList*head,*p;// Forgot
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

//尾插法建立链表
LinkList* CreateLinkListT()
{
	LinkList*head,*p,*r;
	head=(LinkList*)malloc(sizeof(LinkList));
	char ch;
	head->next=NULL;
	r=head;
	while((ch=getchar())!='\n')
	{
		p=(LinkList*)malloc(sizeof(LinkList));
		p->data=ch;
		p=r->next;
		r=p;
	}
	r->next=NULL;
	return head;
}

//建立不带头结点的单链表
LinkList*CreateLinkListN()
{
	char ch;
	LinkList*head,*p,*r;
	head=NULL;
	r=NULL;
	while((ch=getchar())!='\n')
	{
		p=(LinkList*)malloc(sizeof(LinkList));
		p->data=ch;
		if(head==NULL)
			head=p;
		else
			p=r->next;
		r=p;
	}
	if(r!=NULL)//判断是否是空表
		r->next=NULL;
	return head;
}

//按序号查找单链表的元素
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

//按值查找单链表
LinkList* Getv(LinkList*head,ElemType x)
{
	LinkList*p=head->next;
	while(p!=NULL&&p->data!=x)
		p=p->next;
	return p;
}

//给定位置插入单链表
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

//建立有序链表并将元素插入
void Insertbs(LinkList*head,ElemType x)
{
	LinkList *p,*q,*s;
	s=(LinkList*)malloc(sizeof(LinkList));
	s->data=x;
	s->next=NULL;
	p=head->next;
	q=head;
	while(p!=NULL&&p->data<x)
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
		q->next=s;
	else
	{
		q->next=s;
		s->next=p;
	}
}

//单链表的删除，给出要删除的第i个结点
void Delete(LinkList*L,int i)
{
	LinkList*p=Get(L,i-1);
	if(p!=NULL&&P->next!=NULL)
	{
		LinkList*r=p->next;
		p->next=r->next;
		free(r);
	}
	else
		printf("the node of i donnot exit.");
}

/*循环链表 数据类型书上没有，想想没
什么问题，数据类型那肯定是跟链表一样啊*/

//直接上例题，在单循环链表的基础上把两个非空循环链表a,b合并成一个循环链表

//第一种情况，函数参数是尾指针
LinkList*connectt(LinkList*La,LinkList*Lb)
{
	La->next=Lb->next->next;
	free(Lb->next);
	Lb->next=La->next;
	return Lb;
}

//第二种情况，函数参数是头指针
LinkList*connecth(LinkList*La,LinkList*Lb)
{
	LinkList*p=La;
	while(p->next!=La)
		p=p->next;
	p->next=Lb->next;
	LinkList*q=Lb;//也可以直接用p，不再加这个q
	while(q->next!=Lb)
		q=q->next;
	q->next=La;
	free(Lb);
	return La;
}

//双向链表
//双向链表的数据结构类型
typedef struct dnode
{
	ElemType data;
	struct dnode *prior,*next;
}dlinklist;
dlinklist* head;


//双向链表的后插
void hinsert(dlinklist*p,ElemType x)
{
	dlinklist*s=(dlinklist*)malloc(sizeof(dlinklist));
	s->data=x;
	s->prior=p;
	s->next=p->next;
	p->next->prior=s;
	p->next=s;
}

//前插差不多我就不写了，上面能看懂也就可以自己写了

//双向链表的删除