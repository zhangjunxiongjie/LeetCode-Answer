/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    void stringtochar(string& s, char* c) {
        int i = 0;
        for (; i < s.size(); i++)
        {
            c[i] = s.at(i);
        }
        c[i] = '\0';
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> heap;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens.at(i) != "+" && tokens.at(i) != "-" && tokens.at(i) != "*" && tokens.at(i) != "/")
            {
                // 这里为了将字符串转数字先将 string 转为 char*。然后使用 atoi() 将 char* 转为数字。
                char buffer[tokens.at(i).size() + 1];
                stringtochar(tokens.at(i), buffer);

                heap.push(atoi(buffer));
            }
            else
            {
                int figure2 = heap.top();
                heap.pop();
                int figure1 = heap.top();
                heap.pop();

                int figure = 0;
                if (tokens.at(i) == "+")
                {
                    figure = figure1 + figure2;
                }
                else if (tokens.at(i) == "-")
                {
                    figure = figure1 - figure2;
                }
                else if (tokens.at(i) == "*")
                {
                    figure = figure1 * figure2;
                }
                else if (tokens.at(i) == "/")
                {
                    figure = figure1 / figure2;
                }
                else
                {
                    cout << "error";
                }

                heap.push(figure);
            }
        }
        return heap.top();
    }
};
// @lc code=end

