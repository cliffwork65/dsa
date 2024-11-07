// BUBBLE SORT
#include<stdio.h>
int main()
{
	int i,j,n,temp;
	printf("Enter Size of the Array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter Elements in the Array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("After Bubble Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d		",a[i]);
	}
	
}

