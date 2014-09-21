#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int myatoi(const char *str) {
    const char *s;
    char c;
    unsigned int acc, cutoff;
    int neg, any, cutlim;

    if(str == NULL)
        return 0;
    s = str;
    // 跳过前导的空格和制表符
    do {
        c = *s++;
    } while (c == ' ' || c == '\t');
    // 判断符号
    if (c == '-') {
        neg = 1;
        c = *s++;
    }else {
        neg = 0;
        if (c == '+') {
            c = *s++;
        }
    }

    // 分正负计算边界值
    cutoff = neg ? (unsigned int)-(INT_MAX + INT_MIN)+INT_MAX : INT_MAX;
    // 边界值的个位
    cutlim = cutoff % 10;
    // 计算过程中乘10前的结果的边界值
    cutoff /= 10;
    acc = any = 0;
    for ( ; ; c = *s++) {
        if (c >= '0' && c <= '9') {
            c -= '0';
        }else{
            // 如果不允许数字后出现非数字字符，如"123abc"
            errno = EINVAL;
            break;
        }
        if (acc > cutoff || (acc == cutoff && c > cutlim)) {
            any = -1;
            break;
        }
        else {
            any = 1;
            acc *= 10;
            acc += c;
        }
    }

    if (any < 0) {
        errno = ERANGE;
        acc = neg ? INT_MIN : INT_MAX;
    }
    else if (any == 0) {
        errno = EINVAL;
    }
    else if (neg) {
        acc = -acc;
    }
    return (int)acc;
}

int main()
{
    char str[100];
    int result;
    printf("please input a string to convert int\n");
    scanf("%s",&str);
    result = myatoi(str);
    printf("\n%d",result);
    return 0;
}