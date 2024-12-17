#include <iostream>
using namespace std;

class IP {
public:
    IP(int num1, int num2, int num3, int num4, int num5);
    int getNum1() const;
    int getNum2() const;
    int getNum3() const;
    int getNum4() const;
    int getNum5() const;  
    void setNum1(int);
    void setNum2(int);
    void setNum3(int);
    void setNum4(int);
    void setNum5(int);  
    void imprimir() const;

private:
    int num1, num2, num3, num4, num5;
};
