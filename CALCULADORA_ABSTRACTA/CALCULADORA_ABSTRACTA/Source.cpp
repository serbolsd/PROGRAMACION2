#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void agregar_nuevo(string n, string *total, int nt)
{
	ofstream *archivo_n = new ofstream(n.c_str(), ios::app);
	for (int i = 0; i < nt; i++)
	{
		if (nt == 1)
		{
			*archivo_n << "Resultado= ";
		}
		*archivo_n << total[i];
	}
	*archivo_n << "\n";
	if (nt == 1)
	{
		*archivo_n << "\n";
	}
	delete (archivo_n);
}

void crear_archivo(string archi)
{
	ofstream archivo_n(archi.c_str());
	archivo_n.open(archi.c_str(), ios::out);
}

void leer_archivo(string nombre, string& guardar)
{
	//char *lector = new char[1000];
	char lector[1000];
	string nom = nombre;
	char simbolo = '¹';
	ifstream *archivo = new ifstream(nom.c_str());
	archivo->getline(lector, 1000, '\0');
	guardar = lector;
	//delete (nom);
	delete (archivo);
	//delete []lector;
}


class calculadora
{
 public:
	calculadora() = default;
	~calculadora() = default;
	string c_contnido;
	vector <float> C_numeros;
	vector <char> C_operandos;
	void operaciones(string contenido, vector <float> &numeros, vector <char> operandos);
	void gerarquia_operaciones(vector <char> operaciones, vector <float> numero);
	void acomodar(int& i, vector <char>& ope, vector <float>& num, float resultado);
	void imprimir(vector <char>& ope, vector <float>& num);
	float suma(float num1,float num2);
	float resta(float num1, float num2);
	float multiplicacion(float num1, float num2);
	float division(float num1, float num2);
	float potencia(float num1, float num2);
	float raiz(float num1, float num2);
	float logaritmoNatural(float num1);
	float seno(float num1, float num2);
	float coseno(float num1, float num2);
	float tangente(float num1, float num2);

 private:
	/*
	int C_resultado = 0;
	int C_numero_1 = 0;
	int C_numero_2 = 0;*/
};

void calculadora::imprimir(vector <char>& ope, vector <float>& num)
{
	string nuevoar = "respuestas.txt";
	int nt = ope.size() + num.size();
	string *total = new string[nt];
	int t = 0;
	int l = 0;
	while (t<nt)
	{
		char m[50];
		snprintf(m, 50, "%f", num[l]);
		string to = m;
		total[t] = to;
		t += 2;
		l += 1;
	}
	int t2 = 1;
	int o = 0;
	while (t2<nt)
	{
		total[t2] = ope[o];
		t2 += 2;
		o += 1;
	}
	for (size_t a = 0; a < nt; a++)
	{
		if (nt == 1)
		{
			cout << "Resultado= ";
		}
		cout << total[a] << " ";
	}
	agregar_nuevo(nuevoar, total, nt);
	cout << "\n";
	delete[]total;
}

void calculadora::acomodar(int& i, vector <char>& ope, vector <float>& num, float resultado)
{
	string nuevoar = "respuestas.txt";
	int n = num.size();
	int n2 = ope.size();
	int j = i;
	if (ope.size()>0)
	{
		num[i] = resultado;
		if (num.size()>ope.size())
		{
			i += 1;
			while (i<n - 1)
			{
				num[i] = num[i + 1];
				i++;
			}
			num.pop_back();
		}
		else if (ope[i] == 'l' || ope[i] == 'L')
		{

		}
		else
		{
			i += 1;
			while (i<n - 1)
			{
				num[i] = num[i + 1];
				i++;
			}
			num.pop_back();
		}
		while (j<n2 - 1)
		{
			ope[j] = ope[j + 1];
			j++;
		}
		ope.pop_back();
		imprimir(ope, num);
	}
}

