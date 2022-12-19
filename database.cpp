#include <iostream>

using namespace std;

class BST {
private:
    struct Node
    {
        int val;
        string position;
        string name;
        Node * left;
        Node * right;
    };

    Node * root;

    Node * insert(Node * t, int x, string position, string name)
    {
        //  Sets root as the first node
        if (t == NULL)
        {
            t = newNode(x, position, name);
            return t;
        } 
        // Checks if value should go left
        else if (x < t->val) 
        {
            t->left = insert(t->left, x, position, name);
        }
        // Checks if value should go right
        else 
        {
            t->right = insert(t->right, x, position, name);
        }
        return t;
    }

    void inorder(Node * t)
    {
        if (t != NULL) 
        {
            inorder(t->left);
            cout << t->val << " ";
            cout << t->position << " ";
            cout << t->name << endl;
            inorder(t->right);
        }
    }

    void preorder(Node * t)
    {
        if (t != NULL)
        {
            cout << t->val << " ";
            cout << t->position << " ";
            cout << t->name << endl;
            preorder(t->left);
            preorder(t->right);
        }
    }
    
    void postorder(Node * t)
    {
        if (t != NULL)
        {
            postorder(t->left);
            postorder(t->right);
            cout << t->val << " ";
            cout << t->position << " ";
            cout << t->name << endl;
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    Node * newNode(int x, string position, string name)
    {
        Node * newNode = new Node();
        newNode->val = x;
        newNode->position = position;
        newNode->name = name;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void insertNode(int x, string position, string name)
    {
        root = insert(root, x, position, name);
    }

    void inorderDisplay()
    {
        inorder(root);
    }

    void preorderDisplay()
    {
        preorder(root);
    }

    void postorderDisplay()
    {
        postorder(root);
    }
};

int main()
{
    BST theTree;

    theTree.insertNode(30, "CEO", "Jeff");
    theTree.insertNode(20, "COO", "Gary");
    theTree.insertNode(40, "CIO", "Amberly");
    theTree.insertNode(15, "Operations Manager", "Hector");
    theTree.insertNode(25, "HR Manager", "Ludwig");
    theTree.insertNode(35, "Marketing Manager", "Friedrich");
    theTree.insertNode(55, "Accounting Manager", "Mark");
    theTree.insertNode(10, "Copier", "Darrell");
    theTree.insertNode(23, "Recruiter", "Camila");
    theTree.insertNode(32, "Salesman", "Marion");
    theTree.insertNode(53, "Accountant", "Drew");

    theTree.preorderDisplay();

    return 0;
}