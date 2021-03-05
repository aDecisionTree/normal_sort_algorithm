#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void printArr(vector<int> & nums){
    for(auto e:nums){
        cout<<e<<' ';
    }
    cout<<endl;
}
struct TreeNode{
    int val;
    TreeNode * lchild;
    TreeNode *rchild;
    TreeNode(int x):val(x),lchild(nullptr),rchild(nullptr){}
};
void printBST(TreeNode * node){
//    DFS
    if(node==nullptr)return ;
    printBST(node->lchild);
    cout<<node->val<<' ';
    printBST(node->rchild);
}
void insertBST(TreeNode * root,int num){
    if(num > root->val){
        if(root->rchild==nullptr){
            root->rchild = new TreeNode(num);
            return ;
        }
        insertBST(root->rchild,num);
    }else{
        if(root->lchild==nullptr){
            root->lchild = new TreeNode(num);
            return ;
        }
        insertBST(root->lchild,num);
    }
}
//  BST
TreeNode* buildBST(vector<int> & arr){
    if(!arr.size()) return nullptr;
    TreeNode * root = new TreeNode(arr[0]);
    for(int i = 1; i<arr.size() ; i++){
        insertBST(root,arr[i]);
    }
    return root;
}

int main(){
    vector<int> nums1 = {1000,999,123,45,56,67,3,0,22,87};
    TreeNode * root = buildBST(nums1);
    printBST(root);
    return 0;
}
