/*

	题：从一个字符串中找到一个连续子串，该子串中任何两个字符不能相同，求子串的最大长度并输出一条最长不重复子串。
*/
#include <stdio.h>
#include <string.h>

#define MAXLEN 1001
char arr[MAXLEN];

char visit[256];
int maxlen,maxindex;

/* 输出LNRS */
void output_str(char * arr)
{
    if(maxlen == 0)
    {
        printf("NO LNRS\n");
    }
    printf("The len of LNRS is %d\n",maxlen);
 
    int i = maxindex;
    while(maxlen--)
    {
        printf("%c",arr[i++]);
    }
    printf("\n");
}
 


void LNRS_hash(char *arr,int size)
{
	int i,j;
	for(i=0;i<size;++i){
		memset(visit,0,sizeof(visit));
		visit[arr[i]] = 1;
		for(j=i+1;j<size;++j){
			if(visit[arr[j]] == 0){
				visit[arr[j]] = 1;
			}else{
				if(j-i > maxlen){
					maxindex = i;
					maxlen = j - i;
				}
				break;
			}
		}
		if(j == size && j-i>maxlen){
			maxindex = i;
			maxlen = j - i;
		}
	}
	output_str(arr);
}

int main()
{
	int len = 0;
	
	scanf("%s",&arr);

	   /* LNRS 基本算法 */
    LNRS_hash(arr,strlen(arr));

	return 0;
}
