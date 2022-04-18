#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start

struct S{
    S *p;
    int rank, l, r;
};

void make_set(S *x, int l, int r){
    x->p = x;
    x->rank = 0;
    x->l = l;
    x->r = r;
}

void link(S *x, S *y){
    if(x->rank > y->rank){
        y->p = x;
        x->l = min(x->l, y->l);
        x->r = max(x->r, y->r);
    }
    else{
        x->p = y;
        if(x->rank == y->rank)y->rank++;
        y->l = min(x->l, y->l);
        y->r = max(x->r, y->r);
    }
}

S *find(S *x){
    if(x != x->p)
        x->p = find(x->p);
    return x->p;
}

void Union(S *x, S *y){
    link(find(x), find(y));
}

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<S*>> m(row, vector<S*>(col, nullptr));
        for(int t = 0; t < cells.size(); t++){
            int i = cells[t][0] - 1, j = cells[t][1] - 1;
            m[i][j] = new S;
            make_set(m[i][j], j, j);
            for(int di = i - 1; di <= i + 1; di++)
                for(int dj = j - 1; dj <= j + 1; dj++)
                    if(di >= 0 && di < row && dj >= 0 && dj < col && m[di][dj])
                        Union(m[i][j], m[di][dj]);
            auto temp = find(m[i][j]);
            if(temp->l == 0 && temp->r == col - 1)return t;
        }
        return cells.size();
    }
};
// @lc code=end

int main(){
    int row = 5, col = 2;
    vector<vector<int>> cells{{5, 1}, {1, 2}, {3, 1}, {2, 2}};
    Solution s;
    cout << s.latestDayToCross(row, col, cells);
}