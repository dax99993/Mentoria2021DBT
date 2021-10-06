#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_REPETICIONES 5

int main(int argc, char **argv)
{

	// Declarar las variables para hacer un calculo
	float operando1, operando2;
	char operacion;
	char respuesta;
	float resultado;
	bool valido = false;
	
	// Arreglos para guardar los resultados
	float Resultados[NUM_REPETICIONES] = {0.0f};
	char Operaciones[NUM_REPETICIONES];
	float Operandos1[NUM_REPETICIONES] = {0.0f};
	float Operandos2[NUM_REPETICIONES] = {0.0f};

	// Imprimir el uso
	printf("Uso: \noperador operando1 operador2\n");
	printf("Ej. + 2.3 -4.64\n");

	// Repetir NUMREPETICIONES veces
	for(int i = 0; i < NUM_REPETICIONES; ++i)
	{

		do{
			// Leo los datos y verificar que la lectura fue exitosa
			if ( scanf(" %c%f%f", &operacion, &operando1, &operando2) != 3)
				printf("Error al leer los datos\n");

			// Verificar si es la operacion deseada
			printf("Desea realiza el calculo %c %f %f\n", operacion, operando1, operando2);
			printf("El calculo es el deseado s/n: ");
	
			// Leer respuerta y verificar que la lectura fue exitosa
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

		// Guardar los resultados en el arreglo
		Operandos1[i] = operando1;
		Operandos2[i] = operando2;
		Operaciones[i] = operacion;
		Resultados[i] = resultado;
	
	}

	// Imprimir Titulo Tabla
	printf("| Numero | Valor 1 | Valor 2 | Operacion | Resultado |\n");

	// Imprimir resto de la tabla
	for(int i = 0; i < NUM_REPETICIONES ; ++i )
		printf("| %5d | %5.3f | %5.3f | %5c | %5.3f |\n", i+1, Operandos1[i], Operandos2[i], Operaciones[i], Resultados[i] );

	return 0;
}
