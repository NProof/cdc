#ifndef MOV_H
#define MOV_H

#include <ostream>

using namespace std;

class Mov
{
	public:
		/** Default constructor */
		Mov(int,int,int);
		/** Default destructor */
		virtual ~Mov();
		string toString();

		int dst() const;

	friend ostream & operator<<(ostream &, const Mov);
//	protected:

//	private:
		int type; //0: overboard, 1: flip, 2: move, 3: eat
		int src;
		int dir;
		int len;
		int kind;
};

#endif // MOV_H
