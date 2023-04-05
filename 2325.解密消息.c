/*
 * @lc app=leetcode.cn id=2325 lang=c
 *
 * [2325] 解密消息
 */

// @lc code=start


char * decodeMessage(char * key, char * message){

    char charAssistant[26];
    int charIndex = 0;

    memset(charAssistant, 0, (sizeof(char) * 26));

    for (char *keyPointer = key; keyPointer < (key + strlen(key)); keyPointer++) {
                    
        if ((*keyPointer) <= 'z' && (*keyPointer) >= 'a') {

            if ((charAssistant[(*keyPointer) - 'a'] == 0) && (charIndex < 26)) {

                charAssistant[(*keyPointer) - 'a'] = ('a' + charIndex);
                // printf("%c, ", charAssistant[charIndex]);                
                charIndex++;
            }
        }        
    }

    for (char *messagePointer = message; (messagePointer < (message + strlen(message))); messagePointer++) {

        if ((*messagePointer) != ' ') {

            (*messagePointer) = charAssistant[(*messagePointer) - 'a'];
        }
    }

    return message;
}

// @lc code=end

