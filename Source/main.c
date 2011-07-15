/*###############################################################################
  Kodierung: UTF-8 ohne BOM
###############################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "vektoren.h"
#include "eingaben.h"
#include "generator.h"
#include "analysen.h"
#include "matrizen.h"

#include "vektoren.c"
#include "eingaben.c"
#include "generator.c"
#include "analysen.c"
#include "matrizen.c"

//###############################################################################
/**
  Das Programm dient der wahlweisen Berechnung (Addition,Subtraktion, Multiplikation) 
  manuell erfasster oder zufällig generierter Matrizen.

  @author Thomas Gerlach
  @version 1.0 
**/
//###############################################################################
int main(void)
{
  zufall_initialisieren();

  do {

    system("clear");
    printf("\n\n\tM a t r i z e n\n\n");
    printf("Ich erfasse oder erzeuge und addiere, subtrahiere oder multipliziere Matrizen.\n\n");

    int dimension = erfasse_ganzzahl("Dimension der Matrizen (1 <= n <= 10)", 1, 10);

    int anzahl = dimension * dimension;
    int *matrix_a = NULL;
    int *matrix_b = NULL;
    int *matrix_c = NULL;

    switch (erfasse_ganzzahl("Erfassung der Werte manuell (1) oder zufällig (2) ?", 1, 2)) {

      case 1:
        matrix_a = matrix_ganzzahl_werte_erfassen("Erfasse Matrix A", dimension, dimension, -1000, 1000);
        matrix_b = matrix_ganzzahl_werte_erfassen("Erfasse Matrix B", dimension, dimension, -1000, 1000);
        break;

      case 2:
        matrix_a = liste_ganzzahl_zufall_schreiben(liste_ganzzahl_erstellen(anzahl), anzahl, -1000, 1000);
        matrix_b = liste_ganzzahl_zufall_schreiben(liste_ganzzahl_erstellen(anzahl), anzahl, -1000, 1000);
        break;
    }

    do {

      system("clear");
      liste_ganzzahl_matrix_ausgeben("Matrix A", matrix_a, anzahl, dimension, 6);
      liste_ganzzahl_matrix_ausgeben("Matrix B", matrix_b, anzahl, dimension, 6);

      switch (erfasse_ganzzahl("Rechenart Addition (1) Subtraktion (2) Multiplikation (3) ?", 1, 3)) {
        
        case 1:
          matrix_c = matrix_ganzzahl_addieren(matrix_a, matrix_b, dimension);
          break;

        case 2:
          matrix_c = matrix_ganzzahl_subtrahieren(matrix_a, matrix_b, dimension);
          break;

        case 3:
          matrix_c = matrix_ganzzahl_multiplizieren(matrix_a, matrix_b, dimension);
          break;
      }

      liste_ganzzahl_matrix_ausgeben("Matrix C", matrix_c, anzahl, dimension, 10);
      free(matrix_c);

    } while (erfasse_antwort("\nOperation erneut wählen? (j/n)"));
    
    free(matrix_a);
    free(matrix_b);
    
  } while (erfasse_antwort("\n\nNoch einmal? (j/n)"));

  printf("\n\n\tAuf Wiedersehen!\n\n");
}