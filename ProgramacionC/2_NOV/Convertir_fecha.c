#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM (30)

int main(int argc, char *argv[])
{
	
	/* Adquisicion de la fecha por el usuario */

	/* String para guardar la fecha*/	
  char fecha[TAM] = { 0 };
	// Guardar cada letra de forma temporal (miefechaas lees los datos)
	char c;
	/* Guarda el numero total de caracteres */
  int numCaracteres = 0;
	/* Leer String caracter a caracter y guardar en fecha */
	while( ( (c = getchar()) != '\n' ) && numCaracteres < TAM - 1 )
	{
		fecha[numCaracteres] = c;
		numCaracteres++;
	}
	/* Agregar 0 al final de la fecha para marcar el final de los datos */
	fecha[numCaracteres] = 0;

	/*----------------------------------------------*/
	
	/* Procesar la cadena con la fecha separando el dia, el mes y el anio*/

	/* La posicion     0123456789 */
	/*                 |  |  |    */
	/* Separar por los DD/MM/YYYY */
	/* Convertir a numero utilizando funcion atoi */
	int dia =  atoi(&fecha[0]);
	/* los caracteres del mes empiezan en la posicion 3 */
	int mes = atoi(&fecha[3]);
	/* los caracteres del mes empiezan en la posicion 6 */
	int anio = atoi(&fecha[6]);

	/* Imprimir la fecha en numeros para verificar que la conversion fue correcta */
	printf("%d - %d - %d \n", dia, mes, anio);


	/*-------------------------------------------------------*/
	

	/* Convertir de fecha en entero a nombre del numero */

	/* Verificar que el dia sea valido, que este entre 1 y 31 */
	if( dia >= 1 && dia <= 31 ){
		/* Imprimir cada dia por su nombre*/
		switch(dia)
		{
			case 1: printf("Primero "); break;
	  	case 2: printf("Segundo "); break;
			case 3: printf("Tercer "); break;
			/* Cuando el dia es mas grande que 3 ya ponemos el numero de forma directa */
			default: printf("%d ", dia);
		}
	}
	
	/* Conectar el dia con el mes */
	printf("de ");

	/* Verificar que el mes sea valido, que ente entre 1 y 12*/
	if(mes >= 1 && mes <= 12){
		switch(mes)
		{
			case 1: printf("Enero ");break;
			case 2: printf("Febrero ");break;
			case 3: printf("Marzo ");break;
			case 4: printf("Abril ");break;
			case 5: printf("Mayo ");break;
			case 6: printf("Junio ");break;
			case 7: printf("Julio ");break;
			case 8: printf("Agosto ");break;
			case 9: printf("Septiembre ");break;
			case 10: printf("Octubre ");break;
			case 11: printf("Noviembre ");break;
			case 12: printf("Diciembre ");break;
		}
	}

	/* Conectar el mes con el anio */
	printf("de ");

	/* Obtener las milesimas de anios e implimir*/
	switch( anio / 1000 )
	{
		case 1: printf("Mil ");break;
		case 2: printf("Dos mil ");break;
		case 3: printf("Tres mil ");break;
		case 4: printf("Cuatro mil ");break;
		case 5: printf("Cinco mil ");break;
		case 6: printf("Seis mil ");break;
		case 7: printf("Siete mil ");break;
		case 8: printf("Ocho mil ");break;
		case 9: printf("Nueve mil ");break;
	}

	/* Obtener las centesimas de anios e implimir*/
	switch( (anio % 1000 ) / 100 )
	{
		case 1: printf("Ciento ");break;
		case 2: printf("Doscientos ");break;
		case 3: printf("Trescientos ");break;
		case 4: printf("Cuatrocientos ");break;
		case 5: printf("Cincocientos ");break;
		case 6: printf("Seiscientos ");break;
		case 7: printf("Sietecientos ");break;
		case 8: printf("Ochocientos ");break;
		case 9: printf("Noveientos ");break;
	}

	/* Obtener las decenas y las unidades */
	int decenas = (anio % 100 ) / 10;
	int unidades = anio % 10;

	/*Imprimir las decenas es mas complicado debido a los nombres especiales de ciertos
	 * numeros, como el 11, 13, 20, etc 
	 * Por suerte estos solo ocurren del 11-19*/
	
	/* Checar si el numero no tiene unidades */
	if( unidades == 0 ){
	 	switch(decenas){
			case 1: printf("Diez ");break;
		 	case 2: printf("Veinte");break;
		 	case 3: printf("Treinta ");break;
			case 4: printf("Cuarenta ");break;
			case 5: printf("Cincuenta ");break;
			case 6: printf("Sesenta ");break;
			case 7: printf("Setenta ");break;
			case 8: printf("Ochenta ");break;
		 	case 9: printf("Noventa ");break;
 	 	}
	}
	/* Checar si el numero esta entre 11 y 19 */
	else if(decenas == 1)
	{
		switch( unidades ){
	 		case 1: printf("Once ");break;
			case 2: printf("Doce ");break;
			case 3: printf("Trece ");break;
			case 4: printf("Catorce ");break;
			case 5: printf("Quince ");break;
			case 6: printf("Dieciseis ");break;
			case 7: printf("Diecisiete ");break;
			case 8: printf("Dieciocho ");break;
		 	case 9: printf("Diecinueve ");break;
		}
	}
	/* Es un nombre concatenado*/
	else{

		if(decenas == 2){
			printf("Veinti");
		}
		else{
			switch(decenas){
		 		case 3: printf("Treinta y ");break;
				case 4: printf("Cuarenta y ");break;
				case 5: printf("Cincuenta y ");break;
				case 6: printf("Sesenta y ");break;
				case 7: printf("Setenta y ");break;
				case 8: printf("Ochenta y ");break;
		 		case 9: printf("Noventa y ");break;
			}
		}
			switch(unidades){
				case 1: printf("Uno");break;
				case 2: printf("Dos");break;
		 		case 3: printf("Tres ");break;
				case 4: printf("Cuatro");break;
				case 5: printf("Cinco");break;
				case 6: printf("Seis");break;
				case 7: printf("Siete");break;
				case 8: printf("Ocho");break;
		 		case 9: printf("Nueve");break;
			}
		}

	printf("\n");

	return EXIT_SUCCESS;
}

