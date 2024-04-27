/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18LF26K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c2_master_example.h"
#include "mcc_generated_files/i2c2_master.h" 

#define I2C_SLAVE_ADDR              0b1001100
#define READ_HUM_ADDR               0x27
#define READ_TEMP_ADDR              0x00
#define DIAG_HUM_ADDR               0x07

//void ISR_ManualTurnOff(){
//    char manual;
//    uint8_t motorData;
//    uint8_t stp = 0b11101100;
//    EUSART1_Receive_ISR();
//    
//    if (EUSART1_is_rx_ready()){
//        manual = EUSART1_Read();
//    }
//    if (manual == '0'){
//        // Turn off debugging LED 
//        LEDG1_SetHigh();
//
//        // Turn off debugging LED 
//        LEDR1_SetLow();
//        
//        // Stop the Motor
//        CSN_SetLow();
//        motorData = SPI1_ExchangeByte(stp);
//        CSN_SetHigh();
//    }
//}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    EUSART1_Initialize();
    I2C2_Initialize();
    SPI1_Initialize();
    //EUSART1_SetRxInterruptHandler(ISR_ManualTurnOff);
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    SPI1_Open(SPI1_DEFAULT);
    
    // Define Serial Data
    uint8_t tempData = 0;
    uint8_t tempDataF = 0;
    uint8_t humData = 0;
    uint8_t motorData = 0;
    
    // Define Checker Data
    uint8_t home = 0;
    uint8_t alert = 0;
    // uint16_t humReadable = 0;
    
    // Define Motor Commands
    uint8_t fwd = 0b11101110;
    uint8_t bwd = 0b11101111;
    uint8_t stp = 0b11101100;
    
    // Define Manual input
    char manual;
    uint8_t man = 3;
    
    while (1){
//        LEDR1_SetLow();
        // Temperature Sensor Read
        tempData = I2C2_Read1ByteRegister(I2C_SLAVE_ADDR, READ_TEMP_ADDR); 
        
        // Temperature Conversion
        tempDataF = (tempData* (9/5)) + 32;
        
        // Humidity Sensor Read
//        __delay_ms(3);
//        I2C2_Write1ByteRegister(READ_HUM_ADDR,0x80,0x0000);
//        __delay_ms(50);
//        humData = I2C2_Read1ByteRegister(I2C_SLAVE_ADDR, READ_HUM_ADDR);
//        __delay_ms(50);
        // humReadable = (humData[0] << 8 | humData[1]);
        // float humPer = (humReadable/16382.0) * 100.0;
        
        // If tempData is greater than 27 C:
        if (tempData >= 27){
            // If the plant isn't at home:
            if (home == 0){
                // Turn on debugging LED (Moving)
                LEDR1_SetHigh();
                
                // Move Motor for 4.55 seconds
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(fwd);
                CSN_SetHigh();
                __delay_ms(3000);
                __delay_ms(100);
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(stp);
                CSN_SetHigh();
                
                // Tell MQTT it's at home
                home = 1;
                
                // Turn on debugging LED (At Home)
                LEDG1_SetHigh();
                
                // Turn off debugging LED (Not Moving)
                LEDR1_SetLow();
                
                __delay_ms(3000);
            }
            else{
                // Nothing
            }
        }
        // If tempData is less than 27 C:        
        if (tempData < 27){
            // If the plant is at home:
            if (home == 1){
                // Turn on debugging LED (Moving)
                LEDR1_SetHigh();
                
                // Move Motor Backward for 4.55 seconds
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(bwd);
                CSN_SetHigh();
                __delay_ms(3000);
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(stp);
                CSN_SetHigh();
                
                // Tell MQTT it's not at home
                home = 0;  
                
                // Turn off debugging LED (Not Home)
                LEDG1_SetLow();
                
                // Turn off debugging LED (Not Moving)
                LEDR1_SetLow();
                        
                __delay_ms(3000);
            }
            else{
                // Nothing
            }
        }
//        if (humData <= 1000){
//            alert = 1;
//        }
//        else{
//            alert = 0;
//        }
        // Print Data: 
        
        printf("-Temp: %u C, %u F\n\r", tempData, tempDataF);
        __delay_ms(100);
        printf("*Humidity: %u\n\r", humData);
        __delay_ms(100);
        printf("+Alert: %u\n\r", alert);
        __delay_ms(100);
        printf("!Home: %u\n\r", home);
        __delay_ms(100);
        
        // Manual: Reads either an h or o and moves motor accordingly assuming it can
        // Read from MQTT -> ESP32 -> PIC
        if (EUSART1_is_rx_ready()){
            manual = EUSART1_Read();
        }
        
        // Check manual input
        if (manual == 'h'){
           man = 1;
        }
        if (manual == 'o') {
           man = 0;
        }
        
        // Check if man is going on
        if (man == 1){
            // Check if plant is not at home
            if (home == 0){
                // Turn on debugging LED (Moving)
                LEDR1_SetHigh();
                
                // Move Motor for 4.55 seconds
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(fwd);
                CSN_SetHigh();
                __delay_ms(3000);
                __delay_ms(100);
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(stp);
                CSN_SetHigh();
                
                // Tell MQTT it's at home
                home = 1;
                
                // Turn on debugging LED (At Home)
                LEDG1_SetHigh();
                
                // Turn off debugging LED (Not Moving)
                LEDR1_SetLow();
                
                __delay_ms(3000);
                man = 3;
            }
            else{
                // Nothing
                man = 3;
            }
        }
        
        // If man is going out
        if (man == 0){
            // If the plant is at home:
            if (home == 1){
                // Turn on debugging LED (Moving)
                LEDR1_SetHigh();
                
                // Move Motor Backward for 4.55 seconds
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(bwd);
                CSN_SetHigh();
                __delay_ms(3000);
                CSN_SetLow();
                motorData = SPI1_ExchangeByte(stp);
                CSN_SetHigh();
                
                // Tell MQTT it's not at home
                home = 0;  
                
                // Turn off debugging LED (Not Home)
                LEDG1_SetLow();
                
                // Turn off debugging LED (Not Moving)
                LEDR1_SetLow();
                        
                __delay_ms(3000);
                man = 3;
            }
            else{
                // Nothing
                man = 3;
            }
        }
    }
}

/**
 End of File
*/