#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#define E_AIGU_MIN 130
#define E_GRAVE_MIN 138
void AfficherEntete(double filAri)//Date date
{
    //setTitreMenu(filAri);
    gotoxy(1,1);printf("(%3.1f)",filAri);
    gotoxy(28,1);printf("Le Roi de l'informatique Inc.");
    gotoxy(31,2);printf("Syst%cme de paye",E_GRAVE_MIN);
    gotoxy(34,3);printf("MENU");
    gotoxy(70,1);printf("DATE");
}

#endif // AFFICHAGE_H_INCLUDED
