#ifndef BOARD_H
#define BOARD_H

#include "Mov.h"
#include "Kinds.h"
#include "Chess.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Board
{
	public:
		/** Default constructor */
		Board();
		/** Default destructor */
		virtual ~Board();

		void flip(Mov mov); // type = 1
		void move(Mov mov); // type = 2
		void eati(Mov mov); // type = 3
		pair<__UINT32_TYPE__,int> PartOfdark(); /*Pieces*/
		vector<Mov *> nextMovs();

	friend ostream & operator<<(ostream &, const Board);
//	protected:

//	private:
		Chess cheses[32];
		__UINT32_TYPE__ darks;
		int color; // 0: unknown, 1:red, 2:black, 3:end
		Kinds kinks;
};

#endif // BOARD_H
