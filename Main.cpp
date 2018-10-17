#include "Main.h"

void test()
{
	{
		Mov mov[] = {Mov(3,4,8),Mov(3,5,1),Mov(3,27,24),Mov(3,4,5)};
	assert(mov[0].dst()==8);
	assert(mov[1].dst()==1);
	assert(mov[2].dst()==24);
	assert(mov[3].dst()==5);
	assert(mov[0].toString()=="d2-d3");
	assert(mov[1].toString()=="c2-c1");
	assert(mov[2].toString()=="a7-d7");
	assert(mov[3].toString()=="d2-c2");
//	cout << mov[0] << mov[1] << mov[2] << mov[3] << endl;
	}
	{
		Board board;
	board.flip(Mov(1,2,2));
	assert(Mov(1,2,2).toString() == "b1(g)");
	assert(board.cheses[2].type == 2);
	board.flip(Mov(1,3,9));
	board.eati(Mov(3,2,3));
//	cout << Mov(3,2,3).toString() << endl;
	assert(board.cheses[2].type == 0);
	assert(board.cheses[3].type == 2);
	board.flip(Mov(1,12,5));
	board.move(Mov(2,3,2));
	assert(Mov(2,3,2).toString() == "a1-b1");
	assert(board.cheses[3].type == 0);
	assert(board.cheses[2].type == 2);
//	cout << board << endl;
	}
}

int main(int arg, char *argv[])
{
	test();
	Board board;
	char move[6];
	Player player1, player2;

	player1.generateMove(move, board);
//	if( color == PCLR_UNKNOW )
//	{
//		player1.setColor(color);
//	}
//	player1.makeMove(move);
//	player2.makeMove(move);

	/*while(1)
	{
		player.generateMove(move);
		// protocol.send(move);
		// protocol.recv(move,time);
		player.makeMove(move);
		// protocol.recv(move,time);
		player.makeMove(move);
	}*/
	cout << board << hex << board.darks << endl;
	return 0;
}
