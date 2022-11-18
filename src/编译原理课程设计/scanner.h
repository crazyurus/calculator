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
 * ���캯��
 *
 */
Scanner::Scanner(Reader& reader) : reader(reader) {
    row = 1;
}

/*
 * �Ƿ�������ļ�β
 * @return ����ֵ
 *
 */
bool Scanner::hasNextLine() {
    return reader.hasNext();
}

/*
 * ɨ������Ϣ
 * @param const string& ���ַ���
 * @param string::size_type index ����
 *
 */
void Scanner::scanLine(const string& str, string::size_type& index) {
    if (index >= str.size()) return;
    char ch = str[index++];
    if (ch == '.') {
        cout << "С����ǰ���������֣�λ�ã�" << index << endl;
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
            cout << "�Ƿ��ַ�����" << ch << "����λ�ã�" << index << endl;
            exit(0);
            break;
        }
    }
}

/*
 * ������
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
 * �����Ϣ
 * @param type ����
 * @param const string& word ��ʶ��
 *
 */
void Scanner::out(int type, const string& word) {
    /* ��¼�ʷ�������� */
    words.push_back(Word(type, word));

    /* ����ʷ�������� */
    //cout << "(" << type << "," << word << ")" << endl;
};