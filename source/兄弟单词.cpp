#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 
#define MAXLEN 100  /* 单词最大长度 */
 
/* qsort比较函数 */
int charcmp(const void *p, const void *q)
{
    return *(char *)p - *(char *)q;
}
 
/* 打印输出 & 释放内存 */
void output(map<string,vector<char*>> dic)
{
    for(map<string,vector<char*>>::iterator it = dic.begin(); it != dic.end(); ++it)
    {
        for(vector<char *>::iterator itv = it->second.begin(); itv != it->second.end(); ++itv)
        {
            printf("%s ",*itv);
            free(*itv);
        }
        printf("\n");
    }
}
 
void main()
{
    map<string,vector<char*>> dic;  /* 存储<key,兄弟单词集> */
    char word[MAXLEN];
    int len = 0;
 
    while(scanf("%s",word) != EOF) /* ctrl+z结束输入 */
    {
        len = strlen(word);
        if(len > 0)
        {
            char * ptr = (char *) malloc(len+1);
            strcpy(ptr,word);
            qsort(word,len,sizeof(char),charcmp);//将输入的单词排序
            string key(word);
            dic[key].push_back(ptr);
        }
    }
    output(dic);
	fflush(stdin);
	getchar();
}