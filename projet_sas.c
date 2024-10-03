#include<stdio.h>
#include<string.h>
#define reservation_max 100 //les tableaux déclarés au niveau du fichier (portée globale) doivent avoir
                            // une taille constante connue au moment de la compilation
int nb_reservation = 0;  //track nombre de reservation.

struct reservation
{
    char    nom[50];
    char    prenom[50];
    char    telephone[12];
    int     age;
    char    statut[20];
    int     reference;
    char    date[11];
};
struct reservation reservations[reservation_max];

void    ajouterReservation()
{
    if(nb_reservation < reservation_max)
    {
    printf("\ntapez les informations de la réservation que vous souhaitez effectuer\n");
    
    printf("tapez le nom: ");
    scanf("%s", reservations[nb_reservation].nom);
    printf("\ntapez le prenom: ");
    scanf("%s", reservations[nb_reservation].prenom);
    printf("\ntapez le Téléphon: ");
    scanf("%s", reservations[nb_reservation].telephone);
    printf("\ntapez l'Âge: ");
    scanf("%d", &reservations[nb_reservation].age);
    printf("\ntapez le Statut: ");
    scanf("%s", reservations[nb_reservation].statut);
    printf("\ntapez la Date (JJ-MM-AAAA): ");
    scanf("%s", &reservations[nb_reservation].date);
    
    reservations[nb_reservation].reference = nb_reservation + 1;
    nb_reservation++;
    printf("Réservation ajoutée avec succès!\n");
    }
    else
    printf("réservation complète, impossible d'en ajouter plus");   
}

void    supprimer_reservation()
{
    int i;
    int j;
    int ref_supprimer;

    i =0;
    printf("\ntapez la reference unique pour supprimer une reservation: ");
    scanf("%d", &ref_supprimer);
    while(i < nb_reservation)
    {
        if(ref_supprimer == reservations[i].reference)
        {
            j = i;
            while(j < nb_reservation - 1) //- 1 pour nous assurer que nous ne sortons pas des limites
            {
                strcpy(reservations[j].nom, reservations[j + 1].nom);
                strcpy(reservations[j].prenom, reservations[j + 1].prenom);
                strcpy(reservations[j].telephone, reservations[j + 1].telephone);
                strcpy(reservations[j].statut, reservations[j + 1].statut);
                strcpy(reservations[j].date, reservations[j + 1].date);
                reservations[j].age = reservations[j + 1].age;
                reservations[j].reference = reservations[j + 1].reference;
            }
            nb_reservation--;
            printf("l'opération de suppression a réussi\n");
            return;
        }
        i++;
    }
    printf("réservation non trouvée\n");
    
}

void    modifier_reservation()
{
    int i;
    int ref_modifier;
    int option;

    i = 0;
    option = 0;
    printf("\ntapez la reference unique pour modifier une reservation: ");
    scanf("%d", &ref_modifier);
    while(i < nb_reservation)
    {
        if(ref_modifier == reservations[i].reference)
        {
            while(option != 7)
            {
                printf("choisissez parmi les options ci-dessous ce que vous souhaitez modifier: \n");
                printf("choix 1: modifier le Nom\n");
                printf("choix 2: modifier le prenom\n");
                printf("choix 3: modifier le telephone\n");
                printf("choix 4: modifier l'age\n");
                printf("choix 5: modifier le statut\n");
                printf("choix 6: modifier la date réservation\n");
                printf("choix 7: quitter\n");
                printf("votre option: ");
                scanf("%d", &option);

                switch (option)
                {
                case 1: 
                printf("tapez le nouveau nom: ");
                scanf("%s", reservations[i].nom);
                printf("nom changé avec succès\n\n");
                break;
                case 2: 
                printf("tapez le nouveau prenom: ");
                scanf("%s", reservations[i].prenom);
                printf("prenom changé avec succès\n\n");
                break;
                case 3: 
                printf("tapez le nouveau telephone: ");
                scanf("%s", reservations[i].telephone);
                printf("telephone changé avec succès\n\n");
                break;
                case 4: 
                printf("tapez le nouveau age: ");
                scanf("%d", &reservations[i].age);
                printf("age changé avec succès\n\n");
                break;
                case 5: 
                printf("tapez le nouveau statut: ");
                scanf("%s", reservations[i].statut);
                printf("statut changé avec succès\n\n");
                break;
                case 6: 
                printf("tapez le nouveau date: ");
                scanf("%s", reservations[i].date);
                printf("date changé avec succès\n\n");
                break;
                default:
                printf("Option invalide, veuillez réessayer.\n\n");
                }
            }
            return;
        }
        i++;
    }
    printf("réservation non trouvée");
}

