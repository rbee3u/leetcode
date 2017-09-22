#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


const int MAXN = 10000001;
const char OPEP = 'p', OPEV = 'v';
struct Behavior {
	char ope; int uid; string s;
};


vector<Behavior> rdata; void input() {
	// cout << "input..." << endl;
	Behavior elem;
	while (cin>>elem.ope>>elem.uid) {
		if (elem.ope==OPEP) { cin>>elem.s; }
		rdata.push_back(elem); elem.s = "";
	}
}


unordered_set<int> phash, vhash;
void calc_phash_and_vhash() {
	// cout << "calc_phash_and_vhash..." << endl;
	for (auto &elem : rdata) {
		if (elem.ope==OPEP) {
			phash.insert(elem.uid);
		} else {
			vhash.insert(elem.uid);
		}
	}
}


unordered_map<int, vector<int>> followers;
void calc_followers() {
	// cout << "calc_followers..." << endl;
	for (auto &uid : phash) {
		for (int mul=uid*2; mul<MAXN; mul+=uid) {
			if (vhash.find(mul) != vhash.end()) {
				followers[uid].push_back(mul);
			}
		}
		if (1!=uid&&vhash.find(1)!=vhash.end()) {
			followers[uid].push_back(1);
		}
	}
}


unordered_map<int, vector<string>> msg_q;
void do_exe_timeline() {
	// cout << "do_exe_timeline..." << endl;
	for (auto &elem : rdata) {
		if (elem.ope==OPEP) {
			for (auto &flw : followers[elem.uid]) {
				msg_q[flw].push_back(elem.s);
			}
		} else {
			string towrite("");
			int nsize = msg_q[elem.uid].size();
			for (int i=nsize-1; i >= 0; --i) {
				if (i<nsize-1) { towrite += "-"; }
				towrite += msg_q[elem.uid][i];
			}
			msg_q[elem.uid].clear();
			cout << towrite << endl;
		}
	}
}


int main() {
	input();
	calc_phash_and_vhash();
	calc_followers();
	do_exe_timeline();
	return 0;
}


