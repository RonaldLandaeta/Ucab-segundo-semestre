#include <iostream>
using namespace std;
void parenumber(int num)
{  int par=0,impar=0,rest=0;
    while (num!=0)
    {
        rest=num % 10;
        if (rest % 2 == 0)
            par += rest; 
        else
            impar += rest;
        num = num/10;
    }
    if (par == impar)
        cout<<"El numero es parejo la suma es"<<par;
    else
        cout<<"El numero no es parejo";
}
int main(){
    int num;
    cout<<"ingresa el num que quieras";
    cin>>num;
    parenumber(num);
}
int a;
int b;
int sumadetodo(int a, int b){
    int sucesiva = 0;
    int i=0;
    for(i=0; i< b; i++){
        sucesiva += a;
    }
    cout<<"el suma sucesiva da como resultado" << sucesiva;
}
int main(){
    cout<<"ingresa el num que quieras, solo 2";
    cin>>a>>b;
    sumadetodo(a,b);
}