#include<iostream>
using namespace std;
class circularqueue
{
	private:
		int arr[10],max,front,rear;
	public:
		circularqueue()
		{
			front=-1;
			rear=-1;
			max=10;
		}
		void getfront();
		void insert();
		void remove();
		void display();
};
void circularqueue :: getfront()
{
	int temp;
	if(front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		temp=(front+1)%max;
		cout<<"Front= "<<arr[temp]<<endl;
	}
}
void circularqueue :: insert()
{
	int ele;
	if((rear==max-1)&&(front==0)||(front==rear+1))
	{
		cout<<"Queue is full"<<endl;
	}
	else
	{
		cout<<"Enter the value to be inserted:"<<endl;
		cin>>ele;
		if(front==-1)
		{
			front=0;
		}
		rear = (rear+1)%max;
		arr[rear]=ele;
		cout<<ele<<"is inserted into the queue"<<endl;
	}
}
void circularqueue :: remove()
{
	if(front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		cout<<"Deleted value is "<<arr[front]<<endl;
		front=(front+1)%max;	
	}
}
void circularqueue :: display()
{
	int i;
	if(front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		cout<<"The elements in the circular queue are :"<<endl;
		for(i=front;i!=rear;i=(i+1)%max)
		{
			cout<<arr[i]<<" ";
		}
		cout<<arr[i]<<endl;
	}
}
int main()
{
	circularqueue cq;
	int ch1;
	char ch2;
	do
	{
		cout<<"Circular queue using arrays"<<endl;
		cout<<"1.Insert"<<endl;
		cout<<"2.Remove"<<endl;
		cout<<"3.Get front"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1: cq.insert();
			break;
			case 2: cq.remove();
			break;
			case 3: cq.getfront();
			break;
			case 4: cq.display();
			break;
			default: cout<<"Please select valid option"<<endl;
			break;
		}
		cout<<"Do you want to continue(Y/N):"<<endl;
		cin>>ch2;
	}
	while(ch2=='y'||ch2=='Y');
	return 0;
}
