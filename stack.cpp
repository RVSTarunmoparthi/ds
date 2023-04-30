#define maxsize 20
#include<iostream>
using namespace std;
class stack
{
private:int a[maxsize];
       int top;
    public:stack()
      {
      top=-1;
  }
void gettop();    
void push(int element);
void pop();  
void isempty();
void isfull();
void display();
};
void stack::gettop()
{
if(top==-1)
cout<<"stack underflow"<<endl;
else
{
cout<<"address of top is:"<<top<<endl;
cout<<"element at the top"<<a[top]<<endl;
}
}
void stack::push(int element)
{
if(top==maxsize-1)
cout<<"stack overflow";
else
{
top++;
a[top]=element;
cout<<"element \t"<<element<<"\t is inserted"<<endl;
}
}
void stack::pop()
{
if(top==-1)
cout<<"stack underflow";
else
cout<<"deleted element is"<<a[top--]<<endl;
}
void stack::isempty()
{
if(top==-1)
cout<<"stack underflow";
else
cout<<"element in the top of the stack is"<<a[top];
}

void stack::isfull()
{
if(top==maxsize-1)
cout<<"stack overflow";
else
cout<<"elements in the top of the stack is"<<a[top];
}
void stack::display()
{
for(int i=top;i>=-1;i--)
{
cout<<a[i];
cout<<endl;
}
}
int main()
{
int num,ch;
stack s;

while(1)
{
cout<<"enter your choice \n";

      cout<<"1.push \t";
cout<<"2.pop \t";
cout<<"3.gettop \t";
cout<<"4.isempty \t";
cout<<"5.isfull \t";
cout<<"6.display \t";
cout<<"7.exit \t";
cin>>ch;
switch(ch)
{
case 1:
cout<<"enter the  element to be inserted";
cin>>num;
s.push(num);
break;
   case 2:
    s.pop();
    break;
   case 3:
    s.gettop();
    break;
case 4:
   s.isempty();
break;
case 5:
   s.isfull();
break;
case 6:
s.display();
break;
case 7:
      exit(0);
}
}

}

