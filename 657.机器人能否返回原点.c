/*
 * @lc app=leetcode.cn id=657 lang=c
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start


bool judgeCircle(char * moves){
    int x = 0;
    int y = 0;

    for (char *movesPointer = moves; (*movesPointer) != '\0'; movesPointer++) {

        switch (*movesPointer) {
            
            case 'L': {

                x--;
                break;
            }
            case 'R': {
                
                x++;
                break;
            }
            case 'U': {

                y++;
                break;
            }
            case 'D': {
                
                y--;
                break;
            }

            default : {

                break;
            }
        }
    }

    if ((x == 0) && (x == y)) {

        return true;
    }
    else {

        return false;
    }
}
// @lc code=end

