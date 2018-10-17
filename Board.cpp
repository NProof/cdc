#include "Board.h"

Board::Board()
:color(0), darks(__UINT32_MAX__)
{}

Board::~Board()
{
	//dtor
}

void Board::flip(Mov mov)
{
	cheses[mov.src].type = mov.kind;
}

void Board::move(Mov mov)
{
	cheses[mov.dst()].type = cheses[mov.src].type;
	cheses[mov.src].type = 0;
}

void Board::eati(Mov mov)
{
	cheses[mov.dst()].type = cheses[mov.src].type;
	cheses[mov.src].type = 0;
}

vector<Mov *> Board::nextMovs()
{
	return vector<Mov *>();
}

ostream & operator<<(ostream & os, const Board board)
{
	for ( int i=0; i<8; i++)
	{
		for( int j=3; j>=0; j--)
			os << " , " << board.cheses[4*i+j];
		os << "\n";
	}
	return os << board.color << " #" << board.kinks;
}
