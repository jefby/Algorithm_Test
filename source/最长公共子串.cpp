/*
    求最长公共子序列
*/
#include <stdio.h>
#include <string.h>

/* 最长公共子串 DP */
static int maxlen  = 0 , maxindex = 0;
int dp[40][40];

/* 输出LCS
 * 在后缀数组方法中，maxindex=0
 * 因为传进来的就是后缀数组suff[]，从0打印maxlen个字符
*/
void 
outputLCS(char * text)
{
    if(maxlen == 0)
    {
        printf("NULL LCS\n");
        return;
    }
    printf("The len of LCS is %d\n",maxlen);
 
    int i = maxindex;
    while(maxlen--)
    {
        printf("%c",text[i++]);
    }
    printf("\n");
} 


int 
LCS_dp(char * text,char * query)
{

	int textlen =0,querylen=0;

	textlen= strlen(text);
	querylen = strlen(query);
	
    for(int i = 0; i < textlen; ++i)
    {
        for(int j = 0; j < querylen; ++j)
        {
            if(text[i] == query[j])
            {
                if(i && j)
                    dp[i][j] = dp[i-1][j-1] + 1;
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                if(dp[i][j] > maxlen){
                    maxlen = dp[i][j];
                    maxindex = i + 1 - maxlen;
                }  
            }
        }
    }
	return maxlen;
}


 
int main()
{
    char text[] = "acaccbabb";
    char query[] = "acbac";
	printf("%d",LCS_dp(text,query));
	outputLCS(text);
 
	getchar();
}
