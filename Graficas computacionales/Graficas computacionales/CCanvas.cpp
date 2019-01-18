#include "CCanvas.h"
#include <iostream>


CCanvas::CCanvas()
{
}


CCanvas::~CCanvas()
{
	//delete arreglo;
	//free(initarray);
	//free(initarrayformato);
}



void CCanvas::MatrisEnteros()
{
	m_tamaño = sizeof(int);

	EspecificacionMatriz();
	int selec=0;
	while (selec!=5)
	{

		std::cout << "que desea hacer: \n1)Set \n2)Get \n3)Drawn line \n4)Drawn matris \n5)Regresar" << std::endl;
		std::cin >> selec;
		if (selec==1)
		{
			int fil;
			int col;
			int val;
			std::cout << "Ingrese numero de columna" << std::endl;
			std::cin >> col;
			std::cout << "Ingrese numero de fila" << std::endl;
			std::cin >> fil;
			std::cout << "Ingrese el valor a colocar" << std::endl;
			std::cin >> val;

			m_seter(col,fil,val);
		}
		else if (selec == 2)
		{
			int fil;
			int col;
			int val;
			std::cout << "Ingrese numero de columna" << std::endl;
			std::cin >> col;
			std::cout << "Ingrese numero de fila" << std::endl;
			std::cin >> fil;
			std::cout<<"El valor en esa posicion es: "<<m_GetValue(col, fil)<<std::endl;
		}
		else if (selec == 3)
		{
			int fil;
			int col;
			int val;
			int longi;
			int selec2 = 0;
			std::cout << "De que tipo:\n1)Horizontal \n2)Vertical" << std::endl;
			std::cin >> selec2;
			std::cout << "Ingrese numero de columna" << std::endl;
			std::cin >> col;
			std::cout << "Ingrese numero de fila" << std::endl;
			std::cin >> fil;
			std::cout << "Ingrese el valor a colocar" << std::endl;
			std::cin >> val;
			std::cout << "Ingrese la longitud(si es mayor se ajusta al limite)" << std::endl;
			std::cin >> longi;
			if (selec2==1)
			{
				Drawhline(col, fil, longi, val);
			}
			else if(selec2==2)
			{
				DrawVline(col, fil, longi, val);
			}
			else
			{
				std::cout << "No es una opcion valida" << std::endl;
				selec2 = 0;
			}
		}
		else if (selec == 4)
		{
			DrawMatris();
		}
		std::cout << "\n";
	}
	free(initarray);
}
void CCanvas::MartrisFormatos()
{
	elecciondDeFormato();
	EspecificacionMatrizFormato();
	int selec = 0;
	while (selec != 5)
	{
		char* val=new char[255];

		std::cout << "que desea hacer: \n1)Set \n2)Get \n3)Drawn line \n4)Drawn matris \n5)Regresar" << std::endl;
		std::cin >> selec;
		if (selec == 1)
		{
			int fil;
			int col;
			std::cout << "Ingrese numero de columna" << std::endl;
			std::cin >> col;
			std::cout << "Ingrese numero de fila" << std::endl;
			std::cin >> fil;
			if (m_tamaño>1)
			{
				std::cout << "Ingrese los caracteres a colocar (solo se tomaran los primero 4)" << std::endl;
			}
			else
			{
				std::cout << "Ingrese el caracterer a colocar (solo se tomaran el primero)" << std::endl;
			}
			std::cin >> val;

			m_seterFormato(col, fil, val);
		}
		else if (selec == 2)
		{
			int fil;
			int col;
			std::cout << "Ingrese numero de columna" << std::endl;
			std::cin >> col;
			std::cout << "Ingrese numero de fila" << std::endl;
			std::cin >> fil;
			std::cout << "El contenido en este espacio de memoria es:";
			m_GetValueFormato(col, fil);
			//std::cout << m_GetValue(col, fil) << std::endl;
		}
		else if (selec == 4)
		{
			DrawMatrisFormato();
		}
		else if (selec == 3)
		{
			int fil;
			int col;
			//int val;
			int longi;
			int selec2 = 0;
			std::cout << "De que tipo:\n1)Horizontal \n2)Vertical" << std::endl;
			std::cin >> selec2;
			std::cout << "Ingrese numero de columna" << std::endl;
			std::cin >> col;
			std::cout << "Ingrese numero de fila" << std::endl;
			std::cin >> fil;
			std::cout << "Ingrese el valor a colocar" << std::endl;
			std::cin >> val;
			std::cout << "Ingrese la longitud(si es mayor se ajusta al limite)" << std::endl;
			std::cin >> longi;
			if (selec2 == 1)
			{
				DrawhlineFormato(col, fil, longi, val);
			}
			else if (selec2 == 2)
			{
				DrawVlineFormato(col, fil, longi, val);
			}
			else
			{
				std::cout << "No es una opcion valida" << std::endl;
				selec2 = 0;
			}
		}
		delete val;
		std::cout << "\n";
	}
	free(arrayformato);
}

