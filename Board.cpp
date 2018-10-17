#include "Board.h"

Board::Board()
:color(0), darks(__UINT32_MAX__)
{
    for(int i=0;i<8;i++){
        cheses[4*i+3].l1 = 0;
        cheses[4*i+3].l2 = 0;
    }
    for(int i=0;i<8;i++){
        cheses[4*i].r1 = 0;
        cheses[4*i].r2 = 0;
    }
    for(int i=0;i<4;i++){
        cheses[i].u1 = 0;
        cheses[i].u2 = 0;
    }
    for(int i=0;i<4;i++){
        cheses[28+i].d1 = 0;
        cheses[28+i].d2 = 0;
    }
    for(int i=0;i<8;i++){
        cheses[4*i+2].l2 = 0;
    }
    for(int i=0;i<8;i++){
        cheses[4*i+1].r2 = 0;
    }
    for(int i=0;i<4;i++){
        cheses[4+i].u2 = 0;
    }
    for(int i=0;i<4;i++){
        cheses[24+i].d2 = 0;
    }
}

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
    pos = (color & 0x1) ? red : black;
    __UINT32_TYPE__ opp = (color & 0x1) ? black : red;
    while(pos){
        __UINT32_TYPE__ mask = pos & (-pos);
        pos ^= mask;
        src = GetIndex(mask);
        if(cheses[src].r2 || (cheses[src].r1 && cheses[src-1].type==0)){
            ret.push_back(new Mov(2,src,src-1));
        }
        if(cheses[src].l2 || (cheses[src].l1 && cheses[src+1].type==0)){
            ret.push_back(new Mov(2,src,src+1));
        }
        if(cheses[src].u2 || (cheses[src].u1 && cheses[src-4].type==0)){
            ret.push_back(new Mov(2,src,src-4));
        }
        if(cheses[src].d2 || (cheses[src].d1 && cheses[src+4].type==0)){
            ret.push_back(new Mov(2,src,src+4));
        }
        if(cheses[src].isC()){
            if(cheses[src].r1 && cheses[src].r2 && (opp & (0x1<<(src-cheses[src].r2))))
                ret.push_back(new Mov(3,src,src-cheses[src].r2));
            if(cheses[src].l1 && cheses[src].l2 && (opp & (0x1<<(src+cheses[src].l2))))
                ret.push_back(new Mov(3,src,src+cheses[src].l2));
            if(cheses[src].u1 && cheses[src].u2 && (opp & (0x1<<(src-4*cheses[src].u2))))
                ret.push_back(new Mov(3,src,src-4*cheses[src].u2));
            if(cheses[src].d1 && cheses[src].d2 && (opp & (0x1<<(src+4*cheses[src].d2))))
                ret.push_back(new Mov(3,src,src+4*cheses[src].d2));
        }
        else{
            if(cheses[src].r1 == 1 && (cheses[src].canMov(cheses[src-1].type)))
                ret.push_back(new Mov(3,src,src-1));
            if(cheses[src].l1 == 1 && (cheses[src].canMov(cheses[src+1].type)))
                ret.push_back(new Mov(3,src,src+1));
            if(cheses[src].u1 == 1 && (cheses[src].canMov(cheses[src-4].type)))
                ret.push_back(new Mov(3,src,src-4));
            if(cheses[src].d1 == 1 && (cheses[src].canMov(cheses[src+4].type)))
                ret.push_back(new Mov(3,src,src+4));
        }
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
