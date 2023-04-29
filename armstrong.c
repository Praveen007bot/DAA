#include<stdio.h>
int main(){
    int n,temp;

    printf("Enter the number: ");
    scanf("%d",&n);
    int sum = 0;
    temp = n;

    while(n>0){
        int r = n%10;
        sum = sum + (r*r*r);
        n = n/10;
    }

    if(sum == temp){
        printf("Armstrong number");
    }
    else{
        printf("Not Armstrong Number");
    }
    
return 0;
}