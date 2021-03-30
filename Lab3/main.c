/******************************************************************************
 * The Mechatronics Revolution: Fundamentals and Core Concepts
 * Code Template for Lab Assignment 3
 *
 * Note: Create a new project as described in Lab Assignment 1.
 * After including the DriverLib library in your project settings,
 * you can use this template to design your program for Lab Assignment 3. 
 *
 * This template follows the steps described in the Software Architecture
 * section (Section 3.6) of the Lab Assignment 3 document.
*******************************************************************************/

/* Include header files */
#include "driverlib.h"
#include "mechrev.h"

/* Define macros and function prototypes if needed */

/*TODO: Figure out the rest enabling interrupt */
GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN7);
GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN7);
GPIO_interruptEdgeSelect(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN7,
GPIO_HIGH_TO_LOW_TRANSITION)
Interrupt_enableInterrupt(INT_PORT4);

/* Declare global and volatile variables if needed */


/* Main program */
void main(void)
{
    /* Stop Watchdog Timer */
    WDT_A_holdTimer();

    /* Call the mechrev_setup function included in the mechrev.h header file */
    mechrev_setup();

    /* Initialize GPIOs P1.1 and P1.4 for PushButtons (S1 and S2 switches) */
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1 | GPIO_PIN4);

    /* Initialize GPIOs P1.0, P2.0, P2.1 and P2.2 for LED1 and LED2 */
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2);

    /* Initialize GPIOs P4.0, P4.2, P4.3, P4.5, P4.6 and P4.7 for Bump Sensors */
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);

    /* Enable interrupts for Bump Sensors' GPIOs */
    MAP_GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2 | GPIO_PIN3 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7);

    /* Declare local variables if needed */
    uint8_t s1Button MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1)
    uint8_t s2Button MAP_GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN2)

    /* Call the initialization grading macro */
    MACRO_LAB3_INIT();

    while(1)
    {
        /* Design a Polling process to detect PushButtons press and turn on or off LED1 accordingly */
        if (s1Button == GPIO_INPUT_PIN_LOW || s2Button == GPIO_INPUT_PIN_LOW) {
            /* Turn on LED for when S1 is pushed */
            MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0)
            /* Note: Call the event grading macro after turning on LED1 */
            MACRO_LAB3_EVENT();
            while (MAP_GPIO_getInputValue(GPIO_PORT_P1, GPIO_PIN1) == GPIO_INPUT_PIN_LOW) {}
            /* Turn off LED for when S1 is released */
            MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0)
        }
    }
}

/* Interrupt Service Routine for PORT4 to handle Bump Sensors */
void PORT4_IRQHandler(void)
{
    /* Check the interrupt status */
    uint32_t status;
    status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P4);

    /* Change the color to RED of LED2 according to the interrupt status */
    if (status & GPIO_PIN0 || status & GPIO_PIN7) {

    }
    /* Change the color to GREEN of LED2 according to the interrupt status */
    if (status & GPIO_PIN1 || status & GPIO_PIN4) {

    }
    /* Change the color to BLUE of LED2 according to the interrupt status */
    if (status & GPIO_PIN2 || status & GPIO_PIN3) {

    }

    /* Clear the PORT4 interrupt flag */
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4, status);

}
