#include<iostream.h>
#include<conio.h>
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
	void insertafter(int num,int val);
	void search(int val);
	void remove();
	void delete1(int val);
	void print();
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
	
   void linkedlist::insertafter(int num,int val)
	{
		 node *current_node = start;
		  while ( current_node->data != num )
		  {
			current_node = current_node->next;
			if(current_node==NULL)
			{
				break;
			}
		   }
		     if(current_node->data==num)
		  {
		    struct node *new_node = new node;
		    new_node->data = val;
		    new_node->next= current_node->next;
		    current_node->next = new_node;
			length++;
		    }
		    else
		    {
		      createNewNode(val);
		    };

	}
	int linkedlist:: length1()
	{
		return length;
	}
	void linkedlist:: createNewNode(int val)
	{

		struct node *new_node = new node;
		new_node->data=val;
		new_node->next=NULL;
		if(start==NULL)
		{
		   start=new_node;
		   last=new_node;
		   length++;
		}
		else
		{
			last->next=new_node;
			last=new_node;
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
			length--;

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
			length--;
		  }
		  }
	      }
main()
{
	linkedlist ll;
	char op;
	clrscr();
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
		else if(op=='h')
		{
			int val,num;
			cout<<"isert num where u want to insert number after"<<endl;
			cin>>num;
			cout<<"insert vaue"<<endl;
			cin>>val;
			ll.insertafter(num,val);
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
