class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> usd(deadends.begin(), deadends.end());
        if(usd.find("0000")!=usd.end()) {
            return -1;
        }
        if("0000"==target) {
            return 0;
        }
        queue<string> que{{"0000"}};
        int res = 0;
		while (!que.empty()) {
            int size = que.size();
            res++;
            for(int i=0;i<size;i++) {
                if (bfs(deadends, target,usd, que)) {
                    return res;
                }
                que.pop();
            }

		}
		return -1;

	}
	bool bfs(vector<string>& deadends, string& target, unordered_set<string>& usd, queue<string>& que) {
		string front = que.front();
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<2; j++) {
				string str = getNewString(front, i, j);
                if (str == target) {
                    return true;
                }
				if (usd.find(str) == usd.end()) {
					usd.insert(str);
					que.push(str);
				}
			}
		}
		return false;
	}
	string getNewString(string target, int i, int j) {
		if (j == 0) {
			target[i] = getPrev(target[i]);
		}
		else {
			target[i] = getNext(target[i]);
		}
		return target;
	}

	char getNext(char c) {
		if (c == '9') {
			return '0';
		}
		else {
			return ++c;
		}
	}
	char getPrev(char c) {
		if (c == '0') {
			return '9';
		}
		else {
			return --c;
		}
	}
};