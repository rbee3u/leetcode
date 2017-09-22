class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		unordered_set<int> sets; for (int i=0; i < n; ++i) {
			sets.insert(i);
		}
		vector<list<int>> graph(n); for (auto &e : edges) {
			graph[e.first].push_front(e.second);
			graph[e.second].push_front(e.first);
		}
		vector<int> curr, next;
		for (int i=0; i < n; ++i) if (graph[i].size()==1) {
			curr.push_back(i);
		}
		for (; sets.size() > 2; ) {
			for (auto i : curr) {
				sets.erase(i); int j=*(graph[i].begin());
				graph[i].remove(j); graph[j].remove(i);
				if (graph[j].size()==1) {next.push_back(j);}
			}
			curr.swap(next); next.clear();
		}
		vector<int> ret(sets.begin(), sets.end());
		sort(ret.begin(), ret.end());
		return ret;
	}
};
