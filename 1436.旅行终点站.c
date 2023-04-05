/*
 * @lc app=leetcode.cn id=1436 lang=c
 *
 * [1436] 旅行终点站
 */

// @lc code=start


char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    
    char *target = paths[0][1];

    while (true) {
        
        bool flag = true;

        for (char ***pathsPointer = paths; pathsPointer < (paths + pathsSize); pathsPointer++) {
            
            // printf("%s\n", (*pathsPointer)[0]);
            
            if (0 == strcmp((*pathsPointer)[0], target)) {
                
                flag = false;
                target = (*pathsPointer)[1];
                break;
            }
            
        }

        if (flag) {

            break;
        }
    }
    
    return target;
}

// @lc code=end

