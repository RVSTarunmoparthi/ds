#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *link;
};
class linkedqueue
{
	private:
		Node*front,*rear;
	public:
		linkedqueue()
		{
			front = NULL;
			rear = NULL;
		}
		Node*getnode();
		void getfront();
		void insert();
		void remove();
		void display();
};
Node * linkedqueue :: getnode()
{
	Node*temp=new Node;
	temp->link=NULL;
	return temp;
}
void linkedqueue :: getfront()
{
	if(front==NULL)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		cout<<"Front="<<front->data<<endl;
	}
}
void linkedqueue :: insert()
{
	int ele;
	cout<<"Enter the value to be inserted:"<<endl;
	cin>>ele;
	Node*NewNode;
	NewNode = getnode();
	NewNode -> data = ele;
	if(rear == NULL)
	{
		front = NewNode;
		rear = NewNode;
	}
	else
	{
		rear -> link = NewNode;
		rear = NewNode;
	}
	cout<<ele<<"is inserted into the queue"<<endl;
}
void linkedqueue :: remove()
{
	if(front == NULL)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		Node *temp;
		temp=front;
		cout<<"Deleted value ="<<temp->data<<endl;
		front = front -> link;
		delete temp;
	}
}
void linkedqueue :: display()
{
	if(front == NULL)
	{
		cout<<"Queue is empty"<<endl;
    }
    else
    {
    	Node *temp;
    	temp=front;	
		cout<<"The queue elements are :"<<endl;
		while(temp->link != NULL)
		{
			cout<<temp->data<<"\t";
			temp = temp->link;
		}
		cout<<temp->data<<endl;
	}
}
int main()
{
	linkedqueue lq;
	int ch1;
	char ch2;
	do
	{
		cout<<"Queue operations using linked list"<<endl;
		cout<<"1.Insert"<<endl;
		cout<<"2.Delete"<<endl;
		cout<<"3.Get front"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1: lq.insert();
			break;
			case 2:lq.remove();
			break;
			case 3:lq.getfront();
			break;
			case 4:lq.display();
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
