/*
 * @lc app=leetcode.cn id=1700 lang=c
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start


int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){

    int loopCounter = 0;

    int studentsIndex = 0;
    int sandwichesIndex = 0;

    while (true) {

        if ((students[studentsIndex] != -1) && (students[studentsIndex] == sandwiches[sandwichesIndex])) {

            students[studentsIndex] = -1;
            
            sandwichesIndex++;
            if (sandwichesIndex >= sandwichesSize) {
                break;
            }

            loopCounter = 0;
        }
        
        loopCounter++;
        if (loopCounter >= sandwichesSize) {
            break;
        }

        studentsIndex++;
        if (studentsIndex >= sandwichesSize) {
            
            studentsIndex = 0;
        }
    }

    return (sandwichesSize - sandwichesIndex);
}

// @lc code=end

