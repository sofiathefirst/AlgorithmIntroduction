
#include <stdio.h>
#include <math.h>
#define LEN 7
int m[7][7]={0},s[7][7]={0};

void print_optimal_parens(int i,int j)
{

	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		print_optimal_parens( i,s[i][j]);
		print_optimal_parens(  s[i][j]+1,j);
		printf(")");

	}
}
void matrixChainOrder( int *p,int len)
{// index start from 1
	len = 7;
	int n = len-1, l=0,i=0,j=0,k=0;

	int q=0;
	for(l=2;l<len;l++)// l is the chain length
	{
		for(i=1;i<=n-l+1;i++)
		{
			j = i+l-1;
			m[i][j]=9999999999;
			for(k=i;k<j;k++)
			{
				q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;				
				}
			}
		}

	}
	printf("A1--A6=%d\n",m[1][6]);
	print_optimal_parens(1,6);
	printf("\n");

}
int self_test()
{
	//A1 A2 A3 A4 A5 A6
	int md[]={30,35,15,5,10,20,25};
	matrixChainOrder(md,9);

	printf("ok\n");
	return 0;
}

int main(int argc, char** argv )
{
	self_test();
	//self_test2();
}
