/*
	求最长公共子序列
	测试数据：
	ABCD ABECFD
	输出：
	4
	ABCD

*/
#include <stdio.h>
#include <string.h>

int dp[21][21];

char x[21];
char y[21];


int
main()
{
	int lenA = 0, lenB = 0;
	int i = 0,j = 0;
	int k = 0;
	scanf("%s %s",&x,&y);
	lenA = strlen(x);
	lenB = strlen(y);
/*
	定义dp[i][j]记录序列LCS的长度，合法状态的初始值为当序列X的长度为0或Y的长度为0，公共子序列LCS长度为0，即dp[i][j]=0，所以用i和j分别表示序列X的长度和序列Y的长度，
	1.dp[i][j] = 0  如果i=0或j=0
	2.dp[i][j] = dp[i-1][j-1] + 1  如果X[i-1] = Y[i-1]
	3.dp[i][j] = max{ dp[i-1][j], dp[i][j-1] }  如果X[i-1] != Y[i-1]
*/
	for(i=0;i<=lenA;++i){
		for(j=0;j<=lenB;++j){
			if(i==0||j==0)
				dp[i][j] = 0;
			else{
				if(x[i-1] == y[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else{
					if(dp[i-1][j] > dp[i][j-1])
						dp[i][j] = dp[i-1][j];
					else
						dp[i][j] = dp[i][j-1];
				}
			}
		}
	}
	printf("%d\n",dp[lenA][lenB] );


	/* 输出LCS 本来是逆序打印的，可以写一递归函数完成正序打印
       这里采用的方法是将Y作为临时存储LCS的数组，最后输出Y
    */
    i = lenA;
    j = lenB;
    k = dp[i][j];
    y[k] = '\0';
    while(i && j)
    {
        if(dp[i][j] == dp[i-1][j-1] + 1)
        {
            y[--k] = x[i-1];
            --i; --j;
        }else if(dp[i-1][j] > dp[i][j-1])
        {
            --i;
        }else
        {
            --j;
        }
    }

    printf("%s\n",y);
	fflush(stdin);
	getchar();
	return 0;
}