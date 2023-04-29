#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
	
	int i;
	char str[100];
	
	printf("Enter the stirng: ");
	gets(str);
	
	int n = strlen(str);
	
	
	for(i=0 ; i<n-i-1 ; i++){
		int temp = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = temp;
	}
	
	printf(str);
}