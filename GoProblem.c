#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int b[21][21];
typedef struct point
{
	int x;
	int y;
}Point;
typedef struct node
{
	Point data;
	struct node *next;
}Node;
typedef struct stack
{
	Node *top;
}Stack;
typedef struct list
{
	Node *head;
}List;
void initS(Stack *p);
void push(Stack *p,int x,int y);
Point pop(Stack *p);
int isEmpty(Stack *p);
int isFull(Stack *p);
Point getTop(Stack *p);

void initL(List *p);
Node *getNode(List *p,int pos);
int insert(List *p,int pos,int x,int y);
void output(List *p);
int del(List *p,int pos);
int isEmptyList(List * p);
//计算块数与气数 
void math(int row,int col)
{
	int i,j;
	List l;
	initL(&l);
	int visited[21][21]={0}; 
	for(i=1;i<=row;i++)
	{
        for(j=1;j<=col;j++)
		{
			if(visited[i][j]==0)
			{
				if(b[i][j]==1 || b[i][j]==2)
				{
					int number=0;
					int qiVisited[21][21]={0};
					int qiNumber=0;
					Stack s;
					int find,x,y;
					initS(&s);
					List kuai;
					initL(&kuai);
					push(&s,i,j);
					visited[i][j]=1; 
					number++;
					insert(&l,1,i,j);
					while(!isEmpty(&s))
					{
						Point poi=getTop(&s); 
						x=poi.x;
						y=poi.y;
						find=0;
						if(b[x-1][y]==b[i][j] && visited[x-1][y]==0)//上 
						{
							push(&s,x-1,y);
							visited[x-1][y]=1; 
							find=1; 
							number++;
						} 		
						if(b[x][y+1]==b[i][j] && visited[x][y+1]==0)//右 
						{ 
							push(&s,x,y+1);
							visited[x][y+1]=1; 
							find=1; 
							number++;
						} 
						if(b[x+1][y]==b[i][j] && visited[x+1][y]==0)//下 
						{
							push(&s,x+1,y);
							visited[x+1][y]=1; 
							find=1; 
							number++;
						} 
						if(b[x][y-1]==b[i][j] && visited[x][y-1]==0)//左 
						{
							push(&s,x,y-1);
							visited[x][y-1]=1;
							find=1; 
							number++;
						} 
						if(find==0)
						{
							Point p1=pop(&s);
							int x1=p1.x;
							int y1=p1.y;
							insert(&kuai,1,x1,y1); 
						}
					}
					printf("颜色为%d的棋子所形成的块的棋子数为%d，块中棋子的位置为：\n",b[i][j],number);
					output(&kuai); 
					//求气数
					while(!isEmptyList(&kuai))
					{
						Node *n=getNode(&kuai,1);
						int x1=n->data.x;
						int y1=n->data.y;
						if(b[x1-1][y1]==0 && qiVisited[x1-1][y1]==0)
						{
							qiNumber++;
							qiVisited[x1-1][y1]=1;
						}
						if(b[x1][y1+1]==0 && qiVisited[x1][y1+1]==0)
						{
							qiNumber++;
							qiVisited[x1][y1+1]=1;
						}
						if(b[x1+1][y1]==0 && qiVisited[x1+1][y1]==0)
						{
							qiNumber++;
							qiVisited[x1+1][y1]=1;
						}
						if(b[x1][y1-1]==0 && qiVisited[x1][y1-1]==0)
						{
							qiNumber++;
							qiVisited[x1][y1-1]=1;
						}
						del(&kuai,1);
					}
					printf("此块的气数为%d\n\n",qiNumber);
				}
			}
		}
	}
} 
int main()
{
	//生成棋盘 
	int row,col,i,j;
	printf("请输入围棋的行数和列数（不大于19）： ");
    scanf("%d%d",&row,&col);
    int a[21][21];
    srand(time(0));
    for(i=0;i<=row+1;i++)
	{
        for(j=0;j<=col+1;j++)
		{
			if(i==0||i==row+1||j==0||j==col+1)
				b[i][j]=4;//棋盘外围
			else 
			{
				a[i][j]=rand();
         	    b[i][j]=a[i][j]%10;
        	    if(b[i][j]<3)  b[i][j]=0;//0代表无子
        	    else if(b[i][j]>=3&&b[i][j]<=6)  b[i][j]=1;//1代表白棋
        	    else  b[i][j]=2;//2代表黑棋
			} 
        }
	} 
	//输出棋盘 
    for(i=1;i<=row;i++)
	{
        for(j=1;j<=col;j++)
		{
            printf("%4d",b[i][j]);
        }
        printf("\n");
	}
	//计算块数
	math(row,col); 
    return 0;
}

void initS(Stack *p)
{
	p->top=NULL;
}
void push(Stack *p,int x,int y)
{
	Node *r=(Node *)malloc(sizeof(Node));
	r->data.x=x;
	r->data.y=y;
	r->next=p->top;
	p->top=r;
}
Point pop(Stack *p)
{
	Node *r=p->top;
	Point x=r->data;
	p->top=r->next;
	free(r);
	return x;
	
}
int isEmpty(Stack *p)
{
	return (p->top==NULL);
}
int isFull(Stack *p)
{
	return (0);
}
Point getTop(Stack *p)
{
	return (p->top->data);
}



void initL(List *p)
{
	p->head=(Node *)malloc(sizeof(Node));
	p->head->next=NULL;
}
Node *getNode(List *p,int pos)
{
	int i=0;
	Node *r=p->head;
	if(pos<0)
	{
		return NULL;
	}
	while(i<pos&&r!=NULL)
	{
		i++;
		r=r->next;
	}
	return r;
}
int insert(List *p,int pos,int x,int y)
{
	int i;
	Node *n=(Node *)malloc(sizeof(Node));
	if(pos<=0)
	{
		return -1; 
	}
	Node * q=getNode(p,pos-1);
	if(q==NULL)
	{
		return -1;
	}
	n->data.x=x;
	n->data.y=y;
	n->next=q->next;
	q->next=n;
	return 0;
}
void output(List *p)
{
	Node *r=p->head->next;
	while(r!=NULL)
	{
		printf(" ( %d , %d ) ",r->data.x,r->data.y);
		r=r->next;
	}
	printf("\n");
}
int del(List *p,int pos)
{
	Node *r,*q;
	if(pos<=0)
	{
		return -1; 
	}

	q=getNode(p,pos-1);
	if(q==NULL||q->next==NULL)
	{
		return -1;
	}	
	r=q->next;
	q->next=r->next;	

	free(r);
	return 0;
}
int isEmptyList(List * p)
{
	return (p->head->next==NULL);
}
