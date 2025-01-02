#include"MiLibreria.h"

void linea(int n, char c);
void cuadro(int n, char c);
void trianguloSupIzq(int n, char c);

int n, fig;
char c;
const char menu[3][35] =
{
	"Linea",
	"Cuadrado",
	"Triangulo Superior Izquierdo"
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