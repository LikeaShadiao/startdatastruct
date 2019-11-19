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

//