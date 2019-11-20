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
void Initlist(sqlist**L)
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

