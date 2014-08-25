/*
	utf-8编码
	Author: jefby
	Email : jef199006@gmail.com

	顺序栈实现，并且实现了带括号的四则运算
	错误检查和括号匹配判断

	测试数据：
	1.myops a[]={{'(',1},{10,0},{'+',1},{10,0},{')',1},{'*',1},{10,0}};输出200
	2.myops a[]={{'(',1},{10,0},{'+',1},{10,0},{'*',1},{10,0}};输错
*/
#include <stdio.h>
#include <stdlib.h>

//数据结构设计，顺序栈，最大可存储元素1024
#define SMAX_SIZE 1024

typedef union opcode{
	int val;
	char op;
}opcode;
typedef struct myops//用于存储
{
	opcode op;
	int flag;//如果为0，表示是操作数；否则是运算符
}myops;

typedef myops SElemType;
typedef struct {
	SElemType dat[SMAX_SIZE];
	int top;
}sqStack;


//定义的全局栈
static sqStack sqs;

static int 
initSqStack(sqStack * s)
{
	if(!s){
		printf("initSqStack param s is NULL\n");
		return -1;	
	}
	s->top = -1;
	return 0;
}
static   int 
isEmptyStack(sqStack *s)
{
	return (s->top == -1);
}
static  int
isFullStack(sqStack *s)
{
	return (s->top == SMAX_SIZE);
}
static int 
pushSqStack(sqStack *s,SElemType val)
{
	if(isFullStack(s)){
		perror("pushSqStack stack is full\n");
		return -1;
	}
	s->dat[(++s->top)]= val;
	return 0;
}
static int
popSqStack(sqStack *s,SElemType *val)
{
	if(isEmptyStack(s)){
		perror("popSqStack is empty\n");
		return -1;
	}
	*val = s->dat[s->top--];
	
	return 0;
}
static  SElemType 
topSqStack(sqStack *s)
{
	SElemType val = {-1,1};
	if(isEmptyStack(s)){
		perror("topSqStack is empty\n");
		return (val);
	}
	return s->dat[s->top];
}
//计算op1(opcode)op2的值
static  int 
evaluation(int op1,int op2,char opcode)
{
	int res = 0;
	switch(opcode){
		case '+':
			res = op1 + op2;
		break;
		case '-':
			res = op1 - op2;
		break;
		case '*':
			res = op1 * op2;
		break;
		case '/':
			res = op1 / op2;
		break;
		default:
			perror("%c is not insistanted\n",opcode);
		return -1;
	}
	return res;
}
//比较运算符op1和op2的优先级，如果op1<op2，返回值为1，否则为0
static int 
op_priority(char op1,char op2)
{
	if(((op1 == '+')||(op1=='-')) && ((op2 == '*')||(op2=='/')))
		return 1;
	return 0;
}
/*
 	将中缀表达式转换为后缀表达式
 	1) 如果遇到操作数，则直接输出。
	2) 如果遇到操作符，则检查栈顶元素优先级，如果其优先级不低于当前操作符（左括号除外），则弹出栈顶元素并输出。重复此过程直到栈顶元素优先级小于当前操作符或为左括号，或者栈为空。 然后将当前操作符压入栈中。
	3）如果遇到左括号，直接压入栈中。
	4) 如果遇到右括号，则将栈中元素弹出，直到遇到左括号为止。左括号只弹出栈而不输出。
	5) 表达式处理完毕，则将栈中元素依次弹出。
*/
static myops* 
convert_mid_to_post(myops *ptr,int len,int *return_len)
{
	int i=0,j=0;
	myops * res = (myops*)malloc(sizeof(myops)*len);
	SElemType val;
	int ok = 0;

	initSqStack(&sqs);
	for(i=0;i<len;++i){
		if(ptr[i].flag==0){//操作数
			res[j++] = ptr[i];
		}else{//运算符
			if(ptr[i].op.op =='(')//左括号：直接进栈
				pushSqStack(&sqs,ptr[i]);
			else if(ptr[i].op.op == ')'){//右括号：运算符出栈，直至碰见'('或栈为空
				while(!isEmptyStack(&sqs)){
					popSqStack(&sqs,&val);
					if(val.op.op == '(' ){
						ok = 1;				
						break;
					}
					res[j++]=val;
				}
				if(!ok)//右括号没有匹配到左括号
					goto fail;
			}else{//其他运算符
				if(isEmptyStack(&sqs)){//如果当前栈为空，直接压栈
					pushSqStack(&sqs,ptr[i]);
				}else{//非空，则取栈顶元素，如果栈顶的运算符优先级都不低于当前运算符，则弹栈
					val = topSqStack(&sqs);
					while(!isEmptyStack(&sqs) && val.op.op != '(' && !op_priority(val.op.op,ptr[i].op.op)){
						popSqStack(&sqs,&val);
						res[j++]=val;
						val = topSqStack(&sqs);
					}
					pushSqStack(&sqs,ptr[i]);
				}	
			}

		}
	}//for
	while(!isEmptyStack(&sqs)){
		popSqStack(&sqs,&val);
		if(val.flag == 1 && (val.op.op == '(' || val.op.op == ')'))
			goto fail;
		res[j++]=val;
	}
	if(return_len)
		*return_len = j;
	return res;
	fail:
		free(res);
		perror("convert_mid_to_post \'(\'&&\')\' is not compared\n");
		return NULL;

}
/*
	计算后缀表达式
	1.遇到操作数压入栈中
	2.遇到运算符则将栈顶两元素弹出，用当前运算符求值，然后将结果压入栈中
	3.当表达式处理完，栈中的元素就是表达式的值
*/
static void 
compute_op_post(myops *ptr,int len)
{
	int i=0;
	SElemType val1,val2;
	int res = 0;
	if(!ptr){
		perror("compute_op_post paramter ptr is NULL\n");
		return;
	}
	initSqStack(&sqs);//初始化栈
	for(i=0;i<len;++i)
	{
		if(ptr[i].flag == 0){//操作数,压栈
			pushSqStack(&sqs,ptr[i]);
		}else{//运算符，则弹出两个元素计算值，并将结果返回压栈
			if(!isEmptyStack(&sqs))
				popSqStack(&sqs,&val1);
			else
				goto empty;
			if(!isEmptyStack(&sqs))
				popSqStack(&sqs,&val2);
			else
				goto empty;
			val1.op.val = evaluation(val1.op.val,val2.op.val,ptr[i].op.op);//计算值
			val1.flag = 0;
			pushSqStack(&sqs,val1);//将结果压栈
		}
	}
	popSqStack(&sqs,&val1);
	printf("res=%d\n",val1.op.val);
	return;
	empty:
		perror("compute_op_post stack is empty.\n");
		return;
}
int 
main()
{
	//myops a[]={{'(',1},{10,0},{'+',1},{10,0},{')',1},{'*',1},{10,0}};
	myops a[]={{'(',1},{10,0},{'+',1},{10,0},{'*',1},{10,0}};
	myops * b = NULL;
	int rev = 0;
	int len = sizeof(a)/sizeof(a[0]);

	b = convert_mid_to_post(a,len,&rev);
	compute_op_post(b,rev);
	getchar();
	return 0;
}


