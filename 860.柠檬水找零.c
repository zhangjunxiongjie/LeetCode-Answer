/*
 * @lc app=leetcode.cn id=860 lang=c
 *
 * [860] 柠檬水找零
 */

// @lc code=start


bool lemonadeChange(int* bills, int billsSize){
    
    int fiveCounter = 0;
    int tenCounter = 0;
    int twentyCounter = 0;

    for (int i = 0; i < billsSize; i++) {

        switch (bills[i]) {
            case 5: {
                fiveCounter++;
                break;
            }
            case 10: {

                if (fiveCounter > 0) {
                    fiveCounter--;
                }
                else {
                    return false;
                }

                tenCounter++;
                break;
            }
            case 20: {
                if ((tenCounter > 0) && (fiveCounter > 0)) {

                    fiveCounter--;
                    tenCounter--;                    
                }
                else if ((fiveCounter >= 3)) {

                    fiveCounter--;
                    fiveCounter--;
                    fiveCounter--;
                }
                else {

                    return false;
                }

                twentyCounter++;
                break;
            }
        }
    }

    return true;
}

// @lc code=end

