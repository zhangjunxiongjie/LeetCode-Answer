/*
 * @lc app=leetcode.cn id=728 lang=c
 *
 * [728] 自除数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool judge_self_divisor(int target)
{
    bool resultFlag = true;
    int middleTarget = target;

    while (target) {

        int middle = (target % 10);

        if ((middle != 0)) {

            if (((middleTarget % middle) != 0)) {

                resultFlag = false;
                break;
            }            
        }
        else {

            resultFlag = false;
            break;
        }

        target /= 10;
    }
    
    return resultFlag;
}

int* selfDividingNumbers(int left, int right, int* returnSize)
{    
    int tempCache[9999];
    int counter = 0;

    for (; left <= right; left++) {

        if (judge_self_divisor(left)) {
            // printf ("%d, ", left);
            tempCache[counter] = left;
            counter++;
        }
    }

    // printf ("\n%d", counter);
    int *resultVector = malloc(sizeof(int) * counter);
    (*returnSize) = counter;
    
    for (; counter > 0; ) {
        
        counter--;
        resultVector[counter] = tempCache[counter];
    }    

    return resultVector;
}

// @lc code=end