void    Afficher_reservation()
{
    int ref_afficher;
    int i;

    i = 0;
    printf("\ntapez la reference unique pour afficher les informations d'une reservation: ");
    scanf("%d", &ref_afficher);
    while(i < nb_reservation)
    {
        if(ref_afficher == reservations[i].reference)
        {
            printf("les informations de reference %d sont les suivantes: \n", ref_afficher);
            printf("Nom: %s\n",reservations[i].nom);
            printf("prenom: %s\n",reservations[i].prenom);
            printf("telephone: %s\n",reservations[i].telephone);
            printf("age: %d\n",reservations[i].age);
            printf("statut: %s\n",reservations[i].statut);
            printf("date: %s\n",reservations[i].date);
            return;
        }
        i++;
    }
    printf("réservation non trouvé");
}

int    indice_status(char statut[])
{
    if (strcmp(statut, "validé") == 0) 
    {
        return 1;
    }
    if (strcmp(statut, "reporté") == 0) 
    {
        return 2;
    }
    if (strcmp(statut, "annulé") == 0) 
    {
        return 3;
    }
    if (strcmp(statut, "traité") == 0) 
    {
        return 4;
    }
    return 5; // pour les statut inconnus
}

void    tri_reservation()
{
    struct reservation temp;
    int option;
    int choix;
    int jour1, mois1, anne1;
    int jour2, mois2, anne2;
    while(choix != 4)
    {
        printf("choisissez parmi les options ci-dessous comment vous souhaitez triez les réservation: \n");
        printf("choix 1: tri des réservation par nom\n");
        printf("choix 2: tri des réservation par date\n");
        printf("choix 3: tri des réservation par statut\n");
        printf("choix 4: quiter\n");
        printf("votre option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1: 
            printf("les réservations triées par nom sont les suivantes: \n");
            for(int i =0; i < nb_reservation - 1; i++)
            {
                for(int j = 0; j < nb_reservation -1 - i; j++)
                {
                    if(strcmp(reservations[j].nom, reservations[j + 1].nom) > 0)
                    {
                        temp = reservations[j];
                        reservations[j] = reservations[j + 1];
                        reservations[j + 1] = temp;
                    }
                }
            }
            break;
            case 2:
            printf("les réservations triées par date sont les suivantes: \n");
            for(int i =0; i < nb_reservation - 1; i++)
            {
                for(int j = 0; j < nb_reservation -1 - i; j++)
                {
                    sscanf(reservations[j].date, "%d-%d-%d", &jour1, &mois1, &anne1);
                    sscanf(reservations[j + 1].date, "%d-%d-%d", &jour2, &mois2, &anne2);
                    if (anne1 > anne2 || (anne1 == anne2 && mois1 > mois2) || (anne1 == anne2 && mois1 == mois2 && jour1 > jour2))
                    {
                    temp = reservations[j];
                    reservations[j] = reservations[j + 1];
                    reservations[j + 1] = temp;
                    }
                }
            }
            break;
            case 3: 
            printf("les réservations triées par statut sont les suivantes: ");
              for(int i = 0; i < nb_reservation - 1; i++)
            {
                for(int j = 0; j < nb_reservation - 1 - i; j++)
                {
                    if(indice_status(reservations[j].statut) > indice_status(reservations[j + 1].statut))
                    {
                        temp = reservations[j];
                        reservations[j] = reservations[j + 1];
                        reservations[j + 1] = temp;
                    }
                }
            }
            break;
            default:
            printf("Option invalide, veuillez réessayer.\n\n");
            continue; // Go back to the beginning of the loop
        }
        printf("Réservations triées:\n");
        for (int i = 0; i < nb_reservation; i++)
            {
            printf("Réservation %d:\n", i + 1);
            printf("Nom: %s\n", reservations[i].nom);
            printf("prenom: %s\n", reservations[i].prenom);
            printf("telephone: %s\n", reservations[i].telephone);
            printf("Âge: %d\n", reservations[i].age);
            printf("Statut: %s\n", reservations[i].statut);
            printf("reference: %d\n", reservations[i].reference);
            printf("Date: %s\n\n", reservations[i].date);
            }
    }
}

