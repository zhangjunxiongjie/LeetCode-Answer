/*
 * @lc app=leetcode.cn id=836 lang=c
 *
 * [836] 矩形重叠
 */

// @lc code=start


bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){

    for (int i = 0; i < 4; i++) {

        if (rec1[0] >= rec1[2]) {

            if ((rec1[0] > rec2[0]) && (rec2[0] > rec1[2])) {                        

                if (rec1[1] >= rec1[3]) {

                    if ((rec1[1] > rec2[1]) && (rec2[1] > rec1[3])) {
                        
                        return true;
                    }
                    else if ((rec1[1] > rec2[3]) && (rec2[3] > rec1[3])) {

                        return true;
                    }
                    else if (((rec1[0] >= rec2[2]) && (rec2[2] >= rec1[2]))
                            
                    ) {
                        if (((rec1[1] <= rec2[3]) && (rec2[1] <= rec1[3])) || 
                            ((rec1[1] <= rec2[1]) && (rec2[3] <= rec1[3]))
                        ) {
                            return true;
                        }
                    }
                    
                }
                else {

                    if ((rec1[3] > rec2[1]) && (rec2[1] > rec1[1])) {

                        return true;
                    }
                    else if ((rec1[3] > rec2[3]) && (rec2[3] > rec1[1])) {

                        return true;
                    }
                    else if (((rec1[0] >= rec2[2]) && (rec2[2] >= rec1[2]))

                    ) {
                        if (((rec1[3] <= rec2[3]) && (rec2[1] <= rec1[1])) || 
                            ((rec1[3] <= rec2[1]) && (rec2[3] <= rec1[1]))
                        ) {

                            return true;
                        }
                    }                        
                }
                
            }

            if ((rec1[0] > rec2[2]) && (rec2[2] > rec1[2])) {            

                if (rec1[1] >= rec1[3]) {

                    if ((rec1[1] > rec2[1]) && (rec2[1] > rec1[3])) {

                        return true;
                    }
                    else if ((rec1[1] > rec2[3]) && (rec2[3] > rec1[3])) {

                        return true;
                    }
                    else if (((rec1[0] >= rec2[0]) && (rec2[0] >= rec1[2]))
                            
                    ) {
                        if (((rec1[1] <= rec2[3]) && (rec2[1] <= rec1[3])) || 
                            ((rec1[1] <= rec2[1]) && (rec2[3] <= rec1[3]))
                        ) {

                            return true;
                        }
                    }                        
                }
                else {

                    if ((rec1[3] > rec2[1]) && (rec2[1] > rec1[1])) {

                        return true;
                    }
                    else if ((rec1[3] > rec2[3]) && (rec2[3] > rec1[1])) {

                        return true;
                    }
                    else if (((rec1[0] >= rec2[0]) && (rec2[0] >= rec1[2]))

                    ) {
                        if (((rec1[3] <= rec2[3]) && (rec2[1] <= rec1[1])) || 
                            ((rec1[3] <= rec2[1]) && (rec2[3] <= rec1[1]))
                        ) {

                            return true;
                        }
                    }                         
                }                
            }        
        }
        else {

            if ((rec1[2] > rec2[0]) && (rec2[0] > rec1[0])) {            

                if (rec1[1] >= rec1[3]) {

                    if ((rec1[1] > rec2[1]) && (rec2[1] > rec1[3])) {

                        return true;
                    }
                    else if ((rec1[1] > rec2[3]) && (rec2[3] > rec1[3])) {

                        return true;
                    }
                    else if (((rec1[2] >= rec2[2]) && (rec2[2] >= rec1[0]))
                            
                    ) {
                        if (((rec1[1] <= rec2[3]) && (rec2[1] <= rec1[3])) || 
                            ((rec1[1] <= rec2[1]) && (rec2[3] <= rec1[3]))
                        ) {

                            return true;
                        }
                    }                         
                }
                else {

                    if ((rec1[3] > rec2[1]) && (rec2[1] > rec1[1])) {

                        return true;
                    }
                    else if ((rec1[3] > rec2[3]) && (rec2[3] > rec1[1])) {

                        return true;
                    }
                    else if (((rec1[2] >= rec2[2]) && (rec2[2] >= rec1[0]))

                    ) {
                        if (((rec1[3] <= rec2[3]) && (rec2[1] <= rec1[1])) || 
                            ((rec1[3] <= rec2[1]) && (rec2[3] <= rec1[1]))
                        ) {

                            return true;
                        }
                    }                          
                }
                
            }

            if ((rec1[2] > rec2[2]) && (rec2[2] > rec1[0])) {            

                if (rec1[1] >= rec1[3]) {

                    if ((rec1[1] > rec2[1]) && (rec2[1] > rec1[3])) {

                        return true;
                    }
                    else if ((rec1[1] > rec2[3]) && (rec2[3] > rec1[3])) {

                        return true;
                    }
                    else if (((rec1[2] >= rec2[0]) && (rec2[0] >= rec1[0]))
                            
                    ) {
                        if (((rec1[1] <= rec2[3]) && (rec2[1] <= rec1[3])) || 
                            ((rec1[1] <= rec2[1]) && (rec2[3] <= rec1[3]))
                        ) {

                            return true;
                        }
                    }                           
                }
                else {

                    if ((rec1[3] > rec2[1]) && (rec2[1] > rec1[1])) {

                        return true;
                    }
                    else if ((rec1[3] > rec2[3]) && (rec2[3] > rec1[1])) {

                        return true;
                    }
                    else if (((rec1[2] >= rec2[0]) && (rec2[0] >= rec1[0]))

                    ) {
                        if (((rec1[3] <= rec2[3]) && (rec2[1] <= rec1[1])) || 
                            ((rec1[3] <= rec2[1]) && (rec2[3] <= rec1[1]))
                        ) {

                            return true;
                        }
                    }                          
                }                
            }            
        }

        if (0 == i) {

            int *middle = rec1;
            rec1 = rec2;
            rec2 = middle;
            
        }
        else if (1 == i) {
            
            rec2[0] ^= rec2[2];
            rec2[2] ^= rec2[0];
            rec2[0] ^= rec2[2];

            rec2[1] ^= rec2[3];
            rec2[3] ^= rec2[1];
            rec2[1] ^= rec2[3];                        
            
        }
        else if (2 == i) {

            rec1[0] ^= rec1[2];
            rec1[2] ^= rec1[0];
            rec1[0] ^= rec1[2];

            rec1[1] ^= rec1[3];
            rec1[3] ^= rec1[1];
            rec1[1] ^= rec1[3];
        }
        else if (3 == i) {

            rec1[0] ^= rec1[1];
            rec1[1] ^= rec1[0];
            rec1[0] ^= rec1[1];

            rec1[2] ^= rec1[3];
            rec1[3] ^= rec1[2];
            rec1[2] ^= rec1[3];
            //--------------------------
            rec2[0] ^= rec2[1];
            rec2[1] ^= rec2[0];
            rec2[0] ^= rec2[1];

            rec2[2] ^= rec2[3];
            rec2[3] ^= rec2[2];
            rec2[2] ^= rec2[3];            
        }
    }

    return false;
}

// @lc code=end

