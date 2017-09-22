#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<string>> findLadders(string &beginWord, string &endWord, vector<string> &wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return {};
        unordered_set<string> head({beginWord}); wordSet.erase(beginWord);
        unordered_set<string> tail({ endWord }); wordSet.erase(  endWord);
        unordered_map<string, vector<string>> children;
        auto backward = false, found = false;
        while (!found && !head.empty()) {
            unordered_set<string> temp;
            for (const auto &curr : head) {
                auto next(curr);
                for (auto &o : next) {
                    for (auto c = 'a'; c <= 'z'; c++) {
                        auto t = o; o = c;
                        if (tail.count(next) != 0) {
                            found = true;
                            backward ? children[next].push_back(curr) : children[curr].push_back(next);
                        } else if (!found && wordSet.count(next) != 0) {
                            temp.insert(next);
                            backward ? children[next].push_back(curr) : children[curr].push_back(next);
                        }
                        o = t;
                    }
                }
            }
            for (const auto &next : temp) {
                wordSet.erase(next);
            }
            head.swap(temp); if (head.size() > tail.size()) {
                head.swap(tail); backward = !backward;
            }
        }
        vector<vector<string>> result;
        vector<string> path({beginWord});
        dfs(children, beginWord, endWord, path, result);
        return result;
    }

private:
    void dfs(unordered_map<string, vector<string>> &children, string &beginWord, string &endWord, vector<string> &path, vector<vector<string>> &result) {
        if (beginWord == endWord) {
            result.push_back(path); return;
        }
        for (auto child : children[beginWord]) {
            path.push_back(child);
            dfs(children, child, endWord, path, result);
            path.pop_back();
        }
    }
};

int main() {
    string beginWord("magic");
    string   endWord("pearl");
    vector<string> wordList = {"flail","halon","lexus","joint","pears","slabs","lorie","lapse","wroth","yalow","swear"
                               ,"cavil","piety","yogis","dhaka","laxer","tatum","provo","truss","tends","deana","dried"
                               ,"hutch","basho","flyby","miler","fries","floes","lingo","wider","scary","marks","perry"
                               ,"igloo","melts","lanny","satan","foamy","perks","denim","plugs","cloak","cyril","women"
                               ,"issue","rocky","marry","trash","merry","topic","hicks","dicky","prado","casio","lapel"
                               ,"diane","serer","paige","parry","elope","balds","dated","copra","earth","marty","slake"
                               ,"balms","daryl","loves","civet","sweat","daley","touch","maria","dacca","muggy","chore"
                               ,"felix","ogled","acids","terse","cults","darla","snubs","boats","recta","cohan","purse"
                               ,"joist","grosz","sheri","steam","manic","luisa","gluts","spits","boxer","abner","cooke"
                               ,"scowl","kenya","hasps","roger","edwin","black","terns","folks","demur","dingo","party"
                               ,"brian","numbs","forgo","gunny","waled","bucks","titan","ruffs","pizza","ravel","poole"
                               ,"suits","stoic","segre","white","lemur","belts","scums","parks","gusts","ozark","umped"
                               ,"heard","lorna","emile","orbit","onset","cruet","amiss","fumed","gelds","italy","rakes"
                               ,"loxed","kilts","mania","tombs","gaped","merge","molar","smith","tangs","misty","wefts"
                               ,"yawns","smile","scuff","width","paris","coded","sodom","shits","benny","pudgy","mayer"
                               ,"peary","curve","tulsa","ramos","thick","dogie","gourd","strop","ahmad","clove","tract"
                               ,"calyx","maris","wants","lipid","pearl","maybe","banjo","south","blend","diana","lanai"
                               ,"waged","shari","magic","duchy","decca","wried","maine","nutty","turns","satyr","holds"
                               ,"finks","twits","peaks","teems","peace","melon","czars","robby","tabby","shove","minty"
                               ,"marta","dregs","lacks","casts","aruba","stall","nurse","jewry","knuth"};
    Solution sol;
    auto result = sol.findLadders(beginWord, endWord, wordList);
    cout << result.size() << endl;
    return 0;
}
