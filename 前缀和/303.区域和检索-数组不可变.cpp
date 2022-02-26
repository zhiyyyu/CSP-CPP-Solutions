/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray {
public:
    vector<int> prefix{0};

    NumArray(vector<int>& nums) {
        int sum = 0;
        for(const auto& e: nums){
            sum += e;
            prefix.emplace_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

