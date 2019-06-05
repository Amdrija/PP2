#include "funkcije.h"
void strncpy_from(char *x, char *y, int n, int start)
{
    int i;
    for(i = 0; i < n && y[i + start] != '\0'; i++)
    {
        x[i] = y[i + start];
    }
    x[i] = '\0';
}

void odvoji(cvor *x, int maxlen, cvor **first, cvor **last)
{
    int num = strlen(x->inf.text) / maxlen + 1;
    int sub_len = strlen(x->inf.text) / num + 1;
    double dx = (x->inf.end - x->inf.start)/num;
    sub_title novi;

    for(int i = 0; i < num; i++)
    {
        novi.start = x->inf.start + i * dx;
        novi.end = novi.start + dx;
        novi.text = (char*)malloc((sub_len + 1) * sizeof(char));
        strncpy_from(novi.text,x->inf.text, sub_len, sub_len * i);
        dodaj(first,last,novi);
    }
}

void obrada(cvor **first, cvor **last, int maxlen)
{
    cvor *prev = NULL, *next = NULL, *t = *first;
    if(t == NULL)
    {
        printf("Lista je prazna.\n");
        return;
    }
    next = (*first)->next;
    while(next != NULL)
    {
        if(strlen(t->inf.text) > maxlen)
        {
            cvor *first_t = NULL, *last_t = NULL;
            odvoji(t,maxlen ,&first_t, &last_t);
            last_t->next = next;
            first_t->last = prev;
            if(t == *first)
            {
                *first = first_t;
            }
            else
            {
                prev->next = first_t;
            }
            if(t == *last)
            {
                *last = last_t;
            }
            else
            {
                next->last = last_t;
            }
            free(t->inf.text);
            free(t);
            prev = last_t;
        }
        else
        {
            prev = t;
        }
        t = next;
        next = next->next;
    }
    if(strlen(t->inf.text) > maxlen)
        {
            cvor *first_t = NULL, *last_t = NULL;
            odvoji(t,maxlen ,&first_t, &last_t);
            last_t->next = next;
            first_t->last = prev;
            if(t == *first)
            {
                *first = first_t;
            }
            else
            {
                prev->next = first_t;
            }
            if(t == *last)
            {
                *last = last_t;
            }
            else
            {
                next->last = last_t;
            }
            free(t->inf.text);
            free(t);
            prev = last_t;
        }
}

char *convert_string_to_microDVD(char *s)
{
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '\n')
        {
            s[i] = '|';
        }
    }
    return s;
}

double convert_time_to_fps(double time)
{
    return time*FPS;
}

void convert_subrip_to_microDVD(cvor *first)
{
    while(first != NULL)
    {
        first->inf.start = convert_time_to_fps(first->inf.start);
        first->inf.end = convert_time_to_fps(first->inf.end);
        first->inf.text = convert_string_to_microDVD(first->inf.text);
        first = first->next;
    }
}

char *convert_file_name(char *f)
{
    char *s = (char*)malloc(strlen(f + 1) * sizeof(char));
    int i;
    for(i = 0; i < strlen(f) - 3; i++)
    {
        s[i] = f[i];
    }
    s[i] = '\0';
    strcat(s,"txt");
    return s;
}

int extension_srt(char *f)
{
    return strcmp(f + strlen(f) - 3,"srt") == 0;
}