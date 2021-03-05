#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//  ��node��index = i
//  ��ônode��parent = (i-1)/2
//  child1=i*2+1
//  child2=i*2+1
//  https://www.bilibili.com/video/BV1Eb41147dK?from=search&seid=7050648321157556627
void printArr(vector<int> & nums){
    for(auto e:nums){
        cout<<e<<' ';
    }
    cout<<endl;
}
void heapify(vector<int>& arr,int boundary,int index){
    if(index>=boundary)return ;
    int childL = index*2 +1;
    int childR = index*2 +2;
    int indexMax = index;
    if(childL<=boundary && arr[childL]>arr[indexMax])indexMax=childL;
    if(childR<=boundary && arr[childR]>arr[indexMax])indexMax=childR;
    if(indexMax!=index){
        swap(arr[index],arr[indexMax]);
        //  �ݹ����µ���Heap
//        cout<<"index: "<<index<<endl;
//        printArr(arr);
        heapify(arr,boundary,indexMax);
    }
}
void buildHeap(vector<int> & arr){
    int n = arr.size()-1;
//  �����Ľڵ��parent����build��ȷ���ӵ��¾��Ƕ�
    for(int i=(n-1)/2 ; i>=0 ; i--){
        heapify(arr,n,i);
    }
}

void heapSort(vector<int> & arr){
    buildHeap(arr);
    printArr(arr);
    int n=arr.size()-1;
    for(int i=0;i<n;i++){
//      �����Ѷ��Ͷ�β���Ѷ����õ������������ţ�
        cout<<"swaping: "<<arr[0]<<' '<<arr[n-i]<<endl;
        swap(arr[0],arr[n-i]);
        cout<<"boundary: "<<n-i-1<<endl;
        heapify(arr,n-i-1,0);
        printArr(arr);
    }
}
int main(){
    vector<int> nums1 = {1,4,3,5,7};
    heapify(nums1,nums1.size()-1,0);
    printArr(nums1);
    cout<<"--------------"<<endl;
    heapSort(nums1);
    printArr(nums1);
    return 0;
}
