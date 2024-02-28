#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void afficher_papous(bool est_papa, bool a_poux)
{
    if (est_papa)
      printf(" y'a des papous papa");
    else 
      printf(" y'a des papous  pas papa ");
    
    if (a_poux)
      printf("   à poux\n");
    
    else 
     printf("  pas à poux\n");
    
}

int main(void)
{
    printf("Chez les papous...\n");
    afficher_papous(true, true);
    afficher_papous(true, false);
    afficher_papous(false, true);
    afficher_papous(false, false);

    return EXIT_SUCCESS;
}