void    recherche_reservation()
{
    int option;
    int i;
    char trouve_nom[50];
    char date_recherche[11];

    i = 0;
    while(1)
    {
        printf("choisissez parmi les options ci-dessous comment vous souhaitez rechercher des réservations: \n");
        printf("choix 1: rechercher des réservations par reference\n");
        printf("choix 2: rechercher des réservations par nom\n");
        printf("choix 3: rechercher des réservations par date\n");
        printf("choix 4: quitter\n");
        printf("votre option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            Afficher_reservation();
            break;
            case 2:
            printf("Tapez le nom pour afficher les informations de la réservation: ");
            scanf("%s", trouve_nom);
            while(i < nb_reservation)
            {
                if(strcmp(trouve_nom, reservations[i].nom) == 0)
                {
                    printf("les informations de %s sont les suivantes: \n", trouve_nom);
                    printf("Nom: %s\n",reservations[i].nom);
                    printf("prenom: %s\n",reservations[i].prenom);
                    printf("telephone: %s\n",reservations[i].telephone);
                    printf("age: %d\n",reservations[i].age);
                    printf("statut: %s\n",reservations[i].statut);
                    printf("date: %s\n",reservations[i].date);    
                }
                i++;
            }
            break;
            case 3:
            printf("Tapez la date (JJ-MM-AAAA) pour afficher les informations de la réservation: ");
            scanf("%s", date_recherche);
            for(int i = 0; i < nb_reservation; i++)
            {
                if(strcmp(date_recherche, reservations[i].date) == 0)
                {
                    printf("les informations de reservation de la date %s  sont les suivantes: \n", date_recherche);
                    printf("Nom: %s\n",reservations[i].nom);
                    printf("prenom: %s\n",reservations[i].prenom);
                    printf("telephone: %s\n",reservations[i].telephone);
                    printf("age: %d\n",reservations[i].age);
                    printf("statut: %s\n",reservations[i].statut);
                    printf("date: %s\n",reservations[i].date);
                     
                }
            }
            break;
            case 4:
            return;
            default:
            printf("Option invalide, veuillez réessayer.\n");
            break;
        }
    } 
}

