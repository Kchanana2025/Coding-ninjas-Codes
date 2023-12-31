
void printLevelWise(BinaryTreeNode<int> *root)
{
    // Write your code here
    // void printLevelATNewLine(BinaryTreeNode<int> * root) {
    //   // Write your code here
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> pn;

    pn.push(root);
    pn.push(NULL);

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();

        if (front == NULL)
        {
            if (pn.size() == 0)
                break;
            cout << endl;
            pn.push(NULL);
        }

        else
        {
            cout << front->data << " ";

            if (front->left)
                pn.push(front->left);
            if (front->right)
                pn.push(front->right);
        }
    }
}