#include <stdio.h>

// Precio del fertilizante por metro cuadrado
#define PRECIO_FERTILIZANTE 5
// Precio de la mano de obra por 200 metros cuadrados
#define PRECIO_TRAJADOR 100

int main(int argc, char **argv)
{
	//
	int metrosCuadrados;

	//leer datos
	printf("Ingrese los metros cuadrados\n");
	scanf("%d", &metrosCuadrados);

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
