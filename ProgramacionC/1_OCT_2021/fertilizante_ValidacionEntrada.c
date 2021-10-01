#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Longitud maxima de datos de entrada
const char NUMLEN = 10;
// Precio del fertilizante por metro cuadrado
const float PRECIO_FERTILIZANTE = 5.0f;
// Precio de la mano de obra por 200 metros cuadrados
const float PRECIO_TRAJADOR = 100.0f;

int main(int argc, char **argv)
{
	// Almacena los metros cuadrados
	char datoEntrada[NUMLEN];
	int metrosCuadrados;
	bool datoValido = true;

	//leer datos
	printf("Ingrese los metros cuadrados:\n");
	do{
		
		//Guardar como cadena
		scanf("%s", datoEntrada);
		
		//Iterarar en cadena y verificar que todos los caracteres sean un numero
		for(int i = 0 ; i < strlen(datoEntrada); ++i){
			if(!isdigit(datoEntrada[i]))
				datoValido = false;
			else
				datoValido = true;
		}

		if(!datoValido)
			printf("No ingreso un numero\nIntente nuevamente: ");
	
	}while(!datoValido);
	
	// Convertir de cadena a entero
	metrosCuadrados = atoi(datoEntrada);

	//calcular inversion
	float inversionFertilizante;
	float inversionManodeObra;
	float inversionTotal = 0.0f;

	// calcular inversion por metro cuadrado en fertilizante
	inversionFertilizante = metrosCuadrados * PRECIO_FERTILIZANTE;
	// calcular metros trabajados y multiplicar por precio por metro de mano de obra
	inversionManodeObra = (metrosCuadrados / 200.0) * PRECIO_TRAJADOR;
	// summar inversiones para obtener la inversionTotal
	inversionTotal = inversionFertilizante + inversionManodeObra;

	// Mostrar resultado en pantalla
	printf("-------------------------------------------------------\n");
	printf("Para %d metros cuadrados se invirtio:\n", metrosCuadrados);
	printf("%10.4f $ en fertilizante \n%10.4f $ en mano de obra\n", inversionFertilizante, inversionManodeObra);
	printf("Invirtiendo un total de %.4f $\n", inversionTotal);
	printf("-------------------------------------------------------\n");


	return 0;
}
