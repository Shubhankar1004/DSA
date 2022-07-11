int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    Node* t=root;
    int maxie=INT_MAX;
    while(t!=NULL)
    {
        if (t->data<input)
        t=t->right;
        else if (t->data>input)
        {
            maxie=min(maxie,t->data);
            t=t->left;
        }
        else
        {
            maxie=t->data;
            break;
        }
    }
    if (maxie!=INT_MAX)
    return maxie;
    else
    return input;
    // Your code here
}
