#include<stdio.h>
#include<stdbool.h>
int main(){
   int x,y;
   const float PI = 3.14;
   printf("Enter two numbers: ");
   scanf("%d %d",&x,&y);
   printf("Sum of %d and %d without including constant(%f) is %d\n",x,y,PI,x+y);
   printf("Sum of %d and %d including constant(%f) is %f",x,y,PI,x+y+PI);
   return 0;
} 