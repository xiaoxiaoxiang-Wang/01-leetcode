class Solution {
public:
    int trap(vector<int>& height) {
        int rt = 0;
        // stack保持从底置顶下降
        stack<pair<int,int>> s;
        for(int i = 0; i < height.size(); i++){
            if(s.empty()) {
                s.push(make_pair(height[i],i));
                continue;
            } 
            // 开始计算蓄水
            if(height[i]>s.top().first) {
                pair<int,int> top = s.top();
                while(height[i]>top.first) {
                    s.pop();
                    //已经是最高的
                    if(s.empty()) {
                        s.push(make_pair(height[i],i));
                        break;
                    } 
                    if(s.top().first > height[i]) {
                        rt += (i - s.top().second - 1)*(height[i]-top.first);
                        s.push(make_pair(height[i],i));
                        break;
                    } 
                    if(s.top().first == height[i]){
                        rt += (i - s.top().second - 1)*(height[i]-top.first);
                        s.top().second = i;
                        break;
                    } 
                    rt += (i - s.top().second - 1)*(s.top().first-top.first);
                    top = s.top();
                }
            } else if (height[i]<s.top().first){
                s.push(make_pair(height[i],i));
            } else {
                s.top().second = i;
            }
        }
        return rt;
    }
};
