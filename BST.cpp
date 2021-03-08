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
TreeNode * findMin(TreeNode * root){
    if(root->lchild==nullptr){
        return root;
    }
    return findMin(root->lchild);
}
TreeNode * pre = nullptr;
void deleteNode(TreeNode * root, int num){
    cout<<"cmp : "<<num<<','<<root->val<<endl;
    if(root==nullptr) return;
    if(num!=root->val){
        if(root->val > num){
            pre = root;
            deleteNode(root->lchild,num);
            return;
        }

        if(root->val < num){
            pre = root;
            deleteNode(root->rchild,num);
            return;
        }

    }
    cout<<"deleting "<<num<<endl;
    cout<<"node info "<<(root->lchild? root->lchild->val : -1)<<"  "<<(root->rchild? root->rchild->val:-1)<<endl;
    if(root->lchild==nullptr&&root->rchild==nullptr){
        if(pre->lchild==root)pre->lchild=nullptr;
        if(pre->rchild==root)pre->rchild=nullptr;
        delete root;
        root = nullptr;
        cout<<"root address "<<root<<endl;
        return ;
    }
    if(root->rchild==nullptr){
        root->val = root->lchild->val;
        root->rchild = root->lchild->rchild;
        TreeNode * delPtr = root->lchild;
        root->lchild = root->lchild->lchild;
        delete delPtr;
        cout<<"root info"<<(root->lchild? root->lchild->val : -1)<<"  "<<(root->rchild? root->rchild->val:-1)<<endl;
        return ;
    }
    if(root->lchild==nullptr){
        root->val = root->rchild->val;
        root->lchild = root->rchild->lchild;
        TreeNode * delPtr = root->rchild;
        root->rchild= root->rchild->rchild;
        delete delPtr;
        return ;
    }
    if(root->lchild!=nullptr&&root->rchild!=nullptr){
//        右子树最小点替换
        TreeNode * minPtr = findMin(root->rchild);
        root->val = minPtr->val;
        deleteNode(root->rchild,root->val);
        return ;
    }


}
int main(){
    vector<int> nums1 = {53,17,78,9,45,65,87,23,91};
    TreeNode * root = buildBST(nums1);
    printBST(root);
    cout<<endl<<"-----------"<<endl;

    deleteNode(root,53);
    printBST(root);
    cout<<endl<<root->val<<endl;

    return 0;
}
