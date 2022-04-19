#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

/*
 * @lc app=leetcode id=782 lang=cpp
 *
 * [782] Transform to Chessboard
 */

// @lc code=start
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        // examine rows
        vector<vector<int>> row_pattern(2, vector<int>(n));
        vector<int> row_pattern_count(2, 0);
        int row_pattern_num = 0;
        for(int i = 0; i < n; i++){
            int p = board[i][0];
            if(row_pattern_count[p] == 0){
                row_pattern_count[p] = 1;
                row_pattern[p] = board[i];
                row_pattern_num++;
                if(row_pattern_num == 1){
                    int count[2]{0};
                    for(int j = 0; j < n; j++)count[row_pattern[p][j]]++;
                    if(count[1] - count[0] < -1 || count[1] - count[0] > 1)return -1;
                }
                else{
                    for(int j = 0; j < n; j++)
                        if(row_pattern[p][j] == row_pattern[1 - p][j])
                            return -1;
                }
            }
            else{
                for(int j = 0; j < n; j++)
                    if(board[i][j] != row_pattern[p][j])
                        return -1;
                row_pattern_count[p]++;
            }
        }
        if(row_pattern_num != 2 || row_pattern_count[1] - row_pattern_count[0] < -1
        || row_pattern_count[1] - row_pattern_count[0] > 1)return -1;

        // examine columns
        vector<vector<int>> column_pattern(2, vector<int>(n));
        vector<int> column_pattern_count(2, 0);
        int column_pattern_num = 0;
        for(int i = 0; i < n; i++){
            int p = board[0][i];
            if(column_pattern_count[p] == 0){
                column_pattern_count[p] = 1;
                for(int j = 0; j < n; j++)column_pattern[p][j] = board[j][i];
                column_pattern_num++;
                if(column_pattern_num == 1){
                    int count[2]{0};
                    for(int j = 0; j < n; j++)count[column_pattern[p][j]]++;
                    if(count[1] - count[0] < -1 || count[1] - count[0] > 1)return -1;
                }
                else{
                    for(int j = 0; j < n; j++)
                        if(column_pattern[p][j] == column_pattern[1 - p][j])
                            return -1;
                }
            }
            else{
                for(int j = 0; j < n; j++)
                    if(board[j][i] != column_pattern[p][j])
                        return -1;
                column_pattern_count[p]++;
            }
        }
        if(column_pattern_num != 2 || column_pattern_count[1] - column_pattern_count[0] < -1
        || column_pattern_count[1] - column_pattern_count[0] > 1)return -1;

        // min move num
        int res = 0;
        // row
        vector<int>& pattern = row_pattern[0];
        int num1 = 0;
        for(auto i: pattern)num1 += i;
        int inplace1 = 0;
        if(num1 * 2 > n){ // 1 first
            for(int i = 0; i < n; i += 2)
                inplace1 += pattern[i];
            res += num1 - inplace1;
        }
        else if(num1 * 2 < n){ // 0 first
            for(int i = 1; i < n; i += 2)
                inplace1 += pattern[i];
            res += num1 - inplace1;
        }
        else{ // 0 or 1 first
            for(int i = 0; i < n; i += 2)
                inplace1 += pattern[i];
            res += min(num1 - inplace1, inplace1);
        }
        // column
        pattern = column_pattern[0];
        num1 = 0;
        for(auto i: pattern)num1 += i;
        inplace1 = 0;
        if(num1 * 2 > n){ // 1 first
            for(int i = 0; i < n; i += 2)
                inplace1 += pattern[i];
            res += num1 - inplace1;
        }
        else if(num1 * 2 < n){ // 0 first
            for(int i = 1; i < n; i += 2)
                inplace1 += pattern[i];
            res += num1 - inplace1;
        }
        else{ // 0 or 1 first
            for(int i = 0; i < n; i += 2)
                inplace1 += pattern[i];
            res += min(num1 - inplace1, inplace1);
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    // vector<vector<int>> board{{0,1,1,0}, {0,1,1,0}, {1,0,0,1}, {1,0,0,1}};
    // vector<vector<int>> board{{0,1}, {1,0}};
    // vector<vector<int>> board{{1,0}, {1,0}};
    // vector<vector<int>> board{{1,0,0}, {0,1,1}, {1,0,0}};
    vector<vector<int>> board{{0,1}, {1,1}};
    cout << s.movesToChessboard(board);
}

