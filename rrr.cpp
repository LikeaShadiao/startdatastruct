#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}sqlist;//初始化顺序表


//初始化（建立空的顺序表）
//第一种
sqlist* InitList()
{
	sqlist* L=(sqlist*)malloc(sizeof(sqlist));
	L->length=0;
	return L;
}

//第二种
void InitList(sqlist**L)
{
	*L=(sqlist*)malloc(sizeof(sqlist));
	*L->length=0;
}

//第三种
void InitList(sqlist*&L)
{
	L=(sqlist*)malloc(sizeof(sqlist));
	L->length=0;
}

//查找并返回序位
int Find(sqlist* L,ElemType x)
{
	int i=1;
	while(i<=L->length)
		if(L->data[i-1]!=x)
			i++;
		else
			return i;
	return 0;
}

//啊啊啊好紧张马上3000惹
//顺序表的插入，在第i个位置插入一个新节点x
int Insert(sqlist* L,int i,ElemType x)//插入成功返回1，否则返回0
{
	if(L->length==MAXSIZE)
	{
		printf("list is full");
		return 0;
	}
	else if(i<0||i>L->length)
	{
		printf("location unlaw");
		return 0;
	}
	else
	{
		for(int j=L->length;j>=i;j--)
		{
			L->data[j]=L->data[j-1];
		}
		L->data[i-1]=x;
		L->length++;
		return 1;
	}
}

//顺序表的删除，删除第i个结点，成功返回1，错误返回0
int Delete(sqlist* L,int i)
{
	if(i<0||i>L->length)
	{
		printf("location error");
		return 0;
	}
	else
	{
		for(int j=i;j<=L->length-1;j++)
			L->data[j-1]=L->data[j];
		L->length--;
		return 1;
	}
}

//顺序表的合并
void merge(sqlist*A,sqlist*B,sqlist*&C)
{
	if(A->length+B->length>MAXSIZE)
		printf("erroe!");
	else
	{
		C=(sqlist*)malloc(sizeof(sqlist));//YOU FORGOT!
		int i=0,j=0,k=0;
		while(i<A->length&&j<B->length)//YOU FORGOT!
			if(A->data[i]<B->data[j])
				C->data[k++]=A->data[i++];
			else
				C->data[k++]=B->data[j++];
		while(i<A->length)
			C->data[k++]=A->data[i++];
		while(j<B->length)
			C->data[k++]=B->data[j++];
		C->length=k;
	}
}

//顺序表的应用实例，直接抄的书我只改了变量名
#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
//定义顺序表结构类型
typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];
	int length;
}sqlist;
//声明函数原型
/*函数的定义可放在调用函数前或后，如果放在调用函数之后，就必须
在函数调用之前进行函数原型的声明，函数原型与函数头相同，只是
多了一个分号*/
sqlist*InitList();
int Len(sqlist*);
int Insert(sqlist*,ElemType,int);
int Locate(sqlist*,ElemType);
int Delete(sqlist*,int);
void del_node(sqlist*,ElemType);
void PrintList(sqlist*);


void main()
{
	sqlist*L;
	int i=0;
	ElemType x;
	L=InitList();
	printf("输入若干整形数据，建立顺序表（输入-1结束）：");
	scanf("%d",&x);
	while(x!=-1)
	{
		i++;
		if(!Insert(L,x,i)) exit(0);
		scanf("%d",&x);
	}
	PrintList(L);
	printf("输入所要删除的元素值：");
	scanf("%d",&x);
	del_node(L,x);
	PrintList(L);
}


sqlist* InitList()
{
	sqlist* L=(sqlist*)malloc(sizeof(sqlist));
	L->length=0;
	return L;
}


int Len(sqlist*L)
{
	return L->length;
}


int Insert(sqlist* L,int i,ElemType x)//插入成功返回1，否则返回0
{
	if(L->length==MAXSIZE)
	{
		printf("list is full");
		return 0;
	}
	else if(i<0||i>L->length)
	{
		printf("location unlaw");
		return 0;
	}
	else
	{
		for(int j=L->length;j>=i;j--)
		{
			L->data[j]=L->data[j-1];
		}
		L->data[i-1]=x;
		L->length++;
		return 1;
	}
}


int Delete(sqlist* L,int i)
{
	if(i<0||i>L->length)
	{
		printf("location error");
		return 0;
	}
	else
	{
		for(int j=i;j<=L->length-1;j++)
			L->data[j-1]=L->data[j];
		L->length--;
		return 1;
	}
}


int Locate(sqlist*L,ElemType x)
{
	int i=1;
	while(i<L->length)
		if(L->data[i]!=x)
			i++;
		else
			return i;
	return 0;
}


void del_node(sqlist*L,ElemType x)
{
	int k;
	k=Locate(L,x);
	while(k)
	{
		if(Delete(L,k)==0) break;
		k=Locate(L,x);
	}
}


void PrintList(sqlist*L)
{
	int i;
	for(i=1;i<=L->length;i++)
		printf("%5d",L->data[i-1]);
	printf("\n");
}