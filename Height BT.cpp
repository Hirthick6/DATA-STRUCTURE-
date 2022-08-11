#include <iostream>
using namespace std;
struct tree
{
    tree *l,*r;
    int data;
}
*root=NULL,*p=NULL,*np=NULL;
void create()
{
    int value,c=0;
    while(c<7)
    {
        if(root==NULL)
        {
            root=new tree;
            cout<<"enter value"<<"\t";
            cin>>root->data;
            root->r=NULL;
            root->l=NULL;
        }
        else
        {
            p=root;
            cout<<"enter value of node\n"<<"\t";
            cin>>value;
            while(true)
            {
                if(value<p->data)
                {
                    if(p->l==NULL)
                    {
                        p->l=new tree;
                        p=p->l;
                        p->data=value;
                        p->l=NULL;
                        p->r=NULL;
                        cout<<"value enter left"<<endl;
                        break;
                    }
                    else if(p->l!=NULL)
                    {
                        p=p->l;
                    }
                }
                else if(value>p->data)
                {
                    if(p->r==NULL)
                    {
                        p->r=new tree;
                        p=p->r;
                        p->data=value;
                        p->l=NULL;
                        p->r=NULL;
                        cout<<"value entered in right"<<endl;
                        break;
                    }
                    else if(p->r!=NULL)
                    {
                        p=p->r;
                    }
                }
            }
        }
        c++;
    }
}
void inorder(tree *p)
{
    if(p!=NULL)
    {
        inorder(p->l);
        cout<<p->data<<endl;
        inorder(p->r);
    }
}
void preorder(tree *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
        preorder(p->l);
        preorder(p->r);
    }
}
void postorder(tree *p)
{
    if(p!=NULL)
    {
        postorder(p->l);
        postorder(p->r);
        cout<<p->data<<endl;
    }
}
int numNodes(tree *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return 1 + numNodes(p->l) + numNodes(p->r);
}



  int height(tree *p)
  {
    if (p== NULL)
      return -1;
    else {

      int lheight = height(p ->l);
      int rheight = height(p -> r);


      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }



int main()
{
    create();
    cout<<"printing inorder"<<endl;
    inorder(root);
    cout<<"printing preorder"<<endl;
    preorder(root);
    cout<<"printing postorder"<<endl;
    postorder(root);
    cout << endl;
    cout << "Number Of Nodes: " << numNodes(root);
    cout<<endl;
    cout<<"height of the tree :"<<height(root);
    return 0;
}
