#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Numbers {
private:
    unsigned int ui;
    float f;
    const int order = sizeof(ui) * 8 - 1;

public:
    Numbers();
    ~Numbers();

    void setUi(const unsigned int num);
    void setF(const float num);
    unsigned int getUi() const;
    float getF() const;
    int getOrder() const;
    std::string getUiBits() const;
    std::string getFBIts() const;
    void mirror(const int index, const int count, bool isFloat);
};

#endif // NUMBER_H