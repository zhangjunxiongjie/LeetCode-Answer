/*
 * @lc app=leetcode.cn id=1450 lang=c
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start


int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime){

    int resultCounter = 0;

    for (int i = 0; i < startTimeSize; i++) {

        // if ((startTime[i] <= queryTime) && (endTime[i] >= queryTime)) {
        //     resultCounter++;
        // }

        if (startTime[i] > queryTime) {
            
            continue;
        }
        else if (endTime[i] < queryTime) {

            continue;
        }
        else {
            
            resultCounter++;
        }
    }

    return resultCounter;
}


// @lc code=end

