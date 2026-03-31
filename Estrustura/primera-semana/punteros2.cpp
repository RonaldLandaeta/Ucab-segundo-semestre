#include <iostream>
using namespace std;
main()
{
    float a=2.5, b=3.7;
    float *ptr1, *ptr2;
    ptr1 = &a;
    ptr2 = &b;
    *ptr1 = *ptr1 * 2;
    *ptr2 = *ptr2 + *ptr1;
    cout<<"Valor de a: "<<a<<endl;
    cout<<"Valor de b: "<<b<<endl;
    float c=a+b;
    float *ptr3 = &c;
    *ptr3 = *ptr3 * 3;
    cout<<"valor final de a"<<a<<endl;//5.0
    cout<<"valor final de b"<<b<<endl;//8.7
    cout<<"valor final de c"<<c<<endl;//41.1

}