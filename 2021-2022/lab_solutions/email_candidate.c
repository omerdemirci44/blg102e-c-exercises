// email_candidate.c
// Week 11 (Email Candidate) — Suggest three email addresses based on Name, Surname, Year.
// Includes custom string utilities and pointer-based operations as per spec.
// Comments in English.

#include <stdio.h>
#include <stdlib.h>

// --- String utilities (no <string.h>) ---
static int strlength(const char *s) {
    int n = 0; while (s[n] != '\0') n++; return n;
}

static void strcopy(char *dst, const char *src) {
    while (*src) *dst++ = *src++;
    *dst = '\0';
}

static void strconcatenate(const char *source, char *destination) {
    // Append source in front of destination (result into destination): "dest" <- "source" + "dest"?
    // Spec example shows strconcatenate("1773","ITU") -> "ITU1773" (destination is "ITU").
    // We'll implement destination = destination + source.
    int i = 0; while (destination[i] != '\0') i++;
    int j = 0; while (source[j] != '\0') destination[i++] = source[j++];
    destination[i] = '\0';
}

static void substring(const char *source, char *destination, int start, int size) {
    // Copy 'size' chars starting from index 'start' (0-based). If out of range, copy what exists.
    int i = 0;
    for (; i < size && source[start + i] != '\0'; ++i) {
        destination[i] = source[start + i];
    }
    destination[i] = '\0';
}

static void strreverse(char *s) {
    int n = strlength(s);
    for (int i = 0; i < n/2; ++i) {
        char t = s[i]; s[i] = s[n-1-i]; s[n-1-i] = t;
    }
}

static void inttostring(int x, char *out) {
    // simple base-10 positive conversion; supports zero
    if (x == 0) { out[0] = '0'; out[1] = '\0'; return; }
    char buf[32]; int k = 0; int y = (x < 0) ? -x : x;
    while (y > 0) { buf[k++] = (char)('0' + (y % 10)); y /= 10; }
    if (x < 0) buf[k++] = '-';
    buf[k] = '\0'; // now reverse into out
    // reverse
    for (int i = 0; i < k; ++i) out[i] = buf[k-1-i];
    out[k] = '\0';
}

// Suggestions (both return and write into provided buffers)
static void suggest1(const char *name, const char *surname, int year, char *dst) {
    // initial of name + surname + last 2 digits of year + @itu.edu.tr
    char two[8], tmp[128]; int yy = year % 100; inttostring(yy, two);
    if (yy >= 0 && yy < 10) { tmp[0]='0'; tmp[1]=two[0]; tmp[2]='\0'; }
    else { strcopy(tmp, two); }
    int di = 0;
    dst[di++] = name[0];
    // append surname
    int i = 0; while (surname[i]) dst[di++] = surname[i++];
    // append last two digits
    i = 0; while (tmp[i]) dst[di++] = tmp[i++];
    // append domain
    const char *dom = "@itu.edu.tr";
    i = 0; while (dom[i]) dst[di++] = dom[i++];
    dst[di] = '\0';
}

static void suggest2(const char *name, const char *surname, unsigned int seed, char *dst) {
    // first two from name + first two from surname + random 4-digit + @itu.edu.tr
    char num[16]; srand(seed);
    int r = 1000 + rand() % 9000;
    inttostring(r, num);
    int di = 0;
    // n[0..1]
    for (int k = 0; k < 2 && name[k]; ++k) dst[di++] = name[k];
    // s[0..1]
    for (int k = 0; k < 2 && surname[k]; ++k) dst[di++] = surname[k];
    // random 4-digit
    for (int k = 0; num[k]; ++k) dst[di++] = num[k];
    // domain
    const char *dom = "@itu.edu.tr";
    for (int k = 0; dom[k]; ++k) dst[di++] = dom[k];
    dst[di] = '\0';
}

static void suggest3(const char *name, const char *surname, int year, char *dst) {
    // surname + name + year + @itu.edu.tr
    int di = 0; int i = 0;
    while (surname[i]) dst[di++] = surname[i++];
    i = 0; while (name[i]) dst[di++] = name[i++];
    char ybuf[16]; inttostring(year, ybuf);
    i = 0; while (ybuf[i]) dst[di++] = ybuf[i++];
    const char *dom = "@itu.edu.tr"; i = 0; while (dom[i]) dst[di++] = dom[i++];
    dst[di] = '\0';
}

int main(void) {
    char name[64], surname[64];
    int year; unsigned int seed;
    if (scanf("%63s %63s %d %u", name, surname, &year, &seed) != 4) return 0;
    char s1[256], s2[256], s3[256];
    suggest1(name, surname, year, s1);
    suggest2(name, surname, seed, s2);
    suggest3(name, surname, year, s3);
    printf("%s\n%s\n%s\n", s1, s2, s3);
    return 0;
}
