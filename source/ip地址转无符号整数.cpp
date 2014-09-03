/*

	源码摘自http://www.ahathinking.com/archives/209.html#more-209 ,
	修改了对一些特例情况的处理，现在基本完善了！

*/
#include <iostream>
#include <string>
using namespace std;
 
#define IPLEN 16  // 设输入ip地址长度不超过16
 
enum ERR_STATE
{
    SUCCESS = 0,
    NULL_POINTER,
    OVER_BOUNDARY,
    INVALID_CHAR,
    INVALID_FORM
};
char * ERR_Strings[5] = {
    "Success!",              // SUCCESS
    "Null pointer!",         // NULL_POINTER
    "Over boundary digits!", // OVER_BOUNDARY
    "Invalid char!",         // INVALID_CHAR
    "Invalid form!"          // INVALID_FORM
};
 
/* ip to unint
 * 一般返回一个int作为errorCode，真正的返回值放在参数里
 * para: ip,ip字符串； result，计算结果
 * return: ERROR & SUCCESS
 */
int ipToUnint(char * ip, unsigned int & result)
{
    if(NULL == ip)
    {
        return NULL_POINTER;
    }
 
    unsigned int digit = 0;  // 记录ip地址4个整数
    int dotNum = 0;    // num of dot
	int valueNum = 0;
    char input = 0;
 
    for(int ipIdx = 0; ; ++ipIdx)
    {
        input = ip[ipIdx];
        if(input >= '0' && input <= '9')   // 数字
        {
          
            digit = 10 * digit + (input - '0');
            if(digit > 255 || digit < 0)   // 数字非法或长度过长
            {
                return OVER_BOUNDARY;
            }
        }else if(input == '.')       // 遇点，合并部分结果
        {
            ++ dotNum;
			if(digit/100 || digit /10 || digit)
				++valueNum;
			if( dotNum > valueNum){
				return INVALID_FORM;
			}else // 合并
            {
                result = (result<<8) | digit;
                digit = 0;
            }

        }else if(input == '\0')    // 结束符，检查点数，返回结果
        {
            if(dotNum != 3)
            {
                return INVALID_FORM;
            }else
            {
                result = (result<<8) + digit;
                return SUCCESS;
            }
        }else  // 非法输入
        {
            return INVALID_CHAR;
        }
    }
}
 
void main()
{
    char ipStr[IPLEN] = {0};
 
    string input = "";
    cin>>input;
    sscanf(input.c_str(), "%15s", ipStr);
 
    unsigned int result = 0;
    int state = ipToUnint(ipStr, result);
    if(state == SUCCESS)
    {
        printf("result: 0x%x\n", result);
    }else
    {
        printf("%s\n",ERR_Strings[state]);
    }
	fflush(stdin);
	getchar();
}