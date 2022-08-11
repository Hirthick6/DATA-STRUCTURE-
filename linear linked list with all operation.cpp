#include<iostream>
using namespace std;
class node
{
public:
    string data;
    node* next;
};
node* head = NULL;

void search_element(node* h,string key)
{
     node* current = h;
     int pos =0;
     while(current != NULL && current -> data != key )
    {
        current = current -> next;
         pos ++;
    }
   cout << "The position of the element is :"<< pos;
}
node* insfront(node* h,string new_data)
{
    node* new_node = new node();
    new_node -> data = new_data;
    new_node -> next = h;
    h = new_node;
    return h;
}

node* ins_position(node* h ,int pos,string new_data)
{

    node* current = h;
    int i = 1;
    while(i < pos && current -> next != NULL)
    {
        i++;
        current = current-> next;
    }

    node* new_node = new node();
    new_node -> data = new_data;
    new_node -> next = current -> next;
    current -> next = new_node;

    return h;
}

node* delete_front(node* h)
{
    if(h == NULL)
    {
        cout << "No Element is present to delete";
        return h;
    }

    else
    {
        node* temp = h;
        h = h -> next;
        delete(temp);
        return h;
    }
}

node* delete_key(node* h , string key)
{
 node* current = h;

 while(current != NULL && current -> data != key )
    {
        current = current -> next;
    }

    if (current == NULL)
    {
        cout<<"Key not found in link-List";
        return h;
    }
else
{
   node* temp = current -> next -> next;

   current -> next -> next = current->next->next->next;

   delete(temp);
   cout << "Deleted\n";
   return h;
}
}

node* delete_position(node* h ,int pos)
{
    node* current = h;
    int i = 1;
    while(i < pos && current  != NULL)
    {
        i++;
        current = current-> next;
    }

    if(current != NULL )
{

    node* temp = current->next;
    current -> next = current -> next -> next;
    delete(temp);
    return h;
}
  else
    {
     cout << "Position not available";
    }

}
void display_list(node* h)
{

    if(h == NULL)
    {
        cout << "List is empty";
    }
    else
    {
    while(h != NULL)
    {
        cout << " " << h -> data;
        h= h -> next;
    }
    }
    cout << "\n";
}

int main()
{


    int ch = 0,pos;
    string data;
    string key;
    while(ch != 8)
    {
        cout << "Enter Choice to Proceed: \n";
        cout << "1) INSERT INFRONT \n2) Search \n3) INSERT AT POSITION \n4) Delete at front \n5) Delete at position  \n6) Delete key \n7) Exit";
        cin >> ch;
        switch(ch)
        {
        case 1:
            cout << "Enter Element to Insert :\n";
            cin >> data;
            head = insfront(head,data);
            display_list(head);
            break;

        case 2:
            cout << "Enter element to search:\n";
            cin >> data;
            search_element(head,data);
            cout << "\n";
            break;
        case 3:
            cout << "Enter Element to Insert : \n";
            cin >> data;
            cout << "Enter Position to Insert at: \n";
            cin >> pos;
            head = ins_position(head,pos,data);
            display_list(head);
            break;
        case 4:
            head = delete_front(head);
            cout << "Deleted \n";
            display_list(head);
            break;
        case 5:
            cout << "Enter position to delete:\n";
            cin >> pos;
            head = delete_position(head,pos);
            cout << "Deleted\n";
            display_list(head);
            break;
        case 6:
            cout << "Enter Key to Delete:\n";
            cin >> data;
            head = delete_key(head,data);
            display_list(head);
            break;
        case 7:
            cout << "Exiting";
            break;
        }
    }

return 0;
}
