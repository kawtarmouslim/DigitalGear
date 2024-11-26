#include <stdio.h>
#include <string.h>
enum Preorite {
    HIGH = 0,
    LOW = 1
};
enum Status {
    COMPLETE = 1,
    INCOMPLETE = 0
};
struct DigitalGear {
    char id[7];
    char titre[30];
    char description[50];
    char date[20];
    enum Preorite preorite;
    enum Status status;
};
     void AjouterTache(struct DigitalGear digitalgear[], int index, int *compteurID) {
    sprintf(digitalgear[index].id, "I%02d", *compteurID);
    (*compteurID)++;
    printf("ID : %s\n", digitalgear[index].id);
    printf("Entrer le titre : ");
    scanf(" %[^\n]", digitalgear[index].titre);

    printf("Entrer la description (max 50 caracteres) : ");
    scanf(" %[^\n]", digitalgear[index].description);

    while (1)
    {
        int jours,mois,anne;
       printf("Enter la date :");
       scanf("%11s",digitalgear[index].date);
       if (sscanf(digitalgear[index].date,"%2d/%2d/%4d",& jours,&mois,&anne) != 3 ||
          jours < 1 || jours > 31 ||
          mois < 1 || mois > 12  ||
          anne < 2000 || anne > 2060 )
       {
             printf("\nInvalid forme. entrer la forme correct  MM/DD/YYYY format.\n");
       }
      
        else break;
    }
    

    printf("Entrer la priorite (0 = HIGH, 1 = LOW) : ");
    scanf("%d", &digitalgear[index].preorite);
    printf("Entrer le status (0 = incompete, 1 = complete) : ");
    scanf("%d", &digitalgear[index].status);

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
        printf("Date : %sn\n", digitalGear[i].date);
        printf("Priorite : %s\n", digitalGear[i].preorite == HIGH ? "HIGH" : "LOW");
        printf("Status :%s\n",digitalGear[i].status== COMPLETE ? "complete" :"incomplete");
    }
}


void Modifiertache(struct DigitalGear digitalGear[], int index) {
    char idRecherche[7];
    printf("Entrer ID de la tache a modifier : ");
    scanf("%s", idRecherche);
    for (int i = 0; i < index; i++) {
        if (strcmp(digitalGear[i].id, idRecherche) == 0) {
            int choix;
            printf("1.Modifier titre\n 2.Modifier description \n 3.Modifier la date (jj/mm/aaaa)\n 4.Modifier priorite\n 5.Modifier sattus \n");
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
                  scanf("%s", digitalGear[i].date);
                break;
             case 4:
                 printf("Entrer la nouvelle priorite (0 = HIGH, 1 = LOW) : ");
                 scanf("%d", &digitalGear[i].preorite);
                break;
            case 5:
                 printf("Entrer la nouvelle status (0 = incomplete, 1 = complete) : ");
                 scanf("%d", &digitalGear[i].status);
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
        if ((digitalGear[i].preorite == HIGH && strcasecmp(propriterecherche, "High") == 0) ||
            (digitalGear[i].preorite == LOW && strcasecmp(propriterecherche, "Low") == 0)) {
            printf("Id : %s\n", digitalGear[i].id);
            printf("Priorite : %s\n", digitalGear[i].preorite == HIGH ? "High" : "Low");
            
        }
    }
}
void filterparstatus(struct DigitalGear digitalGear[], int *nbrt, const char *idstatus) {
    for (int i = 0; i < *nbrt; i++) {
        if ((digitalGear[i].status == COMPLETE && strcasecmp(idstatus, "complete") == 0) ||
            (digitalGear[i].status == INCOMPLETE && strcasecmp(idstatus, "incomplete") == 0)) {
            printf("Id : %s\n", digitalGear[i].id);
            printf("Titre : %s\n", digitalGear[i].titre);
            printf("Priorite : %s\n", digitalGear[i].preorite == HIGH ? "High" : "Low");
            printf("Statut : %s\n", digitalGear[i].status == COMPLETE ? "Complete" : "Incomplete");
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
    char idstatus[6];
  

    do {
        printf("\n******************** Gestion des Taches *********************\n");
        printf("1. Ajouter une Tache\n");
        printf("2. Afficher la Liste des Taches\n");
        printf("3. Modifier une Tache\n");
        printf("4. Supprimer une Tache\n");
        printf("5. Filtrer une Tache par preorite\n");
        printf("6. Filtrer une Tache par status\n");
        printf("7. Quitter\n");
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
                printf("Entrez le statut (complete/incomplete) : ");
                scanf("%s", idstatus);
                filterparstatus(digitalgear, &index, idstatus);  
                break;
            case 7:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 6);

    return 0;
}
