#include "CCanvas.h"
int main()
{
	CCanvas canvas;
	CCanvas canvas2;
	//canvas.m_init(8,8,4);
	//canvas.m_seter(4,8);
	//canvas.m_GetValue();
	canvas.m_initialice();
	canvas2.copy(canvas);
	return 0;
}