#include<iostream>
#include<iomanip>
using namespace std;

static int c=0;
class Node {
public:

     int data;
     Node *left, *right;
};


Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}





void printInorder(Node* node)
{
    if (node == NULL)
        return;


    printInorder(node->left);


    cout << node->data << " ";


    printInorder(node->right);
}



int countnodes(Node *root)
        {

            if(root != NULL)
            {
                countnodes(root->left);
                c++;
                countnodes(root->right);


            }

            return c;

        }
int mid(Node*root)
{
int s=0;
    if(root!=NULL)
    {
        mid(root->left);
        c++;
        s=c/2;
        mid(root->right);

    }

    return s;

}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);


    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
    cout<<"\ncount of the tree:"<<setw(5);
    cout<<countnodes(root);
    cout<<"\nmid elem of tree:"<<setw(5);
    cout<<mid(root);

}
