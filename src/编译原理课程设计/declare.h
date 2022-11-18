#pragma once

/* 标识符定义 */
enum Identifier {
    ADD,        // 加号、正号 +
    SUB,        // 减号、负号 -
    MUL,        // 乘号 *
    DIV,        // 除号 /
    LPR,        // 左括号 (
    RPR,        // 右括号 )
    INT,        // 整数
    SRP,        // 结束符 #
    S,
    E,
    T,
    F
};

/* 产生式左部 */
int LEFT_PART[] = { 0, 0, S, E, E, E, T, T, T, F, F, F, F };

/* 词法分析结果 */
vector<Word> words;

/* SLR(1)分析表 */
// 定义type：空-0 S-1 r-2 GOTO-3 acc-4
SLR SLR_TABLE[21][12] = {
    SLR(1, 6), SLR(1, 7), SLR(0, 0), SLR(0, 0), SLR(1, 5), SLR(0, 0), 
    SLR(1, 8), SLR(0, 0), SLR(3, 1), SLR(3, 2), SLR(3, 3), SLR(3, 4),
    //0
    SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), 
    SLR(0, 0), SLR(4, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //1
    SLR(1, 9), SLR(1,10), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    SLR(0, 0), SLR(2, 2), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //2
    SLR(2, 5), SLR(2, 5), SLR(1,11), SLR(1,12), SLR(0, 0), SLR(2, 5),
    SLR(0, 0), SLR(2, 5), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),    
    //3
    SLR(2, 8), SLR(2, 8), SLR(2, 8), SLR(2, 8), SLR(0, 0), SLR(2, 8),
    SLR(0, 0), SLR(2, 8), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //4
    SLR(1, 6), SLR(1, 7), SLR(0, 0), SLR(0, 0), SLR(1, 5), SLR(0, 0),
    SLR(1, 8), SLR(0, 0), SLR(0, 0), SLR(3,13), SLR(3, 3), SLR(3, 4),
    //5
    SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    SLR(1,14), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //6
    SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    SLR(1,15), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //7
    SLR(2,12), SLR(2,12), SLR(2,12), SLR(2,12), SLR(0, 0), SLR(2,12),
    SLR(0, 0), SLR(2,12), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //8
    SLR(1, 6), SLR(1, 7), SLR(0, 0), SLR(0, 0), SLR(1, 5), SLR(0, 0),
    SLR(1, 8), SLR(2, 2), SLR(0, 0), SLR(0, 0), SLR(3,16), SLR(3, 4),
    //9
    SLR(1, 6), SLR(1, 7), SLR(0, 0), SLR(0, 0), SLR(1, 5), SLR(0, 0),
    SLR(1, 8), SLR(2, 2), SLR(0, 0), SLR(0, 0), SLR(3,17), SLR(3, 4),
    //10
    SLR(1, 6), SLR(1, 7), SLR(0, 0), SLR(0, 0), SLR(1, 5), SLR(0, 0),
    SLR(1, 8), SLR(2, 2), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(3,18),
    //11
    SLR(1, 6), SLR(1, 7), SLR(0, 0), SLR(0, 0), SLR(1, 5), SLR(0, 0),
    SLR(1, 8), SLR(2, 2), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(3,19),
    //12
    SLR(1, 9), SLR(1,10), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(1,20),
    SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //13
    SLR(2,10), SLR(2,10), SLR(2,10), SLR(2,10), SLR(0, 0), SLR(2,10),
    SLR(0, 0), SLR(2,10), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //14
    SLR(2,11), SLR(2,11), SLR(2,11), SLR(2,11), SLR(0, 0), SLR(2,11),
    SLR(0, 0), SLR(2,11), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //15
    SLR(2, 3), SLR(2, 3), SLR(1,11), SLR(1,12), SLR(0, 0), SLR(2, 3),
    SLR(0, 0), SLR(2, 3), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //16
    SLR(2, 4), SLR(2, 4), SLR(1,11), SLR(1,12), SLR(0, 0), SLR(2, 4),
    SLR(0, 0), SLR(2, 4), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //17
    SLR(2, 6), SLR(2, 6), SLR(2, 6), SLR(2, 6), SLR(0, 0), SLR(2, 6),
    SLR(0, 0), SLR(2, 6), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //18
    SLR(2, 7), SLR(2, 7), SLR(2, 7), SLR(2, 7), SLR(0, 0), SLR(2, 7),
    SLR(0, 0), SLR(2, 7), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0),
    //19
    SLR(2, 9), SLR(2, 9), SLR(2, 9), SLR(2, 9), SLR(0, 0), SLR(2, 9), 
    SLR(0, 0), SLR(2, 9), SLR(0, 0), SLR(0, 0), SLR(0, 0), SLR(0, 0)
    //20
};
