#include <iostream>
using namespace std;
main()
{
    float x=1.4,*p,*q, y=1.1;
    p = &y;
    x = *p + x;
    q = p;
    *q = y*2;
    cout<<"*p= "<<*p<<endl;
    cout<<"*q= "<<*q<<endl;
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;
    p=&x;
    y=y+*p;
    x=y+x+*q;
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;
}