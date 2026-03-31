#include <iostream>
using namespace std;
main()
{
int num=123,*p=nullptr, *q=nullptr;
p = &num;
q = p;
cout<<"puntero Q"<<q<<endl;
cout<<"variable"<<num<<endl;
cout<<"Direccion de la variable"<<&num<<endl;
cout<<"contenido de la direccion"<<*&num<<endl;
cout<<"Direccion del puntero"<<p<<endl;
cout<<"Contenido de la direccion del ppuntero"<<*p<<endl;
