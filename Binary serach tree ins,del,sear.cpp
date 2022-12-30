#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST {
  public:
    TreeNode * root;
  BST() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
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
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
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
    else {
          temp = temp -> right;
        }
      }
    }
  }
  	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}

		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r;
		}
		return r;
	}

  void print2D(TreeNode * r, int space) {
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


  TreeNode * iterativeSearch(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }

  TreeNode * recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> value == val)
      return r;

    else if (val < r -> value)
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
  }



  TreeNode * deleteNode(TreeNode * r, int v) {
    // base case
    if (r == NULL) {
      return NULL;
    }

    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }

    else if (v > r -> value) {
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
    cout << "4. Display Node" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	      obj.root= obj.insertRecursive(obj.root,new_node);
	      cout<<endl;
    		break;

    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
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
      cout<<("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
