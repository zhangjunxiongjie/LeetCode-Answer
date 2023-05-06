/*
 * @lc app=leetcode.cn id=804 lang=c
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start


/*
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
*/

unsigned char charTable[26][2] = {

    {2, 1},  //{2, 0b01},      // ".-",
    {4, 8},    // {4, 0b1000},    // "-...",
    {4, 10},    // {4, 0b1010},    // "-.-.",
    {3, 4},     // {3, 0b100},     // "-..",
    {1, 0},       // {1, 0b0},       // ".",
    {4, 2},    // {4, 0b0010},    // "..-.",
    {3, 6},     // {3, 0b110},     // "--.",
    {4, 0},    // {4, 0b0000},    // "....",
    {2, 0},      // {2, 0b00},      // "..",
    {4, 7},    // {4, 0b0111},    //".---",
    {3, 5},     // {3, 0b101},     //"-.-",
    {4, 4},    // {4, 0b0100},    //".-..",
    {2, 3},      // {2, 0b11},      //"--",
    {2, 2},      // {2, 0b10},      //"-.",
    {3, 7},     // {3, 0b111},     //"---",
    {4, 6},    // {4, 0b0110},    //".--.",
    {4, 13},    // {4, 0b1101},    //"--.-",
    {3, 2},     // {3, 0b010},     //".-.",
    {3, 0},     // {3, 0b000},     //"...",
    {1, 1},       // {1, 0b1},       //"-",
    {3, 1},     // {3, 0b001},     //"..-",
    {4, 1},    // {4, 0b0001},    //"...-",
    {3, 3},     // {3, 0b011},     //".--",
    {4, 9},    // {4, 0b1001},    //"-..-",
    {4, 11},    // {4, 0b1011},    //"-.--",
    {4, 12},    // {4, 0b1100},    //"--.."
};

int uniqueMorseRepresentations(char ** words, int wordsSize){
    
    int resultCounter = 0;

    unsigned long int *assistantVessel = (unsigned long int*)malloc(sizeof(unsigned long int) * wordsSize);
    
    unsigned char *assistantVessel1 = (unsigned char*)malloc(sizeof(unsigned char) * wordsSize);

    memset(assistantVessel1, 0, (sizeof(unsigned char) * wordsSize));
    memset(assistantVessel, 0, (sizeof(unsigned long int) * wordsSize));

    for (int i = 0; i < wordsSize; i++) {

        for (int j = 0; j < strlen(words[i]); j++) {

            assistantVessel[i] <<= charTable[words[i][j] - 'a'][0];
            assistantVessel[i] += charTable[words[i][j] - 'a'][1];

            assistantVessel1[i] += charTable[words[i][j] - 'a'][0];
        }
        
        resultCounter++;

        for (int z = 0; z < i; z++) {

            if ((assistantVessel[i] == assistantVessel[z]) &&
                (assistantVessel1[i] == assistantVessel1[z])
                ) {

                resultCounter--;
                break;
            }
        }
    }

    return resultCounter;
}

// @lc code=end

