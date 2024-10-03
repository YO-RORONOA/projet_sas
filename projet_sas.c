#include<stdio.h>
#include<string.h>
#define reservation_max 100 //les tableaux declares au niveau du fichier (portee globale) doivent avoir
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
    printf("\ntapez les informations de la reservation que vous souhaitez effectuer\n");

    printf("tapez le nom: ");
    scanf("%s", reservations[nb_reservation].nom);
    printf("\ntapez le prenom: ");
    scanf("%s", reservations[nb_reservation].prenom);
    printf("\ntapez le Telephon: ");
    scanf("%s", reservations[nb_reservation].telephone);
    printf("\ntapez l'age: ");
    scanf("%d", &reservations[nb_reservation].age);
    printf("\ntapez le Statut(valide, reporte, annule, traite): ");
    scanf("%s", reservations[nb_reservation].statut);
    printf("\ntapez la Date (JJ-MM-AAAA): ");
    scanf("%s", &reservations[nb_reservation].date);

    reservations[nb_reservation].reference = nb_reservation + 1;
    nb_reservation++;
    printf("Reservation ajoutee avec succes!\n");
    }
    else
    printf("reservation complete, impossible d'en ajouter plus");
}

void    supprimer_reservation()
{
    int i;
    int j;
    int ref_supprimer;

    i =0;
    printf("\ntapez la reference unique pour supprimer une reservation: ");
    scanf("%d", &ref_supprimer);
    for (i = 0; i < nb_reservation; i++)
    {
        if (ref_supprimer == reservations[i].reference)
        {
            // Shift all following reservations one position to the left
            for (int j = i; j < nb_reservation - 1; j++)
            {
                reservations[j] = reservations[j + 1]; // Copy the whole structure
            }
            nb_reservation--; // Decrement the number of reservations
            printf("L'opération de suppression a réussi.\n");
             for (int k = 0; k < nb_reservation; k++)
            {
                reservations[k].reference = k + 1; // Reassign references
            }
            return; // Exit the function after deletion
        }
    }
    printf("reservation non trouvee\n");

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
                printf("choix 6: modifier la date reservation\n");
                printf("choix 7: quitter\n");
                printf("votre option: ");
                scanf("%d", &option);

                switch (option)
                {
                case 1:
                printf("tapez le nouveau nom: ");
                scanf("%s", reservations[i].nom);
                printf("nom change avec succes\n\n");
                break;
                case 2:
                printf("tapez le nouveau prenom: ");
                scanf("%s", reservations[i].prenom);
                printf("prenom change avec succes\n\n");
                break;
                case 3:
                printf("tapez le nouveau telephone: ");
                scanf("%s", reservations[i].telephone);
                printf("telephone change avec succes\n\n");
                break;
                case 4:
                printf("tapez le nouveau age: ");
                scanf("%d", &reservations[i].age);
                printf("age change avec succes\n\n");
                break;
                case 5:
                printf("tapez le nouveau statut: ");
                scanf("%s", reservations[i].statut);
                printf("statut change avec succes\n\n");
                break;
                case 6:
                printf("tapez le nouveau date: ");
                scanf("%s", reservations[i].date);
                printf("date change avec succes\n\n");
                break;
                default:
                printf("Option invalide, veuillez reessayer.\n\n");
                }
            }
            return;
        }
        i++;
    }
    printf("reservation non trouvee");
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
    printf("reservation non trouve");
}

