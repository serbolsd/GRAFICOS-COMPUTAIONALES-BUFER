#pragma once
#include "CPixel.h"
class CCanvas
{
public:
	CCanvas();
	~CCanvas();
	int m_rows;
	int m_columns;
	int m_pitch;
	float m_normU = 1;
	float m_normV = 1;
	// these values ​​take the value in the uv until another one is taken again
	unsigned char getR, getG, getB, getA;
	CPixel* m_pixeles;
	//format: 1=R8, 2=R8G8, 3=R8G8B8, 4=R8G8B8A8, 5=R32G32B32A32
	void init(int rowns, int columns, int format, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void selectFormato(int format);
	void fill(unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void setFormat(float posU, float posV, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void getFormat(float posU, float posV, unsigned char &R, unsigned char& G, unsigned char& B, unsigned char& A);
	void DrawnHoriLine(float posUorigen, float posUdestino, float posV, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void DrawnVertiLine(float posVorigen, float posVdestino, float posX, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void DrawnMatriz();
	//sample: 1=point 2=bilinear
	void copy(CCanvas canvaslOrigen, int sample, int rowns, int columns, int format, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void point(CCanvas canvaslOrigen);
	void bilinear(CCanvas canvaslOrigen);
	void DrawnDiagonalLine(float posUOrigen, float posVOrigen, float posUdestino, float posVdestino, unsigned char R, unsigned char G, unsigned char B, unsigned char A);

};

