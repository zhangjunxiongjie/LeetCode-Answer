/*
 * @lc app=leetcode.cn id=372 lang=c
 *
 * [372] 超级次方
 */

// @lc code=start

int superPow(int a, int* b, int bSize){

    int result = 1;
    
    bool flag = true;

    // 保存中间数据
    short *middle = malloc(sizeof(short) * bSize);
    memset(middle, 0, (sizeof(short) * bSize));

    char counter = 0;

    int middleIndex = 0;
    int bIndex;

    middle[0] = (a % 1337);

    while (true) {

        if (flag) {

            for (bIndex = (bSize - middleIndex - 1); bIndex >= 0; bIndex--) {

                if (b[bIndex] != 0) {
                    
                    b[bIndex]--;
                    
                    bIndex++;
                    for (int i = bIndex; i < (bSize - middleIndex); i++) {
                        
                        b[i] = 9;
                    }

                    break;                
                }
            }

            result *= middle[middleIndex];
            result %= 1337; 

            counter++;
            if (counter == 10) {
                counter = 1;        

                if (middleIndex < (bSize - 1)) {

                    middle[middleIndex + 1] = result; 
                    middleIndex++;
                }                                            
            }

            if (middleIndex == (bSize - 1))
            {              
                flag = false;
                bIndex = 0;                    
            }                
        }
        else {

            if (b[bIndex] != 0) {                

                b[bIndex]--;
                result *= middle[middleIndex];
                result %= 1337; 
            }
            else {

                if ((middleIndex == 0) && (b[bIndex] == 0)) {

                    break;
                }   

                middleIndex--;
                bIndex++;
            }

            if ((middleIndex == 0) && (b[bIndex] == 0)) {
                
                break;
            }
        }
    }

    // for (int i = 0; i < bSize; i++) {
    //     printf ("%d,", b[i]);
    // }
    // printf ("\n");

    free(middle);

    return result;
}

// @lc code=end

