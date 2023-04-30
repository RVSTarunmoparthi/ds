#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *link;
};
class CircularLinkedList
{
	public :
		Node *head;
		CircularLinkedList()
		{
			head = NULL;
		}
		Node* getnode();
		void insertatbegin(int val);
		void insertatend(int val);
		void insertatpos(int pos,int val);
		void insertafterval(int val1, int val2);
		void insertbeforeval(int val1, int val2);
		void deleteatbegin();
		void deleteatend();
		void deleteatpos(int pos);
		void deleteval(int val);
		void display();
		int getsize();
};
Node* CircularLinkedList :: getnode()
{

	Node *temp = new Node;
	temp -> link = NULL;
	return temp;
}
void CircularLinkedList :: insertatbegin(int val)
{
	Node *NewNode,*temp;
	NewNode = getnode();
	NewNode -> data = val;
	if(head == NULL)
	{
		NewNode -> link = NewNode;
		head = NewNode;
	}
	else
	{
		temp = head;
		while(temp -> link != head)
		{
			temp = temp -> link;
		}
		temp -> link = NewNode;
		head = NewNode;
	}
}
void CircularLinkedList :: insertatend(int val)
{
	Node *NewNode,*temp;
	NewNode = getnode();
	NewNode -> data = val;
	if(head == NULL)
	{
		head = NewNode;
	}
	else
	{
		temp = head;
		while(temp -> link != head)
		{
			temp = temp -> link;
		}
		temp -> link = NewNode;
		NewNode -> link = head;
	}
}
void CircularLinkedList :: insertatpos(int pos,int val)
{
	Node *NewNode,*temp;
	int count = 0;
	NewNode = getnode();
	temp = head;
	while(count<pos-1)
	{
		temp = temp -> link;
		count++;
	}
	NewNode -> link = temp ->link;
	temp -> link = NewNode;
	NewNode -> data = val;
}
void CircularLinkedList :: insertafterval(int val1,int val2)
{
	Node *NewNode,*temp;
	NewNode = getnode();
	temp = head;
	while(temp -> data != val1)
	{
		temp = temp -> link;
	}
	NewNode -> link = temp ->link;
	temp -> link = NewNode;
	NewNode -> data = val2;
}
void CircularLinkedList :: insertbeforeval(int val1,int val2)
{
	Node *NewNode,*temp1,*temp2;
	NewNode = getnode();
	temp2 = head;
	while(temp2 -> data != val1)
	{
		temp1 = temp2;
		temp2 = temp2 -> link;
	}
	temp1 -> link = NewNode;
	NewNode -> link = temp2;
	NewNode -> data  = val2;
}
void CircularLinkedList :: deleteatbegin()
{
	Node *temp1,*temp2;
	if(head == NULL)
	{
		cout<<"Linked List is Empty"<<endl;
	}
	else if(head -> link == head)
	{
		delete head;
		head = NULL;
	}
	else
	{
		temp1 = head;
		while(temp1 -> link != head)
		{
			temp1 = temp1 -> link;
		}
		temp2 = head;
		head = head -> link;
		temp1 -> link = head;
		delete temp2;
	}
}
void CircularLinkedList :: deleteatend()
{
	if(head == NULL)
	{
		cout<<"Linked List is Empty"<<endl;
	}
	else if(head -> link == head)
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node *temp1,*temp2;
		temp2 = head;
		while(temp2 -> link != head)
		{
			temp1 = temp2;
			temp2 = temp2 -> link;
		}
		temp1 -> link = head;
		delete temp2;
	}
}
void CircularLinkedList :: deleteatpos(int pos)
{
	Node *temp1,*temp2;
	int count = 0;
	temp2 = head;
	while(count<pos)
	{
		temp1 = temp2;
		temp2 = temp2 -> link;
		count++;
	}
	temp1 -> link = temp2 ->link;
	delete temp2;
}
void CircularLinkedList :: deleteval(int val)
{
	Node *temp1,*temp2;
	if(head -> data == val)
	{
		temp2 = head;
		while(temp2 -> link != head)
		{
			temp2 = temp2 -> link;
		}
		temp1 = head;
		head = head -> link;
		temp2 -> link = head -> link;
		delete temp1;
	}
	else
	{
		temp2 = head;
		while(temp2 -> data != val)
		{
			temp1 = temp2;
			temp2 = temp2 -> link;
		}
		temp1 -> link = temp2 -> link;
		delete temp2;
	}
}
void CircularLinkedList :: display()
{
	if(head == NULL)
	{
		cout<<"Linked List is Empty"<<endl;
	}
	else
	{
		Node *temp;
		cout<<"The Linked List is:"<<endl;
		temp = head;
		do
		{
			cout<<temp -> data<<" -> ";
			temp = temp -> link;
		}while(temp != head);
		cout<<temp->data<<endl;
	}
}
int CircularLinkedList :: getsize()
{
	Node *temp;
	int size=0;
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		temp = head;
		do
		{
			temp = temp -> link;
			size++;
		}while(temp != head);
		return size;
	}
}
int main()
{
	CircularLinkedList cll;
	int ch1,val,val1,val2,pos;
	char ch2;
	do
	{
		cout<<"Circular Linked List Operations"<<endl;
		cout<<"1.Insert a Value at Beginning"<<endl;
		cout<<"2.Insert a Value at End"<<endl;
		cout<<"3.Insert a Value at a given Position"<<endl;
		cout<<"4.Insert a Value after a given Value"<<endl;
		cout<<"5.Insert a Value before a given Value"<<endl;
		cout<<"6.Delete a Value at Beginning"<<endl;
		cout<<"7.Delete a Value at End"<<endl;
		cout<<"8.Delete a Value at a given Position"<<endl;
		cout<<"9.Delete a given Value"<<endl;
		cout<<"10.Display Linked List"<<endl;
		cout<<"11.Find the Size of Linked List"<<endl;
		cout<<"Enter your Choice:"<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1: cout<<"Enter the Value to be Inserted:"<<endl;
				cin>>val;
				cll.insertatbegin(val);
				break;
			case 2: cout<<"Enter the Value to be Inserted:"<<endl;
				cin>>val;
				cll.insertatend(val);
				break;
			case 3: cout<<"Enter the Position:"<<endl;
				cin>>pos;
				cout<<"Enter the Value to be Inserted:"<<endl;
				cin>>val;
				cll.insertatpos(pos,val);
				break;
			case 4: cout<<"Enter the Value after which Value to be Inserted:"<<endl;
				cin>>val1;
				cout<<"Enter the Value to be Inserted:"<<endl;
				cin>>val2;
				cll.insertafterval(val1,val2);
				break;
			case 5: cout<<"Enter the Value before which Value to be Inserted:"<<endl;
				cin>>val1;
				cout<<"Enter the Value to be Inserted:"<<endl;
				cin>>val2;
				cll.insertbeforeval(val1,val2);
				break;
			case 6: cll.deleteatbegin();
				break;
			case 7: cll.deleteatend();
				break;
			case 8: cout<<"Enter the Position of the Value to be Deleted:"<<endl;
				cin>>pos;
				cll.deleteatpos(pos);
				break;
			case 9: cout<<"Enter the Value to be Deleted:"<<endl;
				cin>>val;
				cll.deleteval(val);
				break;
			case 10: cll.display();
				 break;
			case 11: cout<<"Size of Linked List = "<<cll.getsize()<<endl;
				 break;
			default: cout<<"Please select a valid Option"<<endl;
				break;
		}
		cout<<"Do you want to Continue(Y/N)?"<<endl;
		cin>>ch2;
	}while(ch2 == 'Y' || ch2 == 'y');
	return 0;
}
