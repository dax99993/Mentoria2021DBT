/*
 * Fecha 15-OCT-2021
 *
 *
 * Hacer un programa que simule (en parte) el juego del gorila
    1. Solicitar al usuario que indique la posición del "objetivo".
            A 37.5 metros y está a una altura de 2.18 metros
            posx_objetivo => 37.5
            posy_objetivo => 2.18
            margen_error  => 5 (metros a la redonda)
    
    2.  Solicitar al usuario
        a) vel_inicial.... fuerza, pólvora....
        b) Ángulo de disparo.
            90 grados arriba
            0  plano
           270, -90  disparo

 * 
 * 	
 * Funciones de trayetoria del proyectil sacadas de:
 * https://en.wikipedia.org/wiki/Projectile_motion
 * */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

/* Prototipo de funciones auxiliares */
// Convierte de grados (360) a radianes
double grados_a_RAD(double grados);
// Calcula la posicion en el eje X del proyectil o tiro
double ObtenerPosX(double vel_ini, double tiempo, double angulo_ini);
// Calcula la posicion en el eje Y del proyectil o tiro
double ObtenerPosY(double altura_inicial, double vel_ini, double tiempo, double angulo_ini, double gravedad);
// Calcula el tiempo total que el proyectil esta en el aire
double ObtenerTiempoTotal(double vel_ini, double ang_ini, double gravedad);


// Constantes
#define MARGEN 5.0f
#define GRAVEDAD 9.81f

int main(int argc, char *argv[]) {

	//Declarar posicion del objetivo
	double posObjetivoX = 0.0f, posObjetivoY = 0.0f;

	// Leer posicion del objetivo
	printf("Elija la distancia del objetivo: ");
	scanf(" %lf",&posObjetivoX);
	printf("Elija la altura del objetivo: ");
	scanf(" %lf",&posObjetivoY);

	// Declarar variables del tiro
	double vi, t, ang_ini, alt_ini, t_total;
	double posTiroX, posTiroY;
	// Declarar varialble para repetir hasta acertar el tiro
	bool AcertoTiro = false;	
	
	do
	{
		// Leer datos del tiro
		printf("\nElija el angulo inicial del proyectil: ");
		scanf(" %lf", &ang_ini);
		printf("Elija la velocidad inicial del proyectil: ");
		scanf(" %lf", &vi);

		// Inicializar el tiempo en 0
		t = 0.0f;
		// Calcular tiempo total del tiro
		t_total = ObtenerTiempoTotal(vi, ang_ini, GRAVEDAD);

		while( !AcertoTiro && t < t_total )
		{
			// Actualizar posicion cada decima de segundo
			posTiroX = ObtenerPosX( vi, t, ang_ini);
			posTiroY = ObtenerPosY( 0, vi, t, ang_ini, GRAVEDAD);
			printf("X=%lf y Y=%lf\n", posTiroX, posTiroY );
			
			// Actualizar el tiempo
			t += 0.1;
			
			// Checar si acerto el tiro
			if( posTiroX > posObjetivoX - MARGEN / 2 && posTiroX < posObjetivoX + MARGEN / 2  )
			{
				// Esta en el rango valido horizontal
				if( posTiroY > posObjetivoY - MARGEN / 2 && posTiroY < posObjetivoY + MARGEN / 2 )
				{
					// Esta en el rango valido vertical
					// Entonces si acerto el tiro
					AcertoTiro = true;
				}		
			}

		}
		
		if( !AcertoTiro )
			printf("\nNo acerto, intente de nuevo\n");

	}while(!AcertoTiro);
		
	printf("\nAcerto en el objetivo!\n");

	return 0;
}

/* ---------------------------------------------------------------*/
// Funciones para calcular la fisica del proyectil

double grados_a_RAD(double grados)
{
	return  grados * M_PI / 180.0;
}

/* ---------------------------------------------------------------*/
double ObtenerPosX(double vel_ini, double tiempo, double angulo_ini)
{
	double gradosradianes = grados_a_RAD(angulo_ini);
	return  vel_ini * tiempo * cos( gradosradianes );
}

/* ---------------------------------------------------------------*/
double ObtenerPosY(double altura_ini, double vel_ini, double tiempo, double angulo_ini, double gravedad)
{
	double gradosradianes = grados_a_RAD(angulo_ini);
	return altura_ini + ( vel_ini * tiempo * sin( gradosradianes ) ) - ( 0.5 * gravedad * tiempo * tiempo );
}

/* ---------------------------------------------------------------*/
double ObtenerTiempoTotal(double vel_ini, double ang_ini, double gravedad)
{
	double gradosradianes = grados_a_RAD(ang_ini);
	return 2 * vel_ini * sin(gradosradianes) / gravedad;
}
