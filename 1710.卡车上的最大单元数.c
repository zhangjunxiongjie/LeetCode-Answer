/*
 * @lc app=leetcode.cn id=1710 lang=c
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start


int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){

    int resultSum = 0;

    for (int i = 0; i < boxTypesSize; i++) {

        int targetIndex = i;

        for (int j = (targetIndex + 1); j < boxTypesSize; j++) {

            if (boxTypes[targetIndex][1] < boxTypes[j][1]) {

                targetIndex = j;
            }
            else if ((boxTypes[targetIndex][1] == boxTypes[j][1]) && (boxTypes[targetIndex][0] < boxTypes[j][0])) {

                targetIndex = j;
            }
        }

        // printf ("%d, %d, %d, %d:", boxTypes[i][0], boxTypes[i][1], boxTypes[targetIndex][0], boxTypes[targetIndex][1]); 

        if (targetIndex != i) {

            boxTypes[i][0] ^= boxTypes[targetIndex][0];
            boxTypes[targetIndex][0] ^= boxTypes[i][0];
            boxTypes[i][0] ^= boxTypes[targetIndex][0];

            boxTypes[i][1] ^= boxTypes[targetIndex][1];
            boxTypes[targetIndex][1] ^= boxTypes[i][1];
            boxTypes[i][1] ^= boxTypes[targetIndex][1];
        }

        // printf ("%d, %d, %d, %d\n", boxTypes[i][0], boxTypes[i][1], boxTypes[targetIndex][0], boxTypes[targetIndex][1]);
    }

    for (int i = 0; i < boxTypesSize; i++) {

        if (boxTypes[i][0] <= truckSize) {
            
            truckSize -= boxTypes[i][0];

            resultSum += (boxTypes[i][0] * boxTypes[i][1]);
        }
        else {

            resultSum += (truckSize * boxTypes[i][1]);
            break;
        }
    }

    return resultSum;
}

// @lc code=end

