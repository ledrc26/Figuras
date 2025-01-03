#include"MiLibreria.h"

void linea(int n, char c);
void cuadro(int n, char c);
void trianguloSupIzq(int n, char c);
void trianguloSupDer(int n, char c);
void trianguloInfIzq(int n, char c);
void trianguloInfDer(int n, char c);
void trianguloCent(int n, char c);
void trianguloCentInv(int n, char c);
void rombo(int n, char c);

int n, fig;
char c;
const char menu[8][35] =
{
	"Linea",
	"Cuadrado",
	"Triangulo Superior Izquierdo",
	"Triangulo Superior Derecho",
	"Triangulo Inferior Izquierdo",
	"Triangulo Inferior Derecho",
	"Triangulo Centrado",
	"Triangulo Centrado Invertido"
}; 
int main()
{ 
	n = leerEntero("Dame el tamaño de la figura: ");
	c = leerCaracter("Dame un caracter: ");
	for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++)
	{
		printf("%d.- %s\n", (i + 1), menu[i]);
	}
	fig = leerEntero("Elige una figura: ");
	switch (fig)
	{
	case 1:
		linea(n, c);
		break;
	case 2:
		cuadro(n, c);
		break;
	case 3:
		trianguloSupIzq(n, c);
		break;
	case 4:
		trianguloSupDer(n, c);
		break;
	case 5:
		trianguloInfIzq(n, c);
		break;
	case 6:
		trianguloInfDer(n, c);
		break;
	case 7:
		trianguloCent(n, c);
		break;
	case 8:
		trianguloCentInv(n, c);
		break;
	case 9:
		rombo(n, c);
		break;
	default:
		printf("Opcion no valida");
		break;
	}
}

void linea(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		printf("%c ", c);
	}
}

void cuadro(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		linea(n, c);
		printf("\n");
	}
}

void trianguloSupIzq(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		linea(n - i, c);
		printf("\n");
	}
}

void trianguloSupDer(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		linea(i, ' ');
		linea(n - i, c);
		printf("\n");
	}
}

void trianguloInfIzq(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		linea(i + 1, c);
		printf("\n");
	}
}

void trianguloInfDer(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		linea(n - (i + 1), ' ');
		linea(i + 1, c);
		printf("\n");
	}
}

void trianguloCent(int n, char c)
{
	int ciclos = n / 2 + (n % 2 == 1? 1: 0);
	for (int i = 0; i < ciclos; i++)
	{
		linea(ciclos - (i + 1), ' ');
		linea((n / 2 + 2) - ciclos + (i * 2), c);
		printf("\n");
	}
}

void trianguloCentInv(int n, char c)
{
	int ciclos = n / 2 + (n % 2 == 1 ? 1 : 0);
	for (int i = 0; i < ciclos; i++)
	{
		linea(i, ' ');
		linea(n - (i * 2), c);
		printf("\n");
	}
}

void rombo(int n, char c)
{
	int aux = 0, inc = 1;
	for (int i = 0; i < n * 2; i++, aux += inc)
	{
		linea(n - aux, c);
		linea(aux, ' ');
	}
}

