class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		vector<pair<string, int>> emails;
		for (int i = 0; i < accounts.size(); i++) {
			for (int j = 1; j < accounts[i].size(); j++) {
				emails.push_back({ accounts[i][j],i });
			}
		}
		sort(emails.begin(), emails.end());
		vector<int> uf(accounts.size(),-1);
		unordered_map<int, int> um;
		for (int i = 0; i < emails.size() - 1; i++){
			if (emails[i].first == emails[i + 1].first) {
				unionFind(uf, emails[i].second, emails[i+1].second);
			}
		}
		int idx = 0;
		for (int i = 0; i < accounts.size(); i++) {
			setIndex(uf, um, i, idx);
		}
		vector<vector<string>> res(idx);
		emails.push_back({ "",0 });
		for (int i = 0; i<emails.size() - 1; i++) {
			if (res[um[emails[i].second]].empty()) {
				// 插入名字
				res[um[emails[i].second]].push_back(accounts[emails[i].second][0]);
			}
			if (emails[i].first == emails[i + 1].first) {
				auto iter2 = um.find(emails[i + 1].second);
				if (iter2 == um.end()) {
					um[emails[i+1].second] = um[emails[i].second];
				}
			}
			else {
				// 插入元素
				res[um[emails[i].second]].push_back(emails[i].first);	
			}
		}
		return res;
	}
	int unionFind(vector<int>& uf, int a,int b) {
		a = find(uf,a);
		b = find(uf,b);
		if (a == b) {
			return false;
		}
		uf[a] = b;
		return true;

	}
	int find(vector<int>& uf, int a) {
		while (uf[a] != -1) {
			a = uf[a];
		}
		return a;
	}

	int setIndex(vector<int>& uf, unordered_map<int, int>& um,int i,int& idx) {
		auto iter = um.find(i);
		if (iter != um.end()) {
			return iter->second;
		}
		if (uf[i] == -1) {
			um[i] = idx;
			return idx++;
		}
		return um[i] = setIndex(uf, um, uf[i], idx);
	}

};