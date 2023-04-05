/*
 * @lc app=leetcode.cn id=2309 lang=c
 *
 * [2309] 兼具大小写的最好英文字母
 */

// @lc code=start
/*
bool isSubset(int *nums, int numsSize, int target)
{
    int numsLeftIndex = 0;
    int numsRightIndex = (numsSize - 1);

    do
    {
        int middle = (numsLeftIndex + numsRightIndex) / 2;

        if (nums[numsLeftIndex] == target) {
            return true;
        }

        if (nums[numsRightIndex] == target) {
            return true;
        }

        if (nums[middle] == target) {
            return true;
        }
        else if (nums[middle] < target) {
            numsLeftIndex = middle;            
        }
        else if (nums[middle] > target) {
            numsRightIndex = middle;
        }
        
    }
    while (numsLeftIndex < (numsRightIndex - 1));

    return false;
}
*/

char * greatestLetter(char * s){
    
    int charVector[26];
    char *resultStr = malloc(sizeof(char) * 2);

    memset(charVector, 0, (sizeof(int) * 26));

    for (char *strPointer = s; strPointer < (s + strlen(s)); strPointer++) {

        if ((*strPointer) <= 'Z' && (*strPointer) >= 'A') {

            charVector[(*strPointer) - 'A'] += 2000;
        }

        if ((*strPointer) <= 'z' && (*strPointer) >= 'a') {
            
            charVector[(*strPointer) - 'a']++;
        }
        
        // printf("%c, ", (*strPointer));

    }

    resultStr[0] = '\0';
    
    for (int i = 25; i >= 0; i--) {
        
        if (((charVector[i] % 2000) != 0) && ((charVector[i] / 2000) != 0)) {

            // printf ("%d\n", charVector[i]);

            resultStr[0] = (char)('A' + i);
            break;
        }
    }
    
    resultStr[1] = '\0';
    // printf("%s\n", resultStr);

    return resultStr;
}

// @lc code=end

