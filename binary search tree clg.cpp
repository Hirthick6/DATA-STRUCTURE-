#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode
{
  public:
  int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode()
   {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v)
   {
    value = v;
    left = NULL;
    right = NULL;
   }
};
class BST
 {
  public:
    TreeNode * root;
  BST()
  {
    root = NULL;
  }

  bool isTreeEmpty()
   {
    if (root == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void insertNode(TreeNode * new_node)
   {
    if (root == NULL)
    {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    }
     else
    {
      TreeNode * temp = root;
      while (temp != NULL)
      {
        if (new_node -> value == temp -> value)
        {
          cout << "Value Already exist," <<"Insert another value!" << endl;
          return;
        }
     else if ((new_node -> value < temp -> value) && (temp -> left == NULL))
        {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        }
     else if (new_node -> value < temp -> value)
        {
          temp = temp -> left;
        }
     else if ((new_node -> value > temp -> value) && (temp -> right == NULL))
        {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        }
     else
        {
          temp = temp -> right;
        }
      }
    }
  }


  void print2D(TreeNode * r, int space)
  {
    if (r == NULL)
      return;
    space += SPACE;
    print2D(r -> right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
      cout << " ";
    cout << r -> value << "\n";
    print2D(r -> left, space);
  }

  TreeNode * iterativeSearch(int v)

   {
    if (root == NULL)
    {
      return root;
    }
    else
    {
      TreeNode * temp = root;
      while (temp != NULL)
      {
        if (v == temp -> value)
        {
          return temp;
        }
       else if (v < temp -> value)
        {
          temp = temp -> left;
        }
        else
        {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }

  TreeNode * deleteNode(TreeNode * r, int v)
  {
    if (r == NULL)
    {
      return NULL;
    }

    else if (v < r -> value)
    {
      r -> left = deleteNode(r -> left, v);
    }

    else if (v > r -> value)
    {
      r -> right = deleteNode(r -> right, v);
    }
    else
    {

      if (r -> left == NULL)
      {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      }
      else if (r -> right == NULL)
      {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      }
      else
        {

        TreeNode * temp ;
        r -> value = temp -> value;
        r -> right = deleteNode(r -> right, temp -> value);
      }
    }
    return r;
  }

};

int main() {
  BST obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print" << endl;
    cout << "5. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    TreeNode * new_node = new TreeNode();

    switch (option)
     {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	     obj.insertNode(new_node);
	      cout<<endl;
    		break;

    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL)
      {
        cout << "Value found" << endl;
      }
      else
      {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL)
      {
        obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;

      break;

    case 5:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
  return 0;
}
\
