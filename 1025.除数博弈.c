/*
 * @lc app=leetcode.cn id=1025 lang=c
 *
 * [1025] 除数博弈
 */

// @lc code=start


bool divisorGame(int n){
    
    bool resultFlag = false;

    while (true) {

        int x = 0;
        for (int i = 1; i <= (n - 1); i++) {
            
            // printf ("i: %d, \n", i);

            if ((n % i) == 0) {
                x = i;
                break;
            }            
        }

        if (x != 0) {

            n -= x;

            resultFlag = (!resultFlag);
            // printf ("bool: %c, n: %d, x: %d, \n", resultFlag, n, x);
        }
        else {

            break;
        }
    }

    return resultFlag;
}

// @lc code=end

