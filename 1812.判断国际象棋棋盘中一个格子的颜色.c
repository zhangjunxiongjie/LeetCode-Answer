/*
 * @lc app=leetcode.cn id=1812 lang=c
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start


bool squareIsWhite(char * coordinates){

    if (((coordinates[0] - 'a') + (coordinates[1] - '0')) % 2 != 0) {

        return false;
    }
    else {

        return true;
    }
}

// @lc code=end

