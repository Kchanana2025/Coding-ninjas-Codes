// O(h)
// O(h)
// iske code mein changes krke sahi file BST_class.cpp hai
// ye file is for looking agt mistakes
#include "Binary_tree.h"
class BST
{
    Binary_tree<int> *root; // hmne isko int dia hai waise float double bhi de skte hai (swal mein mentioned hoga accordingly)string ka sense nai bnega isliye hi template<T> nai dia kyunki specific data types hi aa skte hain isme ,abhi ke lie onteger de dia
    bool getData_helper(int data, Binary_tree<int> *root)
    {
        if (root == NULL)
            return false;

        if (root->data == data)
            return true;
        else if (data < root->data)
        {
            return getData_helper(data, root->left);
        }
        else
        {
            return getData_helper(data, root->right);
        }
    }
    Binary_tree<int> *insert_helper(int data, Binary_tree<int> *root)
    // our data type is pointer of type node because root might be NULL usme root insert karoge na
    {
        if (root == NULL)
        {
            Binary_tree<int> *node = new Binary_tree<int>(data);
            root = node;
            return root;
        }
        else if (data > root->data)
        {
            Binary_tree<int> *node = insert_helper(data, root->right);
            root->right = node;
        }
        else // when data less or equal than data of root node will be inserted in left
        {
            Binary_tree<int> *node = insert_helper(data, root->left);
            root->left = node;
        }
        return root;
    }
    Binary_tree<int> *find_maximum(Binary_tree<int> *root)
    {
        if (root->right != NULL)
            find_maximum(root->right);
        return root;
    }
    Binary_tree<int> *delete_helper(int data, Binary_tree<int> *root) // delet is an inbuilt keyword so we are using delet_helper as function name
                                                                      //  our data type is pointer of type node because root might change  na
    {
        if (root == NULL) // jo node dundh rhe thee wo mili nai/shuru mein hi root NULL tha
        {
            return root;
        }
        if (root->data == data)
        {
            if (root->left == NULL && root->right == NULL) // leaf node
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL || root->right == NULL) // node with 1 child
            {
                if (root->left == NULL)
                {
                    // delete root;agar ye call kr dia toh ye apne aae ka sara ka sara tree delete kr dega
                    // return root->right;
                }
                if (root->right == NULL)
                {
                    return root->left;
                }
            }
            else // two children
            {
                Binary_tree<int> *max_node = find_maximum(root->left);
                root->data = max_node->data;
                delete_helper(max_node->data, max_node);
            }
        }
    }

public:
    BST() // by default root will have garbage value that is not rigght so we initialed it yyo NULL
    {
        root = NULL;
    }
    ~BST()
    {
        delete root; // delete root krne se binary tree ki class ka destrutor call hoga aur tree delete ho jayega
    }
    bool getData(int data) // user will call this function on root eg root.getData() or root->getdata() agar hmien recursive calls krni hai root badal badal ke uske lie helper function bnaana padhega jo private mein bnaya hai.Kyu bnaya hai private mein?hm minimum cheeze public krne ki koshish krte  hain jo cheez public krne ki koi need hi nai hai usse public kyu krien
    {
        return getData_helper(data, root);
    }
    void insert(int data)
    {
        this->root = insert_helper(data, this->root); // bhai root update bhi toh karoge jab insertion ho jayegi
    }                                                 // bina this ke bhi kr skte hain
    void delete_root(int data)
    {
        this->root = delete_helper(data, this->root); // bhai root update bhi toh karoge jab deletion ho jayegi
    }                                                 // bina this ke bhi kr skte hain
};
int main()
{
    BST *B = new BST();
    delete B;
}