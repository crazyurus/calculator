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
 * 构造函数
 *
 */
Reader::Reader() {}

Reader::Reader(const string filePath) {
    this->filePath = filePath;
}

/*
 * 打开文件
 * @return 是否成功打开
 */
bool Reader::openFile() {
    if (!ifs.is_open()) ifs.open(filePath.c_str(), ios::in);
    return ifs.good();
}

/*
 * 判断是否到文件尾部
 * @return 布尔值
 */
bool Reader::hasNext() {
    return !ifs.fail();
}

/*
 * 获取当前行内容
 * @return 内容
 */
string Reader::getLine() {
    string str;
    getline(ifs, str);
    return str;
}

/*
 * 析构函数
 *
 */
Reader::~Reader() {
    ifs.close();
}