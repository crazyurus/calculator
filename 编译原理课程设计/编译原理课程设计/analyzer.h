#pragma once

using namespace std;

/*
算术表达式文法
<无符号整数> ∷＝ <数字>{<数字>}
<标志符> ∷＝ <字母>{<字母>｜<数字>}
<表达式> ∷＝ [＋｜－]<项>{<加法运算符><项>}
<项> ∷＝ <因子>{<乘法运算符><因子>}
<因子> ∷＝ <标志符>｜<无符号整数>｜'（'<表达式>'）'
<加法运算符> ∷＝ ＋｜－
<乘法运算符> ∷＝ ＊｜／

产生式
S′→ S
S → E
E → E+T|E-T|T
T → T*F|T/F|F
F → (E)|+i|-i|i
*/

class Analyzer {
private:
    vector<Word>::size_type index;
    stack<int> state;  //状态栈
    stack<Word> symbol;  //符号栈
    Word& readWord();
    int readState();
    SLR& compare(int state, Word& input);
    void shift(int state, Word& input);
    void reduce(int index);
    double calculate(double num1, const string& operate, double num2);
    void error(const string& msg, vector<Word>::size_type index = 0);
    void pop();
public:
    Analyzer();
    void show();
    void analySyntax();
};

/*
 * 构造函数
 *
 */
Analyzer::Analyzer() : state(), symbol() {
    index = 0;
}

/*
 * 读取符号
 * @return 当前符号
 *
 */
Word& Analyzer::readWord() {
    return words[index];
}

/*
 * 读取状态
 * @return 当前状态
 *
 */
int Analyzer::readState() {
    return state.top();
}

/*
 * 语法分析
 *
 */
void Analyzer::analySyntax() {
    state.push(0);
    symbol.push(Word(SRP, "#"));  //初始化符号栈和状态栈
    while (true) {
        int cur_state = readState();
        Word cur_input = readWord();
        SLR result = compare(cur_state, cur_input);
        switch (result.getType()) {
        case 0:
            error("语法错误！在表达式中“" + cur_input.getWord() + "”附近，位置：", index);
            break;
        case 1:
            //移进
            shift(result.getValue(), cur_input);
            break;
        case 2:
            //归约
            reduce(result.getValue());
        case 3:
            //GOTO
            state.push(compare(state.top(), symbol.top()).getValue());
            break;
        case 4:
            //ACCEPT
            cout << symbol.top().getValue() << endl;
            return;
        default:
            break;
        }
    }
}


/*
 * 比较
 * @param int 状态
 * @param Word& 输入
 * @return 比较结果
 *
 */
SLR& Analyzer::compare(int state, Word& input) {
    return SLR_TABLE[state][input.getType()];
}

/*
 * 移进
 * @param int 状态
 * @param Word& 符号
 *
 */
void Analyzer::shift(int state, Word& input) {
    this->state.push(state);
    this->symbol.push(input);
    ++index;
}

/*
 * 归约
 * @param int 产生式编号
 *
 */
void Analyzer::reduce(int index) {
    switch (index) {
    // 右部长为1
    case 2:
    case 5:
    case 8:
    case 12:
        double num = symbol.top().getValue();
        this->pop();
        symbol.push(Word(LEFT_PART[index], num));
        break;
    // 右部长为2
    case 10:
    case 11:
        double num = symbol.top().getValue();
        this->pop();
        string s = symbol.top().getWord();
        if (s == "-") num = -num;
        this->pop();
        symbol.push(Word(LEFT_PART[index], num));
        break;
    // 括号
    case 9:
        this->pop();
        double num = symbol.top().getValue();
        this->pop();
        this->pop();
        symbol.push(Word(LEFT_PART[index], num));
        break;
    // 右部长为3
    case 3:
    case 4:
    case 6:
    case 7:
        double num1 = symbol.top().getValue();
        this->pop();
        string s = symbol.top().getWord();
        this->pop();
        double num2 = symbol.top().getValue();
        this->pop();
        symbol.push(Word(LEFT_PART[index], calculate(num2, s, num1)));
        break;
    default:
        break;
    }
}

/*
 * 计算
 * @param double 操作数1
 * @param const string& 运算符
 * @param double 操作数2
 * @return 计算结果
 *
 */
double Analyzer::calculate(double num1, const string& operate, double num2) {
    switch (operate[0]) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0) error("除数不能为0！");
        return num1 / num2;
    default:
        return 0;
    }
}

/*
 * 显示错误信息
 * #param const string& 错误信息
 * @param vector<Word>::size_type 位置
 *
 */
void Analyzer::error(const string& msg, vector<Word>::size_type index) {
    if (index == 0) cout << msg << endl;
    else cout << msg << (index + 1) << endl;
    exit(0);
}

/*
 * 出栈
 *
 */
void Analyzer::pop() {
    symbol.pop();
    state.pop();
}

/*
 * 显示文法
 *
 */
void Analyzer::show() {
    cout << "该课程设计文法为：" << endl;
    cout << "S′→ S" << endl;
    cout << "S → E" << endl;
    cout << "E → E + T | E - T | T" << endl;
    cout << "T → T*F | T / F | F" << endl;
    cout << "F →(E) | +i | -i | i" << endl;
}
