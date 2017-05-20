#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//比如上面第一个例子，http://www.google.cn/search是路径部分，?号后面的complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=是查询字符串，由五个“key=value”形式的键值对（Key-value Pair）组成，以&隔开，有些键对应的值可能是空字符串，比如这个例子中的键meta。
//检查一个字符串里面有几个键值对。
int check_url(char *str)
{
	char *i;
	int r = -1, s = 0;
	for (i = str; (*i) != '\0'; i++)
	{
		if ((*i) == '?')
		{
			r = 0;
			s++;
		}
		if (r >= 0)
		{
			if ((*i) == '&')
			{
				s++;
				if (s != 1)
					return -1;
			}
			if ((*i) == '=')
			{
				r++;
				s--;
				if (s != 0)
					return -1;
			}
		}
	}
	return r;
}

int url_token(char *str, char **handle[])
{
	int num = check_url(str);
	int j = 0;
	if (num <= 0)
	{
		(*handle) = NULL;
		return num;
	}
	(*handle) = malloc(2 * num * sizeof(char *));
	
	//char *token;
	for (char *i = str; (*i) != '\0'; i++)
	{
		if ((*i) == '?' || (*i) == '=' || (*i) == '&')
		{
			(*i) = '\0';
			(*handle)[j++] = i + 1;
		}
	}
	//token = strtok(str, "?");
	//for (int i = 0; i < 2 * num - 3; i += 2)
	//{
	//	token = strtok(NULL, "=");
	//	(*handle)[i] = token;
	//	token = strtok(NULL, "&");
	//	(*handle)[i + 1] = token;
	//}
	//token = strtok(NULL, "=");
	//(*handle)[2 * num - 2] = token;
	//token = strtok(NULL, ""); //最后一个后面就没有&啦。
	//(*handle)[2 * num - 1] = token;
	/*
	 * "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=AA"就可以，但是
	 * "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta="就会segmentation fault
	 * 可见还是不要利用strtok，直接自己写比较好。
	 * */
	return num;
}

int main(void)
{
	char a[] = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=";
	char **h;
	int n;
	printf("%s\n", a);
	printf("%d\n", check_url(a));
	n = url_token(a, &h);
	for (int i = 0; i < 2 * n; i++)
	{
		printf("%s\n", h[i]);
	}
	free(h);
	return 0;
}
