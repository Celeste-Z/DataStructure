#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define STACKSIZE 100 
int maze[10][10];
typedef struct
{
    int x;//行号
    int y;//列号
    int next;//下一步的位置 
} Pos;
typedef struct
{
    Pos data[STACKSIZE];
    int top;            
} Stack;
void init(Stack *p)
{
	p->top=0;
}
void push(Stack *p,int x,int y,int next)
{
	p->top++;
	p->data[p->top].x=x;
	p->data[p->top].y=y;
	p->data[p->top].next=next;
}             
int isEmpty(Stack *p)
{
	return (p->top<=0);
}
Pos getTop(Stack * p)
{
	Pos pos;
	pos=p->data[p->top];	
	return pos;
} 
int deal(int sx,int sy,int ex,int ey) 
{
    int x,y,k,next,find;
    Stack s;                  
    init(&s);  
	push(&s,sx,sy,-1);              
    maze[sx][sy]=-1;
    while (!isEmpty(&s))          
    {
    	Pos p=getTop(&s);
    	x=p.x;
        y=p.y;
        next=p.next;
        if (x==ex && y==ey)//到达终点,输出路径 
        {
            printf("\n迷宫路径如下:\n");
            for (k=1; k<=s.top; k++)
            {
                printf("(%d,%d)",s.data[k].x,s.data[k].y);
                    printf("\n");
            }
            printf("\n");
            return 1;      
        }
        find=0;
        while (next<4 && find==0)//找下一个可走方向 
        {
            next++;//next初始值为-1，所以必须要写在前面！
			if(next==0)//上 
            {
                x=s.data[s.top].x-1;
				y=s.data[s.top].y;
            } 
            if(next==1)//右 
            {
                x=s.data[s.top].x;
                y=s.data[s.top].y+1;
            }
             if(next==2)//下 
            {
                x=s.data[s.top].x+1;
                y=s.data[s.top].y;
            }
            if(next==3)//左 
            {
                x=s.data[s.top].x;
                y=s.data[s.top].y-1;
            }
           
            if (maze[x][y]==0) find=1;//找到下一个可走方向 
        }
        if (find==1)//找到下一个可走方向 
        {
            s.data[s.top].next=next;      
            push(&s,x,y,-1);
            maze[x][y]=1;//***避免重复走到该方块*** 
        }
        else//没找到，死路 
        {
            maze[s.data[s.top].x][s.data[s.top].y]=0;//让该位置变为其他路径可走
            s.top--;                  
        }
    }
    return 0;                        
}

int main()
{
	//生成随机迷宫
	int i,j,col,row;
	printf("请输入迷宫的行数和列数（少于8）：");
    scanf("%d%d",&row,&col);
 	int b[10][10];
    srand(time(0));
    for(i=0;i<=row+1;i++)
	{
        for(j=0;j<=col+1;j++)
		{
			if( i==0 || j==col+1 || j==0 || i==row+1 )
			{
				maze[i][j]=1;
			}
			else
			{
            b[i][j]=rand();
            maze[i][j]=b[i][j]%10;//随机产生0到9的随机数
            if(maze[i][j]>4) 
				maze[i][j]=1;
            else 
				maze[i][j]=0;
			}
        }
    }
    maze[1][1]=0;//起点
    maze[row][col]=0;//终点
    //输出迷宫
    printf("\n随机生成迷宫为：\n");
	for(i=1;i<=row;i++)
	{
        for(j=1;j<=col;j++)
		{
			printf("%3d",maze[i][j]);
		}
		printf("\n");
	} 
	//迷宫求解
	int rs=deal(1,1,row,col);
	if(rs==0)
		printf("迷宫无解\n");
	return 0; 
}
