#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
};

bool childrensum(Node* root)
{
    if(root==NULL)
    return true;

    if(root->left==NULL && root->right==NULL)
    return true;

    int sum=0;
    if(root->left!=NULL)
    sum+=root->left->key;

    if(root->right!=NULL)
    sum+=root->right->key;

    return (root->key==sum && (childrensum(root->left),childrensum(root->right)));

}

int main()
{
    Node *root=new Node(10);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);

    cout<<childrensum(root);


    return 0;
}