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

	friend ostream & operator<<(ostream &, const Chess);
//	protected:

//	private:
		unsigned char type;
};

#endif // CHESS_H
