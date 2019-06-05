#include "funkcije.h"


int main(int argc, char*argv[])
{
    cvor *first = NULL, *last = NULL;
    int eof_flag = 0;

    if(argc == 0)
    {
        printf("No commandline arguments.\n");
        exit(1);
    }

    /*if(extension_srt(argv[1]))
    {
        char *newfile_name = convert_file_name(argv[1]);
        printf("%s\n",newfile_name);
        if(rename(argv[1],newfile_name) == 1)
        {
            printf("File rename unsuccessful.\n");
            exit(1);
        }
        strcpy(argv[1],newfile_name);
        free(newfile_name);
    }*/

    FILE *ulaz = fopen(argv[1], "r");
    FILE *izlaz = fopen(argv[2], "w");
    FILE *lista = fopen("lista.txt","w");
    if(izlaz == NULL)
    {
        printf("Greska pri otvaranju fajla.\n");
        exit(1);
    }
    if(ulaz == NULL)
    {
        printf("Greska pri otvaranju fajla.\n");
        exit(1);
    }
    while(!eof_flag)
    {
        dodaj(&first,&last, fread_title(ulaz,&eof_flag));
    }
    fclose(ulaz);
    f_pisi(lista,first);
    fclose(lista);

    printf("Lista ucitana.\n");
    char obradi[2];
    int max_duzina_linije;
    printf("Da li zelite da obradite listu? (da / ne)\n");
    scanf("%s",obradi);
    if(strcmp(obradi,"da") == 0)
    {
        printf("Unesite maksimalni broj karaktera u liniji.\n");
        scanf("%d", &max_duzina_linije);
        obrada(&first, &last, max_duzina_linije);
    }
    convert_subrip_to_microDVD(first);
    f_print_list_microDVD(izlaz,first); 
    brisi(first);
    fclose(izlaz); 
    return 0;
}