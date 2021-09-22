#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

char precede(char lopt,char ropt)
{   //运算符优先级判断函数
    switch(lopt)
    {
    case '+':
    case '-':
        if(ropt=='+'||ropt=='-'||ropt==')'||ropt=='#') return '>';
        else if(ropt=='*'||ropt=='/'||ropt=='%'||ropt=='('||ropt=='^'||ropt=='√'||ropt=='!') return '<';
    case '*':
    case '/':
    case '%':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt==')'||ropt=='#') return '>';
        else if(ropt=='('||ropt=='^'||ropt=='√'||ropt=='!') return '<';
    case '^':
    case '√':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='√'||ropt==')'||ropt=='#') return '>';
        else if(ropt=='('||ropt=='!') return '<';
    case '!':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='√'||ropt==')'||ropt=='!'||ropt=='#') return '>';
        else if(ropt=='(') return '<';
    case '(':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='('||ropt=='^'||ropt=='√'||ropt=='!') return '<';
        else if(ropt==')') return '=';
    case ')':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='√'||ropt==')'||ropt=='!'||ropt=='#') return '>';
    case '#':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='√'||ropt=='!'||ropt=='(') return '<';
        else if(ropt=='#') return '=';
    }
}

bool isOperate(char opt)
{   //判断是否为运算符
    if(opt=='+'||opt=='-'||opt=='*'||opt=='/'||opt=='%'||opt=='^'||opt=='('||opt==')'||opt=='#'||opt=='√'||opt=='!') return true;
    else return false;
}

double calculate(double x,char opt,double y=0)
{   //二元运算函数
    switch(opt)
    {
    case '+':return x+y;
    case '-':return x-y;
    case '*':return x*y;
    case '/':return x/y;
    case '%':return int(x)%int(y);
    case '^':return pow(x,y);
    case '√':return pow(y,1.0/x);
    }
}

template<typename T>
T getTop(stack<T> &s)
{   //获取栈顶元素并出栈
    T ch=s.top();
    s.pop();
    return ch;
}

double toNum(stack<char> &tmp)
{   //将临时栈转换为double型数字
    int k=1,j=0;
    double s=0;
    while(!tmp.empty())
    {
        char ch=getTop(tmp);
        if(ch=='.') j=k-1;
        else s+=pow(10,k++-1)*(ch-'0');
    }
    return s/pow(10,j);
}

int main()
{
    stack<char> optr,optmp;
    stack<double> opnd;
    double x,y;
    try
    {
        optr.push('#');
        char c=getchar();
        while(c!='#'||optr.top()!='#')
        {
            if(!isOperate(c))  //判断是否输入运算符
            {
                optmp.push(c);  //将数字入临时栈
                c=getchar();
            }
            else
            {   
                if(!optmp.empty()) opnd.push(toNum(optmp));
                switch(precede(optr.top(),c))  //判断输入的运算符与栈顶运算符的优先级
                {
                case '<':  //如果栈顶运算符优先级低，将运算符入栈
                    optr.push(c);
                    c=getchar();
                    break;
                case '=':  //如果栈顶运算符优先级相同，即遇到了括号
                    optr.pop();
                    c=getchar();
                    break;
                case '>':  //如果栈顶运算符优先级高，进行运算
                    x=getTop(opnd);
                    y=getTop(opnd);
                    opnd.push(calculate(y,getTop(optr),x));  //将运算结果入栈
                    break;
                }
            }
            if(c=='='||c=='\n') c='#';
        }
        if(opnd.empty()) cout<<toNum(optmp)<<endl;
        else cout<<opnd.top()<<endl;  //输出运算结果
    }catch(...){
        cout<<"ERROR"<<endl;  //输出错误信息
    }
    return 0;
}