/*
 * @lc app=leetcode.cn id=2485 lang=c
 *
 * [2485] 找出中枢整数
 */


// @lc code=start
int pivotInteger(int n){

    int resultTarget = -1;

    for (int x = 1; x <= n; x++) {

        if ((((x) * (x + 1)) / 2) == (((n - x + 1) * (x + n)) / 2)) {

            resultTarget = x;
            break;
        }
    }

    return resultTarget;
}


// @lc code=end

