#include<stdlib.h>
#include<stdio.h>

int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int rev = 0,flag = 1;
    if(num < 0){
        num = num * -1;
        flag = -1;
    }
    while(num > 0 ){
        rev = rev * 10 + num % 10;
        num = num /10 ;
    }
    if(flag == -1){
        rev *= -1;
    }
    printf("Reversed : %d",rev);
    return 0;
}