#include <iostream>

/*******************************Déclarations des variables globales****************************/
int resultat=0;
int rep=0;
int op=0;
int reputil=0;
int total=0;
int nbquestions=0;
/****************************Déclarations des prototypes*****************************************/
void generateQuestion();
void generateReponse(int);
void saisieReponse();
void checkreponse();
void calculTotal();
int generateRandom(int);
void chooseNbQuestions();

/*******************************Définition des fonctions********************************************/



/************************Génération d'une question****************************************************/

void generateQuestion() {

        int nombre1 = generateRandom(100); //nombre entre 1 et 100 avec affectation sur variable locale
        int nombre2 = generateRandom(100); //nombre entre 1 et 100 avec affectation sur variable locale

        /***********************propose une question aléatoire************************************/
        op = generateRandom(3); //nombre entre 1 et 3
        switch (op) {
            case 1:
                printf("%d+%d=?\n", nombre1, nombre2);
                resultat = nombre1 + nombre2;
                break;
            case 2:
                printf("%d-%d=?\n", nombre1, nombre2);
                resultat = nombre1 - nombre2;
                break;
            case 3:
                printf("%d*%d=?\n", nombre1, nombre2);
                resultat = nombre1 * nombre2;
                break;

        }

}

/********************************genération d'un nombre aleatoire de  1 à la fin*************************/

 int generateRandom( int fin) {


    return  rand()%fin+1;
}

/*****************choix par l'utilisateur du nombre de questions********************/

void chooseNbQuestions() {

    printf("A combien de questions voulez-vous répondre\n");
    scanf("%d",&nbquestions);

}

/****************Génération des réponses en param le nombre de réponse****************/

void generateReponse(int nbreponses) {
    int j = 0;
    for(int i=0;i<nbreponses;i++) {

        if (i == 0)
            j =generateRandom(2); //definit sur quel numéro de question sera positionnée la bonne réponse
        if (i == j) {
            rep = resultat;

        } else {
            if (op == 3)
                rep = generateRandom(10000);
            else
                rep = generateRandom(200);
        }
        printf("%d\n", rep);

    }
}

/********************saisie de la réponse******************************************************/

void saisieReponse() {


    printf("Veuillez choisir une réponse\n");
    scanf("%d",&reputil);

}

/******************vérification de la réponse***************************************************/
void checkreponse() {

    if(reputil== resultat)
    {
        printf("Bonne réponse\n");
        total++;
    }
    else
    {
        printf("La Réponse est fausse la bonne réponse est %d\n",resultat);
    }

}
/**********************************calcul du total*************************************************/

void calculTotal() {
    printf("Votre total de bonne réponse est de %d sur %d\nMerci d'avoir jouer",total,nbquestions);
}

/***********************************main************************************************************/
int main() {
    srand(time(NULL));
    chooseNbQuestions();
    for(int i;i<nbquestions;i++) {
        generateQuestion();
        generateReponse(3);
        saisieReponse();
        checkreponse();
    }
    calculTotal();
    return 0;
}
