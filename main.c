#include <curses.h>
#include <term.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "utils-eliquid.h"

void
souligne (const char *phrase)
{
  printf ("\n\t\033[1;37m%s\033[0m\n", phrase);
  printf ("\t");
  for (size_t i = 0; i < strlen (phrase); i++)
      {
	      printf ("\033[1;37m%s\033[0m", "-");
      }
  printf ("\n");
}


void
format (const char *variante, double chiffre)
{
  char phrase[100] ="";
  memcpy(phrase,variante,strlen(variante));
  printf ("\n\t\033[1;41m%s %.2f\033[0m\n", phrase,chiffre);

}

int
main (void)
{
  const char *texte[] = {
    "CALCULATEUR DE E-LIQUIDE",
    "Prix de ",
    "Entrez la quantité de eliquide souhaitée en ml : ",
    "Entrez la dose de nicotine souhaitée en mg/ml : "
  };


  const struct prix tarif = { 0.075, 0.0099, 0.39 };

  int liquide = 0;
  int dosenicotine = 0;

      souligne (texte[0]);

      printf("\t%sla base       : %5.2f €/L\n",texte[1],tarif.base);
      printf("\t%sla nicotine   : %5.2f €/L\n",texte[1],tarif.nicotine);
      printf("\t%sl'arome       : %5.2f €/L\n\n",texte[1],tarif.arome);

      printf("\n\t*****************************************************\n");

      printf ("\t%s", texte[2]);
      liquide = Get_Quantity ();

      printf ("\t%s", texte[3]);
      dosenicotine = Get_Quantity ();

      struct quantite demande = {
	    liquide,
	    dosenicotine,
	    0,
	    0
        };

      struct quantite reponse = { 0, 0, 0, 0 };
      float total = 0;

      reponse = calc_eliquid (demande);
      total = calc_prix (reponse, tarif);

      printf("\tEliquide : %5.2u\n", reponse.eliquide);
      printf("\tBase     : %5.2u\n", reponse.base);
      printf("\tBooster  : %5.2u\n", reponse.nicotine);
      printf("\tArome    : %5.2u\n", (unsigned char)reponse.arome);

      printf ("\n\n\t\033[1;41m %d ml de base\033[0m | ", reponse.base);
      printf ("\033[1;41m %2d boosters de nicotine\033[0m | ", reponse.nicotine / 10);
      printf ("\033[1;41m %.2f flacons d'arome\033[0m\n", reponse.arome / 10);

      format (" Prix total      : ", total);
      format (" Prix de revient : ", total / (float) reponse.eliquide);
      printf("\n");

  return (0);
}