void calculadora::gerarquia_operaciones(vector <char> operaciones, vector <float> numero)
{
	vector <char> ope;
	vector <float> num;
	for (int i = 0; i < operaciones.size(); i++)
	{
		ope.push_back(operaciones[i]);
	}
	for (int i = 0; i < numero.size(); i++)
	{
		num.push_back(numero[i]);
	}

	while (ope.size()>0)
	{
		int i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'p' || ope[i] == 'P')
			{
				double nume1, nume2, resultado;
				nume1 = num[i];
				nume2 = nume1;
				resultado = potencia(nume1, nume2);
				
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'r' || ope[i] == 'R')
			{
				double nume, ra, resultado;
				nume = num[i];
				ra = num[i + 1];
				resultado = pow(nume, (1 / ra));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'l' || ope[i] == 'L')
			{
				double nume, nume2, resultado;
				if (ope.size() == (num.size()))
				{
					nume = num[i];
					resultado = log(nume) / log(2.718281828);
				}
				else
				{
					nume = num[i];
					nume2 = num[i + 1];
					nume2 = log(nume2) / log(2.718281828);
					resultado = nume * nume2;
				}
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 's' || ope[i] == 'S')
			{
				double nume, nume2, resultado;
				nume = num[i];
				nume2 = num[i + 1];
				nume2 = nume2 * 3.14159 / 180;
				resultado = nume * (sin(nume2));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'C' || ope[i] == 'c')
			{
				double nume, nume2, resultado;
				nume = num[i];
				nume2 = num[i + 1];
				resultado = nume * (cos(nume2*3.14159 / 180));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'T' || ope[i] == 't')
			{
				double nume, nume2, resultado;
				nume = num[i];
				nume2 = num[i + 1];
				resultado = nume * (tan(nume2*3.14159 / 180));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '*')
			{
				double resultado = num[i] * num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '/')
			{
				double resultado = num[i] / num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '-')
			{
				double resultado = num[i] - num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '+')
			{
				double resultado = num[i] + num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
	}
}

void calculadora::operaciones(string contenido, vector <float> &numeros, vector <char> operandos)
{
	char numero[10];
	for (int a = 0; a < 9; a++)
	{
		numero[a] = '\0';
	}
	string operacion;
	char registro = 'A';
	int num1, num2, result;

	int i = 0;

	while (registro != '\0')
	{
		bool se_puede = true;
		bool anteregistro = false;
		int j = 0;
		registro = 'A';
		{
			while (registro != '\n')
			{
				if (i < contenido.size() + 1)
					registro = contenido[i];
				else
				{
					break;
				}
				if (registro == ' ')
				{

				}
				else if (registro == '\n' || registro == '\0')
				{
					num1 = atoi(numero);
					numeros.push_back(num1);
				}
				else if (registro == '+')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == '*')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == '-')
				{
					if (numeros.size() > 0)
					{
						if (operandos.size() == numeros.size())
						{
							numero[j] = registro;
							j++;
						}
					}
					else if (operandos.size() == numeros.size())
					{
						operandos.push_back(registro);
						num1 = atoi(numero);
						numeros.push_back(num1);


						for (int a = 0; a < 9; a++)
						{
							numero[a] = '\0';
						}
						j = 0;
						anteregistro = true;
					}
					else
					{
						operandos.push_back(registro);
						num1 = atoi(numero);
						numeros.push_back(num1);


						for (int a = 0; a < 9; a++)
						{
							numero[a] = '\0';
						}
						j = 0;
						anteregistro = true;
					}
				}
				else if (registro == '/')
				{
					operandos.push_back(registro);
					operacion = "divi";
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == 'P' || registro == 'p')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == 'S' || registro == 's')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == 'C' || registro == 'c')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == 'T' || registro == 't')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == 'L' || registro == 'l')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					if (num1 > 0)
					{
						numeros.push_back(num1);

					}

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == 'R' || registro == 'r')
				{
					operandos.push_back(registro);
					num1 = atoi(numero);
					numeros.push_back(num1);

					for (int a = 0; a < 9; a++)
					{
						numero[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro < 65)
				{
					numero[j] = registro;
					if (numero[j] == '0' && operacion == "divi")
					{
						se_puede = false;
						operacion = "nada";
					}
					else
					{
						operacion = "nada";
					}
					j++;
					anteregistro = false;
				}
				i++;
			}
		}

		if (numeros.size() == 1)
		{
			cout << numeros[0] << "\n";
		}
		else if (se_puede)
		{
			imprimir(operandos, numeros);
			gerarquia_operaciones(operandos, numeros);
		}
		else
		{
			imprimir(operandos, numeros);
			cout << "No se puede hacer esta operacion\n";
		}
		cout << "\n";
		while (operandos.size() > 0)
		{
			operandos.pop_back();
		}
		while (numeros.size() > 0)
		{
			numeros.pop_back();
		}
		for (int a = 0; a < 9; a++)
		{
			numero[a] = '\0';
		}
	}
}

