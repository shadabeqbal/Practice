#include<stdio.h>


int main(){
	int x = 4;
	do{
		printf("%d",x--);
		putchar(x+65);
	}while(x);
}