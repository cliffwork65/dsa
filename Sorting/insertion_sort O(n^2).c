// INSERTION SORT
#include<stdio.h>
int main()
{
	int i,j,n,temp;
	printf("Enter Size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;i++){
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		}
	printf("After Insertion Sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d		",a[i]);
	}
	return 0;
}

