#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMP 1
#define PREM 0


void afft(int nbt, int tab[]);

void afft(int nbt, int tab[])
{
  int counter = 0;
  for(int u = 0; u<nbt; u++)
  {
           if(tab[u] == PREM) 
           {
           printf(" %9d |",u);
           counter++;
           if(counter %10 == 0 && counter != 0) putchar('\n');
           }

  }
  putchar('\n');
}

int main(int argc, char **argv) {
  
    char *nbl; 
    int nb;

    if (argc ==2) 
    {
        nbl = strdupa(argv[1]);
        sscanf(nbl,"%d",&nb);
    }
    else
    {
        nb = 100;
    }

  int tab[nb];
  memset(tab,PREM,sizeof(tab));
  
  
  /* afft(nb,tab); */
  
  tab[0] = COMP;
  tab[1] = COMP;
  
  int x = 0;

  for(x = 0; ( x*x < nb);x++ )
  {
      while(tab[x] ==  COMP) x++;
      for(int u = 2; u*x < nb ; u++)
      {
        tab[u * x] = COMP;  
      }
  }
 
afft(nb,tab);
  return 0;
}
