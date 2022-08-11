#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* front;
        Node* rear;
        Node* next;
        Node()
        {
          front=NULL;
          rear=NULL;
        }
        void Display()
        {
        if (front == NULL)
        {
            cout << "Queue is Empty\n";
            return;
        }
        Node* h = front;
        cout<<"QUEUE: ";
        while (h != NULL){
            cout << h->data << " ";
            h = h->next;
        }
        cout << endl;
        }

        void EnQueue(int new_data)
        {

            Node* nn = new Node();
            nn->data = new_data;
            nn->next = NULL;

            if (rear == NULL)
            {
                front = nn;
                rear = nn;
            }
            else
            {
              rear->next=nn;
              rear=nn;
            }
            cout<<"Element inserted\n";
            cout<<new_data;
           // Display();
        }

        void DeQueue()
        {
            Node* temp = front;
            if (temp == NULL)
            {
                cout << "Queue is Empty\n";
                return;
            }
            front = front->next;
            delete temp;
            cout<<"Element deleted\n";
           // Display();
        }

        void perform()
        {

            int ch, a;
        while(ch != 3)
            {
            cout << "\nEnter your choice : ";
            cin >> ch;

            switch(ch)
            {

                case 1:
                    cout << "Enter the value to be insert to the Queue : ";
                    cin >> a;
                    EnQueue(a);
                    break;

                case 2:
                    DeQueue();
                    break;

                case 3:
                    cout<<"\nQueue Created\n";
                    break;

                default:
                    cout << "Enter a value between 1 and 4";
            }
        }
       }

       void greatest()
       {
        if(front==NULL)
        {
           cout<<"NONE";
        }
        else
        {
          Node* max=front;
          Node* t=front;
          while(t!=NULL)
          {
           if(max->data < t->data)
             max = t;
            t=t->next;
          }
          cout<<max->data;
        }
       }

};

int main()
{
    cout <<"---QUEUE OPERATIONS---\n\n";
    cout << "1.Insert element in Queue \n";
    cout << "2.Delete element in Queue \n";
    cout << "3.Stop implementing Queue\n";

    Node n;
    n.perform();
    cout <<"\nTHE GREATEST ELEMENT IN THE QUEUE: ";
    n.greatest();
    return 0;
}
