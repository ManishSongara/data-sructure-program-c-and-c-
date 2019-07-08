#include<iostream.h>
struct node {
   int data;
   struct node *prev;
   struct node *next;
};
struct node* head = NULL, *last;
void insert(int newdata)
{
   struct node *newnode = new node;
   newnode->data  = newdata;
   newnode->prev = NULL;
   newnode->next = NULL;
   if(head ==  NULL)
   {
	head=newnode;
	last =newnode;
   }
   else
   {
	last->next=newnode;
	newnode->prev=last;
	last=newnode;
   }

}
void insertafter(int num,int val)
	{
		 node *current_node = head;
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
		    new_node->prev = current_node;
		    current_node->next = new_node;
		    current_node->prev= new_node;

		    }
		    else
		    {
		      insert(val);
		    };

	}

void display()
{
   node* ptr;
   ptr = head;
   while(ptr != NULL)
   {
      cout<< ptr->data<<endl;
      ptr = ptr->next ;
  }
}
void remove_data(int data)
{
    struct node *pre_node,*current,*temp;
	  current=head;
   if(current==NULL)
   {
      cout<<"Linked List not initialized";
      return;
   }
   else if(current->next==NULL || current->data==data)
   {
	head=head->next;
   }
   else
   {
	while(current->next !=NULL && current->data !=data)
	{
		pre_node=current;
		current=current->next;
		if(current==NULL)
		{
			break;
		}
	  }
		 cout<<"current"<<" "<<current->data<<endl;
		 cout<<"pre"<<" "<<pre_node->data<<endl;

	if(current->data==data)
	 {
		pre_node->next=current->next;
		current->next->prev=pre_node;
		temp=current;
		delete temp;
	 }
	}
}
int main()
{
	long int i,val;
	char c;
       insert(56);insert(77);insert(47);insert(74);insert(83);insert(21);
	while(c!='q')
	{
	if(c=='i')
	{
		cout<<endl<<"Enter value:";
		cin>>i;
		val=i;
		insert(val);
	}
       else if(c=='r')
	{
		cout<<endl<<"Enter value:";
		cin>>i;
		val=i;
		remove_data(val);
	}
	if(c=='h')
	{
		int val,num;
		cout<<"enter value";
		cin>>num;
		cout<<"enter val";
		cin>>val;
		insertafter(num,val);
	}
	if(c=='p')
	{
	  display();
	}
	cin>>c;
}
   return 0;
}