float calculadora::suma(float num1, float num2)
{
	float resultado;
	resultado = num1 + num2;
	return resultado;
}

float calculadora::resta(float num1, float num2)
{
	float resultado;
	resultado = num1 - num2;
	return resultado;
}

float calculadora::multiplicacion(float num1, float num2)
{
	float resultado;
	resultado = num1 * num2;
	return resultado;
}

float calculadora::division(float num1, float num2)
{
	float resultado;
	resultado = num1 / num2;
	return resultado;
}

float calculadora::potencia(float num1, float num2)
{
	float resultado, potencia=1;
	resultado = num1;
	while (potencia < num2)
	{
		resultado = resultado * num1;
	}
	return resultado;
}

float calculadora::raiz(float num1, float num2)
{
	float resultado;
	resultado = pow(num1,(1/num2));
	return resultado;
}

float calculadora::logaritmoNatural(float num1)
{
	float resultado;
	resultado = log(num1) / log(2.718281828);
	return resultado;
}

float calculadora::seno(float num1, float num2)
{
	float resultado, sen;
	sen = num2 * 3.14159 / 180;
	resultado = num1 * sin(sen);
	return resultado;
}

float calculadora::coseno(float num1, float num2)
{
	float resultado, cose;
	cose=num2 * 3.14159 / 180;
	resultado = num1 *cos(cose);
	return resultado;
}

float calculadora::tangente(float num1, float num2)
{
	float resultado, tangen;
	tangen = num2 * 3.14159 / 180;
	resultado = num1 * tan(tangen);
	return resultado;
}

int main()
{
	string contenidoarchivo;
	string nombre = "prueba.txt";
	string nuevoar = "respuestas.txt";
	crear_archivo(nuevoar);
	string mensaje = ("Esta calculadora funciona con los siguientes parametros:\n\
	1)La 'P' o 'p' es para sacar la potencia del numero de la izquierda\n\
	2)La 'R' o 'r' es para sacar la raiz del numero de la izquierda\n\
	3)La 'S' o 's' es para calcular el seno\n\
	4)La 'C' o 'c' es para calcular el coseno\n\
	5)La 'T' o 't' es para calcular la tangente\n\
	6)La 'L' o 'l' es para calcular el logaritmo natural");
	cout << mensaje << "\n Presione CUALQUIER TECLA para continuar\n";
	ofstream archivo_n(nuevoar.c_str(), ios::app);
	archivo_n << mensaje << "\n\n\n";
	archivo_n.close();
	cin.get();
	system("cls");
	leer_archivo(nombre, contenidoarchivo);
	cout << contenidoarchivo << endl;
	cout << "\n";
	calculadora calculos;
	calculos.c_contnido = contenidoarchivo;
	calculos.operaciones(calculos.c_contnido, calculos.C_numeros, calculos.C_operandos);

	cin.get();
	return 0;
}