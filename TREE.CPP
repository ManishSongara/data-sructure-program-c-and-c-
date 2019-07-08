#include <iostream.h>
#include <conio.h>
struct node
{
    node *l, *r;
    int data;
}*root = NULL, *p = NULL, *np = NULL, *q;
int n=1;
void create()
{
    int value,c = 0;
    while (c < 7)
    {
	if (root == NULL)
	{
	    root = new node;
	    cout<<"enter value of root node\n";
	    cin>>root->data;
	    root->r=NULL;
	    root->l=NULL;
	}
	else
	{
	    p = root;
	    cout<<"enter value of node\n";
	    cin>>value;
	    while(1)
	    {
		if (value < p->data)
		{
		    if (p->l == NULL)
		    {
			p->l = new node;
			p = p->l;
			p->data = value;
			p->l = NULL;
			p->r = NULL;
			cout<<"value entered in left\n";
			break;
		    }
		    else if (p->l != NULL)
		    {
			p = p->l;
		    }
		}
		else if (value > p->data)
		{
		    if (p->r == NULL)
		    {
			p->r = new node;
			p = p->r;
			p->data = value;
			p->l = NULL;
			p->r = NULL;
			cout<<"value entered in right\n";
			break;
		    }
		    else if (p->r != NULL)
		    {
			p = p->r;
		    }
		 }
	     }
	}
	c++;
    }
}
int countnode(node *root)
{       int n=1;
	if(root==NULL)
	{
		return 0;
	}
	if(root->l!=NULL)
	{
		//n=n+1;
		n+=countnode(root->l);
	}
	if(root->r!=NULL)
	{
	       //	n=n+1;
		n+=countnode(root->r);
	}
	return n;
}
void mirror(node* root)  
{ 
    if (root == NULL)
	return;
    else
    {
	struct node *temp;

	/* do the subtrees */
	mirror(root->l);
	mirror(root->r);

	/* swap the pointers in this node */
	temp = root->l;
	root->l = root->r;
	root->r = temp;
    }
}

void inorder(node *p)
{

    if (p != NULL)
    {
	inorder(p->l);
	cout<<p->data<<" ";
	inorder(p->r);
    }
}
void preorder(node *p)
{
    if (p != NULL)
    {
	cout<<p->data<<" ";
	preorder(p->l);
	preorder(p->r);
    }
}
void postorder(node *p)
{   if (p != NULL)
    {

	postorder(p->l);
	postorder(p->r);
	cout<<p->data<<" ";
    }

}
int main()
{
    create();
    cout<<"printing traversal in inorder\n";
    inorder(root);
    mirror(root);
    cout<<endl;
    cout<<" printing traversal in inorder (mirror)\n";
    inorder(root);
     cout<<endl;

    cout<<"printing traversal in preorder\n";
    preorder(root);
    mirror(root);
    cout<<endl;
    cout<<" printing traversal in preorder (mirror)\n";
    preorder(root);
    cout<<endl;

    cout<<"printing traversal in inorder\n";
    postorder(root);
    mirror(root);
    cout<<endl;
    cout<<" printing traversal in inorder (mirror)\n";
    postorder(root);
    cout<<endl;
    cout<<"root= "<<countnode(root);

    getch();
    return 0;
}