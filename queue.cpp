#include<iostream>
using namespace std;
class queuearray
{
	private:
		int arr[20],max,front,rear;
	public:
		queuearray()
		{
			front=rear=-1;
			max=10;
		}
		void getfront();
		void insert();
		void remove();
		void display();
};
void queuearray :: getfront()
{
	if(rear == front)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		cout<<"front = "<<arr[front]<<endl;
	}
}
void queuearray :: insert()
{
	int ele;
	if(rear==max-1)
	{
		cout<<"Queue is full"<<endl;
	}
	else
	{
		cout<<"Enter the value to be inserted :"<<endl;
		cin>>ele;
		rear++;
		arr[rear]=ele;
		cout<<ele<<" is inserted into the queue"<<endl;
	}
}
void queuearray :: remove()
{
	if(rear==front)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		front++;
		cout<<"The deleted element is : "<<arr[front]<<endl;
	}
}
void queuearray :: display()
{
	int i;
	cout<<"the queue elements are : "<<endl;
	for(i=front+1;i<=rear;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	queuearray qa;
	int ch1;
	char ch2;
	do
	{
		cout<<"Queue operations using arrays"<<endl;
		cout<<"1.Insert"<<endl;
		cout<<"2.Delete"<<endl;
		cout<<"3.Get front"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1 : qa.insert();
			break;
			case 2 : qa.remove();
			break;
			case 3 : qa.getfront();
			break;
			case 4 : qa.display();
			break;
			default : cout<<"Please select valid option : "<<endl;
		}
		cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>ch2;
	}
	while(ch2=='y'||ch2=='Y');
	return 0;
}
