#ifndef _modulo_h_
#define _modulo_h_
#include <cstdint>

struct Piece {
	uint32_t state;
	uint64_t bits;
	Piece();
	Piece(uint32_t o_state, uint64_t o_bits);
};

class Grid {
public:
	static int modu;
	static int nrow;
	static int ncol;
	uint64_t ones, twos;
	Grid();
	Grid(uint64_t o_ones, uint64_t o_twos);
	void add(Piece &a_piece);
	void minus();
	bool is_zero();
	void print();
};

struct GridPred {
	bool operator() (const Grid &a, const Grid &b) const;
};

struct GridHash {
	size_t operator() (const Grid &g) const;
};

#endif