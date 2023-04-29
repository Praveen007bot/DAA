#include<stdio.h>

int main(){
	
	int n;
	
	printf("Enter the number: ");
	scanf("%d",&n);
	int flag=0;
	
	for(int i=2 ; i<=n/2 ; i++){
		if(n%i==0){
			flag =1;
		}
	}
	
	if(flag == 0){
		printf("Prime number");
	}
	else{
		printf("Not prime number");
	}
	
}