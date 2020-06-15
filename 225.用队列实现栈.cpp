/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {

private:
    queue<int> oneQueue;
    queue<int> twoQueue; 
    bool flag;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        flag = true;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (flag) // one 有效
        {
            twoQueue.push(x);

            while (!oneQueue.empty())
            {
                twoQueue.push(oneQueue.front());
                oneQueue.pop();
            }

            flag = false;
        }
        else // two 有效
        {
            oneQueue.push(x);

            while (!twoQueue.empty())
            {
                oneQueue.push(twoQueue.front());
                twoQueue.pop();
            }
            
            flag = true;
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result;
        if (flag)
        {
            result = oneQueue.front();
            oneQueue.pop();
        }
        else
        {
            result = twoQueue.front();
            twoQueue.pop();
        }
        return result;
    }
    
    /** Get the top element. */
    int top() {
        int result;
        if (flag)
        {
            result = oneQueue.front();
        }
        else
        {
            result = twoQueue.front();
        }
        return result;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        bool result;
        if (flag)
        {
            result = oneQueue.empty();
        }
        else
        {
            result = twoQueue.empty();
        }
        return result;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

