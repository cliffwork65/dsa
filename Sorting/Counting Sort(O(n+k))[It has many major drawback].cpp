// WAP in C to implement Count Sort
#include<stdio.h>   
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;  
}  
  
void countSort(int a[], int n) 
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1];  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0;  
  }  
    
  for (int i = 0; i < n; i++)
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; 
  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i]; 
	count[a[i]]--; 
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; 
   }  
}  
  
void printArr(int a[], int n) 
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
int main() {  
    int n,i;
    printf("Enter size of the array: ");
    scanf("%d",&n);
	int a[n]; 
	printf("Enter elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    countSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
  
}  
