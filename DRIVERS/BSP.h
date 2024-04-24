/*****************************************************************************
 *  FileName:        BSP.h
 *  Dependencies:    None.
 *  Processor:       MSP432
 *  Board:			 MSP432P401R
 *  Program version: CCS V10.4 TI
 *  Company:         TecNM /IT Chihuahua
 *  Description:     Incluye la capa de abstracción de los drivers.
 *  Authors:         Alfredo Chacon
 *   Created on:     6 mar. 2021
 *   Updated:        11/2021
  ***************************************************************************/
/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribucion, modificacion o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/
#ifndef BSP_H_
#define BSP_H_

//#include "msp.h"
// Si hay problemas con los 'includes', busque la siguiente dirección.
//#include <ti/devices/msp432p4xx/inc/msp432p401r.h>
#include "../Drivers/GPIO_MSP432.h"
/* Definición de botones con su respectivo puerto. */


/* Definición de led's plasmados en tarjeta con su respectivo puerto. */

/* Definiciones del estado 'normal' de los botones externos a la tarjeta (solo hay dos botones). */
#define GND 0
#define VCC 1

/************************************************
  DEFINICIONES DE CONSTANTES Y/O MASCARAS DE MAIN
 ************************************************/
#define RETARDO (100000)
#define RETARDO2 (10000)
#define PIN0    (0x01)  //definimos el numero Hexadecimal segun el Pin del PUERTO
#define PIN1    (0x02)
#define PIN2    (0x04)
#define PIN4    (0x10)
#define FALSE   0
#define TRUE    1

#endif /* BSP_H_ */
