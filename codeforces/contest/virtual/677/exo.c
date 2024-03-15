#include <stdio.h>
#include <stdlib.h>
const int MAX = 10;

int afficheMenu() {
    int c;
    do {
        printf("1 - Ajouter produit ?\n");
        printf("2 - Consulter stock ?\n");
        printf("3 - Effectuer vente ?\n");
        printf("4 - Afficher le chiffre d'afffaire ?\n");
        printf("0 Quiter ?");
        printf("Ecrire votre choix ? \n");
        scanf("%d", &c);
    } while (c < 0 || c > 4);
    return c;
}

int recherche(char* nom, char* tNom[], int n) {
    int i = 0;
    while (i != n && nom != tNom[i]) i++;
    return i;
}

void ajouter_produit(char* tNom[], int tQte[], float tPrix[]) {
    char* nom;
    printf("Nom produit ? ");
    scanf();
    printf("Quantité ?");

}

void consulter_stock(int n, char* tNom[], int tQte[], float tPrix[]) {
    printf("Bilan Stock\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Produit N = %d\n", i);
        printf("%s - %d - %f\n", tNom[i], tQte[i], tPrix[i]);
    }
}

void effectuer_vente() {

}


void traiter(int c, int n, float chaff, char* tNom[], int tQte[], float tPrix[]) {
    switch (c)
    {
    case 1:
        ajouter_produit();
        break;
    case 2:
        consulter_stock(n, tNom, tQte, tPrix);
        break;
    case 3:
        effectuer_vente();
        break;
    case 4:
        printf("Chiffre d'affaire = %f", chaff);
        break;
    default:
        break;
    }
}


int main() {
    int n, choix;
    float chaff;
    int tQte[MAX];
    char* tNom[MAX];
    float tPrix[MAX];
    chaff = 0;
    n = 0;
    choix = afficheMenu();
    return 0;
}
