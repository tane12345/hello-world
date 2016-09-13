#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct list{
	int data;
	struct list* next;
	struct list* prev;
}dll;
dll *head=NULL,*temp,*temp1;
dll* del(dll*,int);
dll* insert(dll*,int);
dll* search(dll*,int);
dll* new_node(int);
void traverse(dll*);
void menu();
int main()
{
	menu();
	return 0;
}
void menu()
{
	int a,b;
	cout<<"\nWhat do you wnat to do\n1)Insert\n2)Delete\n3)Search\n4)Traverse\n5)Exit\n";
	cin>>a;
	switch(a)
	{
		case 1:cout<<"\nWhich element do ypou wish to insert?\n";
		cin>>b;
		head=insert(head,b);
		cout<<"\n\n"<<head->data;
		break;
		case 2:cout<<"\nWhich element do you wish to delete?\n";
		cin>>b;
		head=del(head,b);
		break;
		case 3:"\nWhich element do you wish to search?";
		cin>>b;
		temp=search(head,b);
		if(temp==NULL)
		cout<<"\nnot found";
		else
		{
		cout<<"\nfound";
		cout<<"\n\n\n"<<temp->data;}
		break;
		case 4: traverse(head);
		break;
		case 5:exit(0);
		defalut:cout<<"\nSorry,wrong choice\n";
		break;
	}
	menu();
}
dll* insert(dll* root,int a)
{
	if(root==NULL)
	{
		return new_node(a);
	}
	else
	{
		int b;
		cout<<"\nWhere do you want to insert?\n1)Begining\n2)Middle\n3)End\n";
		cin>>b;
		switch(b)
		{
			case 1:temp=new_node(a);
			temp->next=root;
			root->prev=temp;
			root=temp;
			break;
			case 2:cout<<"\nAfter which element do you wish to insert the new element?\n";
			cin>>b;
			temp=search(root,b);
			temp1=new_node(a);
			temp1->next=temp->next;
			temp1->prev=temp;
			temp->next->prev=temp1;
			temp->next=temp1;
			break;
			case 3:temp1=new_node(a);
			temp=root;
			while(temp->next!=NULL)
			temp=temp->next;
			temp->next=temp1;
			temp1->prev=temp;
			temp1->next=NULL;
			break;
			default:cout<<"\nSorry, wrong choice\n";
			break;
		}
		return root;
	}
}
dll* search(dll* root,int a)
{
	temp=root;
	while(temp->next!=NULL)
	{
		if(temp->data==a)
		{
			break;
		}
		else
		temp=temp->next;
	}	
	if(temp->data==a)
	return temp;
	else
	return NULL;
}
void traverse(dll* root)
{
	temp=root;
	cout<<"\n";
	while(temp->next!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	 cout<<temp->data<<endl;
}
dll* del(dll* root,int a)
{
	if(root==NULL)
	{
		cout<<"\nEmpty list";;
		return NULL;
	}
	else
	{
		temp=search(root,a);
		if(temp==NULL)
		{
			cout<<"\nElement not found\n";
		}
		if (temp->next!=NULL&&temp->prev!=NULL)
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			delete(temp);
		}
		else if(temp->next==NULL)
		{
			temp->prev->next=NULL;
			delete (temp);
		}
		else
		{
			root=temp->next;
			delete(temp);
		}
		return root;
	}
	
}
dll* new_node(int a)
{
	temp=new(dll);
	temp->data=a;
	temp->prev=temp->next=NULL;
	return temp;
}
