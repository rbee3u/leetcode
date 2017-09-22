#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "LibMd5.h"
using namespace std;


const int MAXN = 10000001;
const char OPEP = 'p', OPEV = 'v';
struct Behavior {
	char ope; int uid; string s;
};


template<typename T> class PrimeTable {
private:
	vector<uint32_t> array; vector<T> plist;
	void setf(T n) {array[n/32] &= ~(1<<(n%32));}
public:
	bool isPrime(T n) {return (array[n/32]&(1<<(n%32)));}
	T getPrime(T idx) {return plist[idx];}
	T getLimit() {return (array.size() * 32);}
	T getCount() {return (plist.size() - 1);}
	PrimeTable(T limit) {
		limit = (limit+31) / 32 * 32;
		array.resize(limit / 32, -1);
		setf(0); setf(1); T d, n;
		for (d=2; d*d<limit; ++d) if(isPrime(d)) {
			for (n=d+d; n<limit; n+=d) {setf(n);}
		}
		plist.push_back(0); for (n=1; n<limit; ++n) {
			if (isPrime(n)) {plist.push_back(n);}
		}
	}
};
PrimeTable<int> pt(MAXN);


vector<Behavior> rdata; void input() {
	// cout << "input..." << endl;
	int cnt = 0;
	Behavior elem;
	while (cin>>elem.ope>>elem.uid) {
		++cnt; if (cnt > 10000000) break;
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


vector<vector<int>> followers(MAXN);
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


int md5str(char *buffer, char *target)
{
    Md5Context      md5Context;
    MD5_HASH        md5Hash;
    uint16_t        i;

    Md5Initialise( &md5Context );
    Md5Update( &md5Context, buffer, (uint32_t)strlen(buffer) );
    Md5Finalise( &md5Context, &md5Hash );

    for( i=0; i<sizeof(md5Hash); i++ )
    {
        sprintf( target+i*2, "%02x", md5Hash.bytes[i] );
    }

    return 0;
}


void str2md5(string &str, char *target) {
	static char buffer[99999999];
	sprintf(buffer, "%s", str.c_str());
	md5str(buffer, target);
}


vector<vector<int>> msg_q(MAXN);
vector<int> last(MAXN, 0);
vector<int> prime_pq;
void do_exe_timeline() {
	// cout << "do_exe_timeline..." << endl;
	static char target[99999999];
	for (int i=0; i < rdata.size(); ++i) {
		Behavior &elem = rdata[i];
		if (elem.ope==OPEP) {
			for (auto &flw : followers[elem.uid]) {
				msg_q[flw].push_back(i);
			}
			if (pt.isPrime(elem.uid)) {
				prime_pq.push_back(i);
			}
		} else {
			string towrite("");
			vector<int> viewlist;
			for (auto &x : msg_q[elem.uid]) {
				viewlist.push_back(x);
			}
			while (last[elem.uid] < prime_pq.size()) {
				int temp = last[elem.uid];
				if (elem.uid < rdata[prime_pq[temp]].uid) {
					viewlist.push_back(prime_pq[temp]);
				}
				++last[elem.uid];
			}
			sort(viewlist.begin(), viewlist.end());
			int nsize = viewlist.size();
			for (int i=nsize-1; i >= 0; --i) {
				if (i<nsize-1) { towrite += "-"; }
				towrite += rdata[viewlist[i]].s;
			}
			msg_q[elem.uid].clear();
			str2md5(towrite, target);
			printf("%s\n", target);
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


