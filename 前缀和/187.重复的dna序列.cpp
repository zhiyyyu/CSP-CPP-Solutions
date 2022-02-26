/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> ans;
    vector<int> num;
    vector<int> diff;
    vector<int> prefix;
    unordered_map<int, int> hash;

    vector<string> findRepeatedDnaSequences(string s) {
        static unordered_map<char, int> umap = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        static int pow_4_10 = pow(4, 9);
        int n = s.length();
        if(n <= 10){
            return {};
        }
        num = vector<int>(n - 9, 0);
        diff = vector<int>(n - 10, 0);
        prefix = vector<int>(n - 10, 0);
        int num_s = 0;
        for (int i = 0; i < 10;i++){
            num_s *= 4;
            num_s += umap[s[i]];
        }
        hash[num_s]++;
        // num[0] = num_s;
        for (int i = 10; i < n; i++){
            num_s -= pow_4_10 * umap[s[i - 10]];
            num_s *= 4;
            num_s += umap[s[i]];
            hash[num_s]++;
            // num[i - 9] = num_s;
            // diff[i - 10] = num[i - 9] - num[i - 10];
        }
        // int sum = 0;
        // for (int i = 0; i < n - 10;i++){
        //     sum += diff[i];
        //     prefix[i] = sum;
        // }
        for(const auto& [k, v]: hash){
            if(v > 1){
                string ss = "aaaaaaaaaa";
                int num_s = k;
                for (int i = 9; i >= 0;i--){
                    ss[i] = getChar(num_s % 4);
                    num_s /= 4;
                }
                ans.push_back(ss);
            }
        }
        return ans;
    }

    char getChar(int c){
        char ret;
        switch (c){
            case 0:
                ret = 'A';
                break;
            case 1:
                ret = 'C';
                break;
            case 2:
                ret = 'G';
                break;
            case 3:
                ret = 'T';
                break;
        }
        return ret;
    }
};
// @lc code=end

