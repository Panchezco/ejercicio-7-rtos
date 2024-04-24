/*******************************************************************************************
 * FileName:        system.h
 * Dependencies:    BSP.h
 * Processor:       MSP432
 * Board:           MSP432P401R
 * Program version: CCS V10.4 TI
 * Company:         TecNM /IT Chihuahua
 * Description:     Incluye librerías, define ciertas macros y significados así como llevar un control de versiones.
 * Authors:         ALFREDO CHACON
 * Created on:      18 Nov. 2021
 * Updated:
 */
/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribucion, modificacion o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/
#ifndef _system_h_
#define _system_h_

//#define __MSP432P401R__
#define  __SYSTEM_CLOCK    48000000 // Frecuencias funcionales recomendadas: 12, 24 y 48 Mhz.
/* Librerias a usar (paquete predeterminado). */
#include <sys/types.h>
//#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Incluye Board Support Package. */
#include "Drivers/BSP.h"

/*******************************************************************
 * Estas se agregaron de stdbool.h  para definir el tipo bool ya que no es C++
 *******************************************************************/
#define false   0
#define true    1
#define bool    _Bool
/************************************************************************************/
#endif  /* _system_h_ */
