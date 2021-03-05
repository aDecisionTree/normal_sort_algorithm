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
void mergeOp(vector<int> & arr,int low,int mid,int high){
//  这里可以再优化复制的区域，减少时间。
    vector<int> arrCopy(arr);
//  合并两个数列
    int i,j,index;
    for(i=low,j=mid+1,index=low ; i<=mid&&j<=high ; index++){
        if(arrCopy[i]<arrCopy[j]){
            arr[index] = arrCopy[i++];
        }else{
            arr[index] = arrCopy[j++];
        }
    }
    if(i<=mid){
        for(int k=i ; k<=mid ; k++){
            arr[index++] = arrCopy[k];
        }
    }else{
        for(int k=j ; k<=high ; k++){
            arr[index++] = arrCopy[k];
        }
    }
}
void mergeOp_plus(vector<int> & arr,int low,int mid,int high){
//  优化代码。
    vector<int> arrCopy;
//  合并两个数列,用vector存储需要改变的数。
    int i=low,j=mid+1,index=low;
    while(i <= mid && j <= high){
        if(arr[i] > arr[j])
            arrCopy.push_back(arr[j++]);
        else
            arrCopy.push_back(arr[i++]);
    }
    while(i <= mid)
        arrCopy.push_back(arr[i++]);
    while(j <= high)
        arrCopy.push_back(arr[j++]);
    for(int i : arrCopy)
        arr[index++] = i;
}
void mergeSort(vector<int> & arr,int low,int high){
    if(low<high){
        int mid = low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        mergeOp_plus(arr,low,mid,high);
        printArr(arr);
    }
}
int main(){
    vector<int> nums1 = {10,9,8,7,6,5,4,3,2,1};
    printArr(nums1);
    mergeSort(nums1,0,nums1.size()-1);
    cout<<"--------------"<<endl;
    printArr(nums1);
    return 0;
}
