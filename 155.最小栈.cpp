/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    // 有待优化。
    vector<int> data;
    vector<int> list;

    MinStack() {
    }

    void push(int x) {
        data.push_back(x);

        auto iter = list.begin();
        bool flag = true;
        for (; iter != list.end(); iter++)
        {
            if (x > *iter)
            {
                list.insert(iter, x);
                flag = false;
                break;
            }
        }
        if (flag && iter == list.end())
        {
            list.push_back(x);
        }
    }

    void pop() {
        int buffer = data.back();
        data.pop_back();

        auto iter = list.begin();
        bool flag = true;
        for (; iter != list.end(); iter++)
        {
            if (*iter == buffer)
            {
                list.erase(iter);
                flag = false;
                break;
            }
        }
        if (flag && iter == list.end())
        {
            list.pop_back();
        }
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return list.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

