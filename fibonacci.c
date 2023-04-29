#include<stdio.h>
int main(){
    int n = 5;
    int a = 0,b = 1;
    int count  = 2;
    int res=0;
    while(n<=5){
        res = a+b;
        a = b;
        b = res;
        count++;
    }
    printf("%d",res);
    return 0;
}