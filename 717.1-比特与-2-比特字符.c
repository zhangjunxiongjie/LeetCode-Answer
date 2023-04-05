/*
 * @lc app=leetcode.cn id=717 lang=c
 *
 * [717] 1 比特与 2 比特字符
 */

// @lc code=start


bool isOneBitCharacter(int* bits, int bitsSize){

    bool resultFlag = false;

    for (int *bitsPointer = bits; bitsPointer < (bits + bitsSize); bitsPointer++) {

        if ((*bitsPointer) == 1) {
            
            bitsPointer++;
            resultFlag = false;
        }
        else {

            resultFlag = true;
        }
    }

    return resultFlag;
}
// @lc code=end

