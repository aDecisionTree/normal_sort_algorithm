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
    // node��Ϊ��,��Stack��Ϊ��
    while(node||!nodeStack.empty()){
        if(node){
            // ��node��Ϊ��ʱ������ڵ�
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
    // node��Ϊ��,��Stack��Ϊ��
    while(node||!nodeStack.empty()){
        if(node){
            // ��node��Ϊ��ʱ������ڵ�
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
            // ѭ���������Ӳ���ջ
            nodeStack.push(node);
            node = node->lchild;
        }else{
            // ����Ϊ�գ�����ջ���ص���Ϊ�յ���һ���ڵ㣬��ʱ���ܳ�ջ������������ýڵ�ֵ��ʱ��
            node = nodeStack.top();
            // ��ʱ��֪�ýڵ������Ϊ�գ������Һ���
            node = node->rchild;
            if(node && node != pre){
                // ��ǰ�ڵ㣨�Һ��ӣ���Ϊ�գ���ջ
                nodeStack.push(node);
                // �������ʵ�ǰ�ڵ�����
                node = node->lchild;
            }else{
                // ����ǰ�ڵ㣨�Һ��ӣ�Ϊ�գ��������һ���ڵ㣨ջ���ڵ㣩ΪҶ�ӽڵ㣬����Ҫ���ֵ�Ľڵ㣬��ʱ��ջ����Ҷ�ӽڵ�
                node = nodeStack.top();
                nodeStack.pop();
                cout<<node->val<<' ';
                // Ҷ�ӽڵ�������֮���¼��ǰ�ڵ��Ѿ����ʣ��´α�����ʸýڵ㡣
                pre = node;
                // ��node��Ϊ��ָ�룬�����´�ѭ��������������
                node = nullptr;
            }

        }
    }
}
TreeNode* buildTreeOnLevel(vector<int> & arr){
//  ��ι���
    if(arr.size()<1) return nullptr;
    TreeNode * root = new TreeNode(arr[0]);
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    TreeNode * ptr = nullptr;
//    �����Ƿ���Ҫ���õı�־
    bool lNodeSet = true;
    for(int i =1;i<arr.size();i++){
//        ��ָ��Ϊ�յ�ʱ��Ӷ�����ȡ��һ���ڵ�
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
//        �������ҹ����ڵ㣬�����ڵ��������С�
        if(ptr->lchild==nullptr){
            if(lNodeSet){
                ptr->lchild = new TreeNode(arr[i]);
                nodeQueue.push(ptr->lchild);
                continue;
            }

        }
//        �������ҽڵ���ɵ�ʱ�򣬽��ڵ��������У�������ǰptr��Ϊ�գ��Ա��´�ѭ����ʼʱָ���½ڵ�
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
