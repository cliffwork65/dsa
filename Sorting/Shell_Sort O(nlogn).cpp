// Shell Sort in C
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void shellsort(int arr[],int n){
	int gap;
	int i,j;
	for(gap=n/2;gap>=1;gap=gap/2){
		for(j=gap;j<n;j++){
			for(i=j-gap;i>=0;i=i-gap){
				if(arr[i+gap]>arr[i]){
					break;
				}
				else{
					swap(&arr[i],&arr[i+gap]);
				}
			}
		}
	}
	
}
#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter Size: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	shellsort(a,n);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++){
		printf("%d	",a[i]);
	}
	return 0;
}

