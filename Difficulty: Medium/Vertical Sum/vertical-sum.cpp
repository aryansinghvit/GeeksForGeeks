/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
  
    void verticalsum(Node* root,int num,map<int,int> &mp){
        if(root==NULL)return;
        mp[num]+=root->data;
        verticalsum(root->left,num-1,mp);
        verticalsum(root->right,num+1,mp);
        return;
        
    }
    vector<int> verticalSum(Node* root) {
        // code here
        map<int,int> mp;
        verticalsum(root,0,mp);
        vector<int> ans;
        for(auto it:mp){
        ans.push_back(it.second);
        }
        return ans;
        
    }
};