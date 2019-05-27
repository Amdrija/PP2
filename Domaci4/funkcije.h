#define MAX_DUZINA_LINIJE 100

typedef struct s_nclanak
{
    int id;
    char *naslov;
    char *casopis;
    int godina;
}n_clanak;

typedef struct scvor
{
    n_clanak clanak;
    struct scvor *sl;
}cvor;

n_clanak ucitaj_clanak();
void pisi_clanak(n_clanak clanak);
void ucitaj(cvor **prvi,int n);
void pisi(cvor *prvi);
void brisi(cvor *prvi);
void izbaci(cvor **prvi, int clanak_id);
void ubaci_prvi(cvor **prvi, n_clanak clanak_x);
void ubaci_poslednji(cvor **prvi, n_clanak clanak_x);
void ubaci_sortirano(cvor **prvi, n_clanak x);
cvor **obradi(cvor *prvi, int *n);