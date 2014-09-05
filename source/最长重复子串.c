/*
    最长可重叠重复子串
*/
#include <stdio.h>
#include <string.h>

/* 最长重复子串 后缀数组 */
char * suff[30];
int maxlen,maxindex;

/* 最长重复子串 基本算法 */
int comlen(char * p, char * q)
{
    int len = 0;
    while(*p && *q && *p++ == *q++)
    {
        ++len;
    }
    return len;
}

/* 输出LRS
 * 在后缀数组方法中，maxindex=0
 * 因为传进来的就是后缀数组suff[]，从0打印maxlen个字符
 */
void outputLRS(char * arr)
{
	int i;
    if(maxlen == 0)
    {
        printf("NULL LRS\n");
        return;
    }
    printf("The len of LRS is %d\n",maxlen);
 
    i = maxindex;
    while(maxlen--)
    {
        printf("%c",arr[i++]);
    }
    printf("\n");
}
 
int pstrcmp(const void * p, const void * q)
{
    return strcmp(*(char**)p, *(char**)q);
}
//后缀数组方法来求最长重复子串
void LRS_suffix(char * arr, int size)
{
    int suff_index = maxlen = maxindex = 0;
    int i = 0;
    int len = 0;
 
    for(i = 0; i < size; ++i) /* 初始化后缀数组 */
    {
        suff[i] = &arr[i];
    }
    qsort(suff, size, sizeof(char *), pstrcmp); /* 排序后缀 */
    for(i = 0; i < size-1; ++i)  /* 寻找最长重复子串 */
    {
        len = comlen(suff[i],suff[i+1]);
		printf("i=%d,len=%d\n",i,len);
        if(len > maxlen)
        {
            maxlen = len;
            suff_index = i;
        }
    }
    outputLRS(suff[suff_index]);
}

void main()
{
    char X[] = "banana";
 
 
    /* 后缀数组方法 */
    LRS_suffix(X,strlen(X));
	getchar();
}