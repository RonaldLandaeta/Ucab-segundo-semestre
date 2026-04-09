#include <iostream>
using namespace std;
struct list
{
    int data;
    list *next;
};
int main() {
    int x;
    list *P,*Q,*R,*S,*first;
    first = nullptr;
    P= new list;
    P->data=3;
    P->next=nullptr;
    first=P;
    Q = new list;
    Q->next=nullptr;
    first->next=Q;
    R = new list;
    R->data=20;
    R->next=nullptr;
    first->next->next=R;
    list *actual;
    actual=first;
    while (actual!=nullptr)
    {
        cout<<actual->data<<"->";
        actual=actual->next;
    }
cout<<"Null"<<endl;
}

//21 30 40 y 50


