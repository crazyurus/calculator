#include "stdafx.h"
#include "word.h"
#include "slr.h"
#include "declare.h"
#include "reader.h"
#include "scanner.h"
#include "analyzer.h"

using namespace std;

//������֧�ּӡ������ˡ��������š�������С�����㣬�����ȼ���ϵ
int main() {
    string filePath;
    cout << "�������ļ�·����";
    getline(cin, filePath);
    Reader r(filePath);
    if (!r.openFile()) {
        cout << "δ�ҵ����ļ�" << endl;
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