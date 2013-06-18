#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 5005

char ori[MAX_N];
char prc[MAX_N];
char ptr[MAX_N];

//implement Longest_palindrome_substring
//@printf the max length
void longest_palindrome_substring(const char*str)
{

    if(str!=NULL)
    {
        int len = strlen(str);
        int m=0;//delete the non-char
	memset(prc,0,sizeof(prc));
        for(int i=0;i<len;++i)
        {
            if(isalpha(str[i]))
            {
                prc[m++]=toupper(str[i]);
            }

        }//convert the origin string to upper-string
        int  max = 0;
        for(int i=0;i<m;++i)
        {
            for(int j=i;j<m;++j)
            {
                int ok = 1;
                for(int k=i;k<j;++k)
                {
                    if(prc[k] != prc[i+j-k])
                    {
                        ok = 0;
                        break;
                    }
                    if(ok && (j-i+1) > max) max = j-i+1;
                }
            }
        }
        printf("longest palindrome substring's length = %d\n",max);
    }
}

//implement longest palindrome substring
void longest_palindrome_substring_new(const char*str)
{
     if(str!=NULL)
    {
        int len = strlen(str);
	int x,y;
        int m=0;//delete the non-char
	memset(prc,0,sizeof(prc));
        for(int i=0;i<len;++i)
        {
            if(isalpha(str[i]))
            {
		ptr[m] = i;
                prc[m++]=toupper(str[i]);
            }

        }//convert the origin string to upper-string
        int  max = 0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;i-j>=0&&(i+j)<m;++j)
	    {
		if(prc[i-j] != prc[i+j]) break;
		if(2*j+1>max) {x=ptr[i-j];y=ptr[i+j];max=j*2+1;}
	    }
	    for(int j=0;i-j>=0 && i+j+1 < m;++j)
	    {
		if(prc[i-j] != prc[i+j+1])break;
		if(j*2+2 > max) {max = j*2+2; x=ptr[i-j];y=ptr[i+j+1];}
	    }
        }
        printf("longest palindrome substring's length = %d\n",max);
	for(int i=x;i<=y;++i)
	{
		printf("%c",ori[i]);
	}
	printf("\n");
    }
	
}

int main()
{

    fgets(ori,MAX_N,stdin);
    longest_palindrome_substring(ori);
    longest_palindrome_substring_new(ori);
    return 0;
}
