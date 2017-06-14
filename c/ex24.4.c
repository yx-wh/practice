#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	fp = fopen("/etc/shadow", "r");
	if (fp == NULL)
	{
		perror("Open /etc/shadow");
		//exit(1);
	}
	fp = fopen("/home/yx", "r+");
	if (fp == NULL)
	{
		perror("Open /home/yx");
		//exit(1);
	}
	return 0;
}
