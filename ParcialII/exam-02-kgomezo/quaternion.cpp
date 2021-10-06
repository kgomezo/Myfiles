// include any needed header
#include<iostream>

struct Quaternion {
    double a {0.0};
    double b {0.0};
    double c {0.0};
    double d {0.0};

    void print(void);

    Quaternion operator+(const Quaternion & q);
    Quaternion operator-(const Quaternion & q);
    Quaternion operator*(const Quaternion & q);
};
    
// declare here the Quaternion struct/class

int main(int argc, char **argv)
{
    Quaternion q1{1, 2, 3, 0}, q2{0, 2, -3.4, -1};

    Quaternion q3;
    q3 = q1 + q2;
    q3.print();
    q3 = q1 - q2;
    q3.print();
    q3 = q1 * q2;
    q3.print();

    return 0;
}

void Quaternion::print(void){
    std::cout << "( " << a << "," << b << "," << c << "," << d << ")"  <<"\n";
}

Quaternion Quaternion::operator+(const Quaternion & q){
    Quaternion result;
    result.a = a + q.a;
    result.b = b + q.b;
    result.c = c + q.c;
    result.d = d + q.d;

    return result;
}

Quaternion Quaternion::operator-(const Quaternion & q){
    Quaternion result;
    result.a = a - q.a;
    result.b = b - q.b;
    result.c = c - q.c;
    result.d = d - q.d;
    return result;
}
Quaternion Quaternion::operator*(const Quaternion & q){
    Quaternion result;
    result.a = (a*q.a - b*q.b - c*q.c - d*q.d);
    result.b = (a*q.b + b*q.a + c*q.d - d*q.c);
    result.c = (a*q.c - b*q.d + c*q.a + d*q.b);
    result.d = (a*q.d + b*q.c - c*q.b + d*q.a);
    return result;
}













// implement here the Quaternion struct/class
