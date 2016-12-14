#include<stdio.h>
#include<malloc.h>
#define MAXLEN 100000

typedef struct
{
    int key;

} ElemType;

typedef struct
{
    ElemType *r;
    int length;
} SqList;

void creat_SqList(SqList *L)
{

    int i,n;
    scanf("%d",&n);
    L->r=(ElemType*)malloc((n+1)*sizeof(ElemType));
    for(i=1; i<=n; i++)
    {
        scanf("%d",&L->r[i].key);
        L->length++;
    }

}

void show(SqList L)
{
    int i;
    for(i=L.length; i>1; i--)
        printf("%d ",L.r[i].key);
    printf("%d\n",L.r[1].key);
}

int partition(SqList *L,int low,int high)
{
    int pivotkey;
    L->r[0]=L->r[low];
    pivotkey=L->r[low].key;
    while(low<high)
    {
        while(low<high&&L->r[high].key>=pivotkey)
            --high;
        L->r[low]=L->r[high];
        while(low<high&&L->r[low].key<=pivotkey)
            ++low;
        L->r[high]=L->r[low];

    }
    L->r[low]=L->r[0];

    return low;
}

void QSort(SqList *L,int low,int high)
{
    int pivoloc;
    if(low<high)
    {
        pivoloc=partition(L,low,high);
        QSort(L,low,pivoloc-1);
        QSort(L,pivoloc+1,high);
    }
}

void QuickSort(SqList *L)
{
    QSort(L,1,L->length);
}
int  main()
{
    SqList L;
    L.length=0;
    SqList *temp=&L;


    creat_SqList(temp);
    QuickSort(temp);
    show(L);
    return 0;
}
