#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	/* Declarar e inicializar los coeficientes */
	float a,b,c; 
	a = b = c = 0.0f;

	/* Obtener los coeficientes del usuario */
	printf("Escribe los coeficientes de la ecuacion cuadratica ax^2 + bx + c\n");
	scanf(" %f %f %f", &a, &b, &c);

  /* Cacular el discriminante */
	float d = b*b - 4*a*c;
	float x1,x2;

	/* Checar por tipo soluciones */

	/* Solucion Repetida (Tal vez no vale la pena poner debido a que por errores de precision
	 * en tipo float d no puede ser exactamente 0.0f )*/
	if( d == 0.0f )
	{
		x1 = -b/(2*a);
		printf("Existe una solucion repetida x1 = x2 = %f\n", x1);
	}
	/* 2 soluciones Reales */
	else if ( d > 0.0f ){
		x1 = -b/(2*a) + sqrtf(d)/(2*a);
		x2 = -b/(2*a) - sqrtf(d)/(2*a);
		printf("Existen 2 soluciones reales x1 = %f, x2 = %f\n", x1, x2);
	}
	/* 2 soluciones complejos */
	else
	{
		// usar x1 para la parte real
		x1 = -b/(2*a);
		// usar x2 para la parte imaginaria
		x2 = sqrtf(-d)/(2*a);
		printf("Existen 2 soluciones Complejas x1 = %f + i%f, x2 = %f - i%f\n", x1, x2, x1, x2);
	}


	return EXIT_SUCCESS;
}
