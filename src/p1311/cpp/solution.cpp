class Solution {
public:
    vector<string>
    watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level) {
        auto n = int(watchedVideos.size());
        vector<int> persons;
        vector<bool> seen(n, false);
        queue<tuple<int, int>> q;
        seen[id] = true;
        q.emplace(id, 0);
        while (!q.empty()) {
            auto[currId, currLv] = q.front();
            q.pop();
            if (currLv >= level) {
                persons.push_back(currId);
            } else {
                for (auto neighbor : friends[currId]) {
                    if (!seen[neighbor]) {
                        seen[neighbor] = true;
                        q.emplace(neighbor, currLv + 1);
                    }
                }
            }
        }
        unordered_map<string, int> frequencies;
        for (auto person : persons) {
            for (auto &video: watchedVideos[person]) {
                frequencies[video]++;
            }
        }
        vector<tuple<int, string>> pairs;
        for (auto &frequency : frequencies) {
            pairs.emplace_back(frequency.second, frequency.first);
        }
        sort(pairs.begin(), pairs.end());
        vector<string> result;
        for (auto &pair : pairs) {
            result.push_back(get<1>(pair));
        }
        return result;
    }
};
