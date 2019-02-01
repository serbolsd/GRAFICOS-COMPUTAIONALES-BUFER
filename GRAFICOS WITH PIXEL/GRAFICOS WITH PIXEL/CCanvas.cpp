#include "CCanvas.h"
#include <iostream>

using std::cout;
using std::endl;

CCanvas::CCanvas()
{
	delete[]m_pixeles;
}


CCanvas::~CCanvas()
{
}
void CCanvas::selectFormato(int format)
{
	//this is for select format for the first pixel
	switch (format)
	{
	case 1:
		m_pixeles->TYPE_FORMAT =CPixel::TF_R8;
		break;
	case 2:
		m_pixeles->TYPE_FORMAT = CPixel::TF_R8G8;
		break;
	case 3:
		m_pixeles->TYPE_FORMAT = CPixel::TF_R8G8B8;
		break;
	case 4:
		m_pixeles->TYPE_FORMAT = CPixel::TF_R8G8B8A8;
		break;
	case 5:
		m_pixeles->TYPE_FORMAT = CPixel::TF_R32G32B32A32;
		break;
	}
}

void CCanvas::fill(unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			int index = (m_pitch*i) + j;
			if (m_pixeles->TYPE_FORMAT == CPixel::TF_R32G32B32A32)
			{
				//the unsigned char if normalized for transform to float
				(m_pixeles+ index)->R32 = (float)(R / 255);
				(m_pixeles+ index)->G32 = (float)(G / 255);
				(m_pixeles+ index)->B32 = (float)(B / 255);
				(m_pixeles+ index)->A32 = (float)(A / 255);
			}
			else
			{
				(m_pixeles + index)->R8 = R;
				switch (m_pixeles->TYPE_FORMAT)
				{
				case CPixel::TF_R8G8:
					(m_pixeles + index)->G32 = G;
					break;
				case CPixel::TF_R8G8B8:
					(m_pixeles+ index)->G8 = G;
					(m_pixeles+ index)->B8 = B;
					break;
				case CPixel::TF_R8G8B8A8:
					(m_pixeles+ index)->G8 = G;
					(m_pixeles+ index)->B8 = B;
					(m_pixeles+ index)->A8 = A;
					break;

				}
			}
		}

	}

}

void CCanvas::init(int rowns, int columns, int format, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	m_pixeles = new CPixel[rowns*columns];
	m_rows = rowns;
	m_columns = columns;
	m_normU = m_normU / columns;
	m_normV = m_normV / rowns;
	m_pitch = columns;
	selectFormato(format);
	fill(R, G, B, A);
}

void CCanvas::setFormat(float posU, float posV, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	int U;
	int V;
	//here calculated the row to set
	for (int i = 0; i < m_rows; i++)
	{
		if (!(m_normV*(i+1)<posV))
		{
			V = i;
			break;
		}
	}
	//here calculated the column to set
	for (int i=0; i<m_columns;i++)
	{
		if (!(m_normU*(i+1)<posU))
		{
			U = i;
			break;
		}
	}
	int index = (m_pitch*V) + U;
	if (m_pixeles->TYPE_FORMAT==CPixel::TF_R32G32B32A32)
	{
		//the unsigned char if normalized for transform to float
		(m_pixeles+index)->R32 = (float)(R / 255);
		(m_pixeles+index)->G32 = (float)(G / 255);
		(m_pixeles+index)->B32 = (float)(B / 255);
		(m_pixeles+index)->A32 = (float)(A / 255);
	}
	else
	{
		(m_pixeles + index)->R8 = R;
		switch (m_pixeles->TYPE_FORMAT)
		{
		case CPixel::TF_R8G8:
			(m_pixeles + index)->G32 = G;
			break;
		case CPixel::TF_R8G8B8:
			(m_pixeles+index)->G8 = G;
			(m_pixeles+index)->B8 = B;
			break;
		case CPixel::TF_R8G8B8A8:
			(m_pixeles+index)->G8 = G;
			(m_pixeles+index)->B8 = B;
			(m_pixeles+index)->A8 = A;
			break;

		}
	}
	
}

