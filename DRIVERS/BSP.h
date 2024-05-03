/*****************************************************************************
 *  FileName:        BSP.h
 *  Dependencies:    None.
 *  Processor:       MSP432
 *  Board:           MSP432P401R
 *  Program version: CCS V10.4 TI
 *  Company:         TecNM /IT Chihuahua
 *  Description:     Incluye la capa de abstraccion de los drivers.
 *  Authors:         Alfredo Chacon
 *   Created on:     18 nov. 2021
 *   Updated:
  **/
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
// Si hay problemas con los 'includes', busque la direccion o ruta.
//#include <C:/ti_v10_1/ccs/ccs_base/arm/include/msp.h>
#include "DRIVERS\gpio_2021.h"

/* Definición de botones con su respectivo puerto. */
//Definiciones de Puertos
#define PUERTO1    1
#define PUERTO2    2
#define PUERTO3    2
#define PUERTO4    4
#define PUERTO5    5

#define BOTON2    0x10
#define BOTON1   0x02
#define BOTON3   (0x0008)
#define GPIO_PIN4    (0x0010)
#define GPIO_PIN5    (0x0020)
#define GPIO_PIN6    (0x0040)
#define GPIO_PIN7    (0x0080)

/* Definición de led's plasmados en tarjeta con su respectivo puerto. */
//Definiciones de pines para las funciones
#define LEDROJO     (0x0001)
#define LEDVERDE    (0x0002)
#define LEDAZUL     (0x0004)


#endif /* BSP_H_ */










