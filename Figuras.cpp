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
void escalera(int n, char c);
void cruz(int n, char c);
void flecha(int n, char c);
void arbolDeNavidad(int n, char c);

int n, fig;
char c;
const char menu[13][35] =
{
	"Linea",
	"Cuadrado",
	"Triangulo Superior Izquierdo",
	"Triangulo Superior Derecho",
	"Triangulo Inferior Izquierdo",
	"Triangulo Inferior Derecho",
	"Triangulo Centrado",
	"Triangulo Centrado Invertido",
	"Rombo",
	"Escalera",
	"Cruz",
	"Flecha",
	"Arbol de navidad"
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
	case 10:
		escalera(n, c);
		break;
	case 11:
		cruz(n, c);
		break;
	case 12:
		flecha(n, c);
		break;
	case 13:
		arbolDeNavidad(n, c);
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
		if (n - aux == 0)
		{
			inc = -1;
			aux--;
		}
		linea(n - aux, c);
		linea(aux * 2, ' ');
		linea(n - aux, c);
		printf("\n");
	}
}

void escalera(int n, char c)
{
	int relleno = n - 2;
	linea(n, c);
	printf("\n");
	for (int i = 1; i <= (n * n - (n - 1)) - 2; i++)
	{
		linea(1, c);
		linea(relleno, ' ');
		if (i % (n - 1) == 0)
		{
			linea(n, c);
			relleno += (n - 1);
		}
		else {
			linea(1, c);
		}
		printf("\n"); 
	}
	linea((n * n - (n - 1)), c);
}

void cruz(int n, char c)
{
	for (int i = 0; i < n * 4; i++)
	{
		if (i >= n && i < n * 2)
		{
			linea(n * 3, c);
		}
		else {
			linea(n, ' ');
			linea(n, c);
		}
		printf("\n");
	}
}

void flecha(int n, char c)
{
	int espacios = 0;
	for (int i = 0; i < n * 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			linea(espacios, ' ');
			linea(n, c);
			if (j == 0)
			{
				espacios = 0;
				espacios += n;
			}
		}
		printf("\n");
		espacios = 0;
		if (i < n - 1)
		{
			espacios += i + 1;
		}
		else {
			espacios += n - (i - (n - 2));
		}
	}
}

void arbolDeNavidad(int n, char c)
{
	int colores[] = { 1, 3, 4, 5, 14, 15 };
	for (int i = 0; i < n; i++)
	{
		linea(n - i, ' ');
		for (int j = 0; j < i * 2 + 1; j++)
		{
			if (rand() % 100 < 50)
			{
				cambiarColor(2);
			}
			else
			{
				cambiarColor(colores[rand() % 6]);
			}
			linea(1, c);
		}
		printf("\n");
	}
	cambiarColor( 6);
	linea(n, ' ');
	linea(1, c);
	cambiarColor(15);
}