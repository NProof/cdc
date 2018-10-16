#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Protocol.h"
#include "Board.h"
#include "Mov.h"

class Player
{
	public:
		/** Default constructor */
		Player();
		/** Default destructor */
		~Player();

		void setColor(PROTO_CLR);
        void generateMove(char *, Board &);
//        void makeMove(char *);
//        void makeMove(const char *, Board *&);

//	protected:

//	private:
};

#endif // PLAYER_H
