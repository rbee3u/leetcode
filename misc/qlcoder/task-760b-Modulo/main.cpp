#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include "modulo.h"


int backn, level;
int pieces_num;
std::vector<std::vector<Piece>> pieces_list;
void pre_process(Grid &init);
GridPred grid_equal;


std::unordered_map<Grid, std::vector<uint32_t>
				, GridHash, GridPred> bstates;

// int cnt = 0;
void back_dfs(int depth, Grid curr, std::vector<uint32_t> &tr) {
	// std::cout << depth << std::endl;
	if (depth >= pieces_num) {
		// curr.print();
		// cnt++;
		// if (cnt % 1000000 == 0) std::cout << cnt << std::endl;
		bstates[curr] = tr;
		return;
	}
	for (auto &pc : pieces_list[depth]) {
		tr.push_back(pc.state);
		Grid next = curr; next.add(pc);
		back_dfs(depth+1, next, tr);
		tr.pop_back();
	}
}


bool is_found = false;
void forward_dfs(int depth, Grid curr, std::vector<uint32_t> &tr) {
	// std::cout << depth << std::endl;
	if (is_found) {return;}
	if (depth >= backn) {
		// curr.print();
		curr.minus();
		auto it = bstates.find(curr);
		if (it != bstates.end()) {
			is_found = true;
			std::vector<uint32_t> ans;
			for (auto x : tr) ans.push_back(x);
			for (auto x : it->second) ans.push_back(x);
			sort(ans.begin(), ans.end());
			for (auto x : ans) {
				std::cout << (x / 256) % 256;;
				std::cout << (x % 256);
			}
			std::cout << std::endl;
		}
		return;
	}
	for (auto &pc : pieces_list[depth]) {
		// if (rand() % 2) continue;
		if (depth < 2) {
			std::cout << "depth: " << depth << std::endl;
		}
		tr.push_back(pc.state);
		Grid next = curr; next.add(pc);
		forward_dfs(depth+1, next, tr);
		tr.pop_back();
	}
}


int main() {
	// srand(time(NULL));
	// Grid::modu = 4;
	// Grid g(0, 0), h;
	// g.print();
	// h = g; h.minus();
	// h.print();
	// Piece p(0, 1);
	// g.add(p);
	// g.print();
	// h = g; h.minus();
	// h.print();
	// g.add(p);
	// g.print();
	// h = g; h.minus();
	// h.print();
	// g.add(p);
	// g.print();
	// h = g; h.minus();
	// h.print();
	// g.add(p);
	// g.print();
	// h = g; h.minus();
	// h.print();
	Grid init;
	pre_process(init);
	Grid zero(0, 0);
	std::vector<uint32_t> tr;
	back_dfs(backn, zero, tr);
	// std::cout << bstates.size() << std::endl;
	forward_dfs(0, init, tr);
	return 0;
}


void pre_process(Grid &init) {
	std::cin >> backn;
	// std::cout << backn << std::endl;
	std::cin >> level;
	std::cin >> Grid::modu;
	std::cin >> Grid::nrow;
	std::cin >> Grid::ncol;
	std::cin >> init.ones;
	std::cin >> init.twos;
	// init.print();
	std::cin >> pieces_num;
	// std::cout << pieces_num << std::endl;
	pieces_list.resize(pieces_num);
	for (int i = 0; i < pieces_num; ++i) {
		int cands_num; std::cin >> cands_num;
		// std::cout << cands_num << std::endl;
		for (int j = 0; j < cands_num; ++j) {
			int idx, srow, scol;
			uint64_t bits;
			std::cin >> idx;
			std::cin >> srow;
			std::cin >> scol;
			std::cin >> bits;
			uint32_t state = 0;
			state = (state | idx);
			state = (state << 8);
			state = (state | srow);
			state = (state << 8);
			state = (state | scol);
			Piece pc(state, bits);
			pieces_list[i].push_back(pc);
		}
	}
}



