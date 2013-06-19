#include <stdio.h>
#include <ctype.h>

#define MAX 5005
int array[MAX];

//冒泡排序，有时真的很重要
//基本思想：比较相邻两个元素，若后面小于前一个元素，交换两个元素的
//值，如果一趟比较中无任何元素逆序，则停止。
//复杂度：O（N*N)
int bubble(int * ptr,int len)
{
    bool ok;
    for(int i=0;i<len-1;++i)
    {
        ok = 1;
        for(int j=len-1;j>i;--j)
        {
            if(ptr[j] < ptr[j-1])
            {
                int temp = ptr[j];
                ptr[j] = ptr[j-1];
                ptr[j-1] = temp;
                ok = 0;
            }
        }
        if(ok)
            return 0;
    }

    return 0;
}
int main()
{
    int i=0;

    int len ;
    while(scanf("%d",&array[i]) == 1)
    {
        if(array[i] == -1)
            break;
        ++i;
    }
    len = i;
    bubble(array,len);
    printf("new order is: ");
    for(int i=0;i<len;++i)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
