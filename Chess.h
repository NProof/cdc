#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include <utility>

using namespace std;

class Chess
{
	public:
		/** Default constructor */
		Chess();
		/** Default destructor */
		virtual ~Chess();

		bool isC();
		bool canMov(int type);

	friend ostream & operator<<(ostream &, const Chess);
//	protected:

//	private:
		unsigned char type;
		unsigned char r1,l1,u1,d1,r2,l2,u2,d2;
};

#endif // CHESS_H
