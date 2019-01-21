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
	int selec = 0;
	while (selec != 5)
	{

		std::cout << "que desea hacer: \n1)Set \n2)Get \n3)Drawn line \n4)Drawn matris \n5)Regresar" << std::endl;
		std::cin >> selec;
		if (selec == 1)
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

			m_seter(col, fil, val);
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
			std::cout << "El valor en esa posicion es: " << m_GetValue(col, fil) << std::endl;
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
			if (selec2 == 1)
			{
				Drawhline(col, fil, longi, val);
			}
			else if (selec2 == 2)
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
		char* val = new char[255];

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
	//free(arrayformato);
}

void CCanvas::elecciondDeFormato()
{
	int selec = 0;

	std::cout << "seleccione el formato: \n1) R8: 1 Byte \n2) R8 G8: 2 Bytes \n3) R8 G8 B8: 3 Bytes \n4) R8 G8 B8 A8: 4 Bytes " << std::endl;
	//std::cout << "seleccione el formato: \n1) R8: 1 Byte \n2) R8 G8 B8 A8: 4 Bytes  " << std::endl;
	std::cin >> selec;
	while (selec != 1 && selec != 2 && selec != 3 && selec != 4)
	{
		std::cout << "Ese no es una opcion valida" << std::endl;
		std::cout << "seleccione el formato: \n1) R8: 1 Byte \n2) R8 G8: 2 Bytes \n3) R8 G8 B8: 3 Bytes \n4) R8 G8 B8 A8: 4 Bytes " << std::endl;
		std::cin >> selec;

	}
	if (selec == 1)
	{
		m_tamaño = r8;
	}
	else if (selec == 2)
	{
		m_tamaño = r8g8;
	}
	else if (selec == 3)
	{
		m_tamaño = r8g8b8;
	}
	else if (selec == 4)
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
	m_pitch = m_tamaño * Columnas;
	arreglo = (int*)malloc(Columnas * filas * sizeof(int));
	initarray = arreglo;
	for (int i = 0; i < filas*Columnas; i++)
	{
		*(initarray + index + i) = 0;
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
	m_pitch = m_tamaño * Columnas;
	arrayformato = (unsigned char*)malloc(filas*Columnas*m_tamaño);
	for (int i = 0; i < filas*Columnas*m_tamaño; i++)
	{
		*(arrayformato + i) = '0';
	}
	initarrayformato = arrayformato;
	normX =1;
	normX = normX / Columnas;
	normY = 1;
	normY = normY / filas;;
	std::cout << "\n";
}

void CCanvas::m_initialice()
{
	int selec = 0;
	while (selec != 3)
	{
		std::cout << "Desea elegir:\n 1)Por bytes\n 2)En enteros \n 3)Salir" << std::endl;
		std::cin >> selec;
		if (selec == 1)
		{

			MartrisFormatos();
		}
		else if (selec == 2)
		{
			MatrisEnteros();
		}
		std::cout << "\n";
	}
	//EspecificacionMatriz();

	//unsigned char *initarray = (unsigned char*) malloc((filas*Columnas)*m_tamaño);

}
void CCanvas::m_init(int XS, int YS, int tamañoDato)
{
	elecciondDeFormato();
	m_xs = XS;
	m_ys = YS;
	m_tamaño = tamañoDato;
	m_pitch = m_tamaño * m_xs;

}

void CCanvas::m_seter(int posX, int posY, int valor)
{
	if (posX - 1 <= Columnas && posY - 1<filas)
	{
		index = (m_pitch*(posY - 1) + (posX - 1) * m_tamaño) / m_tamaño;
		*(arreglo + index) = valor;
	}
	std::cout << "\n";
}

void CCanvas::m_seterFormato(int posX, int posY, char* valor)
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
	if (posX - 1 <= Columnas && posY - 1<filas)
	{
		int lugar =0;
		index = (m_pitch*(posY - 1) + (posX - 1) * m_tamaño);
		for (int i = 0; i <num; i++)
		{
			*(initarrayformato + index + i) = valor[lugar];
			lugar++;

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
		valor = *(initarray + (index));

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
		for (int i = 0; i < m_tamaño; i++)
		{
			valor[i] = *(initarrayformato + index + i);
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
		if (col-1 + longitud > Columnas)
		{
			longitud = Columnas - (col-1);
		}
		//index = (m_pitch*(col - 1) + (fil - 1) * m_tamaño) / m_tamaño;
		for (int i = 0; i < longitud; i++)
		{
			int lugar = 0;
			index = (m_pitch*(fil - 1) + (col - 1 + i) * m_tamaño);
			for (int j = 0; j < num; j++)
			{
				*(initarrayformato + index + j) = valor[lugar];
				lugar++;

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
		if (fil-1 + longitud > Columnas)
		{
			longitud = Columnas - (fil-1);
		}
		//index = (m_pitch*(col - 1) + (fil - 1) * m_tamaño) / m_tamaño;
		for (int i = 0; i < longitud; i++)
		{
			int lugar =0;
			index = (m_pitch*(fil - 1 + i) + (col - 1) * m_tamaño);
			for (int j =0; j <num; j++)
			{
				*(initarrayformato + index + j) = valor[lugar];
				lugar++;

			}
		}
	}
	std::cout << "\n";
}

void CCanvas::DrawVline(int col, int fil, int longitud, int value)
{
	if (col - 1 <= Columnas && fil - 1<filas)
	{
		if (fil-1 + longitud>filas)
		{
			longitud = filas - fil-1;
		}
		index = (m_pitch*(col - 1) + (fil - 1) * m_tamaño) / m_tamaño;
		int num = 0;
		for (int i = 0; i < filas; i++)
		{
			*(initarray + index + num) = value;
			num += Columnas;
		}
	}
	std::cout << "\n";
}

void CCanvas::Drawhline(int col, int fil, int longitud, int value)
{
	if (col - 1 <= Columnas && fil - 1<filas)
	{
		if (col-1 + longitud>Columnas)
		{
			longitud = Columnas - col-1;
		}
		index = (m_pitch*(col - 1) + (fil - 1) * m_tamaño) / m_tamaño;
		for (int i = 0; i < longitud; i++)
		{
			*(initarray + index + i) = value;
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
			std::cout << "|" << *(initarray + num);
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
			std::cout << *(initarrayformato + num);
			num++;
		}
		salto++;
		if (salto == Columnas)
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

void CCanvas::copy(CCanvas COPIAR)
{
	elecciondDeFormato();
	EspecificacionMatrizFormato();
	float tocopyNormalX = normX;
	float tocopyNormalY = normY;
	int filCopi	=0;
	int filPaste = 0;
	int colCopi = 0;
	int colPaste = 0;
	int newtam=m_tamaño;
	if (COPIAR.m_tamaño<m_tamaño)
	{
		newtam = COPIAR.m_tamaño;
	}
	for (int tmform = 0; tmform < newtam; tmform++)//por cada byte ya que los trabajo en un arreglo unidimensional, para que cada uno se tome en diferente cuenta
	{

		for (float i = 0; i < 1; i+=COPIAR.normY)//utilizo la normalizacion del que quiero compiar
		{
			while (true)
			{
				for (float j = 0; j < 1; j += COPIAR.normX)//utilizo la normalizacion del que quiero compiar
				{
					while (true)
					{
						//trabajo con el index de la matris a copiar y de donde quiero pegar
						index = (m_pitch*(filPaste) + (colPaste) * m_tamaño);
						int indexCopy = (COPIAR.m_pitch*(filCopi) + (colCopi)*COPIAR.m_tamaño);

						if (isFirst)
						{//si es el primero que se va poner en esa casilla solo lo guarda
							*(arrayformato + index+ tmform) = *(COPIAR.arrayformato + indexCopy+ tmform);
							isFirst = false;
						}
						else
						{
							//si no se suman y se le saca promedio
							if (*(COPIAR.arrayformato + indexCopy + tmform)!='0')
							{
								*(arrayformato + index+ tmform) = (*(COPIAR.arrayformato + indexCopy+ tmform)+ *(arrayformato + index+ tmform))/2;
							}
						}
						
						//if (j >= normX)
						//{
						//	colPaste++;
						//	tocopyNormalX += normX;
						//	isFirst = true;
						//}
						if (j+ COPIAR.normX> tocopyNormalX)
						{
							//si la siguiente casilla a copiar tiene la cordenada mayor a la casilla actual de pegado entonces se cambia a la siguente de la de pegado
							colPaste++;
							tocopyNormalX += normX;
							isFirst = true;
							
						}
						else
						{
							//de lo contrario se incremente el de la que se quiere copiar
							colCopi++;
							break;
						}
					}
				}
//				if (i >= normY)
//				{
//					filPaste++;
//					tocopyNormalY += normY;
//					isFirst = true;
//				}
				if (i + COPIAR.normY > tocopyNormalY)
				{
					filPaste++;
					tocopyNormalY += normY;
					isFirst = true;
				}
				else
				{
					filCopi++;
					break;
				}
				isFirst = true;
				colCopi = 0;
				colPaste = 0;
				tocopyNormalX = normX;
			}
		}
		filPaste = 0;
		isFirst = true;
				colCopi = 0;
				colPaste = 0;
		filCopi = 0;
		tocopyNormalX = normX;
		tocopyNormalY = normY;
	}
	DrawMatrisFormato();
	calcularBilineal();
	DrawMatrisFormato();
}

void CCanvas::calcularBilineal()
{
	int secondindex;
	unsigned char resultado;
	int result=0;
	int divi=0;
	for (int tam = 0; tam < m_tamaño; tam++)
	{
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < Columnas; j++)
			{
				index=(m_pitch*(i)+(j)* m_tamaño);
				result = *(arrayformato + index+tam);
				//reviso para filas de arriba
				if (i-1<0)
				{
					//si con uno sobre pasa quiere decir que ya esta al borde

				}
				else if (i-2<0)
				{
					//si no pasa con uno pero pasa con dos quiere decir que solo tiene un al lado
					secondindex = (m_pitch*(i - 1) + (j)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 1;
				}
				else
				{
					//de lo contrario tiene los dos 
					secondindex = (m_pitch*(i - 1) + (j)* m_tamaño);
					result += *(arrayformato + secondindex);
					secondindex = (m_pitch*(i - 2) + (j)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 2;
				}
				//reviso para filas de abajo
				if (i + 1>filas)
				{

				}
				else if (i + 2>filas)
				{
					secondindex = (m_pitch*(i + 1) + (j)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 1;
				}
				else
				{
					secondindex = (m_pitch*(i + 1) + (j)* m_tamaño);
					result += *(arrayformato + secondindex);
					secondindex = (m_pitch*(i + 2) + (j)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 2;
				}
				//reviso para columnas izquiedas
				if (j-1<0)
				{
				}
				else if (j-2<0)
				{
					secondindex = (m_pitch*(i) + (j-1)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 1;
				}
				else
				{

					secondindex = (m_pitch*(i) + (j-1)* m_tamaño);
					result += *(arrayformato + secondindex);
					secondindex = (m_pitch*(i) + (j-2)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 2;
				}
				//reviso para columnas derechas
				if (j +1>Columnas)
				{
				}
				else if (j +2>Columnas)
				{
					secondindex = (m_pitch*(i)+(j + 1)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 1;
				}
				else
				{

					secondindex = (m_pitch*(i)+(j + 1)* m_tamaño);
					result += *(arrayformato + secondindex);
					secondindex = (m_pitch*(i)+(j + 2)* m_tamaño);
					result += *(arrayformato + secondindex);
					divi += 2;
				}
				*(arrayformato + index + tam) = (char)(result / divi);
			}
		}

	}
}