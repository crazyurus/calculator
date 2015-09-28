#pragma once

using namespace std;

class Word {
private:
    int type;
    string word;
    double value;
public:
    Word();
    Word(int type, string word);
    Word(int type, double value);
    int getType();
    void setType(int type);
    string getWord();
    void setWord(string word);
    double getValue();
    void setValue(double value);
};

Word::Word() {}

Word::Word(int type, string word) {
    setType(type);
    setWord(word);
}

Word::Word(int type, double value) {
    setType(type);
    setValue(value);
}

int Word::getType() {
    return type;
}

void Word::setType(int type) {
    this->type = type;
}

string Word::getWord() {
    return word;
}

void Word::setWord(string word) {
    this->word = word;
    if (isdigit(word[0])) this->value = atof(word.c_str());
}

double Word::getValue() {
    return this->value;
}

void Word::setValue(double value) {
    this->value = value;
}