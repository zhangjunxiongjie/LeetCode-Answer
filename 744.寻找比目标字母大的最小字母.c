/*
 * @lc app=leetcode.cn id=744 lang=c
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start


char nextGreatestLetter(char* letters, int lettersSize, char target){
    
    int leftIndex = 0;
    int rightIndex = (lettersSize - 1);
    int middle = ((leftIndex + rightIndex) / 2);

    while (true) {

        if (letters[leftIndex] == target) {
            middle = leftIndex;
            break;
        }
        else if (letters[rightIndex] == target) {
            middle = rightIndex;
            break;
        }
        else if (abs(rightIndex - leftIndex) <= 1) {

            break;
        }

        if (letters[middle] == target) {

            break;
        }
        else if (letters[middle] < target) {

            leftIndex = middle;
        }
        else if (letters[middle] > target) {

            rightIndex = middle;
        }

        middle = ((leftIndex + rightIndex) / 2);
    }

    // printf ("%c, %d\n", letters[middle], middle);
    while ((middle < lettersSize) && (letters[middle] <= target)) {

        middle++;
    }

    if (middle == lettersSize) {

        return letters[0];
    }
    else {

        return letters[middle];
    }
    
}


// @lc code=end

