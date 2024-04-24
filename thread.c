/**********************************************************************************************************************
  FileName:        thread.c  / Proyect: IO_POINTERS_tirtos_ccs
  Dependencies:    unistd.h, stdint.h, stddef.h, BSP.h, main_tirtos.c
  Processor:       MSP432
  Board:           MSP432P401R
  Program version: CCS V10.4 TI
  Company:         TecNM /IT Chihuahua
  Description:     UTILIZACION DE DRIVER DE GPIO CON ACCESO DIRECTO A REGISTROS, EN TIRTOS.
  Authors:         ALFREDO CHACON
  Created on:      6 mar. 2021
  Updated:         11/2021
  Nota:            Ejemplo basado en IO_POINTERS al cual se incorpora el Simplelink y la carpeta de Drivers con TiRtos
 ************************************************************************************************************************/
//
//  Descripcion; Toggle RGB LED P2.0 P2.1 P2.2 dentro de un loop sensando  PUSH BOTTOM P1.4
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP432P4xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P2.0|-->LED ROJO
//            |             P2.1|-->LED VERDE
//            |             P2.2|-->LED AZUL
//            |                 |
//            |             P1.4|<--PUSH BOTON
//
//
//  TecNM /IT Chihuahua
//  Marzo 2021
//  Built with Code Composer Studio v10.4

/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribución, modificación o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/
/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

#include "DRIVERS/BSP.h"
/************************************************
  DEFINICIONES DE CONSTANTES Y/O MASCARAS
 ************************************************/
#define RETARDO (1000000)
#define RETARDO2 (10000)
#define PIN0    (0x01)  //definimos el numero Hexadecimal segun el Pin del PUERTO
#define PIN1    (0x02)
#define PIN2    (0x04)
#define PIN4    (0x10)
#define FALSE   0
#define TRUE    1

/*****************************************************************************
     * Function: mainThread
     * Preconditions: main
     * Overview:
     * Input: NINGUNA.
     * Output: NINGUNA
     *
 *****************************************************************************/
void *mainThread(void *arg0)
{
    /************************************************
              DECLARACION DE VARIABLES
     ************************************************/
    uint32_t i;
    uint8_t bandera = 0;
    int cuco=0;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;           // DETIENE EL TIMER DEL WATCHDOG
    /************************************************
        CONFIGURACION DE GPIO
    ************************************************/
    GPIO_setPinEntradaconPullUp(PUERTO1,BOTON2 );                 //PIN P1.4 COMO ENTRADA
    GPIO_setPinEntradaconPullUp(PUERTO1,BOTON1 );                 //PIN P1.1 COMO ENTRADA

    GPIO_setPinSalida(PUERTO1,LEDROJO);
    GPIO_setPinSalida(PUERTO2,  LEDROJO |  LEDVERDE | LEDAZUL );   // CONFIGURA PINES 2.0,2.1,2.2  COMO SALIDA (LEDS RGB)"
    GPIO_setPinBajo(PUERTO2,  LEDROJO |  LEDVERDE | LEDAZUL );      // APAGADOS
    GPIO_setPinBajo(PUERTO1,LEDROJO);

    while(1)
     {

         if ( Gpio_Pin_in(BOTON2) != 1)                // ENTRA AL PRESIONAR EL SWITCH DEL PUERTO P1.4 (CUANDO ESTA EN BAJO)
                 {
                 GPIO_setPinBajo(PUERTO1,LEDROJO);
                     if(bandera == FALSE)
                         {
                             bandera = TRUE;                                 //BANDERA EN ALTO
                             while (bandera==TRUE){
                                 GPIO_setPinBajo(PUERTO2, LEDAZUL);    //APAGA BLUE
                                 GPIO_setPinAlto(PUERTO2, LEDROJO);    //ENCIENDE RED
                                 for(i=RETARDO; i>0 ;i--);
                                 GPIO_setPinBajo(PUERTO2, LEDROJO);    //APAGA RED
                                 GPIO_setPinAlto(PUERTO2, LEDVERDE);    //ENCIENDE GREEN
                                 for(i=RETARDO; i>0 ;i--);
                                 GPIO_setPinBajo(PUERTO2, LEDVERDE);    //APAGA GREEN
                                 GPIO_setPinAlto(PUERTO2, LEDAZUL);    //ENCIENDE BLUE

                              if ( Gpio_Pin_in(BOTON2) != 1) bandera=FALSE;    // ENTRA CUANDO PRESIONAMOS BOTON DE P1.4
                              while( Gpio_Pin_in(BOTON2) != 1);                //MIENTRAS ESTE PRESIONADO EL BOTON
                              if ( Gpio2_Pin_in(BOTON3) != 1) bandera=FALSE;    // ENTRA CUANDO PRESIONAMOS BOTON DE P1.4
                               while( Gpio2_Pin_in(BOTON3) != 1);                //MIENTRAS ESTE PRESIONADO EL BOTON
                             }
                         }
                  GPIO_setPinBajo(PUERTO2,  LEDROJO |  LEDVERDE | LEDAZUL);  //APAGA TODOS
                 }

         if ( Gpio_Pin_in(BOTON1) != 1)                // ENTRA AL PRESIONAR EL SWITCH DEL PUERTO P1.4 (CUANDO ESTA EN BAJO)
                 {
             GPIO_setPinBajo(PUERTO2,  LEDROJO |  LEDVERDE | LEDAZUL);  //APAGA TODOS
                               if(bandera == FALSE)
                                   {
                                   cuco++;
                                       bandera = TRUE;                                 //BANDERA EN ALTO

                                           GPIO_setPinAlto(PUERTO1,LEDROJO);


                                       if(cuco==2){
                                           GPIO_setPinBajo(PUERTO1,LEDROJO);
                                           cuco=0;
                                       }
                                   }

                               if ( Gpio_Pin_in(BOTON1) != 1) bandera=FALSE;    // ENTRA CUANDO PRESIONAMOS BOTON DE P1.4
                               while( Gpio_Pin_in(BOTON1) != 1);                //MIENTRAS ESTE PRESIONADO EL BOTON
                 }
         if ( Gpio2_Pin_in(BOTON3) != 1)                // ENTRA AL PRESIONAR EL SWITCH DEL PUERTO P1.4 (CUANDO ESTA EN BAJO)
                       {
                   GPIO_setPinBajo(PUERTO2,  LEDROJO |  LEDVERDE | LEDAZUL);  //APAGA TODOS
                                     if(bandera == FALSE)
                                         {
                                         cuco++;
                                             bandera = TRUE;                                 //BANDERA EN ALTO

                                                 GPIO_setPinAlto(PUERTO1,LEDROJO);


                                             if(cuco==2){
                                                 GPIO_setPinBajo(PUERTO1,LEDROJO);
                                                 cuco=0;
                                             }
                                         }

                                     if ( Gpio2_Pin_in(BOTON3) != 1) bandera=FALSE;    // ENTRA CUANDO PRESIONAMOS BOTON DE P1.4
                                     while( Gpio2_Pin_in(BOTON3) != 1);                //MIENTRAS ESTE PRESIONADO EL BOTON
                       }

     }

}

