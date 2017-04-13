#include <stdio.h>
#include <myconio.h>

#define FAUX 0
#define VRAI !FAUX

#define E_AIGU_MIN 130
#define E_AIGU_MAJ 144
#define E_GRAVE_MIN 138
#define ECHAP 27

char AfficherMenuPrincipal(void);
int EstChoixValide(char choix);
void EntrerDansMenu(char choix);
void AfficherMenuRegle(int filAri);
int EstRegleValide(int regle);
void AfficherRegleCompagnie(int filAri);
void OuvrirFichierRegleCo(char nomPhysique[], char typeAcces[], FILE * * ref_fichierRegleCo);
void AfficherTitreRegleCo();
void AfficherRegleProvinciales(int filAri);
void OuvrirFichierReglePro(char nomPhysique[], char typeAcces[], FILE * * ref_fichierRegleCo);
void AfficherTitreReglePro();
void AfficherRegleFederales(int filAri);
void OuvrirFichierRegleFed(char nomPhysique[], char typeAcces[], FILE * * ref_fichierRegleCo);
void AfficherTitreRegleFed();

void AfficherRetourMenuPrec(void);




void AfficherMenuGestionEmployes(int filAri);




void AfficherMenuInscriptionDonneesPaye(int filAri);




void AfficherMenuCalculPaye(int filAri);




void AfficherMenuEmissionPaye(int filAri);



/**a voir*/
void FermerProgramme(void);

int main(void)
{

    char choix;

    choix = AfficherMenuPrincipal();
    EntrerDansMenu(choix);

}

char AfficherMenuPrincipal(void)
{
    char choix;
    do
    {
        //afficherEntete();
        gotoxy(17,7);
        printf("1. Consulter les r%cgles", E_GRAVE_MIN);
        gotoxy(17,9);
        printf("2. Gestion des employ%cs", E_AIGU_MIN);
        gotoxy(17,11);
        printf("3. Inscription des donn%ces de la paye", E_AIGU_MIN);
        gotoxy(17,13);
        printf("4. Calcul de la paye");
        gotoxy(17,15);
        printf("5. %cmission de la paye", E_AIGU_MAJ);
        gotoxy(17,17);
        printf("6. Quitter le syst%cme", E_GRAVE_MIN);
        //afficherEntree();
        gotoxy(1,24);
        printf("Votre choix : ");
        fflush(stdin);
        choix = getchar();
    }while(!EstChoixValide(choix));

    return(choix);
}

int EstChoixValide(char choix)
{
    if(choix >= '1' && choix <= '6')
    {
        clrscr();
        return VRAI;
    }
    else
    {
        gotoxy(1,21);
        printf("Choix invalide!");
        return FAUX;
    }
}


void EntrerDansMenu(char choix)
{
    /** filAri a mettre en param ici
    */

    int filAri = 1;

    switch(choix)
    {
        case '1':
            AfficherMenuRegle(filAri);
            break;
        case '2':
            AfficherMenuGestionEmployes(filAri);
            break;
        case '3':
            AfficherMenuInscriptionDonneesPaye(filAri);
            break;
        case '4':
            AfficherMenuCalculPaye(filAri);
            break;
        case '5':
            AfficherMenuEmissionPaye(filAri);
            break;
        case '6':
            FermerProgramme();
            break;
    }
}

void AfficherMenuRegle(int filAri)
{
    char regle;
    do
    {
        //afficherEntete();
        gotoxy(17,7);
        printf("1. Consulter les r%cgles de la Compagnie et de d%cduction", E_GRAVE_MIN, E_AIGU_MIN);
        gotoxy(17,9);
        printf("2. Consulter les r%cgles Provinciales", E_GRAVE_MIN);
        gotoxy(17,11);
        printf("3. Consulter les r%cgles F%cd%crales", E_GRAVE_MIN, E_AIGU_MIN, E_AIGU_MIN);
        gotoxy(17,13);
        printf("4. Retour au menu principal");
        /**afficherEntree();    for now
        */
        gotoxy(1,24);
        printf("Votre choix : ");
        fflush(stdin);
        regle = getchar();
    }while(!EstRegleValide(regle));

    switch(regle)
    {
        case '1':
            AfficherRegleCompagnie(filAri);
            break;
        case '2':
            AfficherRegleProvinciales(filAri);
            break;
        case '3':
            AfficherRegleFederales(filAri);
            break;
        case '4':
            AfficherMenuPrincipal();
            break;
    }
}

int EstRegleValide(int regle)
{
    if(regle >= '1' && regle <= '4')
    {
        clrscr();
        return VRAI;
    }
    else
    {
        gotoxy(1,21);
        printf("Choix invalide!");
        return FAUX;
    }
}

