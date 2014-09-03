/*
对于每个N，先计算出所有可能组合情况的数目，然后根据所有的情况数目all，将[1,all]的值传给函数set，并根据每个数值的三进制（分隔符只有三种情况，如果是四种分隔符，那就是四进制了）表示为str赋值。

for (sp = 1; sp < n; ++sp)
{
    all *= 3;
}
while(all)
{
    set(str, n, --all);
......
Set函数的本质是将每一种分隔符的排列情况映射为一个整数（即1-all之间的数字），由于这些数字是连续的，而连续的整数转换为某个进制上的表示是不会有重复的，故遍历这个区间，就可以通过进制转换表示出所有的可能，
有多少个数被转换，就能输出多少种可能。正如Tutu_Lux所说：当元素有k种取值、总共n种情况时都可以用这一招！！

Calculate函数就是计算每一种set后的表达式值，采用了简单的自动机思想和简单的栈（数组）。值得说明的是，calculate程序程序的功能是计算中缀表达式的值，因此需要使用栈来保存操作数的值。
由于题目中操作符只有加和减，两者是同一优先级的，因此可以直接简化为一个从左向右的扫描过程，同时栈只需要保存两个操作数的值即可（所以stack数组的长度才是3，其中一个用于保存操作符）。
如果运算符不止一个优先级，那么栈就必须是变长了，而且需要一个独立的操作符栈，同时执行过程就会是中缀转后缀的算法了。因此这个函数是针对题目的特定优化和简化。
*/
#include <stdio.h>
 
/*
 * Initialize the string with 1 to 9 and seperated by whitespace
 * for len in range(3, 9+1):
 *    for each possibility of seperators:
 *        calculate the result, if it's zero, output
 */
 
int calculate(char input[], int n)
{
    //Use a simple state machine to interpret the input as an expression
    int stack[3] = {0}, sp = 0, i = 0;
    for(; i < n*2-1; ++i)
    {
        switch(input[i])
        {
        case ' ':
            stack[sp] = stack[sp]*10;
            break;
        case '+':
        case '-':
            if(sp == 0)
            {
                stack[1] = input[i];
                sp = 2;
            }else
            {
                stack[0] = stack[0]+(stack[1]=='-' ? -1 : 1)*stack[2];
                stack[1] = input[i];
                stack[2] = 0;
            }
            break;
        default: //digits
            stack[sp] += input[i]-'0';
            break;
        }
    }
    if (sp == 2)
    {
        stack[0] = stack[0]+(stack[1]=='-' ? -1 : 1)*stack[2];
    }
    return stack[0];
}
 
void set(char str[], int n, int num)
{
    //Transform num into base3 to generate the presentation of seperators
    int sp;
    char choice[] = " +-";
    for(sp = (n-1)*2-1; sp > 0; sp -=2)
    {
        str[sp] = choice[num%3];
        num /= 3;
    }
}
 
void result0()
{
    char str[18] = "1 2 3 4 5 6 7 8 9";
    int n, sp, all;
    for (n = 3; n <= 9; ++n)  // 3-9
    {
        all = 1;
        for (sp = 1; sp < n; ++sp) //Count the num of possibilities on 1-n
        {
            all *= 3;
        }
        while(all)
        {
            set(str, n, --all);
            if (calculate(str, n) == 0)
            {
                str[n*2-1] = '\0';
                printf("%s = 0\n", str);
            }
        }
    }
}
 
int main()
{
    result0();
    return 0;
}