#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (um.find(key) == um.end()) {
            um[key] = {};
        }
        um[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (um.find(key) == um.end()) {
            return "";
        }
        auto it = um[key].lower_bound(timestamp);
        if (it == um[key].end()) {
            return "";
        } else {
            return it->second;
        }
    }

private:
    unordered_map<string, map<int, string, greater<int>>> um;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

