#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node *right;

    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};

Node* ceil(Node* root,int x)
{
    Node* res=NULL;
    if(root==NULL)
    return res;

    while(root!=NULL)
    {
        if(root->key==x)
        return root;

        else if(root->key>x)
        root=root->left;

        else
        {
            res=root;
            root=root->right;
        }
    }

    return res;
}


int main()
{
    struct Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->left=new Node(3);
    root->left->right=new Node(7);
    root->right->left=new Node(12);
    root->right->right=new Node(20);

    int x=100;
    Node* temp=ceil(root,x);

    cout<<temp->key;

    

    return 0;
}