#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <argz.h>
#include <locale.h>
#include <wchar.h>

int
main ()
{
  
  if (setlocale (LC_ALL, "") == NULL)
    {
      perror ("setlocale");
      return EXIT_FAILURE; 
    }


  puts("histogramme des lettres entrées.");
  char **ptr = NULL;
  char **copy = NULL;
  
  char *line =NULL;
  size_t n = 0;
  ssize_t read;
  size_t i = 0;
  char * pt = NULL;

  while ((read = getline(&line, &n,stdin)) != -1)
          {
            ptr = reallocarray(ptr, i+2 ,sizeof(*ptr));
            pt = line;
            if(*pt =='\n') break;
            
            while(*pt != '\n') pt++;
            *pt = '\0';
            ptr[i] = strdupa(line);       
                    if (ptr == NULL)
            { 
                perror("reallocarray");
                free(ptr);
            }
            i++;
          }
  ptr[i] = NULL; 
  free(line);
  
  copy = ptr;
  
  int tab[26];
  memset(tab,0,sizeof(tab));
  int c = 0;

  while(*copy)
  {
   pt = *copy;
   while(*pt)
   {
     c = *pt;
     c = *pt -'a'; 
     if( c >= 0 && c <= 25 ) tab[c] +=1;  
     pt++;
   }
  copy++;
  }

  int max = tab[0];

  for(int u = 0; u<26; u++) 
  {
      max = (max<=tab[u]) ? tab[u] : max;
  }
  
  for(int f = max; f>0; f--) 
  {
    for(int u = 0; u<26; u++) 
    {
        tab[u]<f ? printf("   ") : printf(" X ");
    }
    putchar('\n');
  }
    for(int u = 0; u<26; u++) printf(" %c ", 'a' + u); 
    putchar('\n');
  
  free(ptr);
  
  return (EXIT_SUCCESS);
}
