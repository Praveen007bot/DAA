

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* copyString(char s[])
{
	char* s2;
	s2 = (char*)malloc(20);

	strcpy(s2, s);
	return (char*)s2;
}


int main()
{
	char s1[20] = "Praveen";
	char* s2;

	s2 = copyString(s1);
	printf("%s", s2);
	return 0;
}
