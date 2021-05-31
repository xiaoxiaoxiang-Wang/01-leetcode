class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rt = 0;
        vector<int> heights;
        for(int i=0;i<matrix.size();i++) {
          heights.resize(matrix[i].size());
          for(int j=0;j<matrix[i].size();j++) {
            heights[j] = matrix[i][j]=='0'?0:(heights[j]+1);
          }
          rt = max(rt,largestRectangleArea(heights));
        }
        return rt;
    }
//  84题
    int largestRectangleArea(vector<int> heights)
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