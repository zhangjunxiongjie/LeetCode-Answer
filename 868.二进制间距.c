/*
 * @lc app=leetcode.cn id=868 lang=c
 *
 * [868] 二进制间距
 */

// @lc code=start


int binaryGap(int n){
    /*
    int resultCounter = 0;

    for (int left = 0; left < 32; left++) {

        if (((n >> left) % 2) == 1) {

            int right = (left + 1);

            for (; right < 32; right++) {

                if (((n >> right) % 2) == 1) {

                    if ((right - left) > resultCounter) {

                        resultCounter = right - left;                        
                    }
                    else {
                    
                    }

                    left = right - 1;
                    break;
                }
            }

            if (right == 31) {
                
                break;
            }
        }
        
    }

    return resultCounter;
    */

    int resultCounter = 0;
    int lastSite = -1;
    int nCounter = 0;

    while (n) {

        if (n & 1) {

            if ((-1 != lastSite) && 
                ((nCounter - lastSite) > resultCounter)
            ) {

                resultCounter = (nCounter - lastSite);
            }

            lastSite = nCounter;
        }

        nCounter++;
        n >>= 1;
    }

    return resultCounter;
}

// @lc code=end

