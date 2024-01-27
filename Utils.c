#include "Utils.h"

quantite
calc_eliquid (quantite q)	// calculateur  
{
  quantite retour = { 0, 0, 0, 0 };
  retour.eliquide = q.eliquide;
  retour.arome = q.eliquide * 0.15;
  retour.nicotine = (q.eliquide * q.nicotine) / 20;
  retour.base = q.eliquide - (retour.nicotine + retour.arome);

  return retour;
}

float
calc_prix (quantite q, prix p)	// calculateur  
{
  float total = 0;
  total = (p.nicotine * q.nicotine) + (p.base * q.base) + (p.arome * q.arome);
  return total;
}


int
Get_Quantity ()
{
  int nombre = 0;
  bool ok = false;
  int retour;

  while (!ok)
    {
      retour = scanf ("%d%*[^\n]", &nombre);
      if (!retour)		/* erreur de saisie, on vide le flux */
	{
	  char c;
	  while (((c = getchar ()) != '\n') && c != EOF);
	  printf
	    ("on vous a demande de saisir un nombre, veuillez recommencer :\n");
	}

      else			/* reussite de la saisie */
	{
	  getchar ();		/* on enleve le '\n' restant */
	  ok = true;		/* sort de laboucle */
	}
    }
  return (nombre);
}
