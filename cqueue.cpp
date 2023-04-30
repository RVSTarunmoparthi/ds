#include<iostream>
#define size 5
using namespace std;
class cqueue
{
 private:
       int rear,front;
       int queue[size];
 public:
       cqueue()
 {
  rear=front=0;
 
    }
     int empty();
     int full();
     void add(int element);
     int Delete();
     int getfront();
     void display();
     
};
 int cqueue::empty()
 {
   if(front==rear)
    return 1;
     else
    return 0;
}
int cqueue::full()
 {
   if((rear+1)%size==front)
   return 1;
   else
   return 0;
}
void cqueue::add(int element)
 {
   if(!full())
{
   rear=(rear+1)%size;
   queue[rear]=element;
   cout<<element<<"inserted"<<endl;
}
 else
 {
 cout<<"queue full";
  }
}
int cqueue::Delete()
 { 
   if(!empty())
   front=(front+1)%size;
   return(queue[front]);
 }
int cqueue::getfront()
 {
   int temp;
   temp=(front+1)%size;
   return(queue[temp]);
 }
 void cqueue::display()
{
    if(empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue elements are: ";
        int i;
        for(i=(front+1)%size; i!=(rear+1)%size; i=(i+1)%size)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
 {
  cqueue qq;
   int ch,ele;
       while(1)
       {
        cout<<"enter your choice\n";
        cout<<"1.add \t";
        cout<<"2.Delete \t";
        cout<<"3.getfront \t";
        cout<<"4.empty \t";
        cout<<"5.full \t";
        cout<<"6.display \t";
        cout<<"7.exit \t";
        cin>>ch;
        switch(ch)
        {
        case 1:cout<<"enter element to be inserted:";
        cin>>ele;
        qq.add(ele);
        break;
        case 2:
cout<<"deleted element is"<<qq.Delete();
cout<<endl;
        break;
        case 3:
cout<<"top front element is"<<qq.getfront();
cout<<endl;
break;

case 4:cout<<"queue is empty"<<qq.empty();
cout<<endl;
break;
case 5:cout<<"queue is full"<<qq.full();
cout<<endl;
           break;
case 6:
	qq.display();
	break;
case 7:	
exit(0);
  }
 }
}
