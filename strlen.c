#include<stdio.h>


int length(char str[]){
		int i;
		for(i = 0 ; str[i] != '\0' ; ++i){
			return i;
		}
	}

int main(){
	char str[100];
	
	printf("Enter the string: ");
	scanf("%s",&str);
	
	int len = length(str);
	printf("%d",len);
	return 0;
}
