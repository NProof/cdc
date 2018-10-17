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

int index32[32] = {31,0,1,5,2,16,27,6,3,14,17,19,28,11,7,21,30,4,15,26,13,18,10,20,29,25,12,9,24,8,23,22};

int BitsHash(__UINT32_TYPE__ x)
{
	return (x * 0x08ED2BE6) >> 27;
}

int GetIndex(__UINT32_TYPE__ mask)
{
	return index32[BitsHash(mask)];
}

vector<Mov *> Board::nextMovs()
{
    vector<Mov *> ret;
    int src;
    __UINT32_TYPE__ pos = darks;
    while(pos){
        __UINT32_TYPE__ mask = pos & (-pos);
        pos ^= mask;
        src = GetIndex(mask);
        ret.push_back(new Mov(1,src,15));
    }
	return ret;
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
