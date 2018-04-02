/* 《一站式学习C编程》第24章24.2.11本节综合练习 1
 * 模仿系统日志生成
 *
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int isleapyear(int year)
{
	if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

char *printtime(time_t timefrom, char *timeto)
{
	long int date = timefrom / 86400; //总共有多少天
	int dateremainder = timefrom % 86400; //天以内有多少秒
	int year = 1970; //epoch1970年
	int month;
	int day;
	int hour;
	int minute;
	int second;
	while (date >= 365 + isleapyear(1 + year))
	{
		year++;
		date -= 365 + isleapyear(year);
	}
	if (isleapyear(year))
	{
		switch (date)
		{
			case 0 ... 30:
				month = 1;
				day = date + 1;
				break;
			case 31 ... 59:
				month = 2;
				day = date - 30;
				break;
			case 60 ... 90:
				month = 3;
				day = date - 59;
				break;
			case 91 ... 120:
				month = 4;
				day = date - 90;
				break;
			case 121 ... 151:
				month = 5;
				day = date - 120;
				break;
			case 152 ... 181:
				month = 6;
				day = date - 151;
				break;
			case 182 ... 212:
				month = 7;
				day = date - 181;
				break;
			case 213 ... 243:
				month = 8;
				day = date - 212;
				break;
			case 244 ... 273:
				month = 9;
				day = date - 243;
				break;
			case 274 ... 304:
				month = 10;
				day = date - 273;
				break;
			case 305 ... 334:
				month = 11;
				day = date - 304;
				break;
			case 335 ... 365:
				month = 12;
				day = date - 334;
				break;
		}
	}
	else
	{
		switch (date)
		{
			case 0 ... 30:
				month = 1;
				day = date + 1;
				break;
			case 31 ... 58:
				month = 2;
				day = date - 30;
				break;
			case 59 ... 89:
				month = 3;
				day = date - 58;
				break;
			case 90 ... 119:
				month = 4;
				day = date - 89;
				break;
			case 120 ... 150:
				month = 5;
				day = date - 119;
				break;
			case 151 ... 180:
				month = 6;
				day = date - 150;
				break;
			case 181 ... 211:
				month = 7;
				day = date - 180;
				break;
			case 212 ... 242:
				month = 8;
				day = date - 211;
				break;
			case 243 ... 272:
				month = 9;
				day = date - 242;
				break;
			case 273 ... 303:
				month = 10;
				day = date - 272;
				break;
			case 304 ... 333:
				month = 11;
				day = date - 303;
				break;
			case 334 ... 364:
				month = 12;
				day = date - 333;
				break;
		}
	}
	hour = dateremainder / 3600;
	minute = dateremainder % 3600;
	second = minute % 60;
	minute = minute / 60;
	sprintf(timeto, "%4d-%d-%d %02d:%02d:%02d", year, month, day, hour, minute, second);
	return timeto;
}

int main(void)
{
	/*
	FILE *fp = fopen("test.txt", "a+");
	while (1)
	{
		fprintf(fp, "%ld\n", time(NULL));
		fflush(fp);
		printf("%ld\n", time(NULL));
		sleep(1);
	}
	fclose(fp);
	*/
	/*
	printf("%d\n", isleapyear(1900));
	printf("%d\n", isleapyear(1901));
	printf("%d\n", isleapyear(2000));
	printf("%d\n", isleapyear(2400));
	*/
	char output[20];
	char input[25];
	int count = 0;
	//printf("%s\n", printtime(time(NULL), output));
	FILE *fp = fopen("test.txt", "a+");
	//fgets(input, sizeof(input), fp);
	//printf("%s\n", input);
	while (fgets(input, sizeof(input), fp) > 0)
	{
		sscanf(input, "%d", &count);
	}
	while (1)
	{
		count++;
		fprintf(fp, "%d ", count);
		fprintf(fp, "%s\n", printtime(time(NULL), output));
		fflush(fp);
		printf("%d ", count);
		printf("%s\n", printtime(time(NULL), output));
		sleep(1);
	}
	fclose(fp);

	return 0;
}
