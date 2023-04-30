#include<iostream>
using namespace std;
class stackarray
{
	private:
		int arr[20],max,top;
	public:
		stackarray()
		{
			top=-1;
			max=10;
		}
		void gettop();
		void push();
		void pop();
		void display();
};
void stackarray :: gettop()
{
	if(top == -1)
	{
		cout<<"stack underflow"<<endl;
	}
	else
	{
		cout<<"top = "<<arr[top]<<endl;
	}
}
void stackarray :: push()
{
	int ele;
	if(top == max-1)
	{
		cout<<"stack overflow"<<endl;
	}
	else
	{
		cout<<"Enter the value to be pushed :"<<endl;
		cin>>ele;
		top++;
		arr[top]=ele;
		cout<<ele<<" is pushed into the stack"<<endl;
	}
}
void stackarray :: pop()
{
	if(top==-1)
	{
		cout<<"stack underflow"<<endl;
	}
	else
	{
	
		cout<<"The popped element is : "<<arr[top]<<endl;
		top--;
	}
}
void stackarray :: display()
{
	int i;
	cout<<"the stack elements are : "<<endl;
	for(i=top;i>=0;i--)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	stackarray sa;
	int ch1;
	char ch2;
	do
	{
		cout<<"stack operations using arrays"<<endl;
		cout<<"1.push"<<endl;
		cout<<"2.pop"<<endl;
		cout<<"3.get top"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1 : sa.push();
			break;
			case 2 : sa.pop();
			break;
			case 3 : sa.gettop();
			break;
			case 4 : sa.display();
			break;
			default : cout<<"Please select valid option : "<<endl;
		}
		cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>ch2;
	}
	while(ch2=='y'||ch2=='Y');
	return 0;
}
