#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXDUZ 100

void write(char **s, int n)
{
    for(int i = 0; i < n; i++)
        printf("%s\n",s[i]);
}

void delete_string(char **s, int n)
{
    for(int i = 0; i < n; i++)
        free(s[i]);
    free(s);
}

char* format(char *s)
{
    char *condition_start = strstr(s, "if");
    if(condition_start == NULL)
        return s;


    char *condition_end = strstr(s, "then");
    if(condition_end == NULL)
        return s;


    char *block_start = strstr(s, "begin");
    if(block_start == NULL)
        return s;


    char *block_end = strstr(s,"end;");
    if(block_end == NULL)
        return s;

    *condition_end = '\0';
    *block_end = '\0';

    //duzina uslova je conditioon_end - condition_start - 2, ali posto u uslov 
    //dodajemo i 2 zagrade i \0 karakter, onda treba jos 3 mesta da odvojimo
    char *condition = (char*)malloc((condition_end - condition_start + 1) * sizeof(char));
    if(condition == NULL)
    {
        printf("Failed to format: Memory allocation error.");
        return s;
    }

    char *block = (char*)malloc((block_end - block_start - 2) * sizeof(char));
    if(block == NULL)
    {
        printf("Failed to format: Memory allocation error.");
        return s;
    }
    block[0] = '{';
    condition[0] = '(';
    strcat(condition, condition_start + 2);
    strcat(block, block_start + 5);
    strcat(condition, ")");
    strcat(block, "}");

    free(s);
    s = (char*)malloc((2 + strlen(condition) + strlen(block)) * sizeof(char));
    if(s == NULL)
    {
        printf("Failed to format: Memory allocation error.");
        exit(1);
    }

    *s = '\0';
    strcat(s,"if");
    strcat(s,condition);
    strcat(s,block);


    free(condition);
    free(block);
    return s;
}

char* format2(char *s)
{
    int i = 0, j = 0, br_velikih = 0;
    while(s[i] != '\0')
    {
        br_velikih += (s[i] >= 'A' && s[i++] <='Z');
    }

    j = strlen(s);
    i = strlen(s) + br_velikih;
    s = (char*)realloc(s, (strlen(s) + br_velikih) * sizeof(char));

    while(j >= 0)
    {
        if(s[j] >= 'A' && s[j] <= 'Z')
        {
            s[i--] = s[j] - 'A' + 'a';
            s[i--] = '_';
        }
        else
        {
            s[i--] = s[j];
        }
        j--;
        
    }
    return s;
}

char* format3(char *s)
{
    int cif[10] = {0}, i = 0, min_parna_cif = -1;

    while(s[i] != '\0')
    {
        cif[s[i++] - '0']++;
    }

    for(i = 0; i < 10; i += 2)
    {
        if(cif[i])
        {
            cif[i]--;
            min_parna_cif = i;
            break;
        }
    }

    if(min_parna_cif == -1)
        return "Nema parnih cifara.";


    s[strlen(s) - 1] = min_parna_cif + '0';
    i = 0;
    for(int j = 9; j >= 0; j--)
    {
        while(cif[j])
        {
            s[i++] = j + '0';
            cif[j]--;
        }
    }

    return s;
}

int is_alpha(char a)
{
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <='Z');
}

char to_lower(char a)
{
    return a - ('A' - 'a') * (a <= 'Z');
}


char frequent_letter(char *s)
{
    int slova[26] = {0}, i = 0;
    while(s[i] != '\0')
    {
        if(is_alpha(s[i]))
        {
            slova[to_lower(s[i]) - 'a']++;
        }
        i++;
    }

    int max = 0;
    char max_slovo = ' ';
    for(i = 0; i < 26; i++)
    {
        if(slova[i] > max)
        {
            max = slova[i];
            max_slovo = i + 'A';
        }
    }


    return max_slovo;
}



int main()
{
    char **s, c, *trenutni_string;
    int new_line = 1, i = 0, end = 0, n = 0;

    trenutni_string = (char*)malloc(MAXDUZ * sizeof(char));
    
    trenutni_string[0] = '\0';
    s = (char**)malloc(sizeof(char*));
    if(s == NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    while(!end)
    {
        while(!((c = getchar()) == '\n' && new_line))
        {
            if(new_line)
            {
                //ako smo na novoj liniji, onda resetuj trenutni_string
                i = 0;
                new_line = 0;
                trenutni_string[i++] = c;
            }
            else
            {
                if(c != '\n')
                {
                    trenutni_string[i++] = c;
                }
                else
                {
                    //ako je c == '\n' onda imamo novu liniju, i stavi kraj na trenutni_string
                    trenutni_string[i++] = '\0';
                    new_line = 1;

                    //ako je trenutni_string razlicit od 'dosta Brus Li' onda dodaj trenutni_string u niz stringova s
                    if(strcmp(trenutni_string, "dosta Brus Li"))
                    {
                        s = (char**)realloc(s, (n + 1) * sizeof(char*));
                        if(s == NULL)
                        {
                            printf("Failed to allocate memory.\n");
                            exit(1);
                        }


                        s[n] = (char*)malloc(i * sizeof(char));
                        if(s[n] == NULL)
                        {
                            printf("Failed to allocate memory.\n");
                            exit(1);
                        }


                        strcpy(s[n++], trenutni_string);
                    }
                    else
                    {
                        end = 1;
                        break;
                    }
                    
                }
                
            }
            

        }
        if(!end)
        {
            write(s, n);
            printf("*****************\n");
            for(int i = 0; i < n; i++)
                printf("%c\n",frequent_letter(s[i]));
            delete_string(s, n);

            //ako nije kraj programa, onda resetuj niz stringova s
            n = 0;
            s = (char**)malloc(sizeof(char*));
            if(s == NULL)
            {
                printf("Failed to allocate memory.\n");
                exit(1);
            }
        }
        
    }

}