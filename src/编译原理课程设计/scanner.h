#pragma once

using namespace std;

class Scanner {
private:
    int row;
    string token;
    Reader& reader;
public:
    Scanner(Reader& reader);
    bool hasNextLine();
    void scanLine(const string& str, string::size_type& index);
    void analysisLine();
    void out(int type, const string& word);
};

/*
 * 构造函数
 *
 */
Scanner::Scanner(Reader& reader) : reader(reader) {
    row = 1;
}

/*
 * 是否分析到文件尾
 * @return 布尔值
 *
 */
bool Scanner::hasNextLine() {
    return reader.hasNext();
}

/*
 * 扫描行信息
 * @param const string& 行字符串
 * @param string::size_type index 索引
 *
 */
void Scanner::scanLine(const string& str, string::size_type& index) {
    if (index >= str.size()) return;
    char ch = str[index++];
    if (ch == '.') {
        cout << "小数点前必须是数字，位置：" << index << endl;
        exit(0);
    }
    else if (isdigit(ch)) {
        token = "";
        while (isdigit(ch) || ch == '.') {
            token.push_back(ch);
            ch = str[index++];
        }
        --index;
        out(INT, token);
    }
    else {
        switch (ch) {
        case '+':
            out(ADD, "+");
            break;
        case '-':
            out(SUB, "-");
            break;
        case '*':
            out(MUL, "*");
            break;
        case '/':
            out(DIV, "/");
            break;
        case '(':
            out(LPR, "(");
            break;
        case ')':
            out(RPR, ")");
            break;
        case '#':
            out(SRP, "#");
            break;
        default:
            cout << "非法字符：“" << ch << "”，位置：" << index << endl;
            exit(0);
            break;
        }
    }
}

/*
 * 分析行
 *
 */
void Scanner::analysisLine() {
    string line = reader.getLine();
    string::size_type index = 0;
    cout << line << endl;
    while (index != line.size()) {
        while (isspace(line[index++]));
        this->scanLine(line, --index);
    }
    ++this->row;
}

/*
 * 输出信息
 * @param type 类型
 * @param const string& word 标识符
 *
 */
void Scanner::out(int type, const string& word) {
    /* 记录词法分析结果 */
    words.push_back(Word(type, word));

    /* 输出词法分析结果 */
    //cout << "(" << type << "," << word << ")" << endl;
};