#include<iostream.h>
struct node
{
	int data;
	node *next;
};
class linkedlist
{
	struct node *new_node, *start, *last;
public:
	linkedlist()
	{
		start=NULL;
		last=NULL;
	}
	~linkedlist()
	{
	}
	node *createNewNode(int val)
	{
		struct node *new_node = new node;
		new_node->data=val;
		new_node->next=NULL;
		if(start==NULL)
		{
		   start=new_node;
		   last=new_node;
		}
		else
		{
			last->next=new_node;
			last=new_node;
		}
	   return 0;

	}
	void insert(int val)
	{
		createNewNode(val);

	}
     void remove()
	{
		if(start==NULL)
		{
			cout<<"empty1"<<endl;
		}
		else if (start->next==NULL)
		{

			delete start;
			start=NULL;
			cout<<"empty"<<endl;
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

		       }
		   }
	void print()
	{
		node *tmp;
		tmp=start;
		while(tmp!=NULL)
		{
			cout<<"element: "<<tmp->data<<endl;
			tmp=tmp->next;
		}

	}
   void	 search(int val)
	{
		node *current=start;
		while(current!=NULL)
		{
			if(current->data==val)
			{
				cout<<"found"<<endl;
			}
			current=current->next;
		}

	}
   void indertafter(int num,int val)
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
		    }
		    else
		    {
		      createNewNode(val);
		    };

	}
};
main()
{
	linkedlist ll;
	char op;
	cin>>op;
	while(op!='q')
	{
		if(op=='i')
		{

			int val;
			cout<<"enter value";
			cin>>val;
			ll.insert(val);
		}
		else if(op=='r')
		{
		       /*	int val;
			cin>>val;*/
			ll.remove();
		}
	       /*	else if(op=='l')
		{
			cout<<ll.getLength();<<"\n";
		}*/
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
		else if(op=='h')
		{
			int val,num;
			cout<<"isert num where u want to insert number after"<<endl;
			cin>>num;
			cout<<"insert vaue"<<endl;
			cin>>val;
			ll.indertafter(num,val);
		}
		cin>>op;
		}

	return 0;
}
