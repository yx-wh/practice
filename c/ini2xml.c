/* 《一站式学习C编程》第24章24.2.11本节综合练习 2
 * 转换ini文件
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[])
{
	FILE *fpini, *fpxml;
	char input[80], temp[80], a[80];
	int mark = 0;
	int i = 0;
	if ( (fpini = fopen("a.ini", "r")) == NULL)
	{
		fprintf(stderr, "Error open file a.ini: %s\n", strerror(errno));
		exit(1);
	}
	if ( (fpxml = fopen("a.xml", "w")) == NULL)
	{
		fprintf(stderr, "Error open file a.xml: %s\n", strerror(errno));
		exit(1);
	}
	while (fgets(input, sizeof(input), fpini) > 0)
	{
		if (input[0] == ';')
		{
			sscanf(input, ";%s", a);
			fprintf(fpxml, "<!-- %s -->\n", a);
			continue; 
		}
		if (input[0] == '[')
		{
			/*  sscanf(input, "[%s]", temp);
			 * [http], 实际上temp是“http]”。
			 * 而不是“http”。
			 */
			int i;
			for (i = 1; input[i] != ']'; i++)
				if (input[i] == 0)
					break;
			input[i] = 0;
			strcpy(temp, &input[1]);
			fprintf(fpxml, "<%s>\n", temp);
			mark = 1;
			continue; 
			//这个break漏掉了就会segmentation fault
			//傻逼了，不应该是break，应该是continue
		}
		if (mark)
		{
			while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
			{
				if (input[i] == '\n')
				{
					fprintf(fpxml, "</%s>\n\n", temp);
					mark = 0;
					break;
				}
				i++;
			}
			//以下参考了网上的regex的范例。
			//char *regexString = "(.*)[ \t]+=[ \t]+(.*)"; 傻了，正则的加号乘号分不清……
			char *regexString = "([^ \t]*)[ \t]*=[ \t]*(.*)\n";
			size_t maxGroups = 3;
			regex_t regexCompiled;
			regmatch_t groupArray[maxGroups];
			char * cursor;
			cursor = input;
			if (regcomp(&regexCompiled, regexString, REG_EXTENDED))
			{
				fprintf(stderr, "Could not compile regular expression.\n");
				return 1;
			}
			if (regexec(&regexCompiled, cursor, maxGroups, groupArray, 0))
				continue;  // No more matches
			char cursorCopy[strlen(cursor) + 1];
			strcpy(cursorCopy, cursor);
			cursorCopy[groupArray[1].rm_eo] = 0;
			cursorCopy[groupArray[2].rm_eo] = 0;
			fprintf(fpxml, "<%s>%s</%s>\n", cursorCopy + groupArray[1].rm_so, cursorCopy + groupArray[2].rm_so, cursorCopy + groupArray[1].rm_so);
			regfree(&regexCompiled);
		}
	}
	if (mark)
	{
		fprintf(fpxml, "</%s>", temp);
		mark = 0;
	}
	fclose(fpini);
	fclose(fpxml);
	return 0;
}
