/*
 * File:   senha.c
 * Author: sn1011701
 *
 * Created on 7 de Março de 2022, 09:46
 */


#include <xc.h>
#include "lcd.h"
#include "editnum.h"

#define SENHA   2347

unsigned char senha_estado = 0;
int senha = 0;
char senha_cont;

void senha_start( void )
{
    senha_estado = 0;
}

unsigned char senha_me( unsigned char tecla )
{
    switch( senha_estado )
    {
        case 0:
                lcd_clr();
                lcd_print(0,0,"Senha: ");
                senha_cont = 7;
                senha = 0;
                senha_estado = 1;
                break;
        case 1:
                edit( &senha, tecla, '!', '-', 0, 9999  );
                if( tecla == '#')
                    senha_estado = 10;
                if( tecla >= '0' && tecla <= '9')
                    senha_estado = 2;
                break;
        case 2:
                if( senha_cont < 11 )
                {
                    lcd_print(0, senha_cont, "*");
                    ++senha_cont;
                }
                senha_estado = 3;
                break;
        case 3:
                if( !tecla )
                    senha_estado = 1;
                break;
        case 10:
                if( senha == SENHA )
                    senha_estado = 100;
                else
                    senha_estado = 200;
                break;
        case 100:
                lcd_print(1,0,"Senha Correta   ");
                senha_estado = 101;
                break;
        case 101:
                if( tecla )
                    senha_estado = 102;
                break;
        case 102:
                if( !tecla )
                    senha_estado = 103;
                break;
        case 103:
                break;

        case 200:
                lcd_print(1,0,"Senha Incorreta ");
                senha_estado = 201;
                break;
        case 201:
                if( tecla )
                    senha_estado = 202;
                break;
        case 202:
                if( !tecla )
                    senha_estado = 203;
                break;
        case 203:
                senha_estado = 0;
                break;
    }
    return( senha_estado );
}

unsigned char senha_correta( void )
{
    return( 103 );
}

unsigned char senha_incorreta( void )
{
    return( 203 );
}
