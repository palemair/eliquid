#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef UTILS_ELIQUIDE
#define UTILS_ELIQUIDE

typedef struct
{

  float nicotine;
  float base;
  float arome;
} prix;

typedef struct
{

  unsigned int eliquide;
  unsigned int nicotine;
  unsigned int base;
  float arome;
} quantite;


quantite calc_eliquid (quantite q);

float calc_prix (quantite q, prix p);	// calculateur  

int Get_Quantity ();

#endif
