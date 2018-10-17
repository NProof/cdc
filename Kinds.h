#ifndef KINDS_H
#define KINDS_H

#include <ostream>

using namespace std;

class Kinds
{
	public:
		/** Default constructor */
		Kinds();
		/** Default destructor */
		~Kinds();

	friend ostream & operator<<(ostream &, const Kinds);
//	protected:

//	private:
		int k,g,m,r,n,c,p;
		int K,G,M,R,N,C,P;
};

#endif // KINDS_H
