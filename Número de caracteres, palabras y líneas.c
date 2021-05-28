#include <stdio.h>

int main()
{
  FILE *pf;
  char c;
  // Contadores
  int iChar = 0, iWord = 0, iLine = 0;
  // Abrimos archivo en modo lectura
  pf = fopen("Escape_Room.txt", "r");
  if (pf == NULL) {
    printf("Error al abrir el archivo.\n");
    return -1;
  } else {
    // Leemos carácter a carácter hasta encontrar EOF
    while (fscanf(pf, "%c", &c) != EOF)
      {// En cada paso incrementamos el contador de caracteres
	iChar++;
	// El espacio y el salto de línea definen una nueva palabra,
	// luego incrementamos el contador de palabras
	if (c == ' ' || c == '\n')
	  iWord++;
	// Si lo leído es un salto de línea, incrementamos su contador
	if (c == '\n')
	  iLine++;
      }
    printf("Caracteres: %d \t Palabras: %d \t Líneas: %d.\n",
	   iChar, iWord, iLine);

    fclose(pf);
  }
}
