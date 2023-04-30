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
		void infixtopostfixconv(char ch[]);
		int prec(char c);
};
int stack :: prec(char c)
{
	if(c=='^')
	return 3;
	else if(c=='/'||c=='*')
	return 2;
	else if(c=='+'||c=='-')
	return 1;
	else 
	return -1;
}
void stack ::infixtopostfixconv(char ch[])
{
	string result;
	for(int i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='#') break;
		else if((ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z')||(ch[i]>='0'&&ch[i]<='a'))
		result+=ch[i];
		else if(ch[i]=='(')
		push(ch[i]);
		else if(ch[i]==')')
		{
			while(sta[top]!='(')
			{
				result+=sta[top];
				pop();
			}
			pop();
		}
		else
		{
			while(top!=-1&&prec(ch[i])<=prec(sta[top]))
			{
				result+=sta[top];
				pop();
			}
			push(ch[i]);
		}
	}
	while(top!=-1)
	{
		result+=sta[top];
		pop();
	}
	cout<<"Result:"<<result;
}
void stack ::push(int element)
{
	if(top==maxsize-1)
	cout<<"stack overflow";
	else
	{
		top++;
		sta[top]=element;
	}
}
int stack :: pop()
{
	if(top==-1)
	cout<<"Stack underflow";
	else
	return sta[top--];
}
int main()
{
	stack s;
	char ch[50];
	cout<<"Enter the expression:(end it with '#')";
	cin>>ch;
	s.infixtopostfixconv(ch);
	return 0;
}
