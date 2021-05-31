#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int rt = 0;
        // 保存上升的序列
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            int j = i;
            // 发现下降
            while (!s.empty() && heights[s.top()] > heights[i]) {
                // 栈顶值的面积
                int val = heights[s.top()] * (i - s.top());
                rt = rt > val ? rt : val;
                j = s.top();
                s.pop();
            }
            s.push(j);
            // 修改索引
            heights[j] = heights[i];
        }
        while (!s.empty()) {
            // 栈顶值的面积
            int val = heights[s.top()] * (heights.size() - s.top());
            rt = rt > val ? rt : val;
            s.pop();
        }
        return rt;
    }
};

    // int largestRectangleArea(vector<int> &heights)
    // {
    //     int rt = 0;
    //     // 保存上升的序列
    //     stack<int> s;
    //     for (int i = 0; i < heights.size(); i++) {
    //         int j = i;
    //         // 发现下降
    //         while (!s.empty() && heights[s.top()] > heights[i]) {
    //             // 栈顶值的面积
    //             int val = heights[s.top()] * (i - s.top());
    //             rt = rt > val ? rt : val;
    //             j = s.top();
    //             s.pop();
    //         }
    //         s.push(j);
    //         // 修改索引
    //         heights[j] = heights[i];
    //     }
    //     while (!s.empty()) {
    //         // 栈顶值的面积
    //         int val = heights[s.top()] * (heights.size() - s.top());
    //         rt = rt > val ? rt : val;
    //         s.pop();
    //     }

    //     return rt;
    // }