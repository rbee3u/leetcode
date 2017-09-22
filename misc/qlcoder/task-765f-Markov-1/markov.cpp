#include <iostream>
using namespace std;

const int PROVIENCE_NUM = 31;

double mtr[ PROVIENCE_NUM ][ PROVIENCE_NUM ];
double vx[PROVIENCE_NUM],  vy[PROVIENCE_NUM];

void calc_mtr() {
	int uid, prev, curr;
	while (cin >> uid >> prev >> curr) {
		mtr[curr][prev] += 1;
	}
	for (int j = 0; j < PROVIENCE_NUM; ++j) {
		double col_sum = 0;
		for (int i = 0; i < PROVIENCE_NUM; ++i) {
			col_sum += mtr[i][j];
		}
		for (int i = 0; i < PROVIENCE_NUM; ++i) {
			mtr[i][j] /= col_sum;
		}
	}
}

void calc_vx() {
	int rawin[]={16389723,10262186,20593430,71685839
		,49425543,88979305,8060519, 68538709,33484131
		,23071690,41755874,26457769,36884039,56493891
		,33397663,42181417,89855501,90028072,52745625
		,61911446,43970320,26994017,76207174,33571308
		,43626674,34462115,24052594,2837769,5284525
		,5970133,20802249};
	for (int i = 0; i < PROVIENCE_NUM; ++i) {
		vx[i] = rawin[i];
	}
}

void do_trans() {
	for (int i = 0; i < PROVIENCE_NUM; ++i) {
		vy[i] = 0;
		for (int j = 0; j < PROVIENCE_NUM; ++j) {
			vy[i] += mtr[i][j] * vx[j];
		}
	}
	for (int i = 0; i < PROVIENCE_NUM; ++i) {
		vx[i] = vy[i];
	}
}

void print_vx() {
	for (int i = 0; i < PROVIENCE_NUM; ++i) {
		if (i > 0) cout << ",";
		cout << int(vx[i]);
	}
	cout << endl;
}

int main() {
	calc_mtr();
	calc_vx();
	do_trans();
	do_trans();
	do_trans();
	do_trans();
	do_trans();
	print_vx();
	return 0;
}