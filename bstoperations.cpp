#include <iostream>
using namespace std;

class node {
    public:
	 int data;
    node *lchild,*rchild;
};

class bst
{
public:	
 node *root;

	void insert(int val)
	{
		node * temp,*parent;
		if(root == NULL)
		  {
		  	node *temp=new node;
		  	temp->data = val;
		  	temp->lchild=temp->rchild=NULL;
		   root=temp;
		  }
		else
		{
			 temp=root;
			 while(temp != NULL)
			 {
			 
			if(temp->data > val)
			  {
			  parent= temp;	
			  temp= temp->lchild;
		    }
		   else if (temp-> data <val)
		   {
		   	parent=temp;
		   	temp=temp->rchild;
			}
		   }
		   if(parent->data > val)
		   {
		   	node * temp1 = new node;
		   	temp1->data=val;
		   	temp1->lchild=temp1->rchild=NULL;
		   	parent->lchild=temp1;
			}
			else{
				node * temp1 = new node;
		   	temp1->data=val;
		   	temp1->lchild=temp1->rchild=NULL;
		   	parent->rchild=temp1;
			} 
		}
	}
	void inorder(node *root) 
	{
			
  if (root != NULL)
   {
    inorder(root->lchild);
    cout << root->data << " -> ";
    inorder(root->rchild);
  }
}
  void preorder(node *root) 
  {
  	
  if (root != NULL) 
  {
    cout << root->data << " -> ";
    preorder(root->lchild);
    preorder(root->rchild);
  }
  }
  void postorder(node *root);
  
};
void bst::postorder(node *root) {
  	
  if (root != NULL) 
  {
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << " -> ";
  }
  }
int main() {
  bst b1;
  b1.insert(8);
  b1.insert(3);
  b1.insert(1);
   
  b1.insert(10);
  b1.insert(14);
  b1.insert(4);
  b1.insert(12);
  cout << "\nInorder traversal: \n";
  b1.inorder(b1.root);
  cout<<"\npreoder traversal is:..\n";
  b1.preorder(b1.root);
  cout<<"\npostorder traversal is:..\n";
  b1.postorder(b1.root);
 
}
