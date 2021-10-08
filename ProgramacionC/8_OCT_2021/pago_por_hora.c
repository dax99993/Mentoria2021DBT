#include <stdio.h>

// pago por hora si en la semana se trabajo de 1-40 horas
const float pago50 = 50.0;

// pago por hora si en la semana se trabajo de 41-50 horas
const float pago75 = 75.0;

// pago por hora extra si la semana se trabajo mas de 50 horas
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
