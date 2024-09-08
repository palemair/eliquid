#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afft(int nbt, int tab[][nbt]);

void afft(int nbt, int tab[][nbt])
{
  for(int u = 0; u<nbt; u++)
  {
      for(int y = 0; y<nbt; y++) 
          if(tab[u][y] == 0) putchar(' ');
          else printf("%4d ",tab[u][y]);
      putchar('\n');
  }

}

int main(int argc, char **argv) {
  
    char *nbl; 
    int nb;


    if (argc ==2) 
    {
        nbl = strdupa(argv[1]);
        if(sscanf(nbl,"%d",&nb); 
    }
    else
    {
        nb = 10;
    }

  int tab[nb][nb];
  memset(tab,0,sizeof(tab));
  
  
  for(int u = 0; u<nb; u++)
  {
      tab[u][0] =  1;
      for(int y = 1; y<u+1; y++) 
      {
        tab[u][y] = tab[u-1][y-1] +tab[u-1][y];  
      }
      
  }
  afft(nb,tab);

  return 0;
}
