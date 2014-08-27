/*
   Boyer-Moore字符串模式匹配算法实现

   Boyer-Moore算法
   KMP的匹配是从模式串的开头开始匹配的，而1977年，德克萨斯大学的Robert S. Boyer教授和J Strother Moore教授发明了一种新的字符串匹配算法：Boyer-Moore算法，简称BM算法。
   该算法从模式串的尾部开始匹配，且拥有在最坏情况下O(N)的时间复杂度。在实践中，比KMP算法的实际效能高。

    BM算法定义了两个规则：

   坏字符规则：当文本串中的某个字符跟模式串的某个字符不匹配时，我们称文本串中的这个失配字符为坏字符，此时模式串需要向右移动，移动的位数 = 坏字符在模式串中的位置 - 坏字符在模式串中最右出现的位置。
               此外，如果"坏字符"不包含在模式串之中，则最右出现位置为-1。
   好后缀规则：当字符失配时，后移位数 = 好后缀在模式串中的位置 - 好后缀在模式串上一次出现的位置，且如果好后缀在模式串中没有再次出现，则为-1。

   代码是参考自网址http://igm.univ-mlv.fr/~lecroq/string/node14.html#SECTION00140
   我添加了必要的宏定义和调用。
   Author:jefby
   Email :jef199006@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a)>(b)?(a):(b)
//坏字符原则
#define ASIZE 256
#define XSIZE 256
/*
   处理坏字符规则
*/
void preBmBc(char *x, int m, int bmBc[]) {
   int i;
   //初始化bmBc数组的每个元素为m
   for (i = 0; i < ASIZE; ++i)
      bmBc[i] = m;
   for (i = 0; i < m - 1; ++i){
      bmBc[x[i]] = m - i - 1;
      printf("%c,%d;",x[i],bmBc[x[i]]);
   }
}
 
 
void suffixes(char *x, int m, int *suff) {
   int f, g, i;
 
   suff[m - 1] = m;
   g = m - 1;
   for (i = m - 2; i >= 0; --i) {
      if (i > g && suff[i + m - 1 - f] < i - g)
         suff[i] = suff[i + m - 1 - f];
      else {
         if (i < g)
            g = i;
         f = i;
         while (g >= 0 && x[g] == x[g + m - 1 - f])
            --g;
         suff[i] = f - g;
      }
   }
}
 
void preBmGs(char *x, int m, int bmGs[]) {
   int i, j, suff[XSIZE];
 
   suffixes(x, m, suff);
 
   for (i = 0; i < m; ++i)
      bmGs[i] = m;
   j = 0;
   for (i = m - 1; i >= 0; --i)
      if (suff[i] == i + 1)
         for (; j < m - 1 - i; ++j)
            if (bmGs[j] == m)
               bmGs[j] = m - 1 - i;
   for (i = 0; i <= m - 2; ++i)
      bmGs[m - 1 - suff[i]] = m - 1 - i;
}
/*
   Boyer-Moore implement
   @x : 匹配串字符指针
   @y : 母串字符指针
   @m : 匹配串长度
   @n : 母串长度
*/
 
void BM(char *x, int m, char *y, int n) {
   int i, j, bmGs[XSIZE], bmBc[ASIZE];
 
   /* Preprocessing */
   preBmGs(x, m, bmGs);
   preBmBc(x, m, bmBc);
 
   /* Searching */
   j = 0;
   while (j <= n - m) {
      for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i)
         ;
      if (i < 0) {
         printf("match index = %d\n",j);
         j += bmGs[0];
      }else
         j += MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
   }
}

int main()
{
   
   char *tx = "GCATCGCAGAGAGTATACAGTACG";
   char *pat= "GCAGAGAG";
   /*
   char *tx =  "AABAACAADAABAAABAA";
   char *pat =  "AABA";
   */
   int m = strlen(pat);
   int n = strlen(tx);
   BM(pat,m,tx,n);
   return 0;

}