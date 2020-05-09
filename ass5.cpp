#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
        char data;

        node *left, *right;
};
class tree
{
        node root;

        public:
        tree()
        {
                root=NULL;
        }
        void create();
        void insert();
        void PreTrav(node*);
        int Search(int);
        int Rsearch(node*,int);
        void DFS();
        void RDFS(node*);
        void BFS();
        void RBFS(node*);
        node *R_mir(node*);
        void mirror();
        void delete(int);
        node *return_root();
        {
                return root;
        }
};

void tree::create()
{
        node *temp, *newnode;
        char side,op ;
        do
        {
                newnode= new node;
                cout<<"in Enter data:";
                cin>>newnode->data;
                newnode->left=newnode->right=NULL;

                if(root==NULL)

                root=newnode;

                else
                temp=root;
                while(1)
                { 
                if(newnode->data<temp->data)
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
        cout<<"\n Add More...(Y/N)\n";
        cin>>op;
} while(op=='y');
}
    
void tree::insert()
{
        node *temp, *newnode;
        newnode= new node;
        cout<<"in Enter data:";
        cin>>newnode->data;
        newnode->left=newnode->right=NULL;

        if(root=NULL)

        root=newnode;

        else
        {
        temp=root;
        while(1)

        { 
        if(newnode->data<temp->data)
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
void tree::PreTrav(node *temp)
{
        if(temp!=NULL)
        {
                cout<<"\t"<<temp->data;
                PreTrav(temp->left);
                PreTrav(temp->right);
        }
}
  
  //NON RECURSIVE SEARCH
int tree::Search(int key)
{
    int Flag=0;
    node *temp=root;
    while(temp!=NULL)
    {
        if(key<temp->data)
                temp=temp->left;
        else if(key>temp->data)
                temp=temp->right;
        else
        {
             Flag=1;
             break;
        }
    }
    
    return Flag;
}  

// RECURSIVE SEARCH

int tree::Rsearch(node *temp, int key)
 
{
    static int Flag=0;
    if(temp!=NULL)

    {
        if(key<temp->data)
        {
            Flag=1;          
             return Flag;
        }
        else if(key>temp->data)
            Rsearch(temp->left,key);
        else if(key>temp->data)
            Rsearch(temp->right,key);
        else
             return -1;
      }
}

         
//DEPTH FIRST SEARCH NON RECURSIVE

void tree::DFS()
{
   node *Stack[20],*temp=root;
   int Top=0;
   while(Top>=0)
   {
     while(temp!=NULL)                        
     {
       cout<<"\t"<<temp->data;
       Stack[Top++]=temp;
       temp=temp->left;
     }
          temp=Stack[--Top];
          temp=temp->right;         
  }
}

//DEPTH FIRST SEARCH RECURSIVE

void tree::RDFS(node *temp)
{
   if(temp!=NULL)
   {
          cout<<"\t"<<temp->data;
          RDFS(temp->left);
          RDFS(temp->right);
   }
}  
//BREATH FIRST SEARCH NON RECURSIVE(Levelwise Display)
//Count number of node, no of leaf node & Height of tree

void tree::BFS()
{
        node *Queue[20], *temp=root;
        int Front=0, Rear=1, Level=-1, Count=0, Leaf=0;
   
        if(temp==NULL)
        cout<<"\n Empty tree";
        else  
        {
           Queue[0]=temp;
           Queue[1]=NULL;
           
        cout<<"\n Level"<<++Level;
        
        do 
        {
                temp=Queue[Front++];
                if(temp==NULL)
                {
                        Queue[++Rear]=NULL;
                        cout<<"\nLevel"<<++Level;
                }
                else
                {
                        Count++; //Total no of nodes in tree
                        cout<<" "<<temp->data<<" ";
                if(temp->left!=NULL)
                        Queue[++Rear]=temp->left;                                 
                if(temp->right!=NULL)
                        Queue[++Rear]=temp->right;
                else if(temp->right==NULL && temp->left==NULL )                                 
                      Leaf++; //NO of leaf nodes
                }
          }while(Front<Rear);
                
          }
                cout<<"\n Height of tree:"<<Level-1<<"\nTotal no of Nodes";
}
  
  // BREATH FIRST SEARCH RECURSIVE
  
void tree::RBFS(node *temp)
{
    static int Front=0; static int Rear=0;
    static node *Queue[10];
    if(Front<=Rear)
    {
        cout<<""<<temp->data<<"  ";
        if(temp->left!=NULL)
                     Queue[Rear++]=temp->left;                                 
        if(temp->right!=NULL)
                     Queue[Rear++]=temp->right;            
                     temp=Queue[Front++];
                     RBFS(temp);
     }
}
          
// DISPLAY MIRROR IMAGE OF TREE NON RECURSIVE 

//MIRROR IMAGE RECURSIVE
/*void mirror(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    queue<Node*> q; 
    q.push(root); 
  
    // Do BFS. While doing BFS, keep swapping 
    // left and right children 
    while (!q.empty()) 
    { 
        // pop top node from queue 
        Node* temp = q.front(); 
        q.pop(); 
  
        // swap left child with right child 
        swap(temp->left, temp->right); 
  
        // push left and right children 
        if (temp->left) 
            q.push(temp->left); 
        if (temp->right) 
            q.push(temp->right); 
    } 
} 
 */
//DELETE NODE


int main()
{
    tree ob;
    node *root1;
    char op;
    int key,f,ch,h,ch1;
    
    do
    {
       cout<<"\n 1.Create \n2 .Insert \n 3.Search \n 4.DFS \n 5.BFS \n 6.Mirror \n 7.Delete";
       cout<<"Enter u r choice : ";
       cin>>ch;
       switch(ch)
        
       { 
          case 1:
                 ob.create();
                 ob.PreTrav(ob.return_root());
                 break;
          case 2:
                  ob.insert();
                 ob.PreTrav(ob.return_root());
                 break;              
          case 3:
                 cout<<"\n Enter element to search : ";
                 cin>>key;
                 cout<<" \n Recursive (1) / Non-Recursive (2)";
                 cin>>ch1;
                 if(ch1==1)
                 { 
                     h=ob.Rsearch(ob.return_root(),key);
                     if(h==1)
                        cout<<"\n ELEMENT FOUND";
                     else
                        cout<<"\n ELEMENT NOT FOUND ";
                  }
                  else
                  {
                      f=ob.Search(key);
                      if(h==1)
                         cout<<"\n ELEMENT FOUND ";
                      else
                         cout<<"\n ELEMENT NOT FOUND ";
                   }
                        break;
          case 4:
                  cout<<" \n Recursive (1) / Non-Recursive (2)";
                  cin>>ch1;
                  if(ch1==1)
                  {
                    ob.RDFS(ob.return_root());
                    cout<<"\n";
                  }
                  else
                  {
                       ob.DFS();
                  }
                   break;
                  }
                   cout<<"\n Do you want to continue";
                    cin>>op;
      } while(op=='y' || op=='Y');
}
               