void CCanvas::elecciondDeFormato()
{
	int selec=0;

		std::cout << "seleccione el formato: \n1) R8: 1 Byte \n2) R8 G8 B8 A8: 4 Bytes  "<<std::endl;
		std::cin >> selec;
		while (selec !=1 && selec != 2)
		{
			std::cout << "Ese no es una opcion valida"<<std::endl;
			std::cout << "seleccione el formato: \n1) R8: 1 Byte \n2) R8 G8 B8 A8: 4 Bytes "<<std::endl;
			std::cin >> selec;

		}
		if (selec ==1)
		{
			m_tamaño = r8;
		}
		else if (selec==2)
		{
			m_tamaño = r8g8b8a8;
		}
		std::cout << "\n";
}


void CCanvas::EspecificacionMatriz()
{
	std::cout << "\nEspecifique las filas y columnas de la matriz" << std::endl;
	std::cout << "Filas: ";
	std::cin >> filas;
	std::cout << "\nColumnas: ";
	std::cin >> Columnas;
	m_pitch = m_tamaño*Columnas;
	arreglo= (int*)malloc(Columnas * filas * sizeof(int));
	initarray = arreglo;
	for (int i = 0; i < filas*Columnas; i++)
	{
		*(initarray + index+i) = 0;
	}
	std::cout << "\n";
}

void CCanvas::EspecificacionMatrizFormato()
{
	std::cout << "\nEspecifique las filas y columnas de la matriz" << std::endl;
	std::cout << "Filas: ";
	std::cin >> filas;
	std::cout << "\nColumnas: ";
	std::cin >> Columnas;
	m_pitch = m_tamaño*Columnas;
	arrayformato = (unsigned char*)malloc(filas*Columnas*m_tamaño);
	initarrayformato = arrayformato;
	std::cout << "\n";
}

void CCanvas::m_initialice()
{
	int selec = 0;
	while (selec != 3)
	{
		std::cout << "Desea elegir:\n 1)Por bytes\n 2)En enteros \n 3)Salir"<<std::endl;
		std::cin >> selec;
		if (selec==1)
		{
			
			MartrisFormatos();
		}
		else if(selec==2)
		{
			MatrisEnteros();
		}
		std::cout << "\n";
	}
	//EspecificacionMatriz();

	//unsigned char *initarray = (unsigned char*) malloc((filas*Columnas)*m_tamaño);

}
void CCanvas::m_init(int XS, int YS,int tamañoDato)
{
	elecciondDeFormato();
	m_xs = XS;
	m_ys = YS;
	m_tamaño = tamañoDato;
	m_pitch = m_tamaño * m_xs;

}

void CCanvas::m_seter(int posX, int posY, int valor)
{
	if (posX-1<=Columnas&&posY-1<filas)
	{
		index = (m_pitch*(posY-1) + (posX-1) * m_tamaño) / m_tamaño;
		*(arreglo + index)= valor;
	}
	std::cout << "\n";
}

void CCanvas::m_seterFormato(int posX, int posY, char* valor)
{
	int num=0;
	for (int i = 0; i < m_tamaño; i++)
	{
		if (valor[i]=='\0')
		{
			break;
		}
		else
		{
			num++;
		}
	}
	if (posX-1<=Columnas&&posY-1<filas)
	{
		int lugar = num-1;
		index = (m_pitch*(posY-1) + (posX-1) * m_tamaño);
		for (int i = m_tamaño-1; i > m_tamaño-num-1; i--)
		{
			*(initarrayformato + index+i)= valor[lugar];
			lugar--;

		}
	}
	std::cout << "\n";
}

