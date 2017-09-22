class Solution {
public:
    int compareVersion(string version1, string version2) {
        while (version1 != "" && version2 != "") {
            pair<int,string> sp1 = split(version1);
            pair<int,string> sp2 = split(version2);
            if (sp1.first > sp2.first) {
                return 1;
            } else
            if (sp1.first < sp2.first) {
                return -1;
            } else {
                version1 = sp1.second;
                version2 = sp2.second;
                if (version1[0] == '.') {
                    version1 = version1.substr(1);
                }
                if (version2[0] == '.') {
                    version2 = version2.substr(1);
                }
                if (version1 == "" && version2 != "") {
                    version1 = "0";
                }
                if (version1 != "" && version2 == "") {
                    version2 = "0";
                }
            }
        }
        return 0;
    }
private:
    pair<int,string> split(string s) {
        string::size_type sz;
        int fst = std::stoi(s, &sz);
        string snd = s.substr(sz);
        return make_pair(fst, snd);
    }
};