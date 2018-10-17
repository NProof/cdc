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
bool Chess::isC()
{
    return type==6||type==13;
}

bool Chess::canMov(int betype)
{
    switch(type)
    {
    case 0: //  "-";
        return false;
	case 1: // "k";
		return 7<betype&&betype<14;
	case 2: // "g";
		return 8<betype&&betype<15;
	case 3: // "m";
		return 9<betype&&betype<15;
	case 4: // "r";
		return 10<betype&&betype<15;
	case 5: // "n";
		return 11<betype&&betype<15;
	case 6: // "c";
		exit(2);
	case 7: // "p";
		return betype==8||betype==14;
	case 8: // "K";
		return 0<betype&&betype<7;
	case 9: // "G";
		return 1<betype&&betype<8;
	case 10: // "M";
		return 2<betype&&betype<8;
	case 11: // "R";
		return 3<betype&&betype<8;
	case 12: // "N";
		return 4<betype&&betype<8;
	case 13: // "C";
        exit(2);
	case 14: // 'P'
	    betype==7;
	case 15: // 'x'
        exit(3);
	default: // others.
		exit(1);
    };
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
