#include <stdio.h>
#define MaxElem 100


//structure tab qui contient un tableau est nb element
typedef struct tab{
    int tab[MaxElem];
    int nbelem;
}tb;

//inserer valeur dans le tableau
void inserer(tb *tab,int val){
    if(tab->nbelem<MaxElem){
        tab->tab[tab->nbelem]=val;
        tab->nbelem++;
    }
}


void afficher_tab(tb* tab) {
    printf("Tableau : ");
    for (int i = 0; i < tab->nbelem; i++) {
        printf("%d ", tab->tab[i]);
    }
    printf("\n");
}

//indice minimum du tableau
int indice_min(tb* tab,int i){
    for(int j=i+1;j<tab->nbelem;j++){
        if(tab->tab[j]<tab->tab[i]){
            i=j;
        }
    }
    return i;
}

//affichage speciale quand on arrive a l'indice de min du tableau en ecris une | a coter et | a coter de la valeur min
void afficher_tab_min(tb* tab,int i){
    printf("Tableau : ");
    for (int j = 0; j < tab->nbelem; j++) {
        if(j==i){
            printf("|%d| ", tab->tab[j]);
        }else{
            printf("%d ", tab->tab[j]);
        }
    }
    printf("\n");
}


//fonction de tri par insertion
void tri_par_insertion(tb *T)
{
    int i , j , k ;
    for(i=1;i<T->nbelem;i++)
    {
        for(j=i;j>0;j--)
        {

            if(T->tab[j]<T->tab[j-1])
            {
                k=T->tab[j-1];
                T->tab[j-1]=T->tab[j];
                T->tab[j]=k;
                afficher_tab_min(T,j-1);
            }
            else break ;
        }

    }
}

int main() {
    tb tab;
    tab.nbelem = 0;
    inserer(&tab, 5);
    inserer(&tab, 2);
    inserer(&tab, 9);
    inserer(&tab, 1);
    inserer(&tab, 7);
    inserer(&tab, 4);
    inserer(&tab, 6);
    inserer(&tab, 3);
    inserer(&tab, 10);
    inserer(&tab, 11);
    inserer(&tab, 12);
    inserer(&tab, 8);

    printf("Tableau initial :\n");
    afficher_tab(&tab);

    tri_par_insertion(&tab);

    printf("Tableau trié :\n");
    afficher_tab(&tab);

    return 0;
}
