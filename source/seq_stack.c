/*
	Author: jefby
	Email : jef199006@gmail.com

	顺序栈实现
*/
#include <stdio.h>
#include <stdlib.h>

#define SMAX_SIZE 1024

typedef union opcode{
	int val;
	char op;
}opcode;
typedef struct myops
{
	opcode op;
	int flag;//如果为1，表示是opcode,否则是操作数
}myops;

typedef myops SElemType;
typedef struct {
	SElemType dat[SMAX_SIZE];
	int top;
}sqStack;

sqStack sqs;

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
	s->dat[++(s->top)] = val;
	return 0;
}
static int
popSqStack(sqStack *s,SElemType *val)
{
	if(isEmptyStack(s)){
		perror("popSqStack is empty\n");
		return -1;
	}
	val->flag = s->dat[s->top].flag;
	val->op = s->dat[s->top].op;
	--s->top;
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

		break;
	}
	return res;
}
/*
	计算后缀表达式
	1.遇到操作数压入栈中
	2.遇到运算符则将栈顶两元素弹出，用当前运算符求值，然后将结果压入栈中
	3.当表达式处理完，栈中的元素就是表达式的值
*/
void compute_op_post(myops *ptr,int len)
{
	int i=0;
	SElemType val1,val2;
	int res = 0;
	initSqStack(&sqs);//初始化栈
	for(i=0;i<len;++i)
	{
		if(ptr[i].flag == 0){//操作数,压栈
			pushSqStack(&sqs,ptr[i]);
		}else{//运算符，则弹出两个元素计算值，并将结果返回压栈
			if(!isEmptyStack(&sqs))
				popSqStack(&sqs,&val1);
			else{
				perror("compute_op_post stack is empty.\n");
				return;
			}
			if(!isEmptyStack(&sqs))
				popSqStack(&sqs,&val2);
			else{
				perror("compute_op_post stack is empty.\n");
				return;
			}
			val1.op.val = evaluation(val1.op.val,val2.op.val,ptr[i].op.op);
			val1.flag = 1;
			pushSqStack(&sqs,val1);//将结果压栈
		}
	}
	popSqStack(&sqs,&val1);
	printf("res=%d\n",val1.op.val);
}
int main()
{
	//int a[]={9,'+','(',3,'-',1,')','*',3,'+',10,'/',2};
	myops a[]={{10,0},{10,0},{'+',1}};
	int len = sizeof(a)/sizeof(a[0]);
	compute_op_post(a,len);
	getchar();
	return 0;
}


