/* 《一站式学习C编程》第24章24.2.11本节综合练习 3
 * 深度优先搜索include文件
 *
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <regex.h>

char *combine_name(const char *from, const char *to)
{
	const char *t = from;
	char *p;
	char *q;
	t = from;
	int a = strlen(t);
	int b =	strlen(to);
	p = malloc((a + b + 2) * sizeof(char *));
	strcpy(p, to);
	//看看to的最后一个字符是不是'/'。如果不是的话就补上。
	if (p[b - 1] == '/')
	{
		q = p + b;
	}
	else
	{
		p[b] = '/';
		q = p + b + 1;
	}
	strcpy(q, t);
	return p;
}


int search_include_file(const char *filename, const int search_place)
{
	char *full_filename;
	FILE *fp;
	char input[80];
	if(search_place)
	{
		full_filename = combine_name(filename, "/usr/include");
	}
	else
	{
		char *cwd = getcwd(NULL, 0);
		full_filename = combine_name(filename, cwd);
		printf("%s\n", full_filename);
		free(cwd);
	}
	if ((fp = fopen(full_filename, "r")) == NULL)
	{
		fprintf(stderr, "Error open file %s: %s\n", full_filename, strerror(errno));
		return 1;
	}
	printf("Open file %s\n", full_filename);
	while (fgets(input, sizeof(input), fp) > 0)
	{
		char *regexString1 = "#[ \t]*include[ \t]*<(.*)>";
		char *regexString0 = "#[ \t]*include[ \t]*\"(.*)\"";
		size_t maxGroups = 2;
		regex_t regexCompiled;
		regmatch_t groupArray[maxGroups];
		char * cursor;
		cursor = input;
		if (regcomp(&regexCompiled, regexString1, REG_EXTENDED))
		{
			fprintf(stderr, "Could not compile regular expression.\n");
			return 1;
		}
		if (regexec(&regexCompiled, cursor, maxGroups, groupArray, 0) == 0)
		{
			char cursorCopy[strlen(cursor) + 1];
			strcpy(cursorCopy, cursor);
			cursorCopy[groupArray[1].rm_eo] = 0;
			search_include_file(cursorCopy + groupArray[1].rm_so, 1);
		}
		regfree(&regexCompiled);
		if (regcomp(&regexCompiled, regexString0, REG_EXTENDED))
		{
			fprintf(stderr, "Could not compile regular expression.\n");
			return 1;
		}
		if (regexec(&regexCompiled, cursor, maxGroups, groupArray, 0) == 0)
		{
			char cursorCopy[strlen(cursor) + 1];
			strcpy(cursorCopy, cursor);
			cursorCopy[groupArray[1].rm_eo] = 0;
			search_include_file(cursorCopy + groupArray[1].rm_so, 0);
		}
		regfree(&regexCompiled);
	}
	free(full_filename);
	fclose(fp);
	return 0;
}


int main (int argc, char *argv[])
{
	//printf("%s", getcwd(NULL, 0));
	if (argc != 2)
	{
		fprintf(stderr, "Need 1 argument.\n");
		exit(1);
	}
	search_include_file(argv[1], 0);
	return 0;
}
