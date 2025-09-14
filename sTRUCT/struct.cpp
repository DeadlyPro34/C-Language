#include<stdio.h>
#include<string.h>

struct node{
	int myNum;
	char myString[30];
};

int main(){
	struct node s1;
	
	s1.myNum = 13;
	strcpy(s1.myString, "AKHIL BIJU");

	
	printf("My number: %d\n", s1.myNum);
	printf("My Letter: %s", s1.myString);
	return 0;
}
