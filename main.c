#include "Utils.h"
#include <curses.h>
#include <term.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void
format (const char *phrase)
{
  printf ("\n");
  printf ("\t\033[1m%s\033[0m", phrase);
}

void
makephrase (char *variante, double chiffre)
{
  char *phrase = malloc (sizeof *phrase * 100);
  if (phrase == NULL)
    {
      perror ("erreur");
    }
  else
    {
      memset (phrase, 0, sizeof *phrase * 100);
      strcat (phrase, "Prix de ");
      strcat (phrase, variante);
      char nombre[30];
      sprintf (nombre, "%.3f €/ml", chiffre);
      strcat (phrase, nombre);
      format (phrase);
      free (phrase);
    }

}

void
make2phrase (char *variante, double chiffre)
{
  char *phrase = malloc (sizeof *phrase * 100);
  if (phrase == NULL)
    {
      perror ("erreur");
    }
  else
    {
      memset (phrase, 0, sizeof *phrase * 100);
      strcat (phrase, variante);
      char nombre[30];
      sprintf (nombre, "%.2f ml", chiffre);
      strcat (phrase, nombre);
      format (phrase);
      free (phrase);
    }

}

void
make3phrase (char *variante, double chiffre)
{
  char *phrase = malloc (sizeof *phrase * 100);
  if (phrase == NULL)
    {
      perror ("erreur");
    }
  else
    {
      memset (phrase, 0, sizeof *phrase * 100);
      strcat (phrase, variante);
      char nombre[30];
      sprintf (nombre, "%.2f € (euros)", chiffre);
      strcat (phrase, nombre);
      strcat (phrase, " ");
      printf ("\n\t\033[1;41m%s\033[0m\n", phrase);
      free (phrase);
    }

}

int
main (void)
{
  const char *Questions[] = {
    "Entrez la quantité de eliquide souhaitée en ml : ",
    "Entrez la dose de nicotine souhaitée en mg/ml : "
  };

  const char *texte[] = {
    "CALCULATEUR DE ELIQUIDE",
    "Prix de "
  };

  const prix tarif = { 0.075, 0.0099, 0.39 };

  int ret = setupterm (NULL, STDOUT_FILENO, NULL);
  int liquide = 0;
  int dosenicotine = 0;
  size_t i = 0;

  if (ret == 0)

    {
      format (texte[0]);

      printf ("\n\t");
      for (i = 0; i < strlen (texte[0]); i++)
	{
	  printf ("\033[1;37m%s\033[0m", "-");
	}

      makephrase ("la base     : ", tarif.base);
      makephrase ("la nicotine : ", tarif.nicotine);
      makephrase ("l'arome     : ", tarif.arome);

      printf ("\n\n\t");
      for (i = 0; i < 60; i++)
	{
	  printf ("\033[1;37m%s\033[0m", "-");
	}

      printf ("\n\t\033[1;37m%s\033[0m", Questions[0]);
      liquide = Get_Quantity ();

      printf ("\n\t\033[1;37m%s\033[0m", Questions[1]);
      dosenicotine = Get_Quantity ();

      quantite demande = {
	liquide,
	dosenicotine,
	0,
	0
      };

      quantite reponse = { 0, 0, 0, 0 };
      float total = 0;

      reponse = calc_eliquid (demande);
      total = calc_prix (reponse, tarif);

      printf ("\n\t");
      for (i = 0; i < 60; i++)
	{
	  printf ("\033[1;37m%s\033[0m", "-");
	}
      printf ("\n\t");

      make2phrase ("Eliquide : ", reponse.eliquide);
      make2phrase ("Base     : ", reponse.base);
      make2phrase ("Booster  : ", reponse.nicotine);
      make2phrase ("Arome    : ", reponse.arome);

      printf ("\n\n\t\033[1;41m %d ml de base\033[0m", reponse.base);
      printf ("\n\n\t\033[1;41m %2d boosters de nicotine\033[0m",
	      reponse.nicotine / 10);
      printf ("\n\n\t\033[1;41m %.2f flacons d'arome\033[0m",
	      reponse.arome / 10);

      printf ("\n\t");
      for (i = 0; i < strlen (Questions[1]); i++)
	{
	  printf ("\033[1;37m%s\033[0m", "-");
	}

      make3phrase (" Prix total      : ", total);
      make3phrase (" Prix de revient : ", total / (float) reponse.eliquide);
      printf ("\n\n");

    }

  return (0);
}
