#include "funkcije.h"
sub_title read_title()
{
    sub_title x;
    scanf("%lf",&x.start);
    scanf("%lf",&x.end);
    x.text = (char*)malloc(MAXKLEN * sizeof(char));
    scanf("%s",x.text);
    x.text = (char*)realloc(x.text , (strlen(x.text) + 1) * sizeof(char));
    return x;
}

char *read_string(FILE *in, int *eof_flag)
{
    char c, *s = (char*)malloc(MAXKLEN * sizeof(char));
    int new_line = 1, i = 0;
    while(!((c = fgetc(in)) == '\n' && new_line) && c != EOF)
    {
        if(c == '\n')
        {
            new_line = 1;
        }
        else
        {
            new_line = 0;
        }
        
        s[i++] = c;
    }
    s[i++] = '\0';
    s = (char*)realloc(s, i * sizeof(char));
    if(c == EOF)
    {
        *eof_flag = 1;
    }
    return s;
}

sub_title fread_title(FILE *srt, int *eof_flag)
{
    sub_title x;
    int g, h_start, m_start, s_start, ms_start, h_end, m_end, s_end, ms_end;
    fscanf(srt,"%d\n%d:%d:%d,%d --> %d:%d:%d,%d\n",&g,&h_start,&m_start,&s_start,&ms_start,&h_end,&m_end,&s_end,&ms_end);
    x.text = read_string(srt,eof_flag);
    x.start = h_start * 3600 + m_start * 60 + s_start + (double)ms_start / 1000;
    x.end = h_end * 3600 + m_end * 60 + s_end + (double)ms_end / 1000;
    return x;
}

void print_title(sub_title x)
{
    printf("Start: %.3lf\nEnd: %.3lf\n%s\n",x.start,x.end,x.text);
}

void fprint_title(FILE *out,sub_title x)
{
    fprintf(out,"Start: %.3lf\nEnd: %.3lf\n%s\n",x.start,x.end,x.text);
}

void f_print_title_microDVD(FILE *out, sub_title x)
{
    fprintf(out, "{%d}{%d}%s\n",(int)x.start,(int)x.end,x.text);
}

void f_print_list_microDVD(FILE *out, cvor *first)
{
    while(first != NULL)
    {
        f_print_title_microDVD(out,first->inf);
        first = first->next;
    }
}

void f_pisi(FILE *out, cvor *first)
{
    while(first != NULL)
    {
        fprint_title(out, first->inf);
        first = first->next;
    }
}






