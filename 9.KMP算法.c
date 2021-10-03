/*
char *p="hello";
char arr1[]="hello";
char arr2[]={'h','e','l','l','o'} ;
sizeof(arr1)   6  字符串默认以结尾,sizeof()包含的计算
strlen(arr1) 5 strlen求的是字符串长度
printf("%d\n",strlen(arr2));    '\0'为终止符否则生成随机值 
sizeof(arr2) 5  
printf("%d\n",strlen(p));  结果为5  其参数必须是字符型指针(char*)          
printf("%d\n",sizeof(p));  sizeof()  因为指针变量的所占空间大小仅仅和操作系统位数有关 32-4,64-8
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void NEXT(char *T, int *next)
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < strlen(T))
	{
		if (j == 0 || T[i-1] == T[j-1])
		{
			i++;
			j++;
            if(T[i]!=T[j])
			{
                next[i] = j;
		    }
            else
            {
                next[i]=next[j];
            }
        }
		else
		{
			j = next[j];
		}
	}

}

int KMP(char *S, char *T)
{

	int next[10];
	NEXT(T, next);

	int i = 1;
	int j = 1;

	while (i <= strlen(S) && j <= strlen(T))
	{
		if (j == 0 || S[i - 1] == T[j - 1])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

    if (j > strlen(T))
	{
		return i - (int)strlen(T);
	}
    printf("匹配失败！");
	return -1;

}

int main()
{
	//char *s = "ababcabcacbab";
    char *s = "aaabcaaaaacb";
	char *t = "aaaac";

	int pos=KMP(s,t);
	printf("%d\n", pos);


	system("pause");
	return EXIT_SUCCESS;
}
