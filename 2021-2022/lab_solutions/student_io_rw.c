// student_io_rw.c
// Week 12_2 — Read/Write Practice with argc/argv and binary/text conversions.
// Usage: ./prog students_src.txt students_bin students_dst.txt
// Comments in English.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[64];
    int id;
    int exams[3];
    int hws[3];
    char letter[4]; // e.g., "AA"
} Student;

static int read_from_text_file(const char* src_path, Student** out_arr, size_t* out_n) {
    FILE* f = fopen(src_path, "r");
    if (!f) return 0;
    size_t cap = 16, n = 0;
    Student* a = (Student*)malloc(cap * sizeof(Student));
    if (!a) { fclose(f); return 0; }
    while (1) {
        Student s; 
        int r = fscanf(f, "%63s %d %d %d %d %d %d %d %3s",
                       s.name, &s.id,
                       &s.exams[0], &s.exams[1], &s.exams[2],
                       &s.hws[0], &s.hws[1], &s.hws[2],
                       s.letter);
        if (r != 9) break;
        if (n == cap) {
            cap *= 2;
            Student* t = (Student*)realloc(a, cap * sizeof(Student));
            if (!t) { free(a); fclose(f); return 0; }
            a = t;
        }
        a[n++] = s;
    }
    fclose(f);
    *out_arr = a; *out_n = n;
    return 1;
}

static int write_into_binary_file(const char* bin_path, const Student* a, size_t n) {
    FILE* f = fopen(bin_path, "wb");
    if (!f) return 0;
    size_t w = fwrite(a, sizeof(Student), n, f);
    fclose(f);
    return w == n;
}

static int read_from_binary_file(const char* bin_path, Student** out_arr, size_t* out_n) {
    FILE* f = fopen(bin_path, "rb");
    if (!f) return 0;
    // find file size
    fseek(f, 0, SEEK_END);
    long bytes = ftell(f);
    fseek(f, 0, SEEK_SET);
    size_t n = (size_t)(bytes / (long)sizeof(Student));
    Student* a = (Student*)malloc(n * sizeof(Student));
    if (!a) { fclose(f); return 0; }
    size_t r = fread(a, sizeof(Student), n, f);
    fclose(f);
    if (r != n) { free(a); return 0; }
    *out_arr = a; *out_n = n;
    return 1;
}

static int write_into_text_file(const char* dst_path, const Student* a, size_t n) {
    FILE* f = fopen(dst_path, "w");
    if (!f) return 0;
    for (size_t i = 0; i < n; ++i) {
        fprintf(f, "%s %d %d %d %d %d %d %d %s\n", 
            a[i].name, a[i].id,
            a[i].exams[0], a[i].exams[1], a[i].exams[2],
            a[i].hws[0], a[i].hws[1], a[i].hws[2],
            a[i].letter);
    }
    fclose(f);
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <src.txt> <out.bin> <dst.txt>\n", argv[0]);
        return 1;
    }
    const char* src = argv[1];
    const char* bin = argv[2];
    const char* dst = argv[3];

    Student *arr = NULL, *arr2 = NULL; size_t n = 0, n2 = 0;
    if (!read_from_text_file(src, &arr, &n)) { printf("Cannot open/read %s\n", src); return 1; }
    if (!write_into_binary_file(bin, arr, n)) { printf("Cannot write %s\n", bin); free(arr); return 1; }
    if (!read_from_binary_file(bin, &arr2, &n2)) { printf("Cannot read %s\n", bin); free(arr); return 1; }
    if (!write_into_text_file(dst, arr2, n2)) { printf("Cannot write %s\n", dst); free(arr); free(arr2); return 1; }

    free(arr); free(arr2);
    return 0;
}
