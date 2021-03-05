#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int findInsertIndex(vector<int>& nums,int high, int num){
    int low = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
//      ��low==highʱmid==low==high
//      ���num<mid highǰ�ƴ�ʱ��high����Ҫ�����λ��
//      ����num>=mid high������ʱ��high��λ�ü����涼���ڵ���high��highҲ��Ҫ����λ�á�
//      ֮��low+1����ѭ��
//      Ҳ����˵low-high=1
        if(num<nums[mid]) high = mid-1;
        else low = mid+1;
    }
    return nums[high]==num?high:-1;
}
void printArr(vector<int> & nums){
    for(auto e:nums){
        cout<<e<<' ';
    }
    cout<<endl;
}
int main(){
    vector<int> test = {1,2,3,4,5,6,7,8,9,10};
    vector<int> nums = {1,2,3,4,5,6,8,9,10};
    for(auto e:test){
        int index = findInsertIndex(nums,nums.size()-1,e);
        cout<<"index: "<<index<<"num: "<<((index==-1)?INT_MAX:nums[index])<<endl;
    }

    return 0;
}