int    indice_status(char statut[])
{
    if (strcmp(statut, "valide") == 0)
    {
        return 1;
    }
    if (strcmp(statut, "reporte") == 0)
    {
        return 2;
    }
    if (strcmp(statut, "annule") == 0)
    {
        return 3;
    }
    if (strcmp(statut, "traite") == 0)
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
        printf("choisissez parmi les options ci-dessous comment vous souhaitez triez les reservation: \n");
        printf("choix 1: tri des reservation par nom\n");
        printf("choix 2: tri des reservation par date\n");
        printf("choix 3: tri des reservation par statut\n");
        printf("choix 4: quiter\n");
        printf("votre option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            printf("les reservations triees par nom sont les suivantes: \n");
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
            printf("les reservations triees par date sont les suivantes: \n");
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
            printf("les reservations triees par statut sont les suivantes: ");
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
            case 4:
            printf("Quitter le tri des reservations.\n");
            return;
            default:
            printf("Option invalide, veuillez reessayer.\n\n");
            continue; // Go back to the beginning of the loop
        }
        printf("Reservations triees:\n");
        for (int i = 0; i < nb_reservation; i++)
            {
            printf("Reservation %d:\n", i + 1);
            printf("Nom: %s\n", reservations[i].nom);
            printf("prenom: %s\n", reservations[i].prenom);
            printf("telephone: %s\n", reservations[i].telephone);
            printf("age: %d\n", reservations[i].age);
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
        printf("choisissez parmi les options ci-dessous comment vous souhaitez rechercher des reservations: \n");
        printf("choix 1: rechercher des reservations par reference\n");
        printf("choix 2: rechercher des reservations par nom\n");
        printf("choix 3: rechercher des reservations par date\n");
        printf("choix 4: quitter\n");
        printf("votre option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            Afficher_reservation();
            break;
            case 2:
            printf("Tapez le nom pour afficher les informations de la reservation: ");
            scanf("%s", trouve_nom);
            for(i = 0; i < nb_reservation; i++)
            {
                if(strcmp(trouve_nom, reservations[i].nom) == 0)
                {
                    printf("les informations de %s sont les suivantes: \n", trouve_nom);
                    printf("Nom: %s\n",reservations[i].nom);
                    printf("prenom: %s\n",reservations[i].prenom);
                    printf("telephone: %s\n",reservations[i].telephone);
                    printf("age: %d\n",reservations[i].age);
                    printf("reference: %d\n",reservations[i].reference);
                    printf("statut: %s\n",reservations[i].statut);
                    printf("date: %s\n",reservations[i].date);
                }
            }
            break;
            case 3:
            printf("Tapez la date (JJ-MM-AAAA) pour afficher les informations de la reservation: ");
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
            printf("Option invalide, veuillez reessayer.\n");
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

    while(1)
    {
        nb_valide= 0;
        nb_annule = 0;
        nb_reporte = 0;
        nb_traite = 0;
        result = 0;
        age18 = 0;
        age35 = 0;
        age36 = 0;
        printf("\nchoisissez parmi les options ci-dessous les statistiques que vous souhaitez generer: \n");
        printf("choix 1: la moyenne d'age des patients ayant reserve.\n");
        printf("choix 2: le nombre de patients par tranche d'age (0-18 ans, 19-35 ans, 36+ ans).\n");
        printf("choix 3: le nombre total de reservations par statut\n");
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
            printf("la moyenne d'age des patients ayant reserve est %d anne.\n", result / nb_reservation);
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
            printf("\nle nombre total de reservations par statut sont les suivants: \n");
            {
                printf("le nombre de patients par tranche d'age[0-18]= %d\n", age18);
                printf("le nombre de patients par tranche d'age[18-35]= %d\n", age35);
                printf("le nombre de patients par tranche d'age[35+]= %d\n", age36);
            }
            break;
            case 3:
            for(i = 0; i < nb_reservation; i++)
            {
                if(strcmp("valide", reservations[i].statut) == 0)
                {
                    nb_valide++;
                }
                else if(strcmp("annule", reservations[i].statut) == 0)
                {
                    nb_annule++;
                }
                else if(strcmp("reporte", reservations[i].statut) == 0)
                {
                    nb_reporte++;
                }
                else if(strcmp("traite", reservations[i].statut) == 0)
                {
                    nb_traite++;
                }
            }
            printf("les patients ayant reserve par leur statut sont les suivants: \n");
            printf("nb reservation valide: %d\n", nb_valide);
            printf("nb reservation annule: %d\n", nb_annule);
            printf("nb reservation reporte: %d\n", nb_reporte);
            printf("nb reservation traite: %d\n", nb_traite);
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
        {"Haddad", "Samira", "0123456789", 30, "valide", 1, "01-01-2024"},
        {"Khaled", "Omar", "0123456790", 25, "annule", 2, "02-01-2024"},
        {"Benali", "Amina", "0123456791", 40, "reporte", 3, "03-01-2024"},
        {"Farhat", "Layla", "0123456792", 22, "traite", 4, "04-01-2024"},
        {"Mansour", "Youssef", "0123456793", 33, "valide", 5, "05-01-2024"},
        {"El Amrani", "Fatima", "0123456794", 45, "annule", 6, "06-01-2024"},
        {"Abdallah", "Nadia", "0123456795", 28, "reporte", 7, "07-01-2024"},
        {"Bouaziz", "Karim", "0123456796", 31, "traite", 8, "08-01-2024"},
        {"Cherif", "Zahra", "0123456797", 29, "valide", 9, "09-01-2024"},
        {"Saad", "Rami", "0123456798", 50, "annule", 10, "10-01-2024"}
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
        printf("1. Ajouter une reservation\n");
        printf("2. supprimer une reservation\n");
        printf("3. Modifier une reservation\n");
        printf("4. Afficher une reservation\n");
        printf("5. Trier les reservations\n");
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
                printf("Choix invalide, veuillez reessayer.\n");
                break;
        }
    } while (choix != 7);
    return 0;
}
