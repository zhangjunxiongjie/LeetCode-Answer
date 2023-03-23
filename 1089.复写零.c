/*
 * @lc app=leetcode.cn id=1089 lang=c
 *
 * [1089] 复写零
 */

// @lc code=start


void duplicateZeros(int* arr, int arrSize){

    int currentSize = 0;
    int arrIndex = 0;
    bool flag = false;

    for (arrIndex = 0; arrIndex < arrSize; arrIndex++) {
        
        currentSize++;
        if (currentSize >= arrSize) {
            flag = false;
            break;
        }

        if (arr[arrIndex] == 0) {

            currentSize++;
        }        

        if (currentSize >= arrSize) {
            flag = true;
            break;
        }
    }

    for (currentSize = (arrSize - 1); (arrIndex >= 0); arrIndex--) {

        if (arr[arrIndex] == 0) {
            
            if ((!flag) && (currentSize == (arrSize - 1))) {

                if (currentSize >= 0) {

                    arr[currentSize--] = 0;                
                }
                else {

                    break;
                }
            }
            else {

                if (currentSize >= 0) {

                    arr[currentSize--] = 0;
                }
                else {

                    break;
                }

                if (currentSize >= 0) {

                    arr[currentSize--] = 0;                
                }
                else {

                    break;
                }
            }
            
        }
        else {

            if (currentSize >= 0) {

                arr[currentSize--] = arr[arrIndex];
            }
            else {

                break;
            }
        }
    }

    return;
}


// @lc code=end