void CCanvas::getFormat(float posU, float posV, unsigned char &R, unsigned char& G, unsigned char& B, unsigned char& A)
{
	int U;
	int V;
	//here calculated the row to set
	for (int i = 0; i < m_rows; i++)
	{
		if (!(m_normV*(i + 1) < posV))
		{
			V = i;
			break;
		}
	}
	//here calculated the column to set
	for (int i = 0; i < m_columns; i++)
	{
		if (!(m_normU*(i + 1) < posU))
		{
			U = i;
			break;
		}
	}
	int index = (m_pitch*V) + U;
	if (m_pixeles->TYPE_FORMAT == CPixel::TF_R32G32B32A32)
	{
		//the unsigned char if normalized for transform to float
		R=( unsigned char)(((m_pixeles + index)->R32)*255);
		G=( unsigned char)(((m_pixeles + index)->G32)*255);
		B=( unsigned char)(((m_pixeles + index)->B32)*255);
		A=( unsigned char)(((m_pixeles + index)->A32)*255);
	}
	else
	{
		//the value is equal to his respective format 
		R=(m_pixeles + index)->R8;
		switch (m_pixeles->TYPE_FORMAT)
		{
		case CPixel::TF_R8G8:
			G=(m_pixeles + index)->G32;
			break;
		case CPixel::TF_R8G8B8:
			G = (m_pixeles + index)->G8 ;
			B = (m_pixeles + index)->B8 ;
			break;					
		case CPixel::TF_R8G8B8A8:	
			G=(m_pixeles + index)->G8 ;
			B=(m_pixeles + index)->B8 ;
			A=(m_pixeles + index)->A8 ;
			break;

		}
	}
	//here printing the get values
	//cout << "R:" << R << endl;
	//cout << "G:" << G << endl;
	//cout << "B:" << B << endl;
	//cout << "A:" << A << endl;
}

void CCanvas::DrawnHoriLine(float posUorigen, float posUdestino,float posV, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	//int row;
	//int columnOrigen;
	//int columnDestino;
	//float cambiopos=posUorigen;
	//for (int i = 0; i < m_columns; i++)
	//{
	//	if (!(m_normU*(i+1)<posUorigen))
	//	{
	//		columnOrigen = i;
	//	}
	//}
	//for (int i = 0; i < m_columns; i++)
	//{
	//	if (!(m_normU*(i + 1) < posUdestino))
	//	{
	//		columnDestino = i;
	//	}
	//}
	//for (int i = 0; i < m_rows; i++)
	//{
	//	if (!(m_normV*(i + 1) < posV))
	//	{
	//		row = i;
	//	}
	//}
	
	for (float i = posUorigen; i <posUdestino; i+=0.0001f)
	{
		setFormat(i, posV, R, G, B, A);
	}
}

void CCanvas::DrawnVertiLine(float posVorigen, float posVdestino, float posX, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	for (float i=posVorigen;i<posVdestino;i+=0.0001f)
	{
		setFormat(posX, i, R, G, B, A);
	}
}

void CCanvas::DrawnMatriz()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			cout << "|";
			int index = (m_pitch*i) + j;
			switch (m_pixeles->TYPE_FORMAT)
			{
			case CPixel::TF_R8:
				cout << (m_pixeles+index)->R8;
				break;
			case CPixel::TF_R8G8:
				cout << (m_pixeles + index)->R8;
				cout << (m_pixeles + index)->G8;
				break;
			case CPixel::TF_R8G8B8:
				cout << (m_pixeles + index)->R8;
				cout << (m_pixeles + index)->G8;
				cout << (m_pixeles + index)->B8;
				break;
			case CPixel::TF_R8G8B8A8:
				cout << (m_pixeles + index)->R8;
				cout << (m_pixeles + index)->G8;
				cout << (m_pixeles + index)->B8;
				cout << (m_pixeles + index)->A8;
				break;
			case CPixel::TF_R32G32B32A32:
				cout << ((unsigned char)(((m_pixeles + index)->R32)*255));
				cout << ((unsigned char)(((m_pixeles + index)->G32)*255));
				cout << ((unsigned char)(((m_pixeles + index)->B32)*255));
				cout << ((unsigned char)(((m_pixeles + index)->A32)*255));
				break;
			}
		}
		cout << "|\n";
	}
}

