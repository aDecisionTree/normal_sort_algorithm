#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    std::sort(nums.begin(), nums.end(), std::less<int>());

//    cout<<"sort nums: ";
//    for(int i:nums){
//        cout<<i<<' ';
//    }
//    cout<<endl;

    for (int i = 0; i < N - 2; ++i) {
        if (nums[i] > 0) break;
        // 去重，因为当nums[i]=num[i-1]的时候，num[i]所有的情况已经在前一个循环的num[i-1]中计算过了
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // 对后面两个数做双指针逐渐向中间靠拢，取值。直到双指针碰头，跳出循环
        int l = i + 1;
        int r = N - 1;
        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];
            if (s > 0) {
                // 和比零大说明第三位数的指针需要前移，以此减少和的值
                --r;
            } else if (s < 0) {
                // 和比零小说明第二位数的指针需要后移，以此加大和的值
                ++l;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                //和之前一样，去重，当相等的时候继续移动，不等的时候保持自增后的指针。
                while (l < r && nums[l] == nums[++l]);
                while (l < r && nums[r] == nums[--r]);
            }
        }
    }
    return res;

}
int main(){
//    vector<int> nums = {-1, 0, 1, 2, 3, -3, -1, -4};
//    vector<int> nums = {0,0,0};
//    vector<int> nums = {-1,0,1,0};
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    auto results = threeSum(nums);

    for(auto result:results){
        for(auto element: result){
            cout<<element<<' ';
        }
        cout<<endl;
    }
    return 0;
}
