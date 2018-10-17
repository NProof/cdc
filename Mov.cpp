#include "Mov.h"

Mov::Mov(int type, int src, int dstOrkind)
{
	this->type = type;
	switch(type)
	{
	case 0: // overboard.
		break;
	case 1: // flip
		this->src = src;
		this->kind = dstOrkind;
		break;
	case 2: // move
		this->src = src;
		len = 1;
		switch(dstOrkind - src)
		{
		case -4:
			dir = 0;
			break;
		case -1:
			dir = 1;
			break;
		case 1:
			dir = 3;
			break;
		case 4:
			dir = 2;
			break;
		default :
			exit(1);
		};
		break;
	case 3: // eat
		this->src = src;
		int dif = dstOrkind - src;
		if(dif == 0)
		{
			exit(1);
		}
		else if(dif % 4 == 0)
		{
			dir = (dif>0) ? 2 : 0;
			len = (dif>0) ? (dif/4) : (-dif/4);
		}
		else if(-4 < dif && dif < 4)
		{
			dir = (dif>0) ? 3 : 1;
			len = (dif>0) ? dif : -dif;
		}
		else exit(1);
		break;
	};
}

Mov::~Mov()
{
	//dtor
}

string Mov::toString()
{
	int idst = dst();
	if(0<=src&&src<32&&0<=idst&&idst<32){
		return string{char('d'-src%4),char('1'+src/4),'-',char('d'-idst%4),char('1'+idst/4)};
	}
	else if(0<=src&&src<32&&0<=kind&&kind<32){
		return string{char('d'-src%4),char('1'+src/4),'(',"-kgmrncpKGMRNCPX"[kind],')'};
	}
	return "NAN";
}

int Mov::dst() const
{
	switch(dir)
	{
	case 0:
		return src-4*len;
	case 1:
		return src-1*len;
	case 2:
		return src+4*len;
	case 3:
		return src+1*len;
	default:
		return -1;
	}
}

std::ostream & operator<<(std::ostream & os, const Mov mov)
{
	return os << mov.type << " := " << mov.src << " " << mov.dst() << std::endl;
}
