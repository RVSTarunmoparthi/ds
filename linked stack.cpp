#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *link;
};
class linkedstack
{
	private:
		Node *top;
		public:
			linkedstack()
			{
				top = NULL;
			}
			Node* getnode();
			void gettop();
			void push();
			void pop();
			void display();
};
Node * linkedstack :: getnode ()
{
	Node *temp = new Node;
	temp->link = NULL;
	return temp;
}
void linkedstack :: gettop()
{
	if(top == NULL)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		cout<<"Top = "<<top->data<<endl;
	}
}
void linkedstack :: push()
{
	int ele;
	cout<<"Enter the value to be inserted :"<<endl;
	cin>>ele;
	Node *NewNode;
	NewNode = getnode();
	NewNode -> data=ele;
	NewNode -> link=top;
	top = NewNode;
	cout<<ele<<"is inserted into the stack"<<endl;
}
void linkedstack :: pop()
{
	if(top == NULL)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		Node *temp;
		temp = top;
		cout<<"Popped value ="<<temp->data<<endl;
		top = top -> link;
		delete temp;
	}
}
void linkedstack :: display()
{
	if(top == NULL)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		Node *temp;
		temp = top;
		cout<<"The stack elements are :" <<endl;
		while(temp->link != NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->link;
		}
		cout<<temp->data<<endl;
	}
}
int main()
{
	linkedstack ls;
	int ch1;
	char ch2;
	do
	{
		cout<<"Stack operations using linked list"<<endl;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Get top"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1:ls.push();
			break;
			case 2:ls.pop();
			break;
			case 3:ls.gettop();
			break;
			case 4:ls.display();
			break;
			default : cout<<"Please select valid option"<<endl;
			break;
		}
		cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>ch2;
	}
	while(ch2=='y'||ch2=='Y');
	return 0;
}

