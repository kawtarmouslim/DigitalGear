#include <stdio.h>
#include <string.h>

// Définition de l'énumération
enum Preorite {
    HIGH = 0,
    LOW = 1
};

// Structure DigitalGear
struct DigitalGear {
    char id[7];
    char titre[30];
    char description[50];
    int jours, mois, annee;
    enum Preorite preorite;
};

// Fonction pour ajouter une tâche
void AjouterTache(struct DigitalGear digitalgear[], int index,int *compteurID) {
      sprintf(digitalgear[index].id, "I%02d",*compteurID);
      compteurID++;

    printf("ID genere : %s\n", digitalgear[index].id);

    printf("Entrer le titre : ");
    scanf(" %[^\n]", digitalgear[index].titre);

    printf("Entrer la description (max 50 caracteres) : ");
    scanf(" %[^\n]", digitalgear[index].description);

    printf("Entrer la date (jj/mm/aaaa) : ");
    scanf("%d/%d/%d", &digitalgear[index].jours, &digitalgear[index].mois, &digitalgear[index].annee);

    printf("Entrer la priorite (0 = HIGH, 1 = LOW) : ");
    scanf("%d", &digitalgear[index].preorite);

    printf("Tache ajoutee avec succes !\n\n");
}

// Fonction pour afficher toutes les tâches
void Affichertache(struct DigitalGear digitalGear[], int nbr) {
    if (nbr == 0) {
        printf("Pas de tache enregistree !\n");
        return;
    }
    for (int i = 0; i < nbr; i++) {
        printf("\nTâche %d :\n", i + 1);
        printf("ID : %s\n", digitalGear[i].id);
        printf("Titre : %s\n", digitalGear[i].titre);
        printf("Description : %s\n", digitalGear[i].description);
        printf("Date : %02d/%02d/%04d\n", digitalGear[i].jours, digitalGear[i].mois, digitalGear[i].annee);
        printf("Priorité : %s\n", digitalGear[i].preorite == HIGH ? "HIGH" : "LOW");
    }
}

// Fonction pour modifier une tâche
void Modifiertache(struct DigitalGear digitalGear[], int index) {
    char idRecherche[7];
    printf("Entrer l'ID de la tâche à modifier : ");
    scanf("%s", idRecherche);
    
    for (int i = 0; i < index; i++) {
        if (strcmp(digitalGear[i].id, idRecherche) == 0) {


            printf("Entrer le nouveau titre : ");
            scanf(" %s", digitalGear[i].titre);

            printf("Entrer la nouvelle description : ");
            scanf(" %[^\n]", digitalGear[i].description);

            printf("Entrer la nouvelle date (jj/mm/aaaa) : ");
            scanf("%d/%d/%d", &digitalGear[i].jours, &digitalGear[i].mois, &digitalGear[i].annee);

            printf("Entrer la nouvelle priorite (0 = HIGH, 1 = LOW) : ");
            scanf("%d", &digitalGear[i].preorite);

            printf("Tache modifiee avec succes !\n");
           
        }
    }
    printf("Tâche avec ID %s non trouvee.\n", idRecherche);
}

int main() {
    int choix;
    struct DigitalGear digitalgear[1000];
    int index = 0;
    int compteurID = 1;

    do {
        printf("\n******************** Gestion des Taches *********************\n");
        printf("1. Ajouter une Tache\n");
        printf("2. Afficher la Liste des Taches\n");
        printf("3. Modifier une Tache\n");
        printf("4. Supprimer une Tache\n");
        printf("5. Filtrer une Tache\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (index < 1000) {
                    AjouterTache(digitalgear, index,&compteurID);
                    index++;
                } else {
                    printf("La liste des tâches est pleine !\n");
                }
                break;

            case 2:
                Affichertache(digitalgear, index);
                break;

            case 3:
                Modifiertache(digitalgear,index);
                break;

            case 4:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);

    return 0;
}
