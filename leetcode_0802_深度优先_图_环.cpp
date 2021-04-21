class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		vector<bool> cycle(graph.size(), false);
		vector<bool> visited(graph.size(), false);
		vector<bool> curr(graph.size(), false);
		for (int i = 0; i<graph.size(); i++) {
			if (dfs(graph, cycle, visited, curr, i)) {
				cycle[i] = true;
			}
		}
		vector<int> res;
		for (int i = 0; i < cycle.size(); i++) {
			if (!cycle[i]) {
				res.push_back(i);
			}
		}
		return res;
	}

	bool dfs(vector<vector<int>>& graph, vector<bool>& cycle, vector<bool>& visited, vector<bool>& curr, int i) {
		if (visited[i]) {
			if (cycle[i] || curr[i]) {
				return true;
			}
			else {
				return false;
			}
		}
		bool res = false;
		visited[i] = true;
		curr[i] = true;
		for (auto edge : graph[i]) {
			if (dfs(graph, cycle, visited, curr, edge)) {
				cycle[edge] = true;
				res = true;
			}
		}
		curr[i] = false;
		return res;
	}
};