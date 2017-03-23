#include <stdio.h>
#include <string.h>

char *mystrtok(char *str, const char *delim)
{

	return ;
}

int main (int argc, char *argv[])
{
	char str1[] = "a/bbb///cc;xxx:yyy:";
	char *str2 = ";:";
	char *saveptr1;
	char *token;
	token = strtok_r(str1, str2, &saveptr1);
	printf("%s\n", token);
	token = strtok_r(NULL, str2, &saveptr1);
	printf("%s\n", token);
	token = strtok_r(NULL, str2, &saveptr1);
	printf("%s\n", token);
	return 0;
}
