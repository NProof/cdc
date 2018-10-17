#include "Kinds.h"

Kinds::Kinds()
:k(1),g(2),m(2),r(2),n(2),c(2),p(5)
,K(1),G(2),M(2),R(2),N(2),C(2),P(5)
{
	//ctor
}

Kinds::~Kinds()
{
	//dtor
}

ostream & operator<<(ostream & os, const Kinds kinds)
{
	os
	<<kinds.k<<kinds.g<<kinds.m<<kinds.r<<kinds.n<<kinds.c<<kinds.p
	<<kinds.K<<kinds.G<<kinds.M<<kinds.R<<kinds.N<<kinds.C<<kinds.P<<endl;
	return os ;
}