int CCanvas::m_GetValue(int posX, int posY)
{
	int valor;
	if (posX - 1 <= Columnas && posY - 1<filas)
	{
		index = (m_pitch*(posY - 1) + (posX - 1) * m_tamaño) / m_tamaño;
		valor=*(initarray + (index));

	}
	std::cout << "\n";
	return valor;
}

void CCanvas::m_GetValueFormato(int posX, int posY)
{
	char valor[4];
	if (posX - 1 <= Columnas && posY - 1<filas)
	{

		index = (m_pitch*(posY - 1) + (posX - 1) * m_tamaño);
		for (int i =0; i < m_tamaño ; i++)
		{
			valor[i] =*(initarrayformato + index + i);
			std::cout << valor[i];
		}
	}
	std::cout << "\n";
	std::cout << "\n";
	return;
}

void CCanvas::DrawhlineFormato(int col, int fil, int longitud, char* valor)
{
	int num = 0;
	for (int i = 0; i < m_tamaño; i++)
	{
		if (valor[i] == '\0')
		{
			break;
		}
		else
		{
			num++;
		}
	}
	if (col - 1 <= Columnas && fil - 1 < filas)
	{
		if (col + longitud > Columnas)
		{
			longitud = Columnas - col;
		}
		//index = (m_pitch*(col - 1) + (fil - 1) * m_tamaño) / m_tamaño;
		for (int i = 0; i < longitud; i++)
		{
			int lugar = num - 1;
			index = (m_pitch*(fil - 1) + (col - 1+i) * m_tamaño);
			for (int j = m_tamaño - 1; j > m_tamaño - num - 1; j--)
			{
				*(initarrayformato + index + j) = valor[lugar];
				lugar--;

			}
		}
	}
	std::cout << "\n";
}
void CCanvas::DrawVlineFormato(int col, int fil, int longitud, char* valor)
{
	int num = 0;
	for (int i = 0; i < m_tamaño; i++)
	{
		if (valor[i] == '\0')
		{
			break;
		}
		else
		{
			num++;
		}
	}
	if (col - 1 <= Columnas && fil - 1 < filas)
	{
		if (col + longitud > Columnas)
		{
			longitud = Columnas - col;
		}
		//index = (m_pitch*(col - 1) + (fil - 1) * m_tamaño) / m_tamaño;
		for (int i = 0; i < longitud; i++)
		{
			int lugar = num - 1;
			index = (m_pitch*(fil - 1+i) + (col - 1) * m_tamaño);
			for (int j = m_tamaño - 1; j > m_tamaño - num - 1; j--)
			{
				*(initarrayformato + index + j) = valor[lugar];
				lugar--;

			}
		}
	}
	std::cout << "\n";
}

void CCanvas::DrawVline(int col, int fil, int longitud, int value)
{
	if (col - 1 <= Columnas && fil - 1<filas)
	{
		if (fil+longitud>filas)
		{
			longitud = filas-fil;
		}
		index = (m_pitch*(col-1) + (fil-1) * m_tamaño) / m_tamaño;
		int num=0;
		for (int i = 0; i < filas; i++)
		{
			*(initarray + index+num) = value;
			num += Columnas;
		}
	}
	std::cout << "\n";
}

void CCanvas::Drawhline(int col, int fil, int longitud, int value)
{
	if (col - 1 <= Columnas && fil - 1<filas)
	{
		if (col+longitud>Columnas)
		{
			longitud = Columnas-col;
		}
		index = (m_pitch*(col-1) + (fil-1) * m_tamaño) / m_tamaño;
		for (int i = 0; i < longitud; i++)
		{
			*(initarray + index+i) = value;
		}
	}
	std::cout << "\n";
}
void CCanvas::DrawMatris()
{
	int num = 0;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < Columnas; j++)
		{
			std::cout<<"|"<< *(initarray + num);
			num++;
		}
		std::cout << "|\n";
	}
	std::cout << "\n";
}
void CCanvas::DrawMatrisFormato()
{
	int num = 0;
	int salto = 0;
	for (int i = 0; i < filas*Columnas; i++)
	{
		std::cout << "|";
		for (int j = 0; j < m_tamaño; j++)
		{
			std::cout<<*(initarrayformato + num);
			num++;
		}
		salto++;
		if (salto==Columnas)
		{
			std::cout << "|\n";
			salto = 0;
		}
		else
		{
			std::cout << "|";

		}
	}
	std::cout << "\n";
}