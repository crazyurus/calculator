#pragma once

class Reader {
private:
    string filePath;
    ifstream ifs;
public:
    Reader();
    Reader(const string filePath);
    bool openFile();
    bool hasNext();
    string getLine();
    ~Reader();
};

/*
 * ���캯��
 *
 */
Reader::Reader() {}

Reader::Reader(const string filePath) {
    this->filePath = filePath;
}

/*
 * ���ļ�
 * @return �Ƿ�ɹ���
 */
bool Reader::openFile() {
    if (!ifs.is_open()) ifs.open(filePath.c_str(), ios::in);
    return ifs.good();
}

/*
 * �ж��Ƿ��ļ�β��
 * @return ����ֵ
 */
bool Reader::hasNext() {
    return !ifs.fail();
}

/*
 * ��ȡ��ǰ������
 * @return ����
 */
string Reader::getLine() {
    string str;
    getline(ifs, str);
    return str;
}

/*
 * ��������
 *
 */
Reader::~Reader() {
    ifs.close();
}