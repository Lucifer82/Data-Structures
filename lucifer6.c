#include<stdio.h>
#include<stdlib.h>	

void printarr(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}



void merge(int arr[],int l,int m,int r){

	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;

	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=arr[l+i];	
	}
	for(j=0;j<n2;j++){
		R[j]=arr[m+1+j];
	}
	i=0,j=0,k=1;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i++];			
		}else{
			arr[k]=R[j++];		
		}
		k++;
	}
	for(;i<n1;){
		arr[k++]=L[i++];
	}
	for(;j<n2;){
		arr[k++]=R[j++];
	}
}





void mergesort(int arr[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main(){
	int n,i;
	int *arr;
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",(arr+i));	
	}
	printarr(arr,n);
	mergesort(arr,0,n-1);
	printarr(arr,n);
	return 0;

}
