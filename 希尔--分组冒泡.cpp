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
void shellSort1(vector<int> & arr){
    int n = arr.size()-1;
    for(int dk=n/2;dk>0;dk/=2){
        for(int i=dk;i<=n;i++){
            int tmp=arr[i];
            int j;
            for(j = i-dk; j>=0&&arr[j]>tmp; j -= dk){
                arr[j+dk]=arr[j];
            }
            arr[j+dk]=tmp;
        }
    }

}
void shellSort2(vector<int> & arr){
    int n = arr.size()-1;
    for(int dk=n/2;dk>0;dk/=2){
//        cout<<"dk: "<<dk<<endl;
        for(int i=dk;i<=n;i++){
            for(int j = i; j-dk>=0&&arr[j-dk]>arr[j]; j -= dk){
//                printArr(arr);
//                cout<<" swap: "<<arr[j]<<' '<<arr[j-dk]<<" i,j,j-dk:"<<i<<','<<j<<','<<j-dk<<endl;
                swap(arr[j],arr[j-dk]);
//                printArr(arr);
            }
        }
    }

}
int main(){
    vector<int> nums1 = {7,3,4,5,1,6,2};
    printArr(nums1);
    shellSort1(nums1);
    printArr(nums1);
    cout<<"-----------------"<<endl;
    vector<int> nums2 = {7,3,1,4,5,6,2};
    shellSort2(nums2);
    printArr(nums2);


    return 0;
}
