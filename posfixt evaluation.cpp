#include<iostream>
#include<string.h>
using namespace std;
const int maxsize=5;
class stack
{
	private:
		int sta[maxsize];
		int top;
	public:
		stack()
		{
			top=-1;
		}
		int pop();
		void push(int element);
		int postfixeval(char ch[]);
};
int stack :: postfixeval(char ch[])
{
	int temp;
	for(int i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='#') break;
		else if(isdigit (ch[i]))
		push(ch[i]-'0');
		else
		{
			int val1=pop();
			int val2=pop();
			switch(ch[i])
			{
				case '+':temp=val2+val1;
						 push(temp); break;
				case '-':temp=val2-val1;
						 push(temp);break;
				case '*':temp=val2*val1;
						 push(temp);break;
				case '/':temp=val2/val1;
						 push(temp);break;
			}
		}
	}
	return sta[top];
}
void stack :: push(int element)
{
	if(top==maxsize-1)
	cout<<"Stack overflow";
	else
	{
		top++;
		sta[top]=element;
		cout<<"element"<<element<<"inserted"<<endl;
	}
}
int stack :: pop()
{
	if(top==-1)
	cout<<"stack underflow";
	else
	return sta[top--];
}
int main()
{
	stack s;
	char ch[50];
	cout<<"Enter the expression:(end it with '#')";
	cin>>ch;
	cout<<"\n The result is:"<<s.postfixeval(ch);
	return 0;
}
