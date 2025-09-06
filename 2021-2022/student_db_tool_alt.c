// alt_fq1.c — Alternative implementation for the student file tool
// Goal: Keep the same prompts and overall I/O contract, but change internal structure.
// Storage format: plain text, one record per line: "<id> <name> <gpa>\n"
// Duplicate check on insert; simple linear scan on search.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct student {
    int id;
    char name[50];
    double gpa;
};

static bool read_record(FILE *fp, struct student *out) {
    // Read one record; return true if a record is read successfully.
    int id;
    char name[50];
    double gpa;
    int r = fscanf(fp, "%d %49s %lf", &id, name, &gpa);
    if (r == 3) {
        out->id = id;
        strcpy(out->name, name);
        out->gpa = gpa;
        return true;
    }
    return false;
}

void search(char *file_name, int id)
{
    // Open the file for reading; if it doesn't exist, treat as empty database.
    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        printf("   Student not found!\n");
        return;
    }

    struct student cur;
    while (read_record(fp, &cur)) {
        if (cur.id == id) {
            // Found — print a concise, informative line.
            printf("   Student found: %d %s %.2f\n", cur.id, cur.name, cur.gpa);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("   Student not found!\n");
}

void insert(char *file_name, struct student std)
{
    // Prevent duplicates by scanning once.
    FILE *fp = fopen(file_name, "r");
    if (fp) {
        struct student cur;
        while (read_record(fp, &cur)) {
            if (cur.id == std.id) {
                fclose(fp);
                printf("   Student already exists!\n");
                return;
            }
        }
        fclose(fp);
    }
    // Append the new record.
    FILE *fa = fopen(file_name, "a");
    if (!fa) {
        // Try creating the file if append failed.
        fa = fopen(file_name, "w");
        if (!fa) {
            printf("   Could not write to file!\n");
            return;
        }
    }
    fprintf(fa, "%d %s %.2f\n", std.id, std.name, std.gpa);
    fclose(fa);
    printf("   Record inserted.\n");
}

int main(void)
{
    struct student std;
    int choice, id;
    char file_name[100];

    // Keep all prompt strings identical to the original skeleton.
    printf("Enter data file name: ");
    if (scanf("%99s", file_name) != 1) return 0;

    while (true)
    {
        printf("Enter 1 to search for data, 2 to insert student record (0 to exit): ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1)
        {
            printf("   Enter student id to search: ");
            if (scanf("%d", &id) != 1) break;
            search(file_name, id);
        }
        else if (choice == 2)
        {
            printf("   Student id: ");
            if (scanf("%d", &(std.id)) != 1) break;

            printf("   Student name: ");
            if (scanf("%49s", std.name) != 1) break;

            printf("   Student gpa: ");
            if (scanf("%lf", &(std.gpa)) != 1) break;

            insert(file_name, std);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
