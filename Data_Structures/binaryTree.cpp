/*
* Binary Tree      -       data container, similar to folders on computer. great for data organization for database searching and sorting
*                               uses nodes like linked list, to connect parent with child nodes via edges
*                               *Main(top) node = Root Node (can only have one)
*                               *last Node in branches = Leaf Node (can have as many as want)                                
*                               *each parent can have 2 child nodes, BUT each child can only have one parent node
*                               *CHILD NODES NEVER CONNECTED
*               (regular tree can have multiple child nodes per parent)
*               **Binary Search Tree = organized binary tree (value of parent node should be higher than left child, and lower than right child)
*/
#include <iostream>

using namespace std;

/********************
 * Struct
 ********************/

 struct Node
{
    int data;
    Node* left;
    Node* right;
};


/********************
 * Function Declaration
 ********************/

 Node* createNode(int data);
void preorderPrint(Node* root);
void inorderPrint(Node* root);
void postorderPrint(Node* root);

 /********************
 * MAIN METHOD
 ********************/

int main() 
{
    //Create Root Node
    Node* root = createNode(1); //Level 1
    //Create 2 child nodes
    root->left = createNode(2); //Level 2
    root->right = createNode(3);  //Level 2
    //Create left child, left child node
    root->left->left = createNode(4); //Level 3 *leaf
    root->left->right = createNode(5); //Level 3
    root->right->left = createNode(6); //Level 3 *leaf
    root->right->right = createNode(7); //Level 3
    //Create level 4 child nodes
    root->left->right->left = createNode(9); //Level 4 *leaf
    root->right->right->left = createNode(10); //Level 4 *leaf

    /*Traversing Binary Tree
    *       Two major kinds of traversing:
    *           breadth first search (BFS) prioritizes searching width of tree
    *           depth first search (DFS) prioritizes searching depth(height) of tree
    *       3 Major Algorithms:
    *           preorder(data, left, right)
    *           inorder(left, right, data)
    *           postorder(left, right, data)
    */
    preorderPrint(root);
    cout << endl;
    inorderPrint(root);
    cout << endl;
    postorderPrint(root);


    system("pause>0");
    // return 0;
}


/*********************
 * Function Initialization
 *********************/

Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void preorderPrint(Node* root) //Data, Left, Right
{
    // Recursive Base Case
    if (root == nullptr)
    {
        return;
    }
    cout << root-> data << ", ";
    preorderPrint(root-> left); //Recursive call to cover each Node on left branch from root
    preorderPrint(root-> right); //recursive call to cover each Node on right branch from root
}

void inorderPrint(Node* root) //Left, Data, Right
{
    // recursive Base Case
    if (root  == nullptr) return;

    inorderPrint(root-> left); //Recursive call to cover each Node on left branch from root
    cout << root-> data << ", ";
    inorderPrint(root-> right); //recursive call to cover each Node on right branch from root
}

void postorderPrint(Node* root) // Left, Right, Data
{
    // Recursive Base Case
    if (root == nullptr) return;

    postorderPrint(root-> left); //Recursive call to cover each Node on left branch from root
    postorderPrint(root-> right); //recursive call to cover each Node on right branch from root
    cout << root-> data << ", ";
}