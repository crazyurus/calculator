#pragma once

using namespace std;

class SLR {
private:
    int type;
    int value;
public:
    SLR();
    SLR(int type, int value);
    int getType();
    void setType(int type);
    int getValue();
    void setValue(int value);
};

SLR::SLR() {}

SLR::SLR(int type, int value) {
    setType(type);
    setValue(value);
}

int SLR::getType() {
    return type;
}

void SLR::setType(int type) {
    this->type = type;
}

int SLR::getValue() {
    return this->value;
}

void SLR::setValue(int value) {
    this->value = value;
}