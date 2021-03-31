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
int qPartition(vector<int> & arr,int low,int high){
    cout<<"range: "<<low<<' '<<high<<endl;
    int key = arr[high];
    int keyIndex = high;
    int flag = 0;

    while(low<high){
//      Ҫȷ������Ķ���key����ô����Ҫ���Ҵ��������������ȥ��
//      ��ǰ�Ҵ����
        while(low<high && arr[low]<=key)low++;
//      �Ӻ���С����
        while(low<high && arr[high]>=key)high--;

        printArr(arr);
        cout<<"Swap: "<<arr[low]<<' '<<arr[high]<<" index: "<<low<<' '<<high<<endl;
        swap(arr[high],arr[low]);
        printArr(arr);
//        flag++;
//        if(flag>8)break;
    }
//  ��low==high��ʱ����Ա�֤ǰ�������С�ڵ���key����ʱ����low��key
    swap(arr[low],arr[keyIndex]);
    printArr(arr);
    cout<<"return: "<<high<<endl;
    return low;
}
void qSort(vector<int> & arr,int low,int high){
    if(low<high){
        int mid = qPartition(arr,low,high);

        qSort(arr,low,mid-1);
//        return;
        qSort(arr,mid+1,high);
    }
}
int main(){
    vector<int> nums1 = {7,6,5,4,3,2,1};
    printArr(nums1);
    cout<<"--------------"<<endl;
    qSort(nums1,0,nums1.size()-1);
    printArr(nums1);
    return 0;
}
