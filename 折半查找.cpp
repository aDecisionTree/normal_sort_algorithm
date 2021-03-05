#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int findInsertIndex(vector<int>& nums,int high, int num){
    int low = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
//      当low==high时mid==low==high
//      如果num<mid high前移此时，high就是要插入的位置
//      否则num>=mid high不动此时，high的位置及后面都大于等于high，high也是要插入位置。
//      之后low+1跳出循环
//      也就是说low-high=1
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