void    statistique_reservation()
{
    int option;
    int i;
    int nb_valide;
    int nb_annule;
    int nb_reporte;
    int nb_traite;
    int result;
    int moyen;
    int age18;
    int age35;
    int age36;

    nb_valide= 0;
    nb_annule = 0;
    nb_reporte = 0;
    nb_traite = 0;
    result = 0;
    age18 = 0;
    age35 = 0;
    age36 = 0;
    while(1)
    {
        printf("\nchoisissez parmi les options ci-dessous les statistiques que vous souhaitez générer: \n");
        printf("choix 1: la moyenne d'âge des patients ayant réservé.\n");
        printf("choix 2: le nombre de patients par tranche d'âge (0-18 ans, 19-35 ans, 36+ ans).\n");
        printf("choix 3: le nombre total de réservations par statut\n");
        printf("choix 4: quitter\n");
        printf("votre option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            for(i = 0; i < nb_reservation; i++)
            {
                result += reservations[i].age;
            }
            printf("la moyenne d'âge des patients ayant réservé est %d anné.\n", result / nb_reservation);
            break;
            case 2:
            for(i = 0; i < nb_reservation; i++)
            {
                if (reservations[i].age <= 18)
                    {
                        age18++;
                    }
                else if (reservations[i].age <= 35 && reservations[i].age >= 19)
                    {
                    age35++;
                    }
                else if (reservations[i].age >= 36)
                    {
                    age36++;
                    }
            }
            printf("\nle nombre total de réservations par statut sont les suivants: \n");
            {
                printf("le nombre de patients par tranche d'âge[0-18]= %d\n", age18);
                printf("le nombre de patients par tranche d'âge[18-35]= %d\n", age35);
                printf("le nombre de patients par tranche d'âge[35+]= %d\n", age36);
            }
            break;
            case 3:
            for(i = 0; i < nb_reservation; i++)
            {
                if(strcmp("validé", reservations[i].statut) == 0)
                {
                    nb_valide++;
                }
                else if(strcmp("annulé", reservations[i].statut) == 0)
                {
                    nb_annule++;
                }
                else if(strcmp("reporté", reservations[i].statut) == 0)
                {
                    nb_reporte++;
                }
                else if(strcmp("traité", reservations[i].statut) == 0)
                {
                    nb_traite++;
                }
            }
            printf("les patients ayant réservé par leur statut sont les suivants: \n");
            printf("nb reservation validé: %d\n", nb_valide);
            printf("nb reservation annulé: %d\n", nb_annule);
            printf("nb reservation reporté: %d\n", nb_reporte);
            printf("nb reservation traité: %d\n", nb_traite);
            break;
            case 4:
            printf("Quitter les statistiques.\n");
            return; 
        }
    }
}
void initialiserReservations()
{
    struct reservation fake_data[10] = 
    {
        {"Haddad", "Samira", "0123456789", 30, "validé", 1, "01-01-2024"},
        {"Khaled", "Omar", "0123456790", 25, "annulé", 2, "02-01-2024"},
        {"Benali", "Amina", "0123456791", 40, "reporté", 3, "03-01-2024"},
        {"Farhat", "Layla", "0123456792", 22, "traité", 4, "04-01-2024"},
        {"Mansour", "Youssef", "0123456793", 33, "validé", 5, "05-01-2024"},
        {"El Amrani", "Fatima", "0123456794", 45, "annulé", 6, "06-01-2024"},
        {"Abdallah", "Nadia", "0123456795", 28, "reporté", 7, "07-01-2024"},
        {"Bouaziz", "Karim", "0123456796", 31, "traité", 8, "08-01-2024"},
        {"Cherif", "Zahra", "0123456797", 29, "validé", 9, "09-01-2024"},
        {"Saad", "Rami", "0123456798", 50, "annulé", 10, "10-01-2024"}
    };
    for (int i = 0; i < 10; i++) 
    {
        reservations[i] = fake_data[i];
        nb_reservation++;
    }
}
int main() 
{
    int choix;

    // Initialize default reservations
    initialiserReservations();

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Ajouter une réservation\n");
        printf("2. supprimer une réservation\n");
        printf("3. Modifier une réservation\n");
        printf("4. Afficher une réservation\n");
        printf("5. Trier les réservations par nom\n");
        printf("6. recherche reservation\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterReservation();
                break;
            case 2:
                supprimer_reservation();
                break;
            case 3:
                modifier_reservation();
                break;
            case 4:
                Afficher_reservation();
                break;
            case 5:
                tri_reservation();
                break;
            case 6:
                recherche_reservation();
                break;
            case 7:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
    } while (choix != 7);
    return 0;
}