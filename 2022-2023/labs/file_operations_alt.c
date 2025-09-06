/*
 * file_operations_alt.c — Alternative file copy (text->binary) harness.
 * I/O text preserved EXACTLY (including typos and line breaks).
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    char id[5];
    int  exams[3];
    int  hws[3];
    char grade;
} STUDENT_DATA;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

static BOOL read_from_text_file(FILE * text_file, STUDENT_DATA * a_student){
    int amount_read = fscanf(text_file, "%19s %4s %d %d %d %d %d %d %c",
                             a_student->name, a_student->id,
                             &a_student->exams[0], &a_student->exams[1], &a_student->exams[2],
                             &a_student->hws[0], &a_student->hws[1], &a_student->hws[2],
                             &a_student->grade);
    return (amount_read == 9) ? TRUE : FALSE;
}

static BOOL write_into_binary_file(FILE * bin_file, STUDENT_DATA * a_student){
    size_t amount_written = fwrite(a_student, sizeof(STUDENT_DATA), 1, bin_file);
    return (amount_written == 1) ? TRUE : FALSE;
}

int main(int argc, char *argv[]){
    if (argc != 4){
        printf("Not enough arguments. \n");
        printf("%s", argv[0]);
        printf("Source text file: %s\n", argv[1]);
        printf("Destination text file: %s\n", argv[2]);
        printf("Destination binary text file: %s\n", argv[3]);
        return 1;
    } else{
        printf("%s", argv[0]);
        printf("Source text file: %s\n", argv[1]);
        printf("Destination text file: %s\n", argv[2]);
        printf("Destination binary text file: %s\n", argv[3]);
    }

    char * src_text_file_name = argv[1];
    char * dst_text_file_name = argv[2]; // kept, although not used (same as original)
    char * bin_file_name      = argv[3];

    FILE * text_file = NULL;
    FILE * bin_file  = NULL;

    STUDENT_DATA a_student;

    printf("Read from the text file and write tro binary! \n");

    if (!(text_file = fopen(src_text_file_name, "r"))){
        printf("Could not open file\n");
        return 1;
    }

    if (!(bin_file = fopen(bin_file_name, "wb"))){
        printf("Could not open binary file!\n");
        fclose(text_file);
        return 1;
    }

    while (read_from_text_file(text_file, &a_student)){
        write_into_binary_file(bin_file, &a_student);
    }

    printf("Read from text file and write to binary - Completed\n");
    fclose(text_file);
    fclose(bin_file);

    return EXIT_SUCCESS;
}
