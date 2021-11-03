#include <stdio.h>
#include <stdlib.h>

#define TAM 30

int main(int argc, char *argv[])
{
	/* Adquisicion de la fecha por el usuario */

	/* String para guardar la fecha*/	
  char frase[TAM] = { 0 };
	// Guardar cada letra de forma temporal (miefechaas lees los datos)
	char c;
	/* Guarda el numero total de caracteres */
  int numCaracteres = 0;
	/* Leer String caracter a caracter y guardar en fecha */
	while( ( (c = getchar()) != '\n' ) && numCaracteres < TAM - 1 )
	{
		frase[numCaracteres] = c;
		numCaracteres++;
	}
	/* Agregar 0 al final de la fecha para marcar el final de los datos */
	frase[numCaracteres] = 0;
	
	/*----------------------------*/
	
	//printf("%s\n", frase);

	/* Contar las vocales */
	int contandorVocales = 0;
	for(int i = 0; frase[i] != 0; ++i)
	{
		switch(frase[i])
		{
			case 'a': case 'e': case 'i': case 'o': case 'u':
			case 'A': case 'E': case 'I': case 'O': case 'U':
				contandorVocales++;
				break;
		}
	}

	printf("La palabra tiene %d vocales\n", contandorVocales);

	return EXIT_SUCCESS;
}
