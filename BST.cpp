#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct n{
	int data;
	struct n* left;
	struct n* right;
}node;
node *r=NULL,*temp,*temp1;
void menu();
node* insert(node*,int);
node* del(node*,int);
node* search(node*,int);
void traverse(node *root);
void inorder(node*);
void postorder(node*);
void preorder(node*);
//int count=0;
int main()
{
	menu();
	return 0;
}
void menu()
{
	int a;
	cout<<"\nWhat do you wish to do?\n1)Insert\n2)Delete\n3)Search\n4)Traverse\n5)Exit\n";
	cin>>a;
	switch(a)
	{
		case 1:int b;
		cout<<"\nWhich element do you wish to insert?\n";
		cin>>b;
		r=insert(r,b);
		//cout<<"\n"<<r->data;
		//count++;
		break;
		case 2://int c;
		cout<<"\nWhich element do you wish to delete?\n";
		cin>>b;		
		r=del(r,b);
		break;
		case 3:int d;
		cout<<"\nWhich element do you wissh to serach?\n";
		cin>>d;
		temp1=search(r,d);
		if(temp1==NULL){
			break;
		}
		cout<<"\n"<<temp1->data;
		break;
		case 4:traverse(r);
		break;
		case 5:exit(0);
		break;
		default:"\nsorry wrong choice";
		exit(0);
		break;
	}
	menu();
}
node* insert(node *root,int a)
{
	if(root==NULL)
	{
		root=new(node);
		root->data=a;
		root->left=root->right=NULL;
		return root;
	}
	else
	{
		temp=root;
		if(temp->data>a)
		{
			if(temp->left==NULL)
			{
				temp1=new(node);
				temp1->data=a;
				temp1->left=temp1->right=NULL;
				temp->left=temp1;
				return root;
			}
			else
			{
				temp1=insert(temp->left,a);
				root->left=temp1;
				return root;
			}
		}
		else
		{
			if(temp->right==NULL)
			{
				temp1=new(node);
				temp1->data=a;
				temp1->left=temp1->right=NULL;
				temp->right=temp1;
				return root;
			}
			else
			{
				temp1=insert(temp->right,a);
				root->right=temp1;
				return root;
			}
		}
	}
}
void traverse(node* root)
{
	int a;
	cout<<"\nHow do you want to traverse\n1)Inorder\n2)Pretorder\n3)Postorder\n";
	cin>>a;
	switch(a)
	{
		case 1:inorder(root);
		break;
		case 2:preorder(root);
		break;
		case 3: postorder(root);
		break;
		default:cout<<"Sorry,  wrong choice";
		break;
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"\n"<<root->data;
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<"\n"<<root->data;
		preorder(root->left);
		//cout<<root->data;
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		//cout<<root->data;
		postorder(root->right);
		cout<<"\n"<<root->data;
	}
}
node* search(node* root,int a)
{
	if(root==NULL)
	{
		cout<<"\nroot==NULL";
		return NULL;
	//	cout<<"\nmast1";
	}
	else
	{
	//	cout<<"\nmast";
		temp=root;
		if(temp->data==a)
		{
			cout<<"\nfound";
			return root;
		}
		else if(temp->data>a)
		{
			return search(temp->left,a);
		}
		else
		{
			return search(temp->right,a);
		}
	}
}
node* del(node* root,int a)
{
	if(root==NULL)
	{
		cout<<"no nodes present";
		return NULL;
	}
	else
	{
		temp=search(root,a);
		if(temp->left==NULL&&temp->right==NULL)
		{
			cout<<"\n\n\nmast;";
			if(root->data==a)
			{
				cout<<"\n\n\n"<<root->data<<endl;
				delete(root);
				return NULL;
			}
			temp1=root;
			while(temp1->left->data!=a&&temp1->right->data!=a)
			{
				if(temp1->data>a)
				temp1=temp1->left;
				else
				temp1=temp1->right;
			}
			if(temp1->left->data==a)
			{
				cout<<"\n\n\nmast2";
				delete(temp);
				temp1->left=NULL;
				return root;
			}
			else
			{
				delete(temp);
				temp1->right=NULL;
				return root;
			}
		}
		
		
		
		else if(temp->left==NULL)
		{
			temp->data=temp->right->data;
			delete(temp->right);
			temp->right=NULL;
			return root;
		}
		else if(temp->right==NULL)
		{
			temp->data=temp->left->data;
			delete(temp->left);
			temp->left=NULL;
			return root;
		}
		else
		{
			cout<<"\n\n\nmast3";
			temp1=temp->right;
			cout<<"\n\n\n"<<temp->right->data;
			if(temp1->left==NULL)
			{
				cout<<"\n\nmast4";
				temp->data=temp1->data;
				delete(temp1);
				temp->right=NULL;
				goto x;
			}
			while(temp1->left->left!=NULL)
			{
				temp1=temp1->left;
				
			}
			temp->data=temp1->left->data;
			delete(temp1->left);
			temp1->left=NULL;
			x:
			return root;
		}
	}
}
