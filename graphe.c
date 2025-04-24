#include <stdio.h>
#include <stdlib.h>

void matricead(int MA[7][7], int n) {
    char condition;
    int i, j;
    do {
        printf("Est-que le graphe de type ponderes [Y,N] : \n");
        scanf(" %c", &condition); // إضافة مسافة قبل %c لتجنب مشاكل قراءة المدخلات
    } while (condition != 'Y' && condition != 'y' && condition != 'N' && condition != 'n');

    if (condition == 'y' || condition == 'Y') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                do {
                    printf("M[ %d , %d ] = ", i+1, j+1);
                    scanf("%d", &MA[i][j]);
                } while (MA[i][j] != 0 && MA[i][j] != 1);
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("M[ %d , %d ] = ", i+1, j+1);
                scanf("%d", &MA[i][j]);
            }
        }
    }
}

void affichegraphe(int MA[7][7], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("- %d ", i + 1);
        for (j = 0; j < n; j++) {
            
            printf("| %d |", MA[i][j]);
        
        }
        printf("\n");
    }
}

int dergree(int sommet, int MA[7][7], int n) {
    int j, deg = 0;
    for (j = 0; j < n; j++) {
        if (MA[sommet - 1][j] != 0) {
            deg++;
        }
    }
    return deg;
}

void tdegree(int MA[7][7], int n, int tabdeg[7]) {
    int i;
    for (i = 0; i < n; i++) {
        tabdeg[i]=0;
        tabdeg[i] = dergree(i + 1, MA, n);
    }
}

int main(void) {
    int taille;
    printf("Exercice de TD4 structures des donnes \n");
    printf("Entrer la taille de graphe : \n");
    scanf("%d", &taille);

    printf("===>>> Initialisation ============ \n");
    int MatriceAd[7][7];
    matricead(MatriceAd, taille);

    printf("===>>> Affichage ============ \n");
    affichegraphe(MatriceAd, taille);

    int sommet;
    printf("===>>> Degree de sommet ============ \n");
    printf("Entrer indice de sommet : \n");
    scanf("%d", &sommet);
    int deg = dergree(sommet, MatriceAd, taille);
    printf("Le degré du sommet %d est : %d\n", sommet, deg);

    printf("===>>> Degree total ============ \n");
    int Tdeg[7];
    tdegree(MatriceAd, taille, Tdeg);
    for (int i = 0; i < taille; i++) {
        printf("%d ==>> %d\n", i + 1, Tdeg[i]);
    }

    return 0;
}