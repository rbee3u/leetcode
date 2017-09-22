class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (auto &edge : prerequisites) {
            adjList[edge.second].push_back(edge.first);
        }
        vector<int> color(numCourses, WHITE);
        for (int u = 0; u < numCourses; ++u) if (color[u]==WHITE
            && !dfsVisit(adjList, color, u)) { return false; }
        return true;
    }
private:
    static const int WHITE, GRAY, BLACK;
    bool dfsVisit(vector<vector<int>> &adjList, vector<int> &color, int u) {
        color[u] = GRAY; for (auto &v : adjList[u]) if (color[v]==GRAY
        || color[v]==WHITE && !dfsVisit(adjList, color, v)) { return false; }
        color[u] = BLACK; return true;
    }
};
const int Solution::WHITE = 0;
const int Solution::GRAY = 1;
const int Solution::BLACK = 2;
