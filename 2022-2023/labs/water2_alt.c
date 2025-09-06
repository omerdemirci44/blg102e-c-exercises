/*
 * water2_alt.c — Phase of water by temperature, unit, and altitude.
 * Behavior notes:
 *   - Boiling points are adjusted by altitude in meters.
 *   - Integer division (altitude/300) is preserved intentionally to match original logic.
 *   - All prompts/output strings are EXACT for test compatibility.
 * I/O:
 *   Input:  temperature (float), unit code (1=Celsius, 2=Fahrenheit), altitude (int, meters)
 *   Output: phase message with altitude-adjusted boiling point.
 */

#include <stdio.h>
#include <math.h>  // kept for parity; sqrt/pow not needed

int main(void) {
    float t_read = 0.0f;             // input temperature
    int u_code = 0;                  // unit selector
    int altitude_m = 0;              // altitude in meters
    float bp_c = 100.0f;             // boiling point in Celsius
    float bp_f = 212.0f;             // boiling point in Fahrenheit

    // Prompts kept verbatim
    printf("Enter the temperature: ");
    if (scanf("%f", &t_read) != 1) return 0;

    printf("Enter the unit of temperature (Celsius:1, Fahrenheit:2): ");
    if (scanf("%d", &u_code) != 1) return 0;

    printf("Enter altitude in meters: ");
    if (scanf("%d", &altitude_m) != 1) return 0;

    // Preserve original adjustment semantics: integer step per 300 m
    bp_c -= altitude_m / 300;                  // int division -> floors the step
    bp_f -= 1.8f * (altitude_m / 300);         // scale Fahrenheit decrease accordingly

    if (u_code == 1) {
        if (t_read <= 0.0f) {
            printf("Water is Solid (Ice) at %.2f degrees Celsius\n", t_read);
        } else if (t_read >= bp_c) {
            printf("Water is Gas (Vapor) at %.2f degrees Celsius\n", t_read);
        } else {
            printf("Water is Liquid at %.2f degrees Celsius\n", t_read);
        }
    } else if (u_code == 2) {
        if (t_read <= 32.0f) {
            printf("Water is Solid (Ice) at %.2f degrees Fahrenheit\n", t_read);
        } else if (t_read >= bp_f) {
            printf("Water is Gas (Vapor) at %.2f degrees Fahrenheit\n", t_read);
        } else {
            // Keep exact original phrase without "Water is"
            printf("Liquid at %.2f degrees Fahrenheit\n", t_read);
        }
    } else {
        printf("Please enter temperature unit as either 1 (celsius) or 2 (fahrenheit).\n");
        return 1;
    }

    return 0;
}
