/*
 编写一个简单的文件复制程序。

$ ./mycp dir1/fileA dir2/fileB

运行这个程序可以把dir1/fileA文件拷贝到dir2/fileB文件。

$ ./mycp dir1/fileA dir2

如果dir2是一个目录名，运行这个命令可以把dir1/fileA文件拷贝到dir2目录下成为dir2/fileA文件。

注意做好各种出错处理。

The mode string can also include the letter 'b' either as a last
character or as a character between the characters in any of
the two-character strings described above.  This is strictly
for compatibility with C89 and has no effect; the 'b' is
ignored on all POSIX conforming systems, including Linux.
(Other systems may treat text files and binary files
differently, and adding the 'b' may be a good idea if you do
I/O to a binary file and expect that your program may be ported
to non-UNIX environments.)


 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *combine_name(const char *from, const char *to)
{
	const char *t = strrchr(from, '/');
	char *p;
	char *q;
	if (t == NULL)
		t = from;
	else
		t++;
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

int main (int argc, char *argv[])
{
//	char *m;
//	m = combine_name("this", "is");
//	printf("%s\n", m);
//	free(m);
//	m = combine_name("/etc/this", "is/");
//	printf("%s\n", m);
//	free(m);
//	m = combine_name("this", "/home/is");
//	printf("%s\n", m);
//	free(m);
//	m = combine_name("this", "/home/is/");
//	printf("%s\n", m);
//	free(m);
	FILE *fpfrom, *fpto;
	int ch;
	if (argc != 3)
	{
		fprintf(stderr, "Need 2 arguments.\n");
		exit(1);
	}
	if ( (fpfrom = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error open file %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}
	if ( (fpto = fopen(argv[2], "w")) == NULL)
	{
		//Is a directory EISDIR = 21
		int t = errno;
		if (EISDIR != t)
		{
			fprintf(stderr, "Error open file %s: %s\n", argv[2], strerror(t));
			exit(1);
		}
		else
		{
			//combine name
			char *m;
			m = combine_name(argv[1], argv[2]);
			if ( (fpto = fopen(m, "w")) == NULL)
			{
				free(m);
				fprintf(stderr, "Error open file %s: %s\n", m, strerror(errno));
				exit(1);
			}
			else
				free(m);
		}
	}
	while ( (ch = fgetc(fpfrom)) != EOF)
	{
		fputc(ch, fpto);
	}
	fclose(fpfrom);
	fclose(fpto);
	return 0;
}
