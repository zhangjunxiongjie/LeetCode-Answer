/*
 * @lc app=leetcode.cn id=1952 lang=c
 *
 * [1952] 三除数
 */

// @lc code=start


bool isThree(int n){

    unsigned char range = (unsigned char)sqrt((double)n);
    unsigned short resultCount = 0;

    for (unsigned char i = 1; i <= range; i++) {

        if ((n % i) == 0) {
            
            if (range != i) {

                resultCount += 2;
            }
            else {

                resultCount++;
            }

            if (resultCount > 3) {

                return false;
            }
        }
    }

    if (resultCount == 3) {

        return true;
    }
    else {

        return false;
    }
}


// @lc code=end

