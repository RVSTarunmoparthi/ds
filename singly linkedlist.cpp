#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node*link;
};
class singlelinkedlist
{
	public:
		node*head;
		singlelinkedlist()
		{
			head=NULL;
		}
		node*getnode();
		void insertatbegin(int val);
		void insertatend(int val);
		void insertatpos(int pos,int val);
		void insertafterval(int val1,int val2);
		void insertbeforeval(int val1,int val2);
		void deleteatbegin();
		void deleteatend();
		void deleteatpos(int pos);
		void deleteval(int val);
		void display();
		int getsize();
};
node*singlelinkedlist::getnode()
{
	node*temp=new node;
	temp->link=NULL;
	return temp;
}
void singlelinkedlist::insertatbegin(int val)
{
	node *Newnode;
	Newnode=getnode();
	if(head==NULL)
	{
		head=Newnode;
	}
	else
	{
		Newnode->link=head;
		head=Newnode;
	}
	Newnode->data=val;
}
void singlelinkedlist::insertatend(int val)
{
	node*Newnode,*temp;
	Newnode=getnode();
	if(head==NULL)
	{
		head==Newnode;
	}
	else
	{
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=Newnode;
	}
	Newnode->data=val;
}
void singlelinkedlist::insertatpos(int pos,int val)
{
	node*Newnode,*temp;
	int count=0;
	Newnode=getnode();
	temp=head;
	while(count<pos-1)
	{
		temp=temp->link;
		count++;
	}
	Newnode->link=temp->link;
	temp->link=Newnode;
	Newnode->data=val;
}
void singlelinkedlist::insertafterval(int val1,int val2)
{
	node*Newnode,*temp;
	Newnode=getnode();
	temp=head;
	while(temp->data!=val1)
	{
		temp=temp->link;
	}
	Newnode->link=temp->link;
	temp->link=Newnode;
	Newnode->data=val2;
}
void singlelinkedlist::insertbeforeval(int val1,int val2)
{
	node*Newnode,*temp1,*temp2;
	Newnode=getnode();
	temp2=head;
	while(temp2->data!=val1)
	{
		temp1=temp2;
		temp2=temp2->link;
	}
	temp1->link=Newnode;
	Newnode->link=temp2;
	Newnode->data=val2;
}
void singlelinkedlist::deleteatbegin()
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else
	{
		node*temp;
		temp=head;
		head=head->link;
		delete temp;
	}
}
void singlelinkedlist::deleteatend()
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else
	{
		node*temp1,*temp2;
		temp2=head;
		while(temp2->link!=NULL)
		{
			temp1=temp2;
			temp2=temp2->link;
		}
		temp1->link=NULL;
		delete temp2;
	}	
}
void singlelinkedlist::deleteatpos(int pos)
{
	node*temp1,*temp2;
	int count=0;
	temp2=head;
	while(count<pos)
	{
		temp1 = temp2;
		temp2 = temp2->link;
		count++;
	}
	temp1->link=temp2->link;
	delete temp2;
}
void singlelinkedlist::deleteval(int val)
{
	node*temp1,*temp2;
	temp2=head;
	while(temp2->data!=val)
	{
		temp1=temp2;
		temp2=temp2->link;
	}
	temp1->link=temp2->link;
	delete temp2;
}
void singlelinkedlist::display()
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else
	{
		node*temp;
		cout<<"Linked list is :"<<endl;
		for(temp=head;temp->link!=NULL;temp=temp->link)
		{
			cout<<temp->data<<"->";
		}
		cout<<temp->data<<endl;
	}
}
int singlelinkedlist::getsize()
{
	node*temp;
	int size=0;
	for(temp=head;temp!=NULL;temp=temp->link)
	{
		size++;
	}
	return size;
}
int main()
{
	singlelinkedlist sl;
	int ch1,val1,val2,val,pos;
	char ch2;
	do
	{
		cout<<"Single linked operations"<<endl;
		cout<<"1.Insert a value at beginning"<<endl;
		cout<<"2.Insert a value at end"<<endl;
		cout<<"3.Insert a value at given position"<<endl;
		cout<<"4.Insert a value after a given position"<<endl;
		cout<<"5.Insert a value before a given position"<<endl;
		cout<<"6.Delete a value at beginning"<<endl;
		cout<<"7.Delete a value at end"<<endl;
		cout<<"8.Delete a value at a given position"<<endl;
		cout<<"9.Delete a given value"<<endl;
		cout<<"10.Display linked list"<<endl;
		cout<<"11.Find size of linked list"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1:cout<<"Enter the value to be inserted"<<endl;
			cin>>val;
			sl.insertatbegin(val);
			break;
			case 2:cout<<"Enter the value to be inserted"<<endl;
			cin>>val;
			sl.insertatend(val);
			break;
			case 3:cout<<"Enter the position :"<<endl;
			cin>>pos;
			cout<<"Enter the value to be inserted"<<endl;
			cin>>val;
			sl.insertatpos(pos,val);
			break;
			case 4:cout<<"Enter the value after which value to be inserted :"<<endl;
			cin>>val1;
			cout<<"Enter the value to be inserted"<<endl;
			cin>>val2;
			sl.insertafterval(val1,val2);
			break;
			case 5: cout<<"Enter the value before which value to be inserted: "<<endl;
			cin>>val1;
			cout<<"Enter the value to be inserted"<<endl;
			cin>>val2;
			sl.insertbeforeval(val1,val2);
			break;
			case 6: sl.deleteatbegin();
			break;
			case 7: sl.deleteatend();
			break;
			case 8: cout<<"Enter the position of the value to be deleted:"<<endl;
			cin>>pos;
			sl.deleteatpos(pos);
			break;
			case 9: cout<<"Enter the value to be deleted:"<<endl;
			cin>>val;
			sl.deleteval(val);
			break;
			case 10: sl.display();
			break;
			case 11: cout<<"size of linked list="<<endl;
			sl.getsize();
			break;
			default:cout<<"Please select a valid option"<<endl;
			break;
		}
		cout<<"Do you want to continue (Y/N)?"<<endl;
		cin>>ch2;
	}
	while(ch2=='y' || ch2=='Y');
	return 0;
}
