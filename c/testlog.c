#include <stdio.h>
#include <unistd.h>
#include <time.h>

char *printtime(time_t timefrom, char *timeto)
{
	
	return timeto;
}

int main(void)
{
	FILE *fp = fopen("test.txt", "a+");
	while (1)
	{
		fprintf(fp, "%ld\n", time(NULL));
		fflush(fp);
		printf("%ld\n", time(NULL));
		sleep(1);
	}
	fclose(fp);
	return 0;
}
