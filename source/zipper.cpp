/*
POJ 2192： http://poj.org/problem?id=2192

题意：就是给定三个字符串A，B，C；判断C能否由AB中的字符组成，同时这个组合后的字符顺序必须是A，B中原来的顺序，不能逆序；例如：A：mnl，B：xyz；
如果C为mnxylz，就符合题意；如果C为mxnzly，就不符合题意，原因是z与y顺序不是B中顺序。

DP求解：定义dp[i][j]表示A中前i个字符与B中前j个字符是否能组成C中的前 (i+j) 个字符，如果能标记true，如果不能标记false；

有了这个定义，我们就可以找出状态转移方程了，初始状态dp[0][0] = 1：

1
2
dp[i][j] = 1 如果 dp[i-1][j] == 1 && C[i+j-1] == A[i-1]
dp[i][j] = 1 如果 dp[i][j-1] == 1 && C[i+j-1] == B[j-1]
*/
#include <stdio.h>
#include <string.h>

 
char A[201];
char B[201];
char C[401];
 
int N; /* 测试次数 */
 
/* dp[i][j] 表示A前i个字符与B前j个字符
   是否能构成C前i+j个字符
*/
short int dp[201][201];
 
int main()
{
    int k,i,j;
    scanf("%d", &N);
    for(k = 1; k <= N; ++k)   /* N个测试用例 */
    {
        memset(dp,0,sizeof dp);
        scanf("%s %s %s", A, B, C);
        int lenA = strlen(A);
        int lenB = strlen(B);
 
        dp[0][0] = 1;
 
        for( i = 0; i <= lenA; ++i)
        {
            for(j = 0; j <= lenB; ++j)
            {
                if(i > 0 && (dp[i-1][j] == 1) && (C[i+j-1] == A[i-1]))
                {
                    dp[i][j] = 1;
                }
                if(j > 0 && (dp[i][j-1] == 1) && (C[i+j-1] == B[j-1]))
                {
                    dp[i][j] = 1;
                }
            }
        }
 
        printf("Data set %d: %s\n", k, dp[lenA][lenB] ? "yes" : "no");
    }
    return 0;
}