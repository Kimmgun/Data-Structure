#define _CRT_SECURE_NO_WARNINGS 1

//顺序表可由数组实现 但数组的大小是固定的
//线性表的长度是可变的 所以需要加入一个变量表示线性表长度
//线性表的顺序存储 = 数组 + 长度变量

#define LIST_INIT_SIZE 100 //数组初始大小

////静态数组
//typedef struct {
//    ElemType data[LIST_INIT_SIZE]; //数组
//    int length; //当前长度
//} SqList;
////动态数组
//typedef struct {
//    ElemType* data; //数组
//    int length; //当前长度
//}SqList;
    
//定义多项式线性表
typedef struct
{
    float p;//多项式的系数
    int e;  //多项式的指数
}Polynomial;
typedef struct
{
    Polynomial data[LIST_INIT_SIZE];
    int length; 
}SqListPol; 

//类C语言有关操作
//动态分配数组空间
//SqList L;
//L.data = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
//malloc(X)：分配X字节内存，返回指向该内存的首地址
//free(p):释放指针P指向的存储空间
//C++的new和delete操作符也可实现动态分配内存
//int *p = new int[100];
//delete[] p;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;


//线性表的初始化
Status InitList(SqList &L)
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    return OK;
}
//线性表的销毁
void DestroyList(SqList &L)
{
    if (L.elem)
    {
            delete[] L.elem;
    }
} 
//清空线性表
void ClearList(SqList& L)
{
    L.length = 0;
}
//求线性表的长度
int GetLength(SqList L)
{
    return L.length;
}
    
//判断线性表是否为空
int IsEmpty(SqList L)
{
    if (L.length == 0)
    {return 1;}
    else
    {return 0;}
}

//按位查找
int GetElem(SqList L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i-1];
    return OK;
}
//按值查找
int LocateElem(SqList L, ElemType e)
{
    for (int i = 1; i <= L.length; i++)
    {
        if (L.elem[i-1] == e)
        {
            return i ;
        }
    }
    return 0;
}
//线性表的插入
//1.判断插入位置是否合法 0~n/1~n+1
//2.判断数组空间是否饱和
//3.将第n个元素至第i个元素后移一位 空出第i个位置
//4.插入元素
//5.更新长度
Status ListInsert(SqList& L, int i, ElemType e)
    {
        if (i < 1 || i > L.length + 1)
        {
            return ERROR;
        }
        if (L.length == LIST_INIT_SIZE)
        {
            return OVERFLOW;
        }
        for (int j = L.length; j >= i; j--)
        {
            L.elem[j] = L.elem[j-1];
        }
        L.elem[i-1] = e;
        L.length++;
        return OK;
//线性表的删除
//1.判断删除位置是否合法1~n
//2.将第i+1个元素至第n个元素前移一位
//3.更新长度
Status ListDelete(SqList& L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i-1];
    for (int j = i; j < L.length; j++)
    {
        L.elem[j-1] = L.elem[j];
    }
    L.length--;
    return OK;
}