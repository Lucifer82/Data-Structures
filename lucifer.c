#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i,j;
	scanf("%d",&n);
	int *a;
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",(a+i));	
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(*(a+j+1)>*(a+j)){
				*(a+j)= *(a+j) ^ *(a+j+1);
				*(a+j+1)= *(a+j) ^ *(a+j+1);
				*(a+j)= *(a+j) ^ *(a+j+1);
			}
		}	
	}
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
return 0;
}
