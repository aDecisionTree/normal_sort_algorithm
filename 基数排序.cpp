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

//  本基数排序只适用于整数，用于浮点数排序效率太低

void bucketSort(vector<int> & arr){
    int maxNum = *max_element(arr.begin(),arr.end());
    int base = 1;
    while(maxNum/base){
        int bucket[10]={0};
        vector<int> arrCopy(arr);
        cout<<"Copy array: ";printArr(arrCopy);
//        计算桶中元素个数
        for(auto ele:arrCopy){
            bucket[ele / base % 10]++;
        }
//        计算累积元素下标
        for(int i = 1;i<10 ;i++){
            bucket[i]+=bucket[i-1];
        }
//        print bucket
        for(int i = 0 ; i<10 ; i++){
            cout<<bucket[i]<<'*';
        }cout<<endl;
//        移动元素到下标中，由于bucket下标是从n自减到0的，新序列中第n个的数一定要在n-1的后面（保持相对的位置顺序），
//        所以这里注意一定要倒序遍历，把靠后较大的数先放置进arr，不然会导致组内逆序。
        for(int i = arr.size()-1; i>=0 ; i--){
            cout<<"Set: "<<bucket[arrCopy[i] / base % 10]<<" , "<<arrCopy[i]<<endl;
            arr[bucket[arrCopy[i] / base % 10]-1] = arrCopy[i];
            bucket[arrCopy[i] / base % 10]--;
        }
        base*=10;
        printArr(arr);
    }
    cout<<maxNum<<endl;
}
void bucketSort_reverse(vector<int> & arr){
    int maxNum = *max_element(arr.begin(),arr.end());
    int base = 1;
    while(maxNum/base){
        int bucket[10]={0};
        vector<int> arrCopy(arr);
        cout<<"Copy array: ";printArr(arrCopy);
//        计算桶中元素个数
        for(auto ele:arrCopy){
            bucket[9-ele / base % 10]++;
        }
//        print bucket
        for(int i = 0 ; i<10 ; i++){
            cout<<bucket[i]<<'*';
        }cout<<endl;
//        计算累积元素下标
        for(int i = 1;i<10 ;i++){
            bucket[i]+=bucket[i-1];
        }
//        print bucket
        for(int i = 0 ; i<10 ; i++){
            cout<<bucket[i]<<'*';
        }cout<<endl;
//        移动元素到下标中，由于bucket下标是从n自减到0的，新序列中第n个的数一定要在n-1的后面（保持相对的位置顺序），
//        所以这里注意一定要倒序遍历，不然会导致组内逆序。
        for(int i = arr.size()-1; i>=0 ; i--){
            cout<<"Set: "<<bucket[9 - arrCopy[i] / base % 10]<<" , "<<arrCopy[i]<<endl;
            arr[bucket[9-arrCopy[i] / base % 10]-1] = arrCopy[i];
            bucket[9-arrCopy[i] / base % 10]--;
        }
        base*=10;
        printArr(arr);
    }
}

int main(){
    vector<int> nums1 = {1000,999,123,45,56,67,3,0,22,87};
    printArr(nums1);
    bucketSort_reverse(nums1);
    cout<<"--------------"<<endl;
    printArr(nums1);
    return 0;
}
