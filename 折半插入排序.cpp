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
//      ����num>=mid high������ʱ��high�ĺ��涼���ڵ���high��highҲ��Ҫ����λ�á�
//      ֮��low+1����ѭ��
//      Ҳ����˵low-high=1
        if(num<nums[mid]) high = mid-1;
        else low = mid+1;
        cout<<low <<' '<<mid<<' '<<high<<endl;
    }
    return high;
}
void printArr(vector<int> & nums){
    for(auto e:nums){
        cout<<e<<' ';
    }
    cout<<endl;
}
int main(){
    vector<int> nums = {7,3,4,5,6,1,2};
    for(int i =1;i<nums.size();i++){
        int index = findInsertIndex(nums,i-1,nums[i]);
        cout<<"insert index"<<index<<endl;
        int value = nums[i];
        for(int j=i;j>index+1;j--){
            nums[j]=nums[j-1];
        }
        nums[index+1]=value;
        printArr(nums);
    }

    return 0;
}
