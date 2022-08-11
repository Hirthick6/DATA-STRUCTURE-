#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
};
node* push(node*h)
{
    int elem;
    if(h == NULL)
    {
        cout<<"Enter element: ";
        cin>> elem;
        node* nn= new node();
        nn->data= elem;
        return nn;
    }
    cout<<"Enter element:";
    cin>>elem;
    node* nn= new node();
    nn->data = elem;
    nn-> next= h;
    h=nn;
    return nn;
}
bool isEmpty(node* h)
{
    if(h==NULL)
        return true;

    else
        return false;

}
node* pop(node* h)
{
    node*t= h->next;
    delete(h);
    h=t;
    return t;
}
void display(node* h)
{
    if(h==NULL)
        cout<<"\nNo elements";
    else
    {
        while(h!=NULL)
        {
            cout<<"["<<h->data<<"]"<< endl;
            h=h->next;
        }
    }
}
int main()
{
    node* stack= NULL;
    int choice;
    while(choice!=4)
    {
        cout<<"\n-----Stack Operation-----\n";
        cout<<"\n1.Push\n2.Pop\n3.IsEmpty\n4.Exit\n";
        cout<<"\nEnter any one of the above: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            stack = push(stack);
            display(stack);
            break;
        case 2:
            stack = pop(stack);
            display(stack);
            break;
        case 3:
            if(isEmpty(stack))
                cout<<"\nStack is empty";
            else
                cout<<"Stack is not empty";
        case 4:
            cout<<"\nProgram Ended";
            return 0;
        }

    }
}
