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
        sscanf(nbl,"%d",&nb) ; 
    }
    else
    {
        nb = 10;
    }

int som = 0;

int u,v;
u=v=1;

while(nb>0)
{
  som = u + v;
  printf("%d + %d = %d\n",u,v,som);
  v=u;
  u=som;
  nb--;
}

  return 0;
}
