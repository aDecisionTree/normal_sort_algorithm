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
        // ȥ�أ���Ϊ��nums[i]=num[i-1]��ʱ��num[i]���е�����Ѿ���ǰһ��ѭ����num[i-1]�м������
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // �Ժ�����������˫ָ�������м俿£��ȡֵ��ֱ��˫ָ����ͷ������ѭ��
        int l = i + 1;
        int r = N - 1;
        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];
            if (s > 0) {
                // �ͱ����˵������λ����ָ����Ҫǰ�ƣ��Դ˼��ٺ͵�ֵ
                --r;
            } else if (s < 0) {
                // �ͱ���С˵���ڶ�λ����ָ����Ҫ���ƣ��Դ˼Ӵ�͵�ֵ
                ++l;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                //��֮ǰһ����ȥ�أ�����ȵ�ʱ������ƶ������ȵ�ʱ�򱣳��������ָ�롣
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
