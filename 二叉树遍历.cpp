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
void printTree(TreeNode * node){
//    DFS
    if(node==nullptr)return ;
    printTree(node->lchild);
    cout<<node->val<<' ';
    printTree(node->rchild);
}
void whilePrintTreeIn(TreeNode * node){
    // InOrder
    stack<TreeNode *> nodeStack;
    // node不为空,或Stack不为空
    while(node||!nodeStack.empty()){
        if(node){
            // 当node不为空时访问左节点
            nodeStack.push(node);
            node = node->lchild;
        }else{
            node = nodeStack.top();
            nodeStack.pop();
            cout<<node->val<<' ';
            node = node->rchild;
        }
    }
}
void whilePrintTreePre(TreeNode * node){
    // PreOrder
    stack<TreeNode *> nodeStack;
    // node不为空,或Stack不为空
    while(node||!nodeStack.empty()){
        if(node){
            // 当node不为空时访问左节点
            nodeStack.push(node);
            cout<<node->val<<' ';
            node = node->lchild;
        }else{
            node = nodeStack.top();
            nodeStack.pop();
            node = node->rchild;
        }
    }
}
void whilePrintTreePost(TreeNode * node){
    // PostOrder
    stack<TreeNode *> nodeStack;
    TreeNode * pre = nullptr;
    while(node || !nodeStack.empty()){
        if(node){
            // 循环访问左孩子并入栈
            nodeStack.push(node);
            node = node->lchild;
        }else{
            // 左孩子为空，访问栈顶回到不为空的上一个节点，此时不能出栈，还不到输出该节点值的时候
            node = nodeStack.top();
            // 此时已知该节点的左孩子为空，访问右孩子
            node = node->rchild;
            if(node && node != pre){
                // 当前节点（右孩子）不为空，进栈
                nodeStack.push(node);
                // 继续访问当前节点左孩子
                node = node->lchild;
            }else{
                // 若当前节点（右孩子）为空，则表明上一个节点（栈顶节点）为叶子节点，是需要输出值的节点，此时出栈访问叶子节点
                node = nodeStack.top();
                nodeStack.pop();
                cout<<node->val<<' ';
                // 叶子节点访问完成之后记录当前节点已经访问，下次避免访问该节点。
                pre = node;
                // 将node置为空指针，避免下次循环继续访问左孩子
                node = nullptr;
            }

        }
    }
}
TreeNode* buildTreeOnLevel(vector<int> & arr){
//  层次构建
    if(arr.size()<1) return nullptr;
    TreeNode * root = new TreeNode(arr[0]);
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    TreeNode * ptr = nullptr;
//    左孩子是否需要设置的标志
    bool lNodeSet = true;
    for(int i =1;i<arr.size();i++){
//        当指针为空的时候从队列中取出一个节点
        if(ptr==nullptr){
            ptr = nodeQueue.front();
            nodeQueue.pop();
        }
        if(arr[i]==-1){
            if(ptr->lchild==nullptr){
                lNodeSet=false;
                continue;
            }
            if(ptr->rchild==nullptr){
                lNodeSet=true;
                ptr=nullptr;
                continue;
            }
        }
//        从左往右构建节点，并将节点放入队列中。
        if(ptr->lchild==nullptr){
            if(lNodeSet){
                ptr->lchild = new TreeNode(arr[i]);
                nodeQueue.push(ptr->lchild);
                continue;
            }

        }
//        当构建右节点完成的时候，将节点放入队列中，并将当前ptr置为空，以便下次循环开始时指向新节点
        if(ptr->rchild==nullptr){
            ptr->rchild = new TreeNode(arr[i]);
            nodeQueue.push(ptr->rchild);
            lNodeSet=true;
            ptr = nullptr;
            continue;
        }
    }
    return root;
}

int main(){
    vector<int> nums1 = {1,2,3,-1,4,5,-1,6,7,8,9};
    TreeNode * root = buildTreeOnLevel(nums1);
    whilePrintTreePost(root);
    return 0;
}
