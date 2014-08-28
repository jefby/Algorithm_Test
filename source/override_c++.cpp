	/*
		阿里巴巴2014系统工程师笔试题目
		考察的是C++里面的函数覆盖、隐藏问题，基类中必须要有virtual才可以覆盖;
		对于继承类中和基类定义相同参数，名称的函数，调用时需要观察调用者的类型（基类还是继承类）
		
		输出结果是：100,50

	*/
	#include <iostream>
	using namespace std;


		class Base
     {
      public:
	      int Bar(char x) {return (int)(x);}
	      virtual int Bar(int x) {return(2*x);}
     };

       class Derived :public Base
     {
       public:
	        int Bar(char x) {return(int)(-x);}
	        int Bar(int x)  {return (x/2);}
     };
 
     void main(void)
     {
		Derived Obj;
		Base*pObj=&Obj;
		printf("%d,",pObj->Bar((char)(100)));
		printf("%d,",pObj->Bar(100));

		getchar();
     }
