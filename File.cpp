#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

char precede(char lopt,char ropt)
{   //��������ȼ��жϺ���
    switch(lopt)
    {
    case '+':
    case '-':
        if(ropt=='+'||ropt=='-'||ropt==')'||ropt=='#') return '>';
        else if(ropt=='*'||ropt=='/'||ropt=='%'||ropt=='('||ropt=='^'||ropt=='��'||ropt=='!') return '<';
    case '*':
    case '/':
    case '%':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt==')'||ropt=='#') return '>';
        else if(ropt=='('||ropt=='^'||ropt=='��'||ropt=='!') return '<';
    case '^':
    case '��':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='��'||ropt==')'||ropt=='#') return '>';
        else if(ropt=='('||ropt=='!') return '<';
    case '!':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='��'||ropt==')'||ropt=='!'||ropt=='#') return '>';
        else if(ropt=='(') return '<';
    case '(':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='('||ropt=='^'||ropt=='��'||ropt=='!') return '<';
        else if(ropt==')') return '=';
    case ')':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='��'||ropt==')'||ropt=='!'||ropt=='#') return '>';
    case '#':
        if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='%'||ropt=='^'||ropt=='��'||ropt=='!'||ropt=='(') return '<';
        else if(ropt=='#') return '=';
    }
}

bool isOperate(char opt)
{   //�ж��Ƿ�Ϊ�����
    if(opt=='+'||opt=='-'||opt=='*'||opt=='/'||opt=='%'||opt=='^'||opt=='('||opt==')'||opt=='#'||opt=='��'||opt=='!') return true;
    else return false;
}

double calculate(double x,char opt,double y=0)
{   //��Ԫ���㺯��
    switch(opt)
    {
    case '+':return x+y;
    case '-':return x-y;
    case '*':return x*y;
    case '/':return x/y;
    case '%':return int(x)%int(y);
    case '^':return pow(x,y);
    case '��':return pow(y,1.0/x);
    }
}

template<typename T>
T getTop(stack<T> &s)
{   //��ȡջ��Ԫ�ز���ջ
    T ch=s.top();
    s.pop();
    return ch;
}

double toNum(stack<char> &tmp)
{   //����ʱջת��Ϊdouble������
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
            if(!isOperate(c))  //�ж��Ƿ����������
            {
                optmp.push(c);  //����������ʱջ
                c=getchar();
            }
            else
            {   
                if(!optmp.empty()) opnd.push(toNum(optmp));
                switch(precede(optr.top(),c))  //�ж�������������ջ������������ȼ�
                {
                case '<':  //���ջ����������ȼ��ͣ����������ջ
                    optr.push(c);
                    c=getchar();
                    break;
                case '=':  //���ջ����������ȼ���ͬ��������������
                    optr.pop();
                    c=getchar();
                    break;
                case '>':  //���ջ����������ȼ��ߣ���������
                    x=getTop(opnd);
                    y=getTop(opnd);
                    opnd.push(calculate(y,getTop(optr),x));  //����������ջ
                    break;
                }
            }
            if(c=='='||c=='\n') c='#';
        }
        if(opnd.empty()) cout<<toNum(optmp)<<endl;
        else cout<<opnd.top()<<endl;  //���������
    }catch(...){
        cout<<"ERROR"<<endl;  //���������Ϣ
    }
    return 0;
}