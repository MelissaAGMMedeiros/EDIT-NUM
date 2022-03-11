#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "teclado.h"
#include "editnum.h"
#include "senha.h"

void main( void )
{
    unsigned char string[] = "Tecla:          ";
    int a,b,c;
    char estado = 0;
    char tecla;
    lcd_init();
    teclado_init();
    
    while( 1 )
    {   
        tecla = teclado();
        switch( estado )
        {
            case 0:
                lcd_clr();
                estado = 1;
                break;
            case 1:
                lcd_print(0,0,"Calculadora");
                senha_start();
                estado = 2;
                break;
            case 2:
                if( tecla )
                    estado = 3;
                break;
            case 3:
                if( !tecla )
                    estado = 10;
                break;
            case 10:
                if( senha_me(tecla) == senha_correta() )
                    estado = 20;
                break;
            case 20:
                lcd_clr();
                lcd_print(0,0,"Operacao: ");
                estado = 21;
                break;
            case 21:
                
                break;
        }
    }
}
