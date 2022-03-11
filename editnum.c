#include <xc.h>
#include "teclado.h"


unsigned char teclaAnt = 0;

void edit(  int * ptr_edit, 
            unsigned char tecla, 
            unsigned char delete,
            unsigned char menos,
            int min,
            int max )
{
    long aux;
    if( !teclaAnt && tecla )
    {
        if( tecla >= '0' && tecla <= '9' )
        {
            aux = ((*ptr_edit) * 10)+(tecla-'0');
            if( aux <= max )
                *ptr_edit = aux;
        }
        if( tecla == delete )
        {
            if( (*ptr_edit)/10 >= min )
                *ptr_edit = (*ptr_edit) / 10;
        }
        if( tecla == menos )
        {
            if( (~(*ptr_edit) + 1 ) >= min )
                *ptr_edit = ~(*ptr_edit) + 1;
        }
    }
    teclaAnt = tecla;
}