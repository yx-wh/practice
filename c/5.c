#include <stdio.h>

char *simple(void)
{
	return "too simple";
}

int main(void)
{
	//int a;
	//scanf("%d", &a);
	//if (a%2 == 0)
	//	printf("oushu");
	//else
	//	if (a%2 == 1)
	//		printf("jishu");
	//printf("%d", a);
	printf("%s\n", simple());
	printf("%d", EOF);
	return 0;
}
