/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start

class Solution {
public:
                    //  -3       0        3         4       0        -1       9        2 
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int cy2 = min(ay2, by2); 
        int cy1 = max(ay1, by1);
        int cx2 = min(ax2, bx2);
        int cx1 = max(ax1, bx1);

        // 思路：高高选低，低低选高，如果选出来的大小反了，说明没有重合
        int hei = cy2>cy1 ? cy2-cy1 : 0;    
        int wid = cx2>cx1 ? cx2-cx1 : 0;    

        int wid1 = ax2 - ax1, hei1 = ay2 - ay1;
        int wid2 = bx2 - bx1, hei2 = by2 - by1;

        return wid1*hei1 + wid2*hei2 - hei*wid;

    }
};

// @lc code=end

