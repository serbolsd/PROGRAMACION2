#include <iostream>
#include <vector>
using namespace std;

class escenario
{
public:
	escenario() = default;
	~escenario() = default;

	vector <int> TotalBloques;
	int e_NumeroDeBloques;
	int e_TamanoDeBloque;
	int numeroDeBloquesAgregar;
	void crear_bloques(vector <int> &TotalBloques,int NumertoDeBloques);
private:

};

escenario::escenario()
{
}

escenario::~escenario()
{
}
 
class Barra

{
public:
	Barra() = default;
	~Barra() = default;
	float b_tamaño = (10, 3);
	float b_posicion_y = 5;
	float b_posicion_x = 0;
private:

};

class pelota
{
public:
	pelota()=default;
	~pelota()=default;
	float p_posicion_x = 0;
	float p_posicion_y = 0;
	float p_tamaño = (5, 5);
	void Moverse();
private:

};


void pelota::Moverse()
{
	Barra barra;
	float direccion_y = 5;
	float direccion_x = 5;
	while (true)
	{
		p_posicion_x = p_posicion_x + direccion_x;
		p_posicion_y = p_posicion_y + direccion_y;
		if (p_posicion_x>=800)
		{
			direccion_x = -5;
		}
		else if (p_posicion_x<=0)
		{
			direccion_x = 5;
		}

		if (p_posicion_y >= 1000)
		{
			direccion_y = -5;
		}
		else if (p_posicion_y <= 0)
		{
			direccion_y = 5;
		}

		if (p_posicion_y-5== barra.b_posicion_y+4)
		{
			direccion_y = 5;
		}
	}


}

void escenario:: crear_bloques(vector <int> &TotalBloques ,int NumertoDeBloques)
{
	
	for (int i = 0; i < NumertoDeBloques; i++)
	{
		TotalBloques.push_back(1);
	}
}