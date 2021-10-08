/* Fecha: 8-OCT-21
 *
 * Crear un programa que indique 
 * Cuánto se debe pagar a un trabajador a partir de las horas trabajadas en la semana. 
 * El tabulador es el siguiente: 
 *  1-40 horas = $50 pesos 
 * 41-50 horas = $75.00 
 * Se marcan como horas extras si se trabaja mas de 50 horas
 * por cada hora superior a las 50 horas se paga $100 
 *
 * Author: Daniel B. T.
 *
 * */

#include <stdio.h>

// Pago por hora si en la semana se trabajo de 1-40 horas
const float pago50 = 50.0;

// Pago por hora si en la semana se trabajo de 41-50 horas
const float pago75 = 75.0;

// Pago por hora extra si la semana se trabajo mas de 50 horas
const float pagoHoraExtra = 100.0;


int main()
{
	//Declarar variables
	// Horas totales trabajadas en la semana
	int horasTrabajadas = 0;
	float pagoTotal = 0.0f;
	int horasExtras = 0;
	float pagoExtra = 0.0f;


	printf("Ingrese las trabajadas en la semana: ");
	scanf(" %d", &horasTrabajadas);

	// Trabajo entre 1 y 40 horas
	if(horasTrabajadas >= 1 && horasTrabajadas <= 40)
	{
		// Se paga 50$ por cada hora trabajada
		pagoTotal = horasTrabajadas * pago50;
	}
	else if( horasTrabajadas >= 41)
	{
		// Paga extra si se pasa de 50 horas
		if( horasTrabajadas > 50 ){
			// Calcular las horas extras al restar
			// horastrabajadas en toda la semana menos 50
			horasExtras = (horasTrabajadas - 50);
			// Por cada hora extra se paga 100$
			pagoExtra = horasExtras * pagoHoraExtra;
			// Calcular horas quitando las extras (pago normal)
			// (horasTrabajadas - horasExtras) siempre vale 50
			pagoTotal = (horasTrabajadas - horasExtras) * pago75;
			// Sumar el pago normal con el pago extra para obtener pago total
			pagoTotal += pagoExtra;
		}
		else{
			// Solo se trabajo entre 41-50 horas (no hay pago extra)
			// Pago de 75$ por cada hora trabajada
			pagoTotal = horasTrabajadas * pago75;
		}

	}
	// El usuario escribio un numero negativo
	else{
		printf("Error: numero de horas trabajadas invalido\n");
	}
	
	//Imprimir pago total
	printf("El pago total es: %.2f\n", pagoTotal);

	return 0;
}
