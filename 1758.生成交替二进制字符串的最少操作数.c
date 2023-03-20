/*
 * @lc app=leetcode.cn id=1758 lang=c
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start


int minOperations(char * s){
    
    int leftSetp = 0;
    int RightSetp = 0;
    bool flag = true;

    while ((*s) != '\0') {

        if (flag) {

            if ((*s) == '0') {
                
                leftSetp++;
            }
            else {

                RightSetp++;
            }
        }
        else {

            if ((*s) == '0') {
                
                RightSetp++;
            }
            else {

                leftSetp++;
            }
        }
        
        flag = (!flag);

        s++;
    }

    // printf ("%d, %d\n", leftSetp, RightSetp);

    return ((leftSetp < RightSetp) ? leftSetp : RightSetp);
}

// @lc code=end

