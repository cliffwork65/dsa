// SELECTION SORT 
#include<stdio.h>
int main()
{
int n,i,j,temp;
	printf("Enter Size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n-1;i++){
		int min =i;
		for(j=i+1;j<n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		if(min!=i){
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	printf("After Selection Sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d		",a[i]);
	}
	return 0;
}

