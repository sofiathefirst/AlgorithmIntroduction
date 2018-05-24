
#include <stdio.h>
#include <math.h>
void insertionSort(int *data, int len)
{
	int datacur=1,j;
	for(datacur = 1;datacur<len;datacur++)
	{
		j = datacur-1;
		int tmp = data[datacur];
		while(j>=0)
		{
			if(data[j]>tmp)
			{
				data[j+1]=data[j];
			}
			else{   break;}
			j--;
		}
		data[j+1]=tmp;
	}
}
int self_test()
{
	int md[]={4,0,-2,9,-34,99,100,-44,88,-4,34};
	int j=0;
	insertionSort(md,11);
	for( j=0;j<10;j++)
	{
		printf("%d ", md[j]);
		if(md[j]<=md[j+1])
		{}
		else
		{
			printf("error\n");
			return 1;
		}
	}
	printf("%d \n", md[j]);
	printf("ok\n");
	return 0;
}
int self_test2()
{
	/*
	r = randi([1 250],1,15)
	r =
	206   174    80   238     9   110    96   192   199    47   123   112   162   178   189
	*/
	int md[]={ 206,   174  ,  80  , 238   ,  9 ,  110  ,  96 ,  192 ,  199    ,47  , 123  , 112  , 162  , 178 ,  189};
	int j=0;
	insertionSort(md,15);
	for( j=0;j<14;j++)
	{
		printf("%d ", md[j]);
		if(md[j]<=md[j+1])
		{}
		else
		{
			printf("error\n");
			return 1;
		}
	}
	printf("%d \n", md[j]);
	printf("ok\n");
	return 0;
}
int main(int argc, char** argv )
{
	self_test();
	self_test2();
}
