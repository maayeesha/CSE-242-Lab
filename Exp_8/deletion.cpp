//Maayeesha Farzana
//ID: 1804069


#include<bits/stdc++.h>
using namespace std;

struct Node{
int info;
Node* left;
Node* right;
};


Node* getPos(Node* root, int val)
{
    if(root->info > val)
    {
        if(root->left == nullptr) return root;
        else return getPos(root->left,val);
    }
     else if(root->info < val)
    {
        if(root->right == nullptr) return root;
        else return getPos(root->right,val);
    }
    else return root; // for deletion
}
Node* inorderSuc(Node* root)
{
    while(root && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}
Node* deletion(Node* root,int x)
{
    if(root == nullptr) return root;

    else if(x < root->info)
    {
        root->left = deletion(root->left,x);
    }
    else if(x > root->info)
    {
        root->right = deletion(root->right,x);
    }
    else
    {
        if(root->left == nullptr && root->right == nullptr)
            return nullptr;
        else if(root->left == nullptr)
        {
            Node* t = root->right;
            delete root;
            return t;
        }
         else if(root->right == nullptr)
        {
            Node* t = root->left;
            delete root;
            return t;
        }


            Node* t = inorderSuc(root->right);
            root->info = t->info;
            root->right = deletion(root->right,t->info);
    }
        return root;
}


void Inorder(Node* currNode)
{
    if(currNode == nullptr) return;
    Inorder(currNode->left);
    cout<<currNode->info<<endl;
    Inorder(currNode->right);
}

int main()
{
    int val,x;
    Node* root = nullptr;
    while(1)
    {
        cin>>val;
        if(val == -1) break;

        Node* currNode = new Node;
        currNode->info = val;
        currNode->left = nullptr;
        currNode->right = nullptr;

        if(root == nullptr) root = currNode;
        else
        {
            Node* toInsert = getPos(root,val);
            if(toInsert->info > val)
            {
                toInsert->left = currNode;
            }
            else toInsert->right = currNode;

        }
    }
    Inorder(root);
    cout<<"Insert an element to delete: ";
    cin>>x;

    deletion(root,x);
    cout<<"After deleting "<<x<<endl;
    Inorder(root);

}