void CCanvas::copy(CCanvas canvasOrigen, int sample, int rowns, int columns, int format, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	init(rowns, columns, format, R, G, B, A);
	switch (sample)
	{
	case 1:
		point(canvasOrigen);
		break;
	case 2:
		bilinear(canvasOrigen);
		break;
	}
	DrawnMatriz();
}

void CCanvas::point(CCanvas canvasOrigen)
{
	//to vertical
	for (float i = 0; i < 1; i+=0.001f)
	{
		//to horizontal
		for (float j = 0; j < 1; j+= 0.001f)
		{
			canvasOrigen.getFormat(j,i,getR,getG,getB,getA);
			setFormat(j, i, getR, getG, getB, getA);
		}
	}
}

void CCanvas::bilinear(CCanvas canvasOrigen)
{
	int secondindex;
	int result = 0;
	int divi = 0;
	int index;
	for (float i = 0; i < 1; i+=0.001f)
	{
		for (float j = 0; j < 1; j += 0.001f)
		{
			unsigned char newR,newG,newB,newA;
			canvasOrigen.getFormat(j, i, getR, getG, getB, getA);
			newR = getR;
			newG = getG;
			newB = getB;
			newA = getA;
			if (i > m_normV)
			{
				canvasOrigen.getFormat(j, i-m_normV, getR, getG, getB, getA);
				newR = (unsigned char)((int(newR+getR))/2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}
			if (i>m_normV*2)
			{	
				canvasOrigen.getFormat(j, i-(m_normV*2), getR, getG, getB, getA);

				newR = (unsigned char)((int(newR + getR)) / 2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}
			if ((i<m_normV*(m_rows-1)))
			{
				canvasOrigen.getFormat(j, i+(m_normV), getR, getG, getB, getA);

				newR = (unsigned char)((int(newR + getR)) / 2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}
			if (i<m_normV*(m_rows-2))
			{
				canvasOrigen.getFormat(j, i + (m_normV*2), getR, getG, getB, getA);

				newR = (unsigned char)((int(newR + getR)) / 2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}
			////////////////////////////////////
			if (j > m_normU)
			{
				canvasOrigen.getFormat(j-m_normU, i, getR, getG, getB, getA);

				newR = (unsigned char)((int(newR + getR)) / 2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}
			if (j > m_normU * 2)
			{
				canvasOrigen.getFormat(j - (m_normU*2), i, getR, getG, getB, getA);

				newR = (unsigned char)((int(newR + getR)) / 2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}
			if (j < m_normU*(m_columns	 - 1))
			{
				canvasOrigen.getFormat(j + (m_normU), i, getR, getG, getB, getA);

				newR = (unsigned char)((int(newR + getR)) / 2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}
			if (j < m_normU*(m_columns - 2))
			{
				canvasOrigen.getFormat(j + (m_normU*2), i, getR, getG, getB, getA);

				newR = (unsigned char)((int(newR + getR)) / 2);
				newG = (unsigned char)((int(newG + getG)) / 2);
				newB = (unsigned char)((int(newB + getB)) / 2);
				newA = (unsigned char)((int(newA + getA)) / 2);
			}

			setFormat(j, i, newR, newG, newB, newA);
		}
	}
}

void CCanvas::DrawnDiagonalLine(float posUOrigen, float posVOrigen, float posUdestino, float posVdestino, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	float m = (posVdestino - posVOrigen) / (posUdestino - posVOrigen);

	for (float i = 0; i < 1; i+=0.001f)
	{
		float x = (((posVOrigen+i) - posVOrigen) / m) + posUOrigen;
		if (x>=1)
		{
			x = 1.0f;
		}
		float y = (m * (posUOrigen+i - posUOrigen))+posVOrigen;
		if (y>=1)
		{
			y = 1.0f;
		}
		setFormat(x, y, R, G, B, A);
	}
	//for (float i = posVOrigen; i < posVdestino; i+=0.001f)
	//{
	//
	//	for (float j = posUOrigen; j < posUdestino; j+=0.001f)
	//	{
	//		float y = (m * (posUOrigen+i - posUOrigen))+posVOrigen;
	//	}
	//}
}
