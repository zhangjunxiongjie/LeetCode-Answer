/*
 * @lc app=leetcode.cn id=2124 lang=c
 *
 * [2124] 检查是否所有 A 都在 B 之前
 */

// @lc code=start


bool checkString(char * s){
    
    bool result = true;
    int index = strlen(s);

    for (; index >= 0; index--) {

        if (s[index] == 'a') {

            result = false;
        }

        if ((!result) && s[index] == 'b') {
            
            break;
        }
    }

    if (index == -1) {

        return true;
    }
    else {

        return result;
    }
}


// @lc code=end

