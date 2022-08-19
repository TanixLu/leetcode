#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
public:
    struct pair_hash{
        size_t operator()(const pair<int, int>& pr) const {
            return pr.first * 31 + pr.second;
        }
    };

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        const int n = rectangles.size();
        int left = rectangles[0][0], bottom = rectangles[0][1],
            right = rectangles[0][2], top = rectangles[0][3];
        long long int area = rectangleArea(rectangles[0]);
        unordered_set<pair<int, int>, pair_hash> points;
        points.emplace(pair{left, top});
        points.emplace(pair{left, bottom});
        points.emplace(pair{right, top});
        points.emplace(pair{right, bottom});
        for(int i = 1; i < n; i++){
            auto& rect = rectangles[i];
            int rectLeft = rect[0], rectBottom = rect[1], rectRight = rect[2], rectTop = rect[3];
            area += rectangleArea(rect);
            left = min<int>(left, rectLeft);
            bottom = min<int>(bottom, rectBottom);
            right = max<int>(right, rectRight);
            top = max<int>(top, rectTop);

            if(points.find(pair{rectLeft, rectTop}) == points.end()) points.emplace(pair{rectLeft, rectTop});
            else points.erase(points.find(pair{rectLeft, rectTop}));
            if(points.find(pair{rectLeft, rectBottom}) == points.end()) points.emplace(pair{rectLeft, rectBottom});
            else points.erase(points.find(pair{rectLeft, rectBottom}));
            if(points.find(pair{rectRight, rectTop}) == points.end()) points.emplace(pair{rectRight, rectTop});
            else points.erase(points.find(pair{rectRight, rectTop}));
            if(points.find(pair{rectRight, rectBottom}) == points.end()) points.emplace(pair{rectRight, rectBottom});
            else points.erase(points.find(pair{rectRight, rectBottom}));
        }
        if(points.find(pair{left, top}) == points.end()) points.emplace(pair{left, top});
            else points.erase(points.find(pair{left, top}));
            if(points.find(pair{left, bottom}) == points.end()) points.emplace(pair{left, bottom});
            else points.erase(points.find(pair{left, bottom}));
            if(points.find(pair{right, top}) == points.end()) points.emplace(pair{right, top});
            else points.erase(points.find(pair{right, top}));
            if(points.find(pair{right, bottom}) == points.end()) points.emplace(pair{right, bottom});
            else points.erase(points.find(pair{right, bottom}));
        vector<int> bigRect{left, bottom, right, top};
        return area == rectangleArea(bigRect) && points.empty();
    }

    bool rectangleOverlap(vector<int>& rect1, vector<int>& rect2){
        int rect1Left = rect1[0], rect1Bottom = rect1[1], rect1Right = rect1[2], rect1Top = rect1[3];
        int rect2Left = rect2[0], rect2Bottom = rect2[1], rect2Right = rect2[2], rect2Top = rect2[3];
        return rect1Left < rect2Right && rect1Right > rect2Left && rect1Top > rect2Bottom && rect1Bottom < rect2Top;
    }

    long long int rectangleArea(vector<int>& rect){
        return ((long long int)rect[2] - rect[0]) * (rect[3] - rect[1]);
    }
};
// @lc code=end

int main(){
    vector<vector<int>> rects{{0,0,4,1},{7,0,8,2},{6,2,8,3},{5,1,6,3},{4,0,5,1},{6,0,7,2},{4,2,5,3},{2,1,4,3},{0,1,2,2},{0,2,2,3},{4,1,5,2},{5,0,6,1}};
    Solution s;
    cout << s.isRectangleCover(rects);
}
