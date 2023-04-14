/*
 * @lc app=leetcode.cn id=1736 lang=c
 *
 * [1736] 替换隐藏数字得到的最晚时间
 */

// @lc code=start


char * maximumTime(char * time){

    if ((time[0] == '?') && (time[1] == '?')) {

        time[0] = '2';
        time[1] = '3';
    }
    else if ((time[0] == '?')) {

        if (time[1] <= '3') {
            time[0] = '2';
        }
        else {
            time[0] = '1';
        }
    }
    else if ((time[1] == '?')) {

        if (time[0] == '2') {

            time[1] = '3';
        }
        else {

            time[1] = '9';
        }
    }
    else {

    }

    if (time[3] == '?') {

        time[3] = '5';
    }

    if (time[4] == '?') {

        time[4] = '9';
    }

    return time;
}

// @lc code=end

