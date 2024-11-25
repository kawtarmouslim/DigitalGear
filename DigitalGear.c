#include <stdio.h>
#include <string.h>
enum Preorite {
    HIGH = 0,
    LOW = 1
};
struct DigitalGear {
    char id[7];
    char titre[30];
    char description[50];
    int jours, mois, annee;
    enum Preorite preorite;
};
     void AjouterTache(struct DigitalGear digitalgear[], int index, int *compteurID) {

    sprintf(digitalgear[index].id, "I%02d", *compteurID);
    (*compteurID)++;
    printf("ID : %s\n", digitalgear[index].id);
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

void Affichertache(struct DigitalGear digitalGear[], int nbr) {
    if (nbr == 0) {
        printf("Pas de tache enregistree !\n");
    }
    for (int i = 0; i < nbr; i++) {
        printf("\nTache %d :\n", i + 1);
        printf("ID : %s\n", digitalGear[i].id);
        printf("Titre : %s\n", digitalGear[i].titre);
        printf("Description : %s\n", digitalGear[i].description);
        printf("Date : %02d/%02d/%04d\n", digitalGear[i].jours, digitalGear[i].mois, digitalGear[i].annee);
        printf("Priorité : %s\n", digitalGear[i].preorite == HIGH ? "HIGH" : "LOW");
    }
}


void Modifiertache(struct DigitalGear digitalGear[], int index) {
    char idRecherche[7];
    printf("Entrer ID de la tache a modifier : ");
    scanf("%s", idRecherche);
    for (int i = 0; i < index; i++) {
        if (strcmp(digitalGear[i].id, idRecherche) == 0) {
            int choix;
            printf("1.Modifier titre\n 2.Modifier description \n 3.Modifier la date (jj/mm/aaaa)\n 4.Modifier priorite\n");
            printf("Entrer votre choix :");
            scanf("%d",&choix);
            switch (choix)
            {
            case 1:
            printf("Entrer le nouveau titre : ");
            scanf(" %s", digitalGear[i].titre);
                break;
            case 2:
                 printf("Entrer la nouvelle description : ");
                 scanf(" %[^\n]", digitalGear[i].description);
                break;
            case 3:
               
                 printf("Entrer la nouvelle date (jj/mm/aaaa) : ");
                  scanf("%d/%d/%d", &digitalGear[i].jours, &digitalGear[i].mois, &digitalGear[i].annee);
                break;
             case 4:
                 printf("Entrer la nouvelle priorite (0 = HIGH, 1 = LOW) : ");
                 scanf("%d", &digitalGear[i].preorite);
                break;
            default:
            printf("le choix invalid");
                break;
            }

           
           
        }
    }
    printf("Tache avec ID %s non trouvee.\n", idRecherche);
}
 
void SupprimerTache(struct DigitalGear digitalGear[], int *nbrt, const char *idRecherche) {
    for (int i = 0; i < *nbrt; i++) {
        if (strcmp(digitalGear[i].id, idRecherche) == 0) {
            for (int j = i; j < *nbrt - 1; j++) {
                digitalGear[j] = digitalGear[j + 1];
            }

            (*nbrt)--; 
            printf("Tache avec ID '%s' supprimee avec succes.\n", idRecherche);
            return;
        }
    }
    printf("ID '%s' introuvable.\n", idRecherche);
}
   

void filtrerParPriorite(struct DigitalGear digitalGear[], int *nbrt, const char *propriterecherche) {
    for (int i = 0; i < *nbrt; i++) {
        if ((digitalGear[i].preorite == HIGH && strcmp(propriterecherche, "High") == 0) ||
            (digitalGear[i].preorite == LOW && strcmp(propriterecherche, "Low") == 0)) {
            printf("Titre : %s\n", digitalGear[i].titre);
            printf("Description : %s\n", digitalGear[i].description);
            printf("Date : %02d/%02d/%04d\n", digitalGear[i].jours, digitalGear[i].mois, digitalGear[i].annee);
            printf("Priorite : %s\n", digitalGear[i].preorite == HIGH ? "High" : "Low");
        }
    }
}
int main() {
    int choix;
    struct DigitalGear digitalgear[1000];
    int index = 0;
    int compteurID = 1;
    char idRecherche[7];
    char propriorite[6];
  

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
                 
                    printf("Entrer ID de la tAche a supprimer : ");
                    scanf("%s", idRecherche);
                    SupprimerTache(digitalgear, &index, idRecherche);
               
                break;
            case 5:
                printf("Entrez la priorit (High/Low) : ");
                scanf("%s", propriorite);
                filtrerParPriorite(digitalgear, &index, propriorite); 
                
                break;
            case 6:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 6);

    return 0;
}
