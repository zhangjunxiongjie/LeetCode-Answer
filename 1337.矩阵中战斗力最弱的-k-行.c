/*
 * @lc app=leetcode.cn id=1337 lang=c
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    
    int *resultVector = malloc(sizeof(int) * k);
    int *assistantVector = malloc(sizeof(int) * matSize);
    int *assistantIndexVector = malloc(sizeof(int) * matSize);

    memset(assistantVector, 0, (sizeof(int) * matSize));
    
    for (int i = 0; i < matSize; i++) {

        for (int j = 0; j < (*matColSize); j++) {

            if (mat[i][j] == 1) {

                assistantVector[i]++;
            }
            else {
                break;
            }
        }

        assistantIndexVector[i] = i;
        // printf ("%d, %d, %d, \n", i, assistantVector[i], assistantIndexVector[i]);
    }

    for (int i = 0; i < matSize; i++) {

        int targetIndex = i;
        for (int j = (targetIndex + 1); j < matSize; j++) {

            if (assistantVector[targetIndex] > assistantVector[j]) {
                
                targetIndex = j;
            }
            else if ((assistantVector[targetIndex] == assistantVector[j]) && (assistantIndexVector[targetIndex] > assistantIndexVector[j])) {

                targetIndex = j;
            }
            
        }

        if (targetIndex != i) {

            assistantVector[targetIndex] ^= assistantVector[i];            
            assistantVector[i] ^= assistantVector[targetIndex];
            assistantVector[targetIndex] ^= assistantVector[i];

            assistantIndexVector[i] ^= assistantIndexVector[targetIndex];
            assistantIndexVector[targetIndex] ^= assistantIndexVector[i];
            assistantIndexVector[i] ^= assistantIndexVector[targetIndex];
        }

        // printf ("%d, %d, \n", assistantIndexVector[i], assistantIndexVector[targetIndex]);

        if (i < k) {

            resultVector[i] = assistantIndexVector[i];
        }
    }

    (*returnSize) = k;
    return resultVector;
}

// @lc code=end

