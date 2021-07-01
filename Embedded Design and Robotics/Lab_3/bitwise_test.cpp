#include<stdio.h> 
#include<iostream>
int main(){
	unsigned int a = 97;
	a = a<<1;
	std::cout<< a <<std::endl;
	a = a>>2;
	
	std::cout<< a;
}
