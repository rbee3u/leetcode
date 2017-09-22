#include <iostream>
#include <cstdint>
#include "modulo.h"


Piece::Piece() : state(0), bits(0) {}


Piece::Piece(uint32_t o_state, uint64_t o_bits)
			: state(o_state), bits(o_bits) {}


int Grid::modu = 2;
int Grid::nrow = 0;
int Grid::ncol = 0;


Grid::Grid() : ones(0), twos(0) {}


Grid::Grid(uint64_t o_ones, uint64_t o_twos)
	: ones(o_ones), twos(o_twos) {}


void Grid::add(Piece &a_piece) {
	uint64_t bits = a_piece.bits;
	switch (modu) {
		case 4: ones = ones ^ bits;
				twos = twos ^ (bits & ~ones);
				break;
		case 3: ones = (ones ^ bits) & ~twos;
				twos = (twos ^ bits) & ~ones;
				break;
		default: ones = ones ^ bits; twos = 0;
				break;
	}
}


void Grid::minus() {
	uint64_t bits;
	switch (modu) {
		case 4: twos = twos ^ ones;
				break;
		case 3: bits = ones;
				ones = ~ones & twos;
				twos = ~twos & bits;
				break;
		default: twos = 0;
				break;
	}
}


bool Grid::is_zero() {
	return (ones==0) && (twos==0);
}


void Grid::print() {
	std::cout << twos << "-" << ones << std::endl;
}


bool GridPred::operator() (const Grid &a, const Grid &b) const {
	return (a.ones == b.ones) && (a.twos == b.twos);
}


size_t GridHash::operator() (const Grid &g) const {
	return size_t(g.ones + ( g.twos * 2) );
}

