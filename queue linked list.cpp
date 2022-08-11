#include <iostream>
using namespace std;


class node
{
    public:
int data;
node *next;
};

node *front = NULL;
node *rear = NULL;

bool isempty(node* h)
{
 if(front == NULL && rear == NULL)
 return true;
 else
 return false;
}
node*enqueue (node* h )
{
    int value;
    cout<<"Enter element:";
    cin>>value;
 node *nn = new node();
 nn->data= value;
 nn->next = NULL;


 if( front == NULL )
 {

  front = nn;
  rear = nn;
 }
 else
 {
  rear ->next =nn;
  rear = nn;
 }
 return nn;
}

node* dequeue ( node* h)
{
 if(front == NULL && rear == NULL)
 cout<<"Queue is empty\n";
 else

 if( front == rear)
 {
  delete(front);
  front = rear = NULL;
 }
 else
 {
  node *temp = front;
  front = front->next;
  delete(temp);
 }
}


void displayQueue(node* h)
{
  if(front == NULL && rear == NULL)
    cout<<"no elements:";
 else
 {
  node *temp= front;
  while( temp !=NULL)
  {
   cout<<temp->data<<" ";
   temp= temp->next;
  }
 }
}


int main()
{
  node* queue= NULL;
 int choice, value;
 while( choice!=5)
 {
  cout<<"\n1.enqueue 2.dequeue  3.isempty 4.exit\n";
  cin>>choice;
  switch (choice)
  {
  case 1:

         queue=enqueue(queue);
         displayQueue( queue);
          break;
  case 2:  queue=dequeue( queue);
            displayQueue( queue);
          break;
  case 3: if(isempty(queue))
                cout<<"\n queue is empty";
            else
                cout<<"queue  is not empty";
                break;

    case 4:  default:
    cout<<" exit bye bye";
          return(0);
  }
 }

 return 0;
}
