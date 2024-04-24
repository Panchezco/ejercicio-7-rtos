/**************************************************************************************
 * FileName:        GPIO_MSP432.c
 * Dependencies:    GPIO_MSP432.h msp.h
 * Processor:       MSP432
 * Board:			MSP432P401R
 * Program version: CCS V10.4 TI
 * Company:         TecNM /IT Chihuahua
 * Description:     Definición de funciones del módulo GPIO para entradas y salidas.
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
#include "GPIO_MSP432.h"     // Configuración del sistema.

/* Declaración del arreglo GPIO_PORT_TO_BASE
 * En el cual se encuentran las direcciones en donde comienzan
 * los registros de control para cada puerto.                   */
static const uint32_t GPIO_PORT_TO_BASE[] =
{   0x00,
    0x40004C00,         // PUERTO 1
    0x40004C01,         // PUERTO 2
    0x40004C20,         // PUERTO 3 ...
    0x40004C21,
    0x40004C40,
    0x40004C41,
    0x40004C60,
    0x40004C61,
    0x40004C80,
    0x40004C81,
    0x40004D20
};


/************************************************
DECLARACION DE APUNTADORES PARA ACCESO A MEMORIA PARA LA FUNCION Gpio_Pin_in
 ************************************************/
  volatile uint8_t *const p1_in  = (uint8_t*)0x040004c00;
  volatile uint8_t *const p2_in  = (uint8_t*)0x040004c01;

/***************************************************************************************
 *
 *       Todas las funciones que siguen a continuacion sirven para configurar y utilizar los GPIO
 *       Con la diferencia que utilizan macrofunciones pero con acceso directo a memoria dereferenciando el registro.
 *
 * ***********************************************************************************/
/*****************************************************************************
 * Function: Gpio_Pin_in
 * Preconditions: ES SOLO PARA EL PUERTO1 SELECCIONADO.
 * Overview: LEE EL PIN DESEADO
 * Input: pin_.
 * Output: 0/1
******************************************************************************/
uint8_t Gpio_Pin_in( uint_fast16_t pin_)
{
        uint_fast16_t inputPinValue;
        inputPinValue = *p1_in & (pin_);        // LEE EL REGISTRO QUE INDICA EL VALOR DE ENTRADA DE UN PIN

        if (inputPinValue > 0)                  // RETORNA EL VALOR 1 o 0
            return (0x01);
        return (0x00);
}

/*****************************************************************************
 * Function: Gpio_Pin_in2
 * Preconditions: ES SOLO PARA EL PUERTO2 SELECCIONADO.
 * Overview: LEE EL PIN DESEADO
 * Input: pin_.
 * Output: 0/1
******************************************************************************/
uint8_t Gpio2_Pin_in( uint_fast16_t pin_)
{
uint_fast16_t inputPinValue;
inputPinValue = *p2_in & (pin_);       // LEE EL REGISTRO QUE INDICA EL VALOR DE ENTRADA DE UN PIN
if (inputPinValue > 0)                          // RETORNA EL VALOR 1 o 0
return (0x01);
return (0x00);
}
/******************************************************************************
 * Function: GPIO_setPinSalida
 * Preconditions: None.
 * Overview: Configura el Pin(es) del Puerto seleccionado como salida.
 * Input: Puerto (i.e 2), Pin (i.e BIT0), estado.
 * Output: None.
 *
 *****************************************************************************/
void GPIO_setPinSalida(uint_fast8_t selectedPort, uint_fast16_t selectedPins)
{
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];

    HWREG16(baseAddress + OFS_LIB_PASEL0) &= ~selectedPins;
    HWREG16(baseAddress + OFS_LIB_PASEL1) &= ~selectedPins;
    HWREG16(baseAddress + OFS_LIB_PADIR) |= selectedPins;
}
/******************************************************************************
 * Function: GPIO_setPinHigh
 * Preconditions: GPIO_setPinSalida.
 * Overview: Establece el Pin(es) del Puerto seleccionado en alto.
 * Input: Puerto (i.e 2), Pin (i.e BIT0), estado.
 * Output: None.
 *
 *****************************************************************************/
