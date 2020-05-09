#include<iostream>
using namespace std;
struct node
 {
   char data;
	int le,ri;
   node *left,*right;
 };
class tree 
{
  node *root;
  public:
    tree()
     {
       root=NULL;
     }
       void create();
       void pre(node*);
       void insert();
       int bfs(node*);
	int leaf(node*);
	int anode(node*);
       node *copy(node *);
       node *return_root()
        {
           return root;
        }
};
void tree::create()
 {
  node *temp,*newnode;
  char op,side;
  do{
   newnode=new node;
   cout<<"\n Enter data : ";
   cin>>newnode->data;
   newnode->left=newnode->right=NULL;
   if(root==NULL)
      root=newnode;
   else
    {
      temp=root;
      while(1)
       {
        cout<<"\n To the side L/R :";
        cin>>side;
        if(side=='L' || side=='l')
         {
          if(temp->left==NULL)
           {
             temp->left=newnode;
             break;
           }
          else
           temp=temp->left;
}
            else
            {
               if(side=='R' || side=='r')
                {
                  if(temp->right==NULL)
                   {
                     temp->right=newnode;
                     break;
                   }
                  else
                   temp=temp->right;
                }
            }
         }
       }
      cout<<"\n Do u want to add new node : ";
      cin>>op;
    }while(op=='y');
 }

void tree::pre(node *temp)
 {
   if(temp!=NULL)
    {
      cout<<"\n\t"<<temp->data;
      pre(temp->left);
      pre(temp->right);
    }
 }

void tree::insert()
 {
  node *temp,*newnode;
 char op,side;
   newnode=new node;
   cout<<"\n Enter data : ";
   cin>>newnode->data;
   newnode->left=newnode->right=NULL;
      temp=root;
      while(1)
       {
        cout<<"\n To the side L/R :";
        cin>>side;
        if(side=='L' || side=='l')
         {
          if(temp->left==NULL)
           {
             temp->left=newnode;
             break;
           }
          else
           temp=temp->left;
}
            else
            {
               if(side=='R' || side=='r')
                {
                  if(temp->right==NULL)
                   {
                     temp->right=newnode;
                     break;
                   }
                  else
                   temp=temp->right;
                }
            }
         }
       }
int tree::bfs(node *temp)
{
if(temp==NULL)
return 0;
else
{
int ld= bfs(temp->left);
int rd= bfs(temp->right);
if(ld>=rd)
return (ld+1);
else
return (rd+1);
}
}
int tree::leaf(node *temp)
{
if(temp==NULL)
return 0;
if(temp->left==NULL && temp->right==NULL)
return 1;
else
return leaf(temp->left)+leaf(temp->right);
}
int tree::anode(node *temp)
{
if(temp==NULL)
return 0;
if(temp->left!=NULL || temp->right!=NULL)
return 1;
else
return leaf(temp->left)+leaf(temp->right);
}
node *tree::copy(node *root1)
 {
   node *root2=new node;
    if(root1!=NULL)
     {
       root2->data=root1->data;
       root2->left=copy(root1->left);
       root2->right=copy(root2->right);
     }
     return root2;
 }
int main()
 {
   tree obj1;
   int ch,aa,aa1,aa3;
node *aa2;
node *root1=NULL;
   do
    {
      cout<<"\n 1.create \n2.Insert \n 3. Display \n 4. Depth of a tree \n 5.Display leaf-nodes \n 6.Create a copy of a tree";
      cout<<"\n Enter ur choice : ";
      cin>>ch;
      switch(ch)
       {
          case 1:
          	obj1.create();
          break;
          case 2:
          	obj1.insert();
	break;
	case 3:
		obj1.pre(obj1.return_root());
		break;
	case 4:
          	aa=obj1.bfs(obj1.return_root());
		cout<<aa;
          break;
	case 5:
          	aa1=obj1.leaf(obj1.return_root());
		cout<<"\nNo of leaf nodes : "<<aa1;
		aa3=obj1.anode(obj1.return_root());
		cout<<"\nNo of nodes : "<<aa3;
          break;
	case 6:
		aa2=obj1.copy(obj1.return_root());
		cout<<aa2;
		break;
       }
    }while(ch<7);
 }