void AfficherRegleCompagnie(int filAri)
{
    FILE * fichierRegleCo;

    char ligne[230];
    int posy = 11;

    OuvrirFichierRegleCo("regleco.dat", "r", &fichierRegleCo);

    if(fichierRegleCo)
    {
        AfficherTitreRegleCo();
        gotoxy(7,10);
        rewind(fichierRegleCo);
        while(fgets(ligne, 230, fichierRegleCo) != NULL)
        {
            gotoxy(7,posy);
            printf("%s", ligne);
            posy++;
        }
        fclose(fichierRegleCo);

        gotoxy(1,24);
        AfficherRetourMenuPrec();

/**A VOiR*/

        do
        {
            if(LireEchap())
            {
                clrscr();
                AfficherMenuRegle(filAri);
            }
        }while(!LireEchap());
    }
}

void OuvrirFichierRegleCo(char nomPhysique[], char typeAcces[], FILE * * ref_fichierRegleCo)
{
    * ref_fichierRegleCo = fopen(nomPhysique, typeAcces);

    if(*ref_fichierRegleCo == NULL)
    {
        printf("ERREUR FILE REGLE CO");
    }
}

void AfficherTitreRegleCo(void)
{
    gotoxy(7,8);
    printf("Identification \t R%cgle        Type   Description", E_GRAVE_MIN);
    gotoxy(7,9);
    printf("______________ \t _________    ____   _________________________________");
}

void AfficherRetourMenuPrec(void)
{
    printf("<Echap> Retour au menu pr%cc%cdent", E_AIGU_MIN, E_AIGU_MIN);
}
/**PPOUR TOUS LES REGLES*/
int LireEchap()
{
    char touche;
    touche = getch();
    if(touche == ECHAP)
        return VRAI;
    else
        return FAUX;
}

void AfficherRegleProvinciales(int filAri)
{
    FILE * fichierReglePro;

    char ligne[230];
    int posy = 11;

    OuvrirFichierReglePro("reglepro.dat", "r", &fichierReglePro);

    if(fichierReglePro)
    {
        AfficherTitreReglePro();
        gotoxy(8,10);
        rewind(fichierReglePro);
        while(fgets(ligne, 230, fichierReglePro) != NULL)
        {
            gotoxy(8,posy);
            printf("%s", ligne);
            posy++;
        }
        fclose(fichierReglePro);

        gotoxy(1,24);
        AfficherRetourMenuPrec();

/**A VOiR*/

        do
        {
            if(LireEchap())
            {
                clrscr();
                AfficherMenuRegle(filAri);
            }
        }while(!LireEchap());
    }
}

void OuvrirFichierReglePro(char nomPhysique[], char typeAcces[], FILE * * ref_fichierReglePro)
{
    * ref_fichierReglePro = fopen(nomPhysique, typeAcces);

    if(*ref_fichierReglePro == NULL)
    {
        printf("ERREUR FILE REGLE Pro");
    }
}

void AfficherTitreReglePro(void)
{
    gotoxy(15,6);
    printf("TABLE POUR CALCUL DE L'IMPOT PROVINCIAL");
    gotoxy(8,8);
    printf("Limite inf%crieur    Limite sup%crieur    T      K1", E_AIGU_MIN,  E_AIGU_MIN);
    gotoxy(8,9);
    printf("________________    ________________    ____   ____");
}

void AfficherRegleFederales(int filAri)
{
    FILE * fichierRegleFed;

    char ligne[230];
    int posy = 11;

    OuvrirFichierRegleFed("reglefed.dat", "r", &fichierRegleFed);

    if(fichierRegleFed)
    {
        AfficherTitreRegleFed();
        gotoxy(8,10);
        rewind(fichierRegleFed);
        while(fgets(ligne, 230, fichierRegleFed) != NULL)
        {
            gotoxy(8,posy);
            printf("%s", ligne);
            posy++;
        }
        fclose(fichierRegleFed);

        gotoxy(1,24);
        AfficherRetourMenuPrec();

/**A VOiR*/

        do
        {
            if(LireEchap())
            {
                clrscr();
                AfficherMenuRegle(filAri);
            }
        }while(!LireEchap());
    }
}

void OuvrirFichierRegleFed(char nomPhysique[], char typeAcces[], FILE * * ref_fichierRegleFed)
{
    * ref_fichierRegleFed = fopen(nomPhysique, typeAcces);

    if(*ref_fichierRegleFed == NULL)
    {
        printf("ERREUR FILE REGLE CO");
    }
}

void AfficherTitreRegleFed(void)
{
    gotoxy(15,6);
    printf("TABLE POUR CALCUL DE L'IMPOT F%cD%cRALE", E_AIGU_MAJ, E_AIGU_MAJ);
    gotoxy(8,8);
    printf("Limite inf%crieur    Limite sup%crieur    T        K1", E_AIGU_MIN,  E_AIGU_MIN);
    gotoxy(8,9);
    printf("________________    ________________    ____     ____");
}

void AfficherMenuGestionEmployes(int filAri)
{
    printf("AfficherMenuGestionEmployes");
}

void AfficherMenuInscriptionDonneesPaye(int filAri)
{
    printf("AfficherMenuInscriptionDonneesPaye");
}

void AfficherMenuCalculPaye(int filAri)
{
    printf("AfficherMenuCalculPaye");
}

void AfficherMenuEmissionPaye(int filAri)
{
    printf("AfficherMenuEmissionPaye");
}

void FermerProgramme()
{
    exit(0);
}







