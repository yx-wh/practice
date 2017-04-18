#include <stdio.h>
#include <string.h>
static char *dock;

char *mystrtok(char *str, const char *delim)
{
	char *start;
	if (str != NULL)
	{
		start = str;
	}
	else
	{
		start = dock;
	}
	for (char *i = start; *i != '\0'; i++)
		for (const char *j = delim; *j != '\0'; j++)
		{
			if (*i == *j)
			{
				*i = '\0';
				dock = 1 + i;
				return start;
			}
		}
	return start;
}
char *mystrtok_r(char *str, const char *delim, char **saveptr)
{
	char *start;
	if (str != NULL)
	{
		start = str;
	}
	else
	{
		start = *saveptr;
	}
	for (char *i = start; *i != '\0'; i++)
		for (const char *j = delim; *j != '\0'; j++)
		{
			if (*i == *j)
			{
				*i = '\0';
				*saveptr = 1 + i;
				return start;
			}
		}
	return start;

}

int main (int argc, char *argv[])
{
	char str1[] = "a/bbb///cc;xxx:yyy:";
	char str2[] = "a/bbb///cc;xxx:yyy:";
	char str3[] = "a/bbb///cc;xxx:yyy:";
	char *stra = ";:";
	char *saveptr1;
	char *token;
	//token = strtok_r(str1, str2, &saveptr1);
	//printf("%s\n", token);
	//token = strtok_r(NULL, str2, &saveptr1);
	//printf("%s\n", token);
	//token = strtok_r(NULL, str2, &saveptr1);
	//printf("%s\n", token);
	token = mystrtok(str1, stra);
	printf("%s\n", token);
	token = mystrtok(NULL, stra);
	printf("%s\n", token);
	token = mystrtok(NULL, stra);
	printf("%s\n", token);

	token = strtok(str2, stra);
	printf("%s\n", token);
	token = strtok(NULL, stra);
	printf("%s\n", token);
	token = strtok(NULL, stra);
	printf("%s\n", token);

	token = mystrtok_r(str3, stra, &saveptr1);
	printf("%s\n", token);
	token = mystrtok_r(NULL, stra, &saveptr1);
	printf("%s\n", token);
	token = mystrtok_r(NULL, stra, &saveptr1);
	printf("%s\n", token);
	return 0;
}
