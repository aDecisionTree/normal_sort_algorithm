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

//  ����������ֻ���������������ڸ���������Ч��̫��

void bucketSort(vector<int> & arr){
    int maxNum = *max_element(arr.begin(),arr.end());
    int base = 1;
    while(maxNum/base){
        int bucket[10]={0};
        vector<int> arrCopy(arr);
        cout<<"Copy array: ";printArr(arrCopy);
//        ����Ͱ��Ԫ�ظ���
        for(auto ele:arrCopy){
            bucket[ele / base % 10]++;
        }
//        �����ۻ�Ԫ���±�
        for(int i = 1;i<10 ;i++){
            bucket[i]+=bucket[i-1];
        }
//        print bucket
        for(int i = 0 ; i<10 ; i++){
            cout<<bucket[i]<<'*';
        }cout<<endl;
//        �ƶ�Ԫ�ص��±��У�����bucket�±��Ǵ�n�Լ���0�ģ��������е�n������һ��Ҫ��n-1�ĺ��棨������Ե�λ��˳�򣩣�
//        ��������ע��һ��Ҫ����������ѿ���ϴ�����ȷ��ý�arr����Ȼ�ᵼ����������
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
//        ����Ͱ��Ԫ�ظ���
        for(auto ele:arrCopy){
            bucket[9-ele / base % 10]++;
        }
//        print bucket
        for(int i = 0 ; i<10 ; i++){
            cout<<bucket[i]<<'*';
        }cout<<endl;
//        �����ۻ�Ԫ���±�
        for(int i = 1;i<10 ;i++){
            bucket[i]+=bucket[i-1];
        }
//        print bucket
        for(int i = 0 ; i<10 ; i++){
            cout<<bucket[i]<<'*';
        }cout<<endl;
//        �ƶ�Ԫ�ص��±��У�����bucket�±��Ǵ�n�Լ���0�ģ��������е�n������һ��Ҫ��n-1�ĺ��棨������Ե�λ��˳�򣩣�
//        ��������ע��һ��Ҫ�����������Ȼ�ᵼ����������
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
