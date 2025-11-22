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
bool searchInBST(TreeNode*root,int target){
    if(root==NULL)return false;
    if(target==root->data)return true;
    else if(target>root->data)return searchInBST(root->right,target);
    else return searchInBST(root->left,target);
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
        if (searchInBST(root,target))
            cout << "FOUND !" << endl;
        else
            cout << "NOT FOUND !" << endl;
        cout << "Enter the value for target : ";
        cin >> target;
    }
    return 0;
}