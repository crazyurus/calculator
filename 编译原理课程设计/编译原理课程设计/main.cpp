#include "stdafx.h"
#include "word.h"
#include "slr.h"
#include "declare.h"
#include "reader.h"
#include "scanner.h"
#include "analyzer.h"

using namespace std;

//本程序支持加、减、乘、除、括号、负数、小数运算，有优先级关系
int main() {
    string filePath;
    cout << "请输入文件路径：";
    getline(cin, filePath);
    Reader r(filePath);
    if (!r.openFile()) {
        cout << "未找到此文件" << endl;
        exit(0);
    }
    Scanner s(r);
    while (s.hasNextLine()) {
        s.analysisLine();
    }
    s.out(SRP, "#");
    Analyzer a;
    a.show();
    a.analySyntax();
    system("Pause");
    return 0;
}