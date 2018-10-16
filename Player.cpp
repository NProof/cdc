#include "Player.h"

Player::Player()
{
	//ctor
}

Player::~Player()
{
	//dtor
}

void Player::generateMove(char * move, Board & board)
{
	std::vector<Mov *> movs = board.nextMovs();
    if(movs.empty())
    {
        strcpy(move, "NAN");
    }
    else
    {
        int times = rand()%(movs.size());
        strcpy(move, (movs[times]->toString()).c_str());
    }
}
