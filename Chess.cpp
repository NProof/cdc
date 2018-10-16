#include "Chess.h"

Chess::Chess()
:type(15)
{
	//ctor
}

Chess::~Chess()
{
	//dtor
}

ostream & operator<<(ostream & os, const Chess chess)
{
	switch(chess.type)
	{
	case 0:
		return os << "-";
	case 1:
		return os << "k";
	case 2:
		return os << "g";
	case 3:
		return os << "m";
	case 4:
		return os << "r";
	case 5:
		return os << "n";
	case 6:
		return os << "c";
	case 7:
		return os << "p";
	case 8:
		return os << "K";
	case 9:
		return os << "G";
	case 10:
		return os << "M";
	case 11:
		return os << "R";
	case 12:
		return os << "N";
	case 13:
		return os << "C";
	case 14:
		return os << "P";
	case 15:
		return os << "X";
	default:
		exit(1);
	};
}
