#include "CCanvas.h"
int main()
{
	CCanvas can;
	can.init(10, 10, 4, 'A', 'B', 'C', 'D');
	//can.init(10, 10,4, 'A', 'B', 'C', 'D');
	can.DrawnHoriLine(0.5f, 1.0f, 0.5f, 'E', 'F', 'G', 'H');
	can.DrawnVertiLine(0.5f, 1.0f, 0.5f, 'I', 'J', 'K', 'L');
	can.DrawnDiagonalLine(0.0f, 0.0f, 1.0f, 1.0f, 'O', 'B', 'O', 'S');
	can.DrawnMatriz();
	CCanvas cancopy;
	cancopy.copy(can,1, 10, 10, 3, 'M', 'N', 'O', 'P');
	
	return 0;
}