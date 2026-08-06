        {
            result.push_back(node);
            return;
        }
        if(root->left)
        {
            addLeaves(node->left,result);
        }
        if(root->right)
        {
            addLeaves(node->right,result);
        }
    }

    void addRightBoundary(Node* node,vector<int>&result)
    {
        Node* curr = node->right;
        vector<int>temp;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                temp.push_back(curr->val);
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        for(int i = 0;i<temp.size();i++)
        {
            result.push_back(temp[temp.size()-i-1]);
        }