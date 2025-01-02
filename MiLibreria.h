#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

int leerEntero(const char *msj)
{
	int x;
	printf("%s", msj);
	fflush(stdin);
	scanf("%d", &x);
	return x;
}

char leerCaracter(const char* msj)
{
	char c;
	printf("%s", msj);
	fflush(stdin);
	scanf(" %c", &c);
	return c;
}