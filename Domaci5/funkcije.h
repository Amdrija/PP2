#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXKLEN 500
#define FPS 25

typedef struct stitl
{
    double start, end;
    char *text;
}sub_title;

typedef struct scvor
{
    sub_title inf;
    struct scvor *next, *last;
}cvor;

sub_title read_title();
void print_title(sub_title);
sub_title fread_title(FILE *srt, int*);
char *read_string(FILE *in,int *);
void f_out_microDVD(FILE *out, sub_title x);
void fprint_title(FILE *out,sub_title x);
void f_print_title_microDVD(FILE *out, sub_title x);
void f_print_list_microDVD(FILE *out, cvor *first);
void f_pisi(FILE *out, cvor *first);

void dodaj(cvor **,cvor **, sub_title);
void pisi(cvor *);
void brisi(cvor *);

void odvoji(cvor *x, int maxlen, cvor **first, cvor **last);
void obrada(cvor **first, cvor **last, int maxlen);

char *convert_string_to_microDVD(char *s);
double convert_time_to_fps(double time);
void convert_subrip_to_microDVD(cvor *first);
char *convert_file_name(char *f);

int extension_srt(char *f);
