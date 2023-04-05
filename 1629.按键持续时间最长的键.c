/*
 * @lc app=leetcode.cn id=1629 lang=c
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start


char slowestKey(int* releaseTimes, int releaseTimesSize, char * keysPressed){

    int cacheMax = 0;
    int cacheMaxIndex = 0;

    for (int i = 0; i < releaseTimesSize; i++) {

        if (((i - 1) >= 0)) {

            int middle = releaseTimes[i] - releaseTimes[i - 1];
            if (middle > cacheMax) {
                
                cacheMaxIndex = i;
                cacheMax = middle;
            }
            else if ((middle == cacheMax) && (keysPressed[i] > keysPressed[cacheMaxIndex])) {

                cacheMaxIndex = i;
                cacheMax = middle;
            }
        }
        else {

            int middle = releaseTimes[i];
            if (middle > cacheMax) {

                cacheMaxIndex = i;
                cacheMax = middle;
            }
            else if ((middle == cacheMax) && (keysPressed[i] > keysPressed[cacheMaxIndex])) {

                cacheMaxIndex = i;
                cacheMax = middle;
            }
        }
    }

    return keysPressed[cacheMaxIndex];
}

// @lc code=end

