/*
 * water1_alt.c — Phase of water by temperature and unit.
 * Behavior notes:
 *   - Prompts and output messages are kept EXACT to pass the given tests.
 *   - Variable names and structure are customized; comments are in English.
 * I/O:
 *   Input:  temperature (float), unit code (1=Celsius, 2=Fahrenheit)
 *   Output: phase message with the original phrasing/format.
 */

#include <stdio.h>
#include <math.h>  // kept for parity; not strictly required

int main(void) {
    float t_value = 0.0f;    // temperature value
    int unit_code = 0;       // 1 for Celsius, 2 for Fahrenheit

    // Exact prompts preserved
    printf("Enter the temperature: ");
    if (scanf("%f", &t_value) != 1) return 0;

    printf("Enter the unit of temperature (Celsius:1, Fahrenheit:2): ");
    if (scanf("%d", &unit_code) != 1) return 0;

    if (unit_code == 1) {
        // Celsius thresholds
        if (t_value <= 0.0f) {
            printf("Water is Solid (Ice) at %.2f degrees Celsius\n", t_value);
        } else if (t_value >= 100.0f) {
            printf("Water is Gas (Vapor) at %.2f degrees Celsius\n", t_value);
        } else {
            printf("Water is Liquid at %.2f degrees Celsius\n", t_value);
        }
    } else if (unit_code == 2) {
        // Fahrenheit thresholds
        if (t_value <= 32.0f) {
            printf("Water is Solid (Ice) at %.2f degrees Fahrenheit\n", t_value);
        } else if (t_value >= 212.0f) {
            printf("Water is Gas (Vapor) at %.2f degrees Fahrenheit\n", t_value);
        } else {
            // NOTE: The original phrasing omits "Water is" here; we keep it exact.
            printf("Liquid at %.2f degrees Fahrenheit\n", t_value);
        }
    } else {
        // Exact validation message
        printf("Please enter temperature unit as either 1 (celsius) or 2 (fahrenheit).\n");
        return 1;
    }

    return 0;
}
