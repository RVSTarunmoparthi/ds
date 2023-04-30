#include<iostream>
using namespace std;
class node
{
	public:
		int data ;
		node * left,*right;
};
class doublelinkedlist
{
	public:
	node* head;
	doublelinkedlist()
	{
		head == NULL;
	}
	node * getnode();
	void insertatbegin(int val);
	void insertatend(int val);
	void insertatpos(int pos , int val);
	void insertafterval(int val1, int val2);
	void insertbeforeval(int val1 , int val2);
	void deleteatbegin();
	void deleteatend();
	void deleteatpos(int pos);
	void deleteval(int val);
	void display();
	int getsize();
};
node * doublelinkedlist :: getnode()
{
	node * temp = new node;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void doublelinkedlist :: insertatbegin(int val)
{
	node *newnode;
	newnode = getnode();
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->right=head;
		head=newnode;
	}
	newnode->data = val;
}
void doublelinkedlist :: insertatend(int val)
{
	node *newnode, *temp;
	newnode = getnode();
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		temp = head;
		while(temp -> right != NULL)
		{
			temp=temp->right;
		}
		temp->right=newnode;
		newnode->left=temp;
	}
	newnode->data = val;
}
void doublelinkedlist :: insertatpos(int pos ,int val)
{
	node *newnode,*temp;
	int count =0;
	newnode = getnode();
	temp =head;
	while(count < pos-1)
	{
		temp=temp->right;
		count++;
	}
	newnode->right = temp->right;
	newnode->left =temp;
	temp->right=newnode;
	(newnode->right)->left=newnode;
	newnode->data=val;
}
void doublelinkedlist::insertafterval(int val1,int val2)
{
	node *newnode,*temp;
	newnode = getnode();
	temp=head;
	while(temp->data != val1)
	{
		temp=temp->right;
	}
	newnode->left=temp;
	newnode->right=temp->right;
	temp->right = newnode;
	(newnode->right)->left= newnode;
	newnode->data=val2;

}
void doublelinkedlist :: insertbeforeval(int val1, int val2)
{
	node*newnode,*temp;
	newnode = getnode();
	temp = head;
	while(temp->data!=val1)
	{
		temp=temp->right;
	}
	newnode->left=temp->left;
	newnode->right=temp;
	(newnode->left)->right=newnode;
	temp->left=newnode;
	newnode->data=val2;
}
void doublelinkedlist::deleteatbegin()
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else
	{
		node *temp;
		temp=head;
		head=head->right;
		delete temp;
	}
}
void doublelinkedlist :: deleteatend()
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else
	{
		node *temp;
		temp=head;
		while(temp->right != NULL)
		{
			temp=temp->right;
		}
		(temp->left)->right=NULL;
		temp->left=NULL;
		delete temp;
	}
}
void doublelinkedlist :: deleteatpos(int pos)
{
	node *temp;
	int count=0;
	temp=head;
	while(count < pos)
	{
		temp=temp->right;
		count++;
	}
	(temp->left)->right = temp->right;
	temp->right->left = temp->left;
	temp->left=NULL;
	temp->right=NULL;
	delete temp;
}
void doublelinkedlist :: deleteval(int val)
{
	node *temp;
	temp=head;
	while(temp->data != val)
	{
		temp=temp->right;
	}
	(temp->left)->right=temp->right;
	(temp->right)->left=temp->left;
	temp->left=NULL;
	temp->right=NULL;
	delete temp;
}
void doublelinkedlist :: display()
{
	if(head==NULL)
	{
		cout<<"Linked list is empty"<<endl;
	}
	else
	{
	node *temp;
	cout<<"Linked list is :"<<endl;

	for(temp=head;temp->right != NULL;temp=temp->right)
	{
		cout<<temp->data<<"<=>";
	}
	cout<<temp->data<<endl;
	}
}
int doublelinkedlist :: getsize()
{
	node *temp;
	int size = 0;
	for(temp=head;temp !=NULL;temp=temp->right)
	{
		size++;
	}
	return size;
}
int main()
{
	doublelinkedlist dll;
	int ch1,val,val1,val2,pos;
	char ch2;
	do
	{
		cout<<"Double linked list operations "<<endl;
		cout<<"1.Insert a value at beginning"<<endl;
		cout<<"2.Insert a value at end"<<endl;
		cout<<"3.Insert a value at a given position"<<endl;
		cout<<"4.Insert a value after a given value"<<endl;
		cout<<"5.Insert a value before a given value"<<endl;
		cout<<"6.Delete a value at beginning"<<endl;
		cout<<"7.Delete a value at end"<<endl;
		cout<<"8.Delete a value at a given position"<<endl;
		cout<<"9.Delete a given value"<<endl;
		cout<<"10.Display linked list"<<endl;
		cout<<"11.Find the size of linked list"<<endl;
		cout<<"enter your choice:"<<endl;
		cin>>ch1;
		switch(ch1)
		{
   		case 1:cout<<"enter the value to be inserted"<<endl;
          	cin>>val;
          	dll.insertatbegin(val);
          	break;
         
 		case 2:cout<<"enter the value to be inserted"<<endl;
          	cin>>val;
          	dll.insertatend(val);
          	break;
 		case 3:cout<<"enter the position:"<<endl;
   	    	cin>>pos;
        	cout<<"enter the value to be inserted:"<<endl;
        	cin>>val;
        	dll.insertatpos(pos,val);
        	break;
 		case 4:cout<<"enter the value after which value to be inserted:"        <<endl;
       		cin>>val1;
       		cout<<"enter the value to be inserted:"<<endl;
       		cin>>val2;
       		dll.insertafterval(val1,val2);
       		break;
 		case 5:cout<<"enter the value before which value to be inserted        :"<<endl;
        	cin>>val1;
        	cout<<"enter the value to be inserted:"<<endl;
        	cin>>val2;
          	dll.insertbeforeval(val1,val2);
        	break;
		case 6: dll.deleteatbegin();
        	 break;
		case 7: dll.deleteatend();
         	break;
 		case 8: cout<<"enter the position of the value to be deleted:"<<endl;
       		cin>>pos;
       		dll.deleteatpos(pos);
       		break;
 		case 9:cout<<"enter the value to be deleted:"<<endl;
         	cin>>val;
          	dll.deleteval(val);
          	break;
 		case 10: dll.display();
        	break;
 		case 11: cout<<"size of linked list="<<dll.getsize()<<endl;
        	break;
         
 		default:cout<<"please select a valid option"<<endl;
        	break;
	 	}
		cout<<"do you want to continue(Y/N)?"<<endl;
		cin>>ch2;
	}	
	while(ch2=='Y'||ch2=='y');
}
