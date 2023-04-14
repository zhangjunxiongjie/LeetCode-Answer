/*
 * @lc app=leetcode.cn id=1773 lang=c
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start


int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    
    int resultCounter = 0;

    if (0 == strcmp(ruleKey, "type")) {
        
        // printf ("type\n");

        for (char ***itemsPointer = items; itemsPointer < (items + itemsSize); itemsPointer++) {

            if (0 == strcmp((*itemsPointer)[0], ruleValue)) {

                resultCounter++;
            }
        }
    }
    else if (0 == strcmp(ruleKey, "color")) {
        
        // printf ("color\n");

        for (char ***itemsPointer = items; itemsPointer < (items + itemsSize); itemsPointer++) {

            // printf ("%s\n", (*itemsPointer)[1]);

            if (0 == strcmp((*itemsPointer)[1], ruleValue)) {

                resultCounter++;
            }
        }
    }
    else if (0 == strcmp(ruleKey, "name")) {

        // printf ("name\n");

        for (char ***itemsPointer = items; itemsPointer < (items + itemsSize); itemsPointer++) {

            if (0 == strcmp((*itemsPointer)[2], ruleValue)) {

                resultCounter++;
            }
        }
    }

    return resultCounter;
}

// @lc code=end

