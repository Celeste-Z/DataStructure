#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int move[3];//移动次数 
int compare[3];//比较次数 
void insertsort(int a[],int n)
{   
	int i,j;
	move[0]=0;
	compare[0]=0;
	for(i=2;i<n;i++)
	{
		a[0]=a[i];
		for(j=i-1;a[j]>a[0];j--)
		{
				a[j+1]=a[j];
				move[0]++;
				compare[0]++;		
		}
		a[j+1]=a[0];
	}
}

int getPosition(int a[],int low,int high)
{
	while(low<high)
	{
		while((low<high)&&(a[high]>=a[0]))
		{
				high--;
				compare[1]++;	
		}
		a[low]=a[high];
		move[1]++;
		while((low<high)&&(a[low]<=a[0])){
				low++;
				compare[1]++;	
		}
		a[high]=a[low];
		move[1]++;
	}
	a[low]=a[0];
	return low;
}
void QSort(int a[],int low,int high)
{
	int pos;
	if(low>=high)
		return;
	a[0]=a[low];
	pos=getPosition(a,low,high);
	a[pos]=a[0];
	QSort(a,low,pos-1);
	QSort(a,pos+1,high);
}
void quicksort(int a[],int n)
{
	QSort(a,1,n);
}

void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	int* c=(int *)malloc(sizeof(int)*(high-low+1));
	while(i<=mid && j<=high) 
	{ 
		move[2]++;
		compare[2]++;
		if(a[i]<=a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else 
		{
			c[k]=a[j];
			j++;
			k++;
		}
	} 
	while(i<=mid)
		{
			c[k]=a[i];
			i++;
			k++;
			move[2]++;
		}
	while(j<=high)
		{
			c[k]=a[j];
			j++;
			k++;
			move[2]++;
		}
	
	k=0;
	i=low;
	while(k<(high-low+1))
	{
		a[i]=c[k];
		i++;
		k++;
		move[2]++;
	}
	free(c);
}
void msort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		msort(a,low,mid);
		msort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void mergesort(int a[],int n)
{
	msort(a,0,n);
}

void sortTime(int a[],int n,void (*f)(int a[],int n)) 
{
    clock_t start,end;
    start=clock();
    f(a,n);
    end=clock();
    printf("%d\n",end-start);
}
int main()
{
	//生成随机数组 
	int a[10001],b[10001];
    int i=0;
    srand(time(0));
    for(i=0;i<10000;i++)
    {
       a[i]=rand();
       b[i]=a[i];
    }
    //实际花费时间、比较次数、移动次数 
	printf("插入排序实际花费时间为:");
	sortTime(b,10000,insertsort);
	printf("插入排序比较次数为:%d\n",compare[0]);
	printf("插入排序移动次数为:%d\n",move[0]);
	printf("\n");
	
	for(i=0;i<10000;i++)
    {
		b[i]=a[i];
    } 
	printf("快速排序实际花费时间为:");
 	sortTime(b,10000,quicksort);
 	printf("快速排序比较次数为:%d\n",compare[1]);
	printf("快速排序移动次数为:%d\n",move[1]);
	printf("\n");
	
	for(i=0;i<10000;i++)
    {	
		b[i]=a[i];
    }
    printf("归并排序实际花费时间为:");
	sortTime(b,10000,mergesort);
	printf("归并排序比较次数为:%d\n",compare[2]);
	printf("归并排序移动次数为:%d\n",move[2]);

} 
