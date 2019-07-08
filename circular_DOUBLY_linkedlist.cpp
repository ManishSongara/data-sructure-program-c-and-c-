#include<iostream>
struct node
{
    int info;
    struct node *next;
    struct node *prev; 
}*start, *last;
int counter = 0;
class double_clist
{
    public:
        node *create_node(int);
        void insert_begin();
        void insert_last();
        void insert_pos();
        void delete_pos();
        void search();
        void display();
        void sort();
        double_clist()
        {
            start = NULL;
            last = NULL;			
        }
};
 
int main()
{
    int choice;
    double_clist cdl;
    while (1)
    {         
        cout<<"1.Insert at Beginning"<<endl;
        cout<<"2.Insert at Last"<<endl;
        cout<<"3.Insert at Position"<<endl;
        cout<<"4.Delete at Position"<<endl;
        cout<<"5.Search Element"<<endl;
        cout<<"6.Display List"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cdl.insert_begin();
            break;
        case 2:
            cdl.insert_last();
            break;   
        case 3:
            cdl.insert_pos();
            break; 
        case 4:
            cdl.delete_pos();
            break;
       case 5:
            cdl.search();
            break;
       case 6:
            cdl.display();
            break;
       case 7:
            exit(1); 
        default:
            cout<<"Wrong choice"<<endl;	
        }
    }
    return 0;
}
node* double_clist::create_node(int value)
{
    counter++;  
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void double_clist::insert_begin()
{
    int value;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    struct node *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {    
        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
        start->prev = last;
        last->next = start;
        cout<<"Element inserted"<<endl;
    }
}
void double_clist::insert_last()
{
    int value;    
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value; 
    struct node *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;    
        start->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;
    }
}
void double_clist::insert_pos()
{    
    int value, pos, i;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    cout<<endl<<"Enter the postion of element inserted: ";
    cin>>pos;
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        if (pos == 1)
        {
            start = last = temp;
            start->next = last->next = NULL;    
            start->prev = last->prev = NULL;
        }
        else
        {
            cout<<"Position out of range"<<endl;
            counter--;
            return;
        }
    }  
    else
    {
        if (counter < pos)
        {
             cout<<"Position out of range"<<endl;
             counter--;
             return;   		
        }
        s = start;		
        for (i = 1;i <= counter;i++)
        {
            ptr = s;
            s = s->next;
            if (i == pos - 1)
            {
                ptr->next = temp;
                temp->prev = ptr;
                temp->next = s;
                s->prev = temp;
                cout<<"Element inserted"<<endl;
                break;
            }
        }
    }
}
void double_clist::delete_pos()
{    
    int pos, i;
    node *ptr, *s;
    cout<<endl<<"Enter the postion of element to be deleted: ";
    cin>>pos;
    s = start;
    if(pos == 1)
    {
        counter--;
        last->next = s->next;
        s->next->prev = last;
        start = s->next;
        free(s);
        cout<<"Element Deleted"<<endl;
        return;	   
    }
    for (i = 0;i < pos - 1;i++ )
    {  
        s = s->next;
        ptr = s->prev;    	  
    }    
    ptr->next = s->next;
    s->next->prev = ptr;
    if (pos == counter)
    {
        last = ptr; 	   
    }
    counter--;
    free(s);
    cout<<"Element Deleted"<<endl;
}
void double_clist::search()
{
    int pos = 0, value, i;
    struct node *s;
    cout<<endl<<"Enter the value to be searched: ";
    cin>>value;
    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->info == value)
        {
            cout<<"Element "<<value<<" found at position: "<<pos<<endl;
            flag = true;
        }    
        s = s->next;
    }           
}
void double_clist::display()
{
    int i;
    struct node *s;
	s = start;
    for (i = 0;i < counter-1;i++)
    {	
        cout<<s->info<<"<->";
        s = s->next; 
    }
    cout<<s->info<<endl;
}