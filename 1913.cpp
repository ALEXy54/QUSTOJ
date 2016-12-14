                                                                                                                                                         #include<stdio.h>
#include<malloc.h>
#define MAXLEN 40
#define MaxInt 32767
typedef struct
{
    int vexs[MAXLEN];
    int arcs[MAXLEN][MAXLEN];
    int vexnum;
    int arcnum;
}AMGRAPH;

int LocateVex(AMGRAPH G,int v)
{   int i;
    for(i=0;i<G.vexnum;i++)
        if(G.vexs[i]==v)
            return i;
   return -1;
}

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    int quan;
}ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *firstarc;
}VNode,AdjList[MAXLEN];

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

AMGRAPH CreatAMG()
{
    int i,j,k;

    AMGRAPH G;
    scanf("%d %d",&i,&j);
    G.vexnum=i;
    G.arcnum=j;
    k=G.vexnum;
    for(i=0;i<k;i++)
        scanf("%d",&G.vexs[i]);

    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
        G.arcs[i][j]=MaxInt;

    for(k=0;k<G.arcnum;k++)
    {   int v1,v2,v;
    scanf("%d %d %d",&v1,&v2,&v);
        i=  LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arcs[i][j]=v;
        G.arcs[j][i]=v;

    }
    return G;


}
int locate(AMGRAPH g,int i)
{
    int j;
    for(j=0;j<g.vexnum;j++)
        {if(i==g.vexs[j])
        return j;}
        return -1;

}

ALGraph MG_TO_ADGJ(AMGRAPH G)
{
    int i,j;
    int n;
    ArcNode *p;
    ALGraph adjg;
    adjg.vexnum=G.vexnum;
    adjg.arcnum=G.arcnum;
    n=G.vexnum;
    for(i=0;i<n;i++)
        {adjg.vertices[i].data=G.vexs[i];
         adjg.vertices[i].firstarc=NULL;

}
        for(i=0;i<n;i++)
            for(j=n-1;j>=0;j--)
        {
            if(j!=i&&G.arcs[i][j]!=MaxInt)
             {  p=(ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex=G.vexs[j];
                p->nextarc=adjg.vertices[i].firstarc;
                adjg.vertices[i].firstarc=p;
            }

        }
    return adjg;

}

int main()
{
    AMGRAPH G;

    ALGraph adjg;
    int i,n;
    ArcNode *p;
    G=CreatAMG();
    n=G.vexnum;
    adjg=MG_TO_ADGJ(G);
  for(i=0;i<n;i++)
  {
       printf("%d",adjg.vertices[i].data);
      p=adjg.vertices[i].firstarc;
      while(p!=NULL)
      {
          printf(" -> %d",p->adjvex);
          p=p->nextarc;
      }
      printf(" -> NULL");
      printf("\n");
  }

  return 0;
}
