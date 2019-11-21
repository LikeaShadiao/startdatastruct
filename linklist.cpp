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

//插入单链表
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

//