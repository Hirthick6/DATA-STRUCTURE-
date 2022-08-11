#include <iostream>
#include<string.h>
using namespace std;
static int a=0;
struct tree
{
    tree *l,*r;
    int data;
}
*root=NULL,*p=NULL;
void create()
{
    int value,c=0;
    while(c<3)
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

int mid(tree* p)
{
    int s=0;
    if(p!=NULL)
    {
        mid(p->l);
        a++;
        s=a/2;
        mid(p->r);
    }
    return s;
}

int main()
{
    create();
    cout<<"printing inorder"<<"\t";
    inorder(root);

    cout<<"\nmiddle element of tree:";
    cout<<mid(root);

    return 0;
}
