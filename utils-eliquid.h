#include <stdio.h>
#include <stdlib.h>
#ifndef UTILS_ELIQUIDE
#define UTILS_ELIQUIDE

struct prix
{

  float nicotine;
  float base;
  float arome;
};

struct quantite
{

  unsigned int eliquide;
  unsigned int nicotine;
  unsigned int base;
  float arome;
};


struct quantite calc_eliquid (struct quantite q);

float calc_prix (struct quantite q, struct prix p);	// calculateur  

int Get_Quantity ();

#endif
