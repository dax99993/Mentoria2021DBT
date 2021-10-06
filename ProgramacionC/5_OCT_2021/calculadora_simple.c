#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
	//Declarar las variables
	float operando1, operando2;
	char operacion;
	char respuesta;
	bool valido = false;

	// Imprimir el uso
	printf("Ingrese la operacion operando1 operando2\nEj. + 2.3 4.64\n");

	do{

		// Leo los datos
		if ( scanf(" %c%f%f", &operacion, &operando1, &operando2) != 3)
			printf("Error al leer los datos\n");

		// Verificar si es la operacion deseada
		printf("Desea realiza el calculo %c %f %f\n", operacion, operando1, operando2);
		printf("El calculo es el deseado s/n: ");
	
		if ( scanf(" %c", &respuesta) != 1 )
			printf("Error al leer los datos\n");
		
		// Chechar la respuesta
		if (respuesta == 's' || respuesta == 'S' ){
				valido = true;
		}
		else{
				valido = false;
				printf("Vuelve a ingresar los datos\n");
		}


	}while( !valido );


	// Calcular los resultados
	float resultado;

	switch(operacion)
	{
		case '+': resultado = operando1 + operando2;
							break;
		case '-': resultado = operando1 - operando2;
							break;
		case '*': resultado = operando1 * operando2;
							break;
		case '/': if(operando2 != 0.0f)
								resultado = operando1 / operando2;
							break;
		default: printf("Operacion invalida\n");
	}

	// Imprimir resultado
	printf("%f\n", resultado);
	

	return 0;
}
