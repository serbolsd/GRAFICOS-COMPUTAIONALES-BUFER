#pragma once
class CCanvas
{
public:
	CCanvas();
	~CCanvas();

	void m_init(int XS, int YS, int val);

	//
	void m_initialice();


	void MatrisEnteros();
	void EspecificacionMatriz();
	void m_seter(int posX, int posY, int valor);
	int m_GetValue(int posX, int posY);
	void Drawhline(int x, int y, int longitud, int value);
	void DrawVline(int x1, int y1, int longitud, int value);
	void DrawMatris();


	void MartrisFormatos();
	void elecciondDeFormato();
	void EspecificacionMatrizFormato();
	void m_seterFormato(int posX, int posY, char* valor);
	void m_GetValueFormato(int posX, int posY);
	void DrawhlineFormato(int x, int y, int longitud, char* valor);
	void DrawVlineFormato(int x, int y, int longitud, char* valor);
	void DrawMatrisFormato();
	void DrawnLineDiagonal(float uOrign,float vOrigen, float uDestino, float vDestino, int Value);
	
	void calcularBilineal();

	void copy(CCanvas COPIAR);
	//
	int r8 = sizeof(char);
	int r8g8 = 2;
	int r8g8b8 = 3;
	int r8g8b8a8 = sizeof(int);
	
	float normX;
	float normY;

	bool isFirst = true;
	
	bool isInt=false;
	//formatos R8	8 bits	1 Byte
	//R8 G8 B8 A8	32 bits	4 Byte
	//R8 G8 		16 bits 2 Byte
	//R8 G8 B8 		24 bits	3 Byte
	//void tamaño(int formato);
	//

	int m_xs;
	int m_ys;

	int filas;
	int Columnas;

	int m_tamaño;
	int m_pitch;
	int index;

	int m_posX;
	int m_posY;

	char* initarraysa;

	unsigned char *arrayformato;
	unsigned char *initarrayformato;

	int *arreglo;
	int *initarray;

	//metodo para mostrar el bufer 
	//formato 1 |A|
	//formato 2 |0Ab1|

	//ya no pedira puntos, pedira uv
	//hacer un copy que contenga un canvas
};