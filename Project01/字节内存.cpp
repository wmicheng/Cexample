#include <iostream>
using namespace std;

int main()
{
    cout << "char: " << sizeof(char) << " 字节" << endl;
    cout << "int: " << sizeof(int) << " 字节" << endl;
    cout << "long: " << sizeof(long) << " 字节" << endl;
    cout << "long long: " << sizeof(long long) << " 字节" << endl;
    cout << "unsigned long long: " << sizeof(unsigned long long) << " 字节" << endl;
    cout << "float: " << sizeof(float) << " 字节" << endl;
    cout << "double: " << sizeof(double) << " 字节" << endl;

    return 0;
}