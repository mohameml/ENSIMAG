#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main(void)
{


    char  utilisateur ;

    do{
        utilisateur=getc(stdin);
        

    }
    while( isupper(utilisateur) == 0 );
    printf("%c\n",utilisateur);

    return EXIT_SUCCESS;
}
