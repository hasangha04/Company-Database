#include <iostream>
#include <algorithm>

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
        if (t == nullptr)
        {
            t = newNode(x, position, name);
            return t;
        }
        else if (x < t->val)
        {
            if (t->left != nullptr)
            {
                // Checks if value should go left
                insert(t->left, x, position, name);
            }
            else
            {
                t->left =  newNode(x, position, name);
                return t;
            }
        }
        else if (x > t->val)
        {
            if (t->right != nullptr)
            {
                // Checks if value should go right
                insert(t->right, x, position, name);
            }
            else
            {
                t->right =  newNode(x, position, name);
                return t;
            }
        }
        else 
        {
            cout << "The value " << x << " has already been added\n";
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
    string input;
    char command;
    int val;
    string position;
    string name;
    BST theTree;

    // Initialize the database
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

    bool quit = true;
	while (quit != false)
    {
        cout << "[A]dd a new contact" << endl;
        cout << "[R]eplace a contact's name" << endl;
        cout << "[P]rint the database" << endl;
        cout << "[Q]uit the program" << endl;
        cout << "What would you like to do to the database: ";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        command = input.at(0);

        switch (command)
        {
            case 'A':
                cout << "What value would you like to add: ";
                cin >> val;
                cout << "What is their position: ";
                cin >> position;
                cout << "What is their name: ";
                cin >> name;
                theTree.insertNode(val,position,name);
                cout << endl;
                break;
            case 'R':
            case 'P':
                cout << "[1] Inorder Display" << endl;
                cout << "[2] Preorder Display" << endl;
                cout << "[3] Postoder Display" << endl;
                cout << "How would you like to display database: ";
                cin >> val;

                switch (val)
                {
                    case 1:
                        theTree.inorderDisplay();
                        cout << endl;
                        break;
                    case 2:
                        theTree.preorderDisplay();
                        cout << endl;
                        break;
                    case 3:
                        theTree.postorderDisplay();
                        cout << endl;
                        break;
                }
                break;
            case 'Q':
                cout << "End of Program\n";
				cout << "Thank you for coming!\n";
				quit = false;
				cout << endl;
				break;
            default:
                cout << "Not a valid choice try again!" << endl;
                break;
        }
    }

    return 0;
}