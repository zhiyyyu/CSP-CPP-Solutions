// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem304.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0;i<m;i++){
            int sum = 0;
            for (int j = 0;j<n;j++){
                sum += matrix[i][j];
                // cout << sum << " ";
                prefix[i][j] = sum;
                if(i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                // cout << i << " " << j << " " << prefix[i][j] << endl;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefix[row2][col2];
        if(row1 > 0)
            ans -= prefix[row1 - 1][col2];
        if(col1 > 0)
            ans -= prefix[row2][col1 - 1];
        if(row1 > 0 && col1 > 0)
            ans += prefix[row1 - 1][col1 - 1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

