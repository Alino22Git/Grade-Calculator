#include <stdio.h>

int getNote(double zt, double at, double ue, double ges); //Deklaration der Funktion -> Compiler

int main(){
    double ein=0,zt=0,at=0,ue=0,ges=0; //Variablen deklarieren/initialisieren fuer die Eingabe
    char typ;

    do{ //do while fuer die iterative Eingabe/Abfrage
    printf("\nZT Punkte: %.2lf\n", zt); //Ausgabe
    printf("AT Punkte: %.2lf\n", at);
    printf("UE Punkte: %.2lf\n", ue);
    printf("Erreichbare Gesamtpunkte: %.2lf", ges);
    printf("\nTyp: ");
    scanf(" %c", &typ); //Eingabe von dem Testtyp

    if(typ=='z'){ //Zwischentest
        printf("\nPunkte: ");
            scanf("%lf", &ein);
            if(ein<0 || ein>10){
                printf("\nungueltiger Bereich: min 0.00, max 10.00");
            }else{
                zt+=ein; //Falls gueltig zt-Punkte speichern (von der Eingabe)
                ges+=10; //Gesamtmoegliche Punkte erhoehen (10 pro Zwischentest)
            }
        }else if(typ=='a'){
        if(at!=0){ //Verhindert die erneute Eingabe von einem Abschlusstest, da schon einer vorhanden ist
            printf("\nnur ein Abschlusstest erlaubt");
        }else{
            printf("\nPunkte: ");
            scanf("%lf", &ein);
            if(ein<0 || ein>70){
                printf("\nungueltiger Bereich: min 0.00, max 70.00");
            }else{
                at+=ein;  //Falls gueltig at-Punkte speichern (von der Eingabe)
                ges+=70; //Gesamtmoegliche Punkte erhoehen (70 pro Abschlusstest)
            }
        }

    }else if(typ=='u'){
        printf("\nPunkte: ");
            scanf("%lf", &ein);
            if(ein<0 || ein>0.5){
                printf("\nungueltiger Bereich: min 0.00, max 0.50");
            }else{
                ue+=ein; //Falls gueltig ue-Punkte speichern (von der Eingabe)
                if(ue>=10){ //Uebungen koennen nicht mehr als 10 Punkte extra zum Zeugnis beitragen
                    ue=10; //Wird fix auf 10 gesetzt falls man mehr Punkte erzielt als 10
                }          //!!Punkte aus den Übungsbeispielen bei der maximal erreichbaren Gesamtpunktzahl nicht berücksichtigt!!
                }
            }
    }while(typ!='='); //Abbruchbedingung

    int note = getNote(at,zt,ue,ges); //Funktionuebergabe um Note zu errechnen

    if(at+zt==0){ //falls keine Abschluss- bzw. Zwischentest abgeschlossen wurde gibt es keine Gesamtpunkte (UE zaehlen nicht)
         printf("\nGesamtpunkte absolut: 0.00\n");
    }else if(note!=5){ //Falls Note positiv -> ue-Punkte dazu zaehlen
    printf("\nGesamtpunkte absolut: %.2lf\n", at+zt+ue);
    }else{
          printf("\nGesamtpunkte absolut: %.2lf\n", at+zt); //Note negativ -> Punkte ausgeben ohne ue-Punkte

    }
    if(ges!=0){
        if(note==5){
            printf("Gesamtpunkte %%: %.2lf %% \n", ((at+zt)/ges*100)); //Note negativ -> Prozent ausgeben ohne ue-Punkte
        }else{
       printf("Gesamtpunkte %%: %.2lf %% \n", ((at+zt+ue)/ges*100));//Note positiv -> Prozent ausgeben mit ue-Punkte
        }
       printf("Note: %d", note); //Note ausgeben
    }else{
    printf("Gesamtpunkte %%: 0.00 %% \n"); //Falls es keine Gesamtpunkte gibt -> alles 0 ausgeben
    printf("Note: 0");
    }
    return 0;
}

int getNote(double zt, double at, double ue, double ges){
    if(at+zt+ue == 0){
        return 0;
    }
 if(((at+zt)/ges*100)<55){
     return 5;
 }
 double pro =(ue+at+zt)/ges*100;

 if(pro>89){
     return 1;
 }else if(pro >= 78){
     return 2;
 }else if(pro >=67){
     return 3;
 }else{
     return 4;
 }
 return 0;
}
