#include<iostream>
using namespace std;
class node
{
public:
    string name;
    int date,month,year;
    node*next;
};
class queue
{
    public:
    node* f;
    queue()
    {
        f=NULL;
    }
void insertq()
{
    node*nn=new node();
    cout<<"Enter name of your frnd : ";
    cin>>nn->name;
    cout<<"Enter "<<nn->name<<"'s Date of Birth : ";
    cin>>nn->date>>nn->month>>nn->year;


    if((f==NULL)||(f->year > nn->year)||(f->year == nn->year && f->month > nn->month)||(f->year == nn->year && f->month == nn->month && f->date > nn->date))

        {
            nn->next=f;
            f=nn;
        }




        else
        {
            node*curr=f;
            while(curr!=NULL)
            {
                if((curr->year < nn->year)||(curr->year == nn->year && curr->month < nn->month)||(curr->year == nn->year && curr->month == nn->month && curr->date < nn->date))
                    break;
                    else
                        curr=curr->next;
            }
            node*p=curr->next;
            curr->next=nn;
            nn->next=p;
        }
}
void display()
{
    if(f!=NULL)
    {
        cout<<f->name<<" "<<f->date<<"."<<f->month<<"."<<f->year<<endl;
        node*curr=f;
        f=f->next;
        delete (curr);
    }
    else
    cout<<"QUEUE EMPTY";
}
};
int main()
{
    queue n;

    cout<<"DATE OF BIRTH DELETION"<<endl;

    cout<<endl<<endl<<"1-ADD FRND DETAILS \n2-DISPLAY DETAILS\n";

    int ch;

    while(ch!=3)
    {
        cout<<"ENTER YOUR CHOICE : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            n.insertq();
            break;
        case 2:
            n.display();

            break;
        }
    }
     return 0;
}
