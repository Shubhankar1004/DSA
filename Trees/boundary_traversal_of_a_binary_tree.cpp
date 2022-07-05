// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void nodes(Node *root,vector<int>&v,int &k)
    {
        if (root->left==NULL && root->right==NULL)
        {
            //k++;
            //if (k==1);
            //else
            v.push_back(root->data);
        }
        if (root->left)
        nodes(root->left,v,k);
        if (root->right)
        nodes(root->right,v,k);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>v;
        if (root==NULL)
        return v;
        v.push_back(root->data);
        if (root->left==NULL && root->right==NULL)
        return v;
        Node *l=root;
        if (root->left)
        {
            l=l->left;
            while(l->left!=NULL || (l->left==NULL && l->right!=NULL))
            {
                v.push_back(l->data);
                if (l->left!=NULL)
                l=l->left;
                else if(l->left==NULL && l->right!=NULL)
                l=l->right;
                else
                break;
            }
        }
        //if (l!=NULL)
        //v.push_back(l->data);
        //if (l->left==NULL && l->right!=NULL)
        //v.push_back(l->right->data);
        int k=0;
        nodes(root,v,k);
        //int s=v.pop_back();
        Node *r=root;
        if (root->right)
        {
            r=r->right;
            vector<int>temp;
            while(r->right!=NULL || (r->right==NULL && r->left!=NULL))
            {
                temp.push_back(r->data);
                if (r->right!=NULL)
                r=r->right;
                else if(r->right==NULL && r->left!=NULL)
                r=r->left;
                else
                break;
            }
            //if (r!=NULL && r!=root)
            //v.push_back(r->data);
            //if (r->right==NULL && r->left!=NULL)
            //v.push_back(r->left->data);
            //if(temp.empty())
            //v.push_back(s);
            reverse(temp.begin(),temp.end());
            for (int i=0;i<temp.size();i++)
            {
                v.push_back(temp[i]);
            }
            
        }
        return v;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
