#include <stdio.h>
#include<unistd.h>
#include <string.h>

const char destinations[5][10] = {"Waterloo", "Anvers", "Bxl-Midi", "Gand", "Tubize"};

void intro()
{
    printf("Loading...\n");
    sleep(2);
    printf("Bonjour et bienvenu sur le site de reservation de trajet de bus de la TEC.\nVeuillez svp suivre les intructions.\n\n");
    sleep(2);
}

void day(FILE *file)
{
    int heure;
    int jour;
    int mois;
    printf("Veuillez indiquer le jour de votre voyage : ");
    scanf("%d", &jour);
    printf("Veuillez indiquer le mois de votre voyage : ");
    scanf(" %d", &mois);
    printf("Veuillez indiquer l'heure pile de votre voyage : ");
    scanf(" %d", &heure);
    printf("\n");
    fprintf(file, "%d", jour);
    fputc(47, file);
    fprintf(file, "%d", mois);
    fprintf(file, "/2023 à %dh00 : ", heure);
}

void strprinter()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d : ", i+1);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", destinations[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void stringmaker(int num, char str[10])
{
    for (int i = 0; i < 10; i++)
    {
        str[i] = destinations[num][i];
    }
}

void depart(FILE *file)
{
    int num;
    char choice[10];
    printf("Choisissez un endroit de depart\n");
    printf("Le choix de depart sont les suivants :\n");
    strprinter();
    printf("Veuillez indiquer le chiffre qui correspond au départ souhaitée : ");
    scanf("%d", &num);
    stringmaker(num - 1, choice);
    fprintf(file, "%s", choice);
    fprintf(file, " -> ");
}

void destination(FILE *file)
{
    int num;
    char choice[10];
    printf("choissisez une destination :\n");
    printf("Le choix des destinations sont les suivants :\n");
    strprinter();
    printf("Veuillez indiquer le chiffre qui correspond à la destination souhaitée : ");
    scanf("%d", &num);
    stringmaker(num - 1, choice);
    fprintf(file, "%s", choice);
    fprintf(file, "\n");
}

int main()
{
    FILE *fichier;
    fichier = fopen("reservation.txt", "a");
    intro();
    day(fichier);
    depart(fichier);
    destination(fichier);
    fclose(fichier);
    printf("\nVotre réservation a bien été enregistrée.\n\n");
    sleep(2);
}
