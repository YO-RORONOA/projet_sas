#include<stdio.h>
#include<string.h>
#define reservation_max 100 //les tableaux déclarés au niveau du fichier (portée globale) doivent avoir
                            // une taille constante connue au moment de la compilation
int nb_reservation = 0;  //track nombre de reservation.

struct reservation
{
    char    nom[50];
    char    prénom[50];
    char    téléphone[12];
    int     age;
    char    statut[20];
    int     référence;
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
    printf("\ntapez le Prénom: ");
    scanf("%s", reservations[nb_reservation].prénom);
    printf("\ntapez le Téléphon: ");
    scanf("%s", reservations[nb_reservation].téléphone);
    printf("\ntapez l'Âge: ");
    scanf("%d", &reservations[nb_reservation].age);
    printf("\ntapez le Statut: ");
    scanf("%s", reservations[nb_reservation].statut);
    printf("\ntapez la Date (JJ-MM-AAAA): ");
    scanf("%s", &reservations[nb_reservation].date);
    
    reservations[nb_reservation].référence = nb_reservation + 1;
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
        if(ref_supprimer == reservations[i].référence)
        {
            j = i;
            while(j < nb_reservation - 1) //- 1 pour nous assurer que nous ne sortons pas des limites
            {
                strcpy(reservations[j].nom, reservations[j + 1].nom);
                strcpy(reservations[j].prénom, reservations[j + 1].prénom);
                strcpy(reservations[j].téléphone, reservations[j + 1].téléphone);
                strcpy(reservations[j].statut, reservations[j + 1].statut);
                strcpy(reservations[j].date, reservations[j + 1].date);
                reservations[j].age = reservations[j + 1].age;
                reservations[j].référence = reservations[j + 1].référence;
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
        if(ref_modifier == reservations[i].référence)
        {
            while(option != 7)
            {
                printf("choisissez parmi les options ci-dessous ce que vous souhaitez modifier: \n");
                printf("choix 1: modifier le Nom\n");
                printf("choix 2: modifier le Prénom\n");
                printf("choix 3: modifier le téléphone\n");
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
                scanf("%s", reservations[i].prénom);
                printf("prenom changé avec succès\n\n");
                break;
                case 3: 
                printf("tapez le nouveau téléphone: ");
                scanf("%s", reservations[i].téléphone);
                printf("téléphone changé avec succès\n\n");
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
        if(ref_afficher == reservations[i].référence)
        {
            printf("les informations de reference %d sont les suivantes: \n", ref_afficher);
            printf("Nom: %s\n",reservations[i].nom);
            printf("Prénom: %s\n",reservations[i].prénom);
            printf("téléphone: %s\n",reservations[i].téléphone);
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
            printf("Prénom: %s\n", reservations[i].prénom);
            printf("Téléphone: %s\n", reservations[i].téléphone);
            printf("Âge: %d\n", reservations[i].age);
            printf("Statut: %s\n", reservations[i].statut);
            printf("Référence: %d\n", reservations[i].référence);
            printf("Date: %s\n\n", reservations[i].date);
            }
    }
}