void GPIO_setPinAlto(uint_fast8_t selectedPort,
        uint_fast16_t selectedPins)
{

    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];

    HWREG16(baseAddress + OFS_LIB_PAOUT) |= selectedPins;
}
/******************************************************************************
 * Function: GPIO_setPinLow
 * Preconditions: GPIO_setPinSalida.
 * Overview: Establece el Pin(es) del Puerto seleccionado en bajo.
 * Input: Puerto (i.e 2), Pin (i.e BIT0), estado.
 * Output: None.
 *
 *****************************************************************************/
void GPIO_setPinBajo(uint_fast8_t selectedPort,
        uint_fast16_t selectedPins)
{

    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];

    HWREG16(baseAddress + OFS_LIB_PAOUT) &= ~selectedPins;
}
/******************************************************************************
 * Function: GPIO_setPinEntradaconPullUp
 * Preconditions: None.
 * Overview: Configura el Pin(es) del Puerto seleccionado como entrada y pone PullUp.
 * Input: Puerto (i.e 2), Pin (i.e BIT0), estado.
 * Output: None.
 *
 *****************************************************************************/
void GPIO_setPinEntradaconPullUp(uint_fast8_t selectedPort,
        uint_fast16_t selectedPins)
{

    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];

    HWREG16(baseAddress + OFS_LIB_PASEL0) &= ~selectedPins;
    HWREG16(baseAddress + OFS_LIB_PASEL1) &= ~selectedPins;
    HWREG16(baseAddress + OFS_LIB_PADIR) &= ~selectedPins;
    HWREG16(baseAddress + OFS_LIB_PAREN) |= selectedPins;
    HWREG16(baseAddress + OFS_LIB_PAOUT) |= selectedPins;
}
/******************************************************************************
 * Function: GPIO_getPinValor
 * Preconditions: GPIO_setPinEntradaconPullUp.
 * Overview: Obtiene el valor del Pin(es) del Puerto seleccionado.
 * Input: Puerto (i.e 2), Pin (i.e BIT0), estado.
 * Output: None.
 *
 *****************************************************************************/
uint8_t GPIO_getPinValor(uint_fast8_t selectedPort,
        uint_fast16_t selectedPins)
{
    uint_fast16_t inputPinValue;
    uint32_t baseAddress = GPIO_PORT_TO_BASE[selectedPort];

    inputPinValue = HWREG16(baseAddress + OFS_LIB_PAIN) & (selectedPins);

    if (inputPinValue > 0)
        return GPIO_INPUT_PIN_HIGH;
    return GPIO_INPUT_PIN_LOW;
}

/*****************************************************************************
 * Function: GPIO_init_board
 * Preconditions: None.
 * Overview: De la tarjeta, Inicialización del módulo GPIO. Se configuran los pines de
 *          entrada y salida que corresponden a los LEDs y los switches
 *          en la tarjeta.
 * Input: None.
 * Output: None.
 * Nota:                   Esta Funcion "Utiliza Macrofunciones con BitBanding"
 *****************************************************************************/
/*
void GPIO_init_board(void)
{
    // Para los led's de la tarjeta (4).
    GPIO_set_output_bit(P1,B0); // LED1 (rojo)
    GPIO_set_output_bit(P2,B0); // LED_RGB (rojo)
    GPIO_set_output_bit(P2,B1); // LED_RGB (verde)
    GPIO_set_output_bit(P2,B2); // LED_RGB (azul)

    // Para los switches de la tarjeta (2).
    GPIO_set_input_bit(P1,B1); // SW1
    GPIO_set_input_bit(P1,B4); // SW2

    GPIO_enable_bit_pullup(P1,B1); // SW1
    GPIO_enable_bit_pullup(P1,B4); // SW2

    GPIO_write_bit_high(P1,B1); // Force pull-up.
    GPIO_write_bit_high(P1,B4); // Force pull-up.
}
*/
