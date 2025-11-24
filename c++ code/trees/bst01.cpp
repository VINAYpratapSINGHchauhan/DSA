#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode *createBSTnode(TreeNode *root, int data)
{
    if (root == NULL)
        return new TreeNode(data);
    if (data > root->data)
        root->right = createBSTnode(root->right, data);
    if (data < root->data)
        root->left = createBSTnode(root->left, data);
    return root;
}
void createBST(TreeNode *&root)
{
    cout << "enter the value of node" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        root = createBSTnode(root, data);
        cin >> data;
    }
}
void levelOrderTraverselWithMarker(TreeNode *root)
{ // this is with marker that each level element in each line
    // row wise traversel that is breadth first traversel
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    // traversel
    while (!q.empty())
    {
        // front ko print kro aur pop kro
        TreeNode *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            // left aur right child dalo queue mei
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}
TreeNode *minValueBST(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    TreeNode *tmp = root;
    while (tmp->left != NULL)
        tmp = tmp->left;
    return tmp;
}
TreeNode *maxValueBST(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    TreeNode *tmp = root;
    while (tmp->right != NULL)
        tmp = tmp->right;
    return tmp;
}
bool searchInBST(TreeNode *root, int target)
{
    if (root == NULL)
        return false;
    if (target == root->data)
        return true;
    else if (target > root->data)
        return searchInBST(root->right, target);
    else
        return searchInBST(root->left, target);
}
TreeNode *deleteInBST(TreeNode *root, int key)
{
    // jb root null ho
    if (root == NULL)
        return NULL;
    // jb target mil jaye
    else if (root->data == key)
    {
        // target k baad hme char case hai
        if (root->left == NULL && root->right == NULL)
        {
            // jb jha mila hai target bo ek leaf node hai
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            // jb jha mila hai target uska left mei subtree hai but right khali hai
            TreeNode *child = root->left;
            delete root;
            return child;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            // jb jha mila hai target uska right mei subtree hai but left khali hai
            TreeNode *child = root->right;
            delete root;
            return child;
        }
        else
        {
            // jb dono left and right subtree present ho
            //  root ki node ki value ko uske left subtree k maximum node se replacement kro
            // getting the max value
            TreeNode *maxChildNode = maxValueBST(root->left);
            // copying the value
            root->data = maxChildNode->data;
            // deleting that node jisse reolace kiya hai
            root->left = deleteInBST(root->left, maxChildNode->data);
            return root;
        }
    }
    else if (root->data > key)
    {
        root->left = deleteInBST(root->left, key);
    }
    else
    {
        root->right = deleteInBST(root->right, key);
    }
    return root;
}
void convertBSTtoDLL(TreeNode*root,TreeNode*&head){
    if(!root)return ;
    convertBSTtoDLL(root->right,head);
    root->right=head;
    if(head)head->left=root;
    head=root;
    convertBSTtoDLL(root->left,head);
}
void printDLL(TreeNode*head){
    TreeNode*temp=head;
    cout<<"printing the DLL : "<<endl;
    while (temp)
    {
        cout<<temp->data<<"->";
        temp=temp->right;
    }
    cout<<endl;
    
}
int sizeOfDLL(TreeNode*head){
    TreeNode*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}
TreeNode*convertDLLtoBST(TreeNode*&head,int n){
    if(head==NULL||n<=0)return nullptr;
    TreeNode*leftsubtree=convertDLLtoBST(head,n/2);
    TreeNode*root=head;
    root->left=leftsubtree;
    head=head->right;
    TreeNode*rightsubtree=convertDLLtoBST(head,n-(n/2)-1);
    root->right=rightsubtree;
    return root;
}
int main()
{
    // creating a binary search tree
    TreeNode *root = NULL;
    createBST(root);
    cout << "printing binary search tree" << endl;
    levelOrderTraverselWithMarker(root);

    // find the minimum element node in the binary search tree
    TreeNode *minNode = minValueBST(root);
    cout << "minimum value of the tree is : " << minNode->data;
    // find the maximum element node in the binary search tree
    cout << endl;
    TreeNode *maxNode = maxValueBST(root);
    cout << "maximum value of the tree is : " << maxNode->data;
    cout << endl;

    // finding the target element in the binary search tree
    int target;
    cout << "Enter the value for target : ";
    cin >> target;
    while (target != -1)
    {
        if (searchInBST(root, target))
            cout << "FOUND !" << endl;
        else
            cout << "NOT FOUND !" << endl;
        cout << "Enter the value for target : ";
        cin >> target;
    }

    // deleting a node from the binary search tree
    levelOrderTraverselWithMarker(root);
    int key;
    cout << "Enter the value for key to be deleted : ";
    cin >> key;
    while (key != -1)
    {
        root = deleteInBST(root, key);
        levelOrderTraverselWithMarker(root);
        cout << "Enter the value for key to be deleted : ";
        cin >> key;
    }

    //creating a sorted doubly linked list from the binary search tree
    TreeNode*head=NULL;
    convertBSTtoDLL(root,head);
    printDLL(head);

    // creating a BST from a sorted doubly linked list
    int n =sizeOfDLL(head);
    TreeNode*newroot=convertDLLtoBST(head,n);
    cout<<"printing the tree from DLL : "<<endl;
    levelOrderTraverselWithMarker(newroot);

    return 0;
}