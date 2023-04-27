/*
 * @lc app=leetcode.cn id=1941 lang=c
 *
 * [1941] 检查是否所有字符出现次数相同
 */

// @lc code=start


bool areOccurrencesEqual(char * s){

    int assistantVessel[26];
    memset(assistantVessel, 0, (26 * sizeof(int)));

    for (char *sPointer = s; sPointer < (s + strlen(s)); sPointer++) {

        assistantVessel[(*sPointer) - 'a']++;
    }

    for (int i = 0, max = -1, min = 1001; i < 26; i++) {

        if ((assistantVessel[i] != 0) && (assistantVessel[i] < min)) {

            min = assistantVessel[i];
        }

        if ((assistantVessel[i] != 0) && (assistantVessel[i] > max)) {

            max = assistantVessel[i];
        }

        // printf ("%d, %d, %d, %d\n", max, min, i, assistantVessel[i]);

        if ((max != -1) && (min != 1001) && (max != min)) {

            return false;
        }
    }

    return true;
}

// @lc code=end

