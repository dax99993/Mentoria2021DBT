/* 
 * Fecha: 8-OCT-21
 *
 * Crear un programa que resulva las ecuaciones simultaneas
 * ax + by = c
 * dx + ey = f
 *
 *
 * Si ae - bd == 0 entonces existen 2 casos
 * 	if (a*f - c*d) == 0  y  (b*f - c*e) == 0 entonces "no existe una solucion unica (infinitas)"
 * 	else "No existe solucion"  
 *
 * Si ae -bd != 0 entonces existe una solucion unica (x,y)
 * Dada por las formulas:
 *
 * 	x = (ce - bf) / ( ae - bd)
 * 	y = (af - cd) / ( ae - bd)
 *
 * Autor: Daniel B. T.
 * */

#include <stdio.h>

int main(int argc, char *argv[])
{

	//Declarar variables
	float a,b,c,d,e,f;
	float x,y;

	//Obterner los datos
	printf("Ingresar los coeficientes ecuacion 1, ax+by = c\n");
	scanf(" %f %f %f", &a, &b ,&c);
	printf("Ingresar los coeficientes ecuacion 2, dx+ey = f\n");
	scanf(" %f %f %f", &d, &e ,&f);

	// Evitar division entre 0 (esto gemeotricamente significa que las lineas son paralelas)
	if( (a*e - b*d) != 0.0 ){
		// Las lineas no son paralelas y se intersectaen el punto (x,y)
		x = ( c*e - b*f ) / ( a*c - b*d );
		y = ( a*f - c*d ) / ( a*c - b*d );
		printf("La solucion (x,y) = (%f,%f)\n", x, y);
	}
	// En caso de que sean paralelas hay dos casos
	// En realidad es la misma linea o son distintas pero paralelas 
	else{
		if( (a*f - c*d) == 0 && (b*f - c*e) == 0 )
			// Las lineas de hecho son iguales
			printf("No hay solucion unica\n");
		else
			// Las lineas son paralelas
			printf("No hay solucion\n");
	}


	return 0;
}
