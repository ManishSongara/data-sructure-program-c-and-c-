#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
class linkedlist
{
	struct node *new_node, *start, *last;
public:
	int length;
	void createNewNode(int val);
	void search(int val);
	void remove();
	void print();
	void delete1(int val);
	int length1();

	linkedlist()
	{
		start=NULL;
		last=NULL;
		length=0;
	}
	~linkedlist()
	{
	}
	void insert(int val)
	{
		createNewNode(val);

	}

};
	int linkedlist:: length1()
	{
		return length;
	}
	void linkedlist:: createNewNode(int val)
	{
		struct node *new_node = new node;
		new_node->data=val;
		new_node->next=NULL;
		if(start==NULL || start->data >=new_node->data)
		{
		   new_node->next=start;
		   start=new_node;
		   length++;

		}
		else
		{
		       node *current1= start;
			while(current1->next != NULL &&  current1->next->data < new_node->data)
			{
				current1=current1->next;
			}
			new_node->next=current1->next;
			current1->next=new_node;
			length++;
		}
	}
       void linkedlist:: search(int val)
	{
		node *current=start;
		while(current!=NULL)
		{
			if(current->data==val)
			{
				cout<<"element found"<<endl;
			}
			current=current->next;
		}

	}
	void linkedlist:: remove()
	{
		if(start==NULL)
		{
			cout<<"linked list is empty"<<endl;
		}
		else if (start->next==NULL)
		{

			delete start;
			start=NULL;
			cout<<"linked list is empty"<<endl;
			length--;
		}
		else{
			node *prev, *temp=start;
			while(temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
			 delete temp->next;
			 prev->next=NULL;
			 length--;

		       }
		   }
	void linkedlist::print()
	{
		node *tmp;
		tmp=start;
		while(tmp!=NULL)
		{
			cout<<"-> "<<tmp->data<<endl;
			tmp=tmp->next;
		}

	}
	void linkedlist::delete1(int val)
	{
		node *currn,*temp,*pr;
		currn=start;
		if(currn==NULL)
		{
			return;
		}

		else if(currn->next==NULL || currn->data==val)
		{
			start=start->next;

		}
		else
		{

		 while (currn->next!=0 && currn->data != val)
		  {
			pr=currn;
			currn = currn->next;
			if(currn==NULL)
			{
				break;
			}
		  }
		if(currn->data==val)
		  {
			pr->next=currn->next;
			temp=currn;
			delete temp;
		  }
		  }
	      }
main()
{
	linkedlist ll;
	char op;
	//clrscr();
	cin>>op;
	while(op!='q')
	{
		if(op=='i')
		{

			int val;
			cout<<"insert an element"<<endl;
			cin>>val;
			ll.insert(val);
		}
		else if(op=='r')
		{
			ll.remove();
		}
		else if(op=='p')
		{
			ll.print();
		}
	       else if(op=='s')
		{
			int val;
			cout<<"enter value for search"<<endl;
			cin>>val;
			ll.search(val);
	       }
	       else if(op=='l')
	       {
		 cout<<"length: "<<ll.length1();
	       }
		else if(op=='d')
		{
			int val;
			cout<<"enter value:";
			cin>>val;
			ll.delete1(val);
		}
		cin>>op;
		}

	return 0;
}
