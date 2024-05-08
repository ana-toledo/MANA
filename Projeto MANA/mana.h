#ifndef MANA_H
#define MANA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// Inclui biblioteca dependendo do sistema
#ifdef _WIN64
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif


int STATUS;

#define STATUS_RACE_SELECT 1
#define STATUS_RACE_HELP 2
#define STATUS_RACE_DEFINED 3
#define STATUS_SUBRACE_SELECT 4
#define STATUS_SUBRACE_HELP 5
#define STATUS_SUBRACE_DEFINED 6

#define STATUS_CLASS_SELECT 7
#define STATUS_CLASS_HELP 8
#define STATUS_CLASS_DEFINED 9

#define STATUS_HAB_SELECT 10
#define STATUS_HAB_HELP 11
#define STATUS_HAB_DEFINED 12

#define STATUS_ANT_SELECT 13
#define STATUS_ANT_HELP 14
#define STATUS_ANT_DEFINED 15

// A estrutura abaixo define caracter�sticas b�sicas de cada ra�a
typedef struct{
    int n; // Numero inteiro usado como codigo para representar a classe
    char *nome; // Nome da ra�a int age; 
    int tend1; // Tendencia mais comum, em que 1 Leal, 2 Caos, 3 Qualquer;
    int tend2; // Tendencia maias comum, em que 1 Bom, 2 Mau, 3 Qualquer;
    int h; // Categoria de altura, em que 1 Pequeno, 2 Medio, 3 Grande
    int sub; // �ndice da subra�a, caso tiver
    float des; // Deslocamento permitido em metros
    char *idioma;
} Raca;

// Estrutura que define as caracteristicas basicas de cada classe
typedef struct {
    int n; //inteiro que representa o �ndice de sele��o de cada classe
    char *nome; //nome da classe
    int dvida; //dado de vida
    char *prof_res; //proficiencias em teste de resistencia
} Classe;

// Estrutura das habilidades
typedef struct {
    int n; // �ndice da habilidade
    char *nome; // nome da habilidade
    int pontos;
    int mod; // qual o modificador proporcionado pela habilidade
}   Habilidade;

// A struct abaixo define caracter�sticas b�sicas de antecedentes
typedef struct{
    int n; // Inteiro usado como c�digo para representar o antecedente
    char* nome; // Nome do antecedente
} Anteced;

// As Fun��o retornam as structs definidas
Raca define_race(int n, int sr);
Classe define_class (int n);
Habilidade define_hab(Raca R, int v, int n); // v - valor, n - idx das hab a receber o valor
Anteced define_background(int n);

// Ra�as
int print_race_select();
void print_race_help_menu();
void print_race_help(int n);
//Sub ra�as
int print_sub_race_select(int n);
void print_sub_race_help(int n, int sr);
void print_sub_race_help_menu(int n);
// Classes
int print_class_select_menu(); 
void print_class_help_menu();
void print_class_help (int n);
// Habilidades
char print_hab_select_menu(); 
void print_hab_help_menu();
int rand_hab(); 
void ordena_hab(Habilidade *H);
int checa_indice(int *h); 
// Antecedentes
int print_bg_select_menu();
void print_bg_help(int n);
void print_bg_help_menu(void);
// Nomes
void choose_name(Raca R, char *nome);

// Fun��o principal da raca
Raca rmain(void);
// Fun��o principal de classe
Classe cmain(void);
// Fun��o principal de habilidade
void hmain(Raca raca, Habilidade *H);
// Fun��o principal dos antecedentes
Anteced amain(void);

// Fun��o que limpa o terminal
void clear_terminal(); 
// Fun��o sleep multiplataforma
void sleep_function(int n); 
// Fun��o visual
void rolar_dados();

// Fun��es free
void free_race(Raca R);
void free_class(Classe C);
void free_ant(Anteced A);
void free_name(char nomes[][20]);

// Fun��es FILE
void create_file(Raca R, Classe C, Habilidade *H, Anteced A, FILE *arq, char *player_name, char *chara_name, int HP);
void print_prof_in_file(FILE *arq, Classe C);
void print_equip_in_file(FILE *arq, Classe C, Anteced A);
void print_capacity_in_file(FILE* arq, Raca R, Classe C);

// Fun��o que printa o menu inicial e a tela final
void print_start_menu(char *file_name, char *player_name);
void print_end();



// A Fun��o retorna uma struct de Raca
Raca define_race(int n, int sr){ // indice da e indice da subraca
    setlocale(LC_ALL, "portuguese-brazilian");
    Raca R;
    R.n = n;
    if(R.n==1 && sr==1){
        R.nome = (char*)malloc(16*sizeof(char));
        R.nome = "An�o da Colina";
        R.h = 2;
        R.tend1 = 1;
        R.tend2 = 1;
        R.des = 7.5;
        R.sub = 1;
        R.idioma = (char*) malloc(9*sizeof(char));
        R.idioma = " e An�o";
    }
    else if(R.n==1 && sr==2){
        R.nome = (char*)malloc(18*sizeof(char));
        R.nome = "An�o da Montanha";
        R.h = 2;
        R.tend1 = 1;
        R.tend2 = 1;
        R.des = 7.5;
        R.sub = 2;
        R.idioma = (char*) malloc(9*sizeof(char));
        R.idioma = " e An�o";
    }
    else if(R.n==2 && sr==3){
        R.nome = (char*)malloc(10*sizeof(char));
        R.nome = "Alto Elfo";
        R.h = 2;
        R.tend1 = 2;
        R.tend2 = 1;
        R.des = 9;
        R.sub = 3;
        R.idioma = (char*) malloc(42*sizeof(char));
        R.idioma = ", �lfico e mais um idioma de sua escolha";
    }
    else if(R.n==2 && sr==4){
        R.nome = (char*)malloc(17*sizeof(char));
        R.nome = "Elfo da Floresta";
        R.h = 2;
        R.tend1 = 2;
        R.tend2 = 1;
        R.des = 9;
        R.sub = 4;
        R.idioma = (char*) malloc(11*sizeof(char));
        R.idioma = " e �lfico";
    }else if(R.n==3 && sr==5){
        R.nome = (char*)malloc(20*sizeof(char));
        R.nome = "Halfling-P�s-Leves";
        R.h = 1;
        R.tend1 = 1;
        R.tend2 = 1;
        R.des = 7.5;
        R.sub = 5;
        R.idioma = (char*) malloc(12*sizeof(char));
        R.idioma = " e Halfling";
    }
    else if(R.n==3 && sr==6){
        R.nome = (char*)malloc(17*sizeof(char));
        R.nome = "Halfling Robusto";
        R.h = 1;
        R.tend1 = 1;
        R.tend2 = 1;
        R.des = 7.5;
        R.sub = 6;
        R.idioma = (char*) malloc(12*sizeof(char));
        R.idioma = " e Halfling";
    }else if(R.n==4){
        R.nome = (char*)malloc(7*sizeof(char));
        R.nome = "Humano";
        R.h = 2;
        R.tend1 = 3;
        R.tend2 = 3;
        R.des = 9;
        R.idioma = (char*) malloc(33*sizeof(char));
        R.idioma = " e mais um idioma de sua escolha";
    }else if(R.n==5){
        R.nome = (char*)malloc(10*sizeof(char));
        R.nome = "Draconato";
        R.h = 2;
        R.tend1 = 3;
        R.tend2 = 3;
        R.des = 9;
        R.idioma = (char*) malloc(14*sizeof(char));
        R.idioma = " e Drac�nico";
    }else if(R.n==6){
        R.nome = (char*)malloc(6*sizeof(char));
        R.nome = "Gnomo";
        R.h = 1;
        R.tend1 = 3;
        R.tend2 = 1;
        R.des = 7.5;
        R.idioma = (char*) malloc(9*sizeof(char));
        R.idioma = " e Gnomo";
    }else if(R.n==7){
        R.nome = (char*)malloc(10*sizeof(char));
        R.nome = "Meio-elfo";
        R.h = 2;
        R.tend1 = 2;
        R.tend2 = 3;
        R.des = 9;
        R.idioma = (char*) malloc(20*sizeof(char));
        R.idioma = ", �lfico e mais um";
    }else if(R.n==8){
        R.nome = (char*)malloc(9*sizeof(char));
        R.nome = "Meio-orc";
        R.h = 2;
        R.tend1 = 2;
        R.tend2 = 2;
        R.des = 9;
        R.idioma = (char*) malloc(7*sizeof(char));
        R.idioma = " e Orc";
    }else if(R.n==9){
        R.nome = (char*)malloc(9*sizeof(char));
        R.nome = "Tiefling";
        R.h = 2;
        R.tend1 = 2;
        R.tend2 = 3;
        R.des = 9;
        R.idioma = (char*) malloc(12*sizeof(char));
        R.idioma = " e Infernal";
    }

    return R;
}

// Fun��o que apresenta os nomes
void choose_name(Raca R, char *nome) { // dando erro
    char names[12][20];
    int g; // genero
    int eh; // escolha exclusiva dos humanos
    int fav; //tamanho da string e nome favorito
    int l, c; // linha e coluna da matriz

    // Aloca dinamicamente o espa�o gasto pelos nomes

    printf("\n============== Parte Final ================\n\n");
    printf("Seu personagem est� quase pronto para suas aventuras. Falta apenas receber um nome que o represente!\n");
    printf("Em Dungeons and Dragons, o nome de um personagem est� ligado � sua ra�a, sendo passado de gera��o em gera��o.\n");
    printf("O seu personagem ser� do sexo: ");
    printf("\n\n1) Masculino\n2) Feminino\n\n");
    printf("Insira o respectivo �ndice: ");
    scanf("%d", &g);

    // De acordo com a ra�a e g�nero, uma lista de poss�veis nomes diferentes vai aparecer
    switch(R.n) {
        case 1:
            if(g == 1) {
                strcpy(names[0], "Adrik");
                strcpy(names[1],  "Baern");
                strcpy(names[2],  "Brottor");
                strcpy(names[3],  "Bruenor");
                strcpy(names[4],  "Dain");
                strcpy(names[5],  "Delg");
                strcpy(names[6],  "Eberk");
                strcpy(names[7],  "Fargrim");
                strcpy(names[8], "Flint");
                strcpy(names[9],  "Kildrak");
                strcpy(names[10], "Oskar");
                strcpy(names[11], "Ulfgar");
            }
            else if(g == 2) {
                strcpy(names[0],  "Amber");
                strcpy(names[1],  "Bardryn");
                strcpy(names[2],  "Diesa");
                strcpy(names[3],  "Eldeth");
                strcpy(names[4],  "Falkrunn");
                strcpy(names[5],  "Gurdis");
                strcpy(names[6],  "Hlin");
                strcpy(names[7], "Kristryd");
                strcpy(names[8],  "Liftrasa");
                strcpy(names[9],  "Riswynn");
                strcpy(names[10], "Sannl");
                strcpy(names[11], "Torgga"); 
            }
        break;    
        case 2:
            if(g == 1) {
                strcpy(names[0], "Adran");
                strcpy(names[1], "Aelar");
                strcpy(names[2], "Berrian");
                strcpy(names[3], "Carric");
                strcpy(names[4], "Enialis");
                strcpy(names[5], "Galinndan");
                strcpy(names[6], "Heian");
                strcpy(names[7], "Immeral");
                strcpy(names[8], "Ivellios");
                strcpy(names[9], "Paelias");
                strcpy(names[10], "Thamior");
                strcpy(names[11], "Theren"); 
            }   
            else if(g == 2) {
                strcpy(names[0], "Adrie");
                strcpy(names[1], "Althea");
                strcpy(names[2], "Biriel");
                strcpy(names[3], "Caelynn");
                strcpy(names[4], "Enna");
                strcpy(names[5], "Jelenneth");
                strcpy(names[6], "Keyleth");
                strcpy(names[7], "Lia");
                strcpy(names[8], "Sariel");
                strcpy(names[9], "Thia");
                strcpy(names[10], "Valanthe");
                strcpy(names[11], "Xanaphia"); 
            }
        break;
        case 3:
            if(g == 1) {
                strcpy(names[0], "Alton");
                strcpy(names[1], "Cade");
                strcpy(names[2], "Corrin");
                strcpy(names[3], "Eldon");
                strcpy(names[4], "Finnan");
                strcpy(names[5], "Garret");
                strcpy(names[6], "Lindal");
                strcpy(names[7], "Lyle");
                strcpy(names[8], "Milo");
                strcpy(names[9], "Perrin");
                strcpy(names[10], "Reed");
                strcpy(names[11], "Wellby"); 
            }   
            else if(g == 2) {
                strcpy(names[0], "Andry");
                strcpy(names[1], "Bree");
                strcpy(names[2], "Callie");
                strcpy(names[3], "Cora");
                strcpy(names[4], "Kithri");
                strcpy(names[5], "Lidda");
                strcpy(names[6], "Merla");
                strcpy(names[7], "Seraphina");
                strcpy(names[8], "Shaena");
                strcpy(names[9], "Trym");
                strcpy(names[10], "Vani");
                strcpy(names[11], "Verna"); 
            }
        break;
        case 4:
            if(g == 1) {
                strcpy(names[0], "Aseir");
                strcpy(names[1], "Blath");
                strcpy(names[2], "Bor");
                strcpy(names[3], "Faugar");
                strcpy(names[4], "Geth");
                strcpy(names[5], "Haseid");
                strcpy(names[6], "Pieron");
                strcpy(names[7], "Ramas");
                strcpy(names[8], "Romero");
                strcpy(names[9], "Stedd");
                strcpy(names[10], "Stor");
                strcpy(names[11], "Orel"); 
            }   
            else if(g == 2) {
                strcpy(names[0], "Atala");
                strcpy(names[1], "Bai");
                strcpy(names[2], "Cefrey");
                strcpy(names[3], "Esvele");
                strcpy(names[4], "Kara");
                strcpy(names[5], "Mei");
                strcpy(names[6], "Navarra");
                strcpy(names[7], "Nephis");
                strcpy(names[8], "Seipora");
                strcpy(names[9], "Selise");
                strcpy(names[10], "Thola");
                strcpy(names[11], "Zolis"); 
            }
        break;
        case 5:
            if(g == 1) {
                strcpy(names[0], "Arjhan");
                strcpy(names[1], "Balasar");
                strcpy(names[2], "Donaar");
                strcpy(names[3], "Ghesh");
                strcpy(names[4], "Kriv");
                strcpy(names[5], "Medrash");
                strcpy(names[6], "Padjed");
                strcpy(names[7], "Rhogar");
                strcpy(names[8], "Shamash");
                strcpy(names[9], "Shedinn");
                strcpy(names[10], "Tarhun");
                strcpy(names[11], "Torinn"); 
            }   
            else if(g == 2) {
                strcpy(names[0], "Akra");
                strcpy(names[1], "Biri");
                strcpy(names[2], "Farideh");
                strcpy(names[3], "Flavilar");
                strcpy(names[4], "Jheri");
                strcpy(names[5], "Kava");
                strcpy(names[6], "Mishann");
                strcpy(names[7], "Nala");
                strcpy(names[8], "Raiann");
                strcpy(names[9], "Sora");
                strcpy(names[10], "Thava");
                strcpy(names[11], "Uadjit"); 
            }
        break;
        case 6:
            if(g == 1) {
                strcpy(names[0], "Alvyn");
                strcpy(names[1], "Brocc");
                strcpy(names[2], "Dimble");
                strcpy(names[3], "Eldon");
                strcpy(names[4], "Erky");
                strcpy(names[5], "Forkin");
                strcpy(names[6], "Gimble");
                strcpy(names[7], "Kellen");
                strcpy(names[8], "Orryn");
                strcpy(names[9], "Seebo");
                strcpy(names[10], "Warryn");
                strcpy(names[11], "Wrenn"); 
            }   
            else if(g == 2) {
                strcpy(names[0], "Breena");
                strcpy(names[1], "Carlin");
                strcpy(names[2], "Donella");
                strcpy(names[3], "Ella");
                strcpy(names[4], "Ellywick");
                strcpy(names[5], "Lilli");
                strcpy(names[6], "Nyx");
                strcpy(names[7], "Orla");
                strcpy(names[8], "Roywyn");
                strcpy(names[9], "Shamil");
                strcpy(names[10], "Tana");
                strcpy(names[11], "Zanna"); 
            }
        break;
        case 7:
            if(g == 1) {
                strcpy(names[0], "Adran");
                strcpy(names[1], "Aelar");
                strcpy(names[2], "Berrian");
                strcpy(names[3], "Carric");
                strcpy(names[4], "Enialis");
                strcpy(names[5], "Galinndan");
                strcpy(names[6], "Heian");
                strcpy(names[7], "Immeral");
                strcpy(names[8], "Ivellios");
                strcpy(names[9], "Paelias");
                strcpy(names[10], "Thamior");
                strcpy(names[11], "Theren"); 
            }   
            else if(g == 2) {
                strcpy(names[0], "Adrie");
                strcpy(names[1], "Althea");
                strcpy(names[2], "Biriel");
                strcpy(names[3], "Caelynn");
                strcpy(names[4], "Enna");
                strcpy(names[5], "Jelenneth");
                strcpy(names[6], "Keyleth");
                strcpy(names[7], "Lia");
                strcpy(names[8], "Sariel");
                strcpy(names[9], "Thia");
                strcpy(names[10], "Valanthe");
                strcpy(names[11], "Xanaphia"); 
            }
        break;
        case 8: 
            if(g == 1) {
                strcpy(names[0], "Dench");
                strcpy(names[1], "Feng");
                strcpy(names[2], "Gell");
                strcpy(names[3], "Henk");
                strcpy(names[4], "Holg");
                strcpy(names[5], "Imsh");
                strcpy(names[6], "Keth");
                strcpy(names[7], "Krusk");
                strcpy(names[8], "Mhurren");
                strcpy(names[9], "Ront");
                strcpy(names[10], "Shump");
                strcpy(names[11], "Thokk"); 
            } 
            else if(g == 2) {
                strcpy(names[0], "Baggi");
                strcpy(names[1], "Emen");
                strcpy(names[2], "Engong");
                strcpy(names[3], "Kansif");
                strcpy(names[4], "Myev");
                strcpy(names[5], "Neega");
                strcpy(names[6], "Ovak");
                strcpy(names[7], "Ownka");
                strcpy(names[8], "Shauta");
                strcpy(names[9], "Sutha");
                strcpy(names[10], "Volen");
                strcpy(names[11], "Yevelda"); 
            }
        break;
        case 9:
            if(g == 1) {
                strcpy(names[0], "Akmenos");
                strcpy(names[1], "Amnon");
                strcpy(names[2], "Damakos");
                strcpy(names[3], "Ekemon");
                strcpy(names[4], "Kairon");
                strcpy(names[5], "Leucis");
                strcpy(names[6], "Melech");
                strcpy(names[7], "Mordai");
                strcpy(names[8], "Morthos");
                strcpy(names[9], "Pelaios");
                strcpy(names[10], "Skamos");
                strcpy(names[11], "Therai"); 
            }   
            else if(g == 2) {
                strcpy(names[0], "Akta");
                strcpy(names[1], "Anakis");
                strcpy(names[2], "Bryseis");
                strcpy(names[3], "Criella");
                strcpy(names[4], "Damaia");
                strcpy(names[5], "Ea");
                strcpy(names[6], "Kallista");
                strcpy(names[7], "Lerissa");
                strcpy(names[8], "Makaria");
                strcpy(names[9], "Nemeia");
                strcpy(names[10], "Orianna");
                strcpy(names[11], "Phelaia"); 
            }
        break;  
    }

    if(R.n == 4) {
        printf("Como voc� � um humano, sinta-se livre para escolher um nome de sua prefer�ncia.\nDigite '1' se deseja digitar um nome, ou digite '2' caso queira escolher da lista de op��es: ");
        scanf("%d%*c", &eh); //escaneia a escolha
        if(eh == 1) {
            printf("Seu nome ser�: ");
            scanf("%[^\n]", nome);
            printf("\n�tima escolha, %s\n!", nome);
        }
        else {
            printf("Nomes dispon�veis para escolha:\n");
            for(l=0; l<12; l++) {
                c = 0;
                printf("%d) ", l+1);
                while(names[l][c] != '\0') {
                    printf("%c", names[l][c]);
                    c++;
            }
                printf("\n");
            }
            printf("Digite o �ndice do seu nome favorito para selecion�-lo: ");
            scanf("%d%*c", &fav);
            strcpy(nome, names[fav-1]);
            printf("\n�tima escolha, %s!\n", nome);
        }
    }
    else {
        printf("\nNomes dispon�veis para escolha:\n");
        for(l=0; l<12; l++) {
            c = 0;
            printf("%d) ", l+1);
            while(names[l][c] != '\0') {
                printf("%c", names[l][c]);
                c++;
            }
            printf("\n");
        }
        printf("\nDigite o �ndice do seu nome favorito para selecion�-lo: ");
        scanf("%d%*c", &fav);
        strcpy(nome, names[fav-1]);
        printf("\n�tima escolha, %s!\n", nome);
    }
    printf("Aperte ENTER para finalizar\n");
    getchar();
    clear_terminal();
}

// A fun��o abaixo printa o menu de escolhas de ra�as
int print_race_select(){
    int escolha;
    clear_terminal();
    setlocale(LC_ALL, "portuguese-brazilian");
    printf("\n=========== Escolhendo a Ra�a de D&D =============\n\n");
    printf("Vamos come�ar escolhendo a ra�a do seu personagem!\nEssa ser� a esp�cie dele, que pode variar de um simples humano a seres m�gicos como elfos e halflings.\n");
    printf("Ela n�o s� afeta seus valores de habilidade e tra�os raciais, mas tamb�m fornece sugest�es para a constru��o da hist�ria do seu personagem.\n");
    printf("Selecione uma das ra�as abaixo digitando o seu respectivo n�mero. Caso n�o tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada uma.\n\n");
    printf("1) An�o\n");
    printf("2) Elfo\n");
    printf("3) Halfling\n");
    printf("4) Humano\n");
    printf("5) Draconato\n");
    printf("6) Gnomo\n");
    printf("7) Meio-elfo\n");
    printf("8) Meio-orc\n");
    printf("9) Tiefling\n");
    printf("10) Ajuda\n");
    printf("\n");
    printf("Op��o selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inv�lida, acontecer� um loop de scanfs
    while(escolha < 1 || escolha > 11) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 11) break;
    }
    if(escolha < 10) {
        STATUS = STATUS_RACE_DEFINED;
    }
    clear_terminal();
    return escolha;
}

// A fun��o abaixo printa o menu de escolhas de ajuda das ra�as
void print_race_help_menu(){
    int escolha;
    setlocale(LC_ALL, "portuguese-brazilian");
    printf("\nSobre qual ra�a deseja saber mais?\n\n");
    printf("1) An�o\n");
    printf("2) Elfo\n");
    printf("3) Halfling\n");
    printf("4) Humano\n");
    printf("5) Draconato\n");
    printf("6) Gnomo\n");
    printf("7) Meio-elfo\n");
    printf("8) Meio-orc\n");
    printf("9) Tiefling\n");
    printf("10) Voltar\n");
    printf("\n"); 
    printf("Saber mais sobre: ");
    scanf("%d%*c", &escolha);
    // Loop caso a escolha seja inv�lida
    while(escolha < 1 || escolha > 10) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 10) break;
    } 
    if(escolha == 10) {
        STATUS = STATUS_RACE_SELECT;
        clear_terminal();
        return;
    }
    clear_terminal();
    print_race_help(escolha);
}

// A fun��o abaixo recebe um id de ra�a n e printa sua frase de ajuda.
void print_race_help(int n){
    setlocale(LC_ALL, "portuguese-brazilian");
    if(n==1) printf("An�es s�o seres leais e que prezam pelo bem de seus cl�s e tradi��es. S�o �timos mineradores e guerreiros e conseguem usar uma variedade de ferramentas como ningu�m!\n");
    else if(n==2) printf("Elfos s�o graciosos, m�gicos, belos, elegantes e ca�ticos. Geralmente vivem em torres brilhantes no meio de lindas florestas.\nS�o muito habilidosos com magia, valorizam a natureza e podem chegar a viver 750 anos.\n");
    else if(n==3) printf("Halflings s�o pequenos, girando em torno de 90cm de altura, e discretos. Tentam se afastar de conflitos e d�o muito valor a um lar pac�fico e alegre. Esses exploradores s�o af�veis e r�pidos.\n");
    else if(n==4) printf("Humanos s�o... Humanos como n�s! S�o conhecidos por serem ambiciosos e flex�veis. N�o h� um padr�o para humanos como h� para as outras ra�as, sinta-se livre para se aventurar no que quiser.\n");
    else if(n==5) printf("Draconatos s�o orgulhosos descendentes de drag�es, apesar de terem uma forma humanoide. Um draconato se dedica totalmente ao seu cl� e aos seus deuses.\n");
    else if(n==6) printf("Gnomos s�o hiperativos, engenhoso, pequenos e extremamente divertidos. Enxergam a vida com uma paix�o admir�vel, s�o curiosos e fariam coisas perigos�ssimas por joias brilhantes.\nVoc� pode escolher cuspir fogo, gelo, veneno etc de acordo com o ancestral drac�nico que escolher\n");
    else if(n==7) printf("Meio-elfos s�o incomuns e solit�rios. N�o se sentem acolhidos em meio aos humanos e muito menos em meio aos elfos.\nAdoram viajar e se aproveitam de seu carisma nato aonde quer que v�o, mas geralmente s� apreciam a companhia de outros meio-elfos.\n");
    else if(n==8) printf("Meio-orcs s�o altos, intensos e muito fortes. Costumam viver em tribos orcs, mas podem viver entre os humanos sem problemas. Resolvem muitos problemas com os punhos.\n");
    else if(n==9) printf("Tieflings s�o descendentes de humanos que cometeram um grande pecado e pagam por isso. Com chifres, caldas e dentes pontudos, tieflings s�o alvos de insultos em todo lugar.\nDificilmente fazem amigos, mas valorizam muito quem os d� um voto de confian�a.\n");
    printf("\n");
    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
}

// A fun��o abaixo printa o menu de escolhas de subra�as
int print_sub_race_select(int n){
    int escolha, sub;
    setlocale(LC_ALL, "portuguese-brazilian");
    clear_terminal();
    printf("\nA ra�a escolhida possui sub-ra�as. Escolha uma delas para o seu personagem!\nCaso n�o tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada sub-ra�a.\n\n");
        if(n==1){
            printf("1) An�o da colina\n");
            printf("2) An�o da montanha\n");
            printf("3) Ajuda\n");
        }

        else if(n==2){
            printf("1) Alto elfo\n");
            printf("2) Elfo da floresta\n");
            printf("3) Ajuda\n");
        }
        else if(n==3){
            printf("1) Halfling p�s-leves\n");
            printf("2) Halfling robusto\n");
            printf("3) Ajuda\n");
        }

    printf("\n");
    printf("Op��o selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inv�lida, acontecer� um loop de scanfs
    while(escolha < 1 || escolha > 3) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 4) break;
    }
    if(escolha < 3) {
        STATUS = STATUS_SUBRACE_DEFINED;
        if(n==1 && escolha==1) sub = 1;
        else if(n==1 && escolha==2) sub = 2;
        else if(n==2 && escolha==1) sub = 3;
        else if(n==2 && escolha==2) sub = 4;
        else if(n==3 && escolha==1) sub = 5;
        else if(n==3 && escolha==2) sub = 6;
    }
    else if(escolha == 3) {
        STATUS = STATUS_SUBRACE_HELP;
        sub = 3;
    }
    clear_terminal();
    return sub;
}

// A Fun��o printa o menu de ajuda das subra�as
void print_sub_race_help_menu(int n) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha, sub;
    printf("\nSobre qual sub-ra�a deseja saber mais?\n\n");
        if(n==1){
            printf("1) An�o da colina\n");
            printf("2) An�o da montanha\n");
            printf("3) Voltar\n");
        }

        else if(n==2){
            printf("1) Alto elfo\n");
            printf("2) Elfo da floresta\n");
            printf("3) Voltar\n");
        }
        else if(n==3){
            printf("1) Halfling p�s leves\n");
            printf("2) Halfling robusto\n");
            printf("3) Voltar\n");
        }
    printf("\n");
    printf("Op��o selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inv�lida, acontecer� um loop de scanfs
    while(escolha < 1 || escolha > 3) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 4) break;
    }
    if(escolha < 3) {
        if(n==1 && escolha==1) sub = 1;
        else if(n==1 && escolha==2) sub = 2;
        else if(n==2 && escolha==1) sub = 3;
        else if(n==2 && escolha==2) sub = 4;
        else if(n==3 && escolha==1) sub = 5;
        else if(n==3 && escolha==2) sub = 6;
    }
    else if(escolha == 3) {
        STATUS = STATUS_RACE_SELECT;
        return;
    }
    clear_terminal();
    print_sub_race_help(n, sub);
}

// A funcao abaixo recebe um id de sub-ra�a sr e printa sua frase de ajuda.
void print_sub_race_help(int n, int sr){
    setlocale(LC_ALL, "portuguese-brazilian");
    if(n==1){
        if(sr==1){
            printf("An�es da colina possuem os sentidos agu�ados, inclusive o sexto sentido, e se adaptam muito bem �s mais diversas situa��es.\n");
        }
        else if(sr==2){
            printf("An�es da montanha s�o fortes e resistentes por serem acostumados � vida em terrenos dificeis.\n");
        }
    }
    else if(n==2){
        if(sr==3){
            printf("Altos elfos possuem um dom�nio de magia b�sico e uma mente afiada. Podem ser arrogantes e egoc�ntricos ou mais amig�veis.\nAl�m disso, s�o muito habilidosos com espadas e arcos.\n");

        }
        else if(sr==4){
            printf("Elfos da floresta possuem os sentidos e intui��o agu�ados, ent�o podem ser um pouco desconfiados.\nAl�m disso, conhecem bem suas florestas nativas e s�o habilidosos com espadas e arcos.\n");
        }
    }
    else if(n==3){
        if(sr==5){
            printf("Halflings p�s-leves s�o simp�ticos e gostam de conhecer novos lugares ao lado de seus companheiros, sejam eles halflings ou n�o.\nAl�m disso, conseguem se esconder facilmente em qualquer ambiente.\n");

        }
        else if(sr==6){
            printf("Halflings robustos s�o resistentes a danos de veneno e honram o nome que levam.\n");
        }
    }
    printf("\n");
    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
}

/*
PAINEL DE SUBRACAS
Anoes da colina - 1
Anoes da montanha - 2
Altos elfos - 3
Elfos da Floresta - 4
Haflings p�s leves - 5
Haflings robustos - 6
*/

// Fun��o que define a classe escolhida
Classe define_class (int n) {
    setlocale(LC_ALL, "portuguese-brazilian");
    Classe C;
    C.n = n;
    switch(n) {
        case 1:
            C.nome = (char*) calloc(9, sizeof(char)); 
            C.nome = "B�rbaro"; 
            C.dvida = 12;
            C.prof_res = (char*) calloc(24, sizeof(char));
            C.prof_res = "For�a & Constitui��o";
            break;
        case 2:
            C.nome = (char*) calloc(6, sizeof(char));
            C.nome = "Bardo";
            C.dvida = 8;
            C.prof_res = (char*) calloc(19, sizeof(char));
            C.prof_res = "Destreza & Carisma";
            break;
        case 3:
            C.nome = (char*) calloc(6, sizeof(char));
            C.nome = "Bruxo";
            C.dvida = 8;
            C.prof_res = (char*) calloc(20, sizeof(char));
            C.prof_res = "Sabedoria & Carisma";
            break;
        case 4:
            C.nome = (char*) calloc(9, sizeof(char));
            C.nome = "Cl�rigo";
            C.dvida = 8;
            C.prof_res = (char*) calloc(20, sizeof(char));
            C.prof_res = "Sabedoria & Carisma";
            break;
        case 5:
            C.nome = (char*) calloc(7, sizeof(char));
            C.nome = "Druida";
            C.dvida = 8;
            C.prof_res = (char*) calloc(26, sizeof(char));
            C.prof_res = "Intelig�ncia & Sabedoria";
            break;
        case 6:
            C.nome = (char*) calloc(11, sizeof(char));
            C.nome = "Feiticeiro";
            C.dvida = 6;
            C.prof_res = (char*) calloc(25, sizeof(char));
            C.prof_res = "Constitui��o & Carisma";
            break;
        case 7:
            C.nome = (char*) calloc(24, sizeof(char));
            C.nome = "Guerreiro";
            C.dvida = 10;
            C.prof_res = (char*) calloc(25, sizeof(char));
            C.prof_res = "For�a & Constitui��o";
            break;
        case 8:
            C.nome = (char*) calloc(7, sizeof(char));
            C.nome = "Ladino";
            C.dvida = 8;
            C.prof_res = (char*) calloc(25, sizeof(char));
            C.prof_res = "Destreza & Intelig�ncia";
            break;
        case 9:
            C.nome = (char*) calloc(5, sizeof(char));
            C.nome = "Mago";
            C.dvida = 6;
            C.prof_res = (char*) calloc(26, sizeof(char));
            C.prof_res = "Intelig�ncia & Sabedoria";
            break;
        case 10:
            C.nome = (char*) calloc(6, sizeof(char));
            C.nome = "Monge";
            C.dvida = 8;
            C.prof_res = (char*) calloc(18, sizeof(char));
            C.prof_res = "For�a & Destreza";
            break;
        case 11:
            C.nome = (char*) calloc(9, sizeof(char));
            C.nome = "Paladino";
            C.dvida = 10;
            C.prof_res = (char*) calloc(20, sizeof(char));
            C.prof_res = "Sabedoria & Carisma";
            break;
        case 12:
            C.nome = (char*) calloc(12, sizeof(char));
            C.nome = "Patrulheiro";
            C.dvida = 10;
            C.prof_res = (char*) calloc(18, sizeof(char));
            C.prof_res = "For�a & Destreza";
            break;
    }
    return C;
}

// Fun��o que printa o menu de sele��o
int print_class_select_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha = 0;
    clear_terminal();
    printf("\n=========== Escolhendo a Classe de D&D =============\n\n");
    printf("Em Dungeons & Dragons, as classes s�o conjuntos de habilidades e caracter�sticas que determinam o papel e o estilo de jogo de um personagem.\n");
    printf("Selecione uma das classes abaixo digitando o seu respectivo n�mero.\n");
    printf("Caso n�o tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada uma.\n\n");
    printf("1) B�rbaro\n");
    printf("2) Bardo\n");
    printf("3) Bruxo\n");
    printf("4) Cl�rigo\n");
    printf("5) Druida\n");
    printf("6) Feiticeiro\n");
    printf("7) Guerreiro\n");
    printf("8) Ladino\n");
    printf("9) Mago\n");
    printf("10) Monge\n");
    printf("11) Paladino\n");
    printf("12) Patrulheiro\n");
    printf("13) Ajuda\n");
    printf("\n");
    printf("Op��o selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inv�lida, acontecer� um loop de scanfs
    while(escolha < 1 || escolha > 13) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 14) break;
    }
    if(escolha < 13) {
        STATUS = STATUS_CLASS_DEFINED;
    }
    clear_terminal();
    return escolha;
}

// Fun��o que printa o menu de ajuda
void print_class_help_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    printf("\nSobre qual classe deseja saber mais?\n\n");
    printf("1) B�rbaro\n");
    printf("2) Bardo\n");
    printf("3) Bruxo\n");
    printf("4) Cl�rigo\n");
    printf("5) Druida\n");
    printf("6) Feiticeiro\n");
    printf("7) Guerreiro\n");
    printf("8) Ladino\n");
    printf("9) Mago\n");
    printf("10) Monge\n");
    printf("11) Paladino\n");
    printf("12) Patrulheiro\n");
    printf("13) Voltar\n"); 
    printf("\n"); 
    printf("Saber mais sobre: ");
    scanf("%d%*c", &escolha);
    // Loop caso a escolha seja inv�lida
    while(escolha < 1 || escolha > 13) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 14) break;
    } 
    if(escolha == 13) {
        STATUS = STATUS_CLASS_SELECT;
        clear_terminal();
        return;
    }
    clear_terminal();
    print_class_help(escolha);
}

// Fun��o que descreve a classe pedida
void print_class_help (int n) { 
    setlocale(LC_ALL, "portuguese-brazilian");
    Classe C;
    C.n = n;
    switch(C.n) {
        case 1:
        printf("B�rbaros s�o combatentes brutais e selvagens que podem entrar em f�ria durante uma batalha.\nA f�ria permite que um b�rbaro sofra menos e cause mais dano ao seu advers�rio.\n");
        printf("Dica: A For�a de um b�rbaro � a sua habilidade mais importante.\n");
        break;
        case 2:
        printf("Bardos s�o seres m�sticos inspiradores que possuem poderes que ecoam a m�sica da cria��o.\nSuas habilidades s�o �teis tanto a dist�ncia, quanto em combates corpo � corpo.\n");
        printf("Dica: O Carisma de um bardo � a sua habilidade mais importante.\n");
        break;
        case 3:
        printf("Bruxos s�o conjuradores cuja magia e derivada de um pacto com alguma entidade.\nEst�o dispostos a tudo para ter conhecimento e poder.\n");
        printf("Dica: O Carisma de um bruxo � a sua habilidade mais importante.\n");
        break;
        case 4:
        printf("Cl�rigos s�o conjuradores que recebem magia atrav�s de preces a divindade a qual veneram.\nSuas magias tendem a inspirar, curar e proteger seus aliados.\n");
        printf("Dica: A Sabedoria de um cl�rigo � a sua habilidade mais importante.\n");
        break;
        case 5:
        printf("Druidas s�o conjuradores de magia intimamente ligados com as forcas elementais da natureza.\nS�o capazes de adotarem formas animais.\n");
        printf("Dica: A Sabedoria de um druida � a sua habilidade mais importante.\n");
        break;
        case 6:
        printf("Feiticeiros s�o conjuradores que possuem magia latente advinda de um dom ou linhagem.\nSuas magias podem ser usadas para causar danos a inimigos, conceder habilidades e a defender a si ou a aliados.\n");
        printf("Dica: O Carisma de um feiticeiro � a sua habilidade mais importante.\n");
        break;
        case 7:
        printf("Guerreiros s�o mestres do combate e peritos em uma vasta gama de armas e armaduras.\nUsam de seus conhecimentos em t�cnicas de combate para lutar.\n");
        printf("Dica: A For�a e a Destreza de um guerreiro s�o as suas habilidades mais importantes.\n");
        break;
        case 8:
        printf("Ladinos s�o trapaceiros que usam de furtividade e ast�cia para sobrepujar os obst�culos e inimigos.\nN�o s�o combatentes t�o poderosos, mas seus meios sorrateiros os igualam a outras classes.\n");
        printf("Dica: A Destreza de um ladino � a sua habilidade mais importante.\n");
        break;
        case 9:
        printf("Magos s�o conjuradores estudiosos, capazes de manipular as estruturas da realidade.\nPossuem a maior quantidade de magia entre todas as classes.\n");
        printf("Dica: A Intelig�ncia de um mago � a sua habilidade mais importante.\n");
        break;
        case 10:
        printf("Monges s�o mestres das artes marciais e utilizam do poder corporal para atingir a perfei��o f�sica e espiritual.\nEstudam a si mesmos e conhecem a energia m�stica presente em cada um.\n");
        printf("Dica: A Destreza e a Sabedoria de um monge s�o as suas habilidades mais importantes.\n");
        break;
        case 11:
        printf("Paladinos s�o guerreiros divinos vinculados a um juramento sagrado.\nCombinam t�cnicas de combate a alguma habilidade de conjura��o.\n");
        printf("Dica: A For�a e o Carisma de um paladino s�o as suas habilidades mais importantes.\n");
        break;
        case 12:
        printf("Patrulheiros s�o guerreiros que utilizam de poderio marcial e magia natural para combater amea�as nos limites da civiliza��o.\n");
        printf("Dica: A Destreza e a Sabedoria de um patrulheiro s�o as suas habilidades mais importantes.\n");
        break;
    }
    printf("\n");
    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
}

// Fun��o que retorna a struct de Habilidade
Habilidade define_hab(Raca R, int v, int n) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int mod, ar = 0; // modificador e atributo racial
    Habilidade H;
    H.pontos = v;
    H.n = n;

    if(n == 1) {
        if(R.n == 5 || R.n == 8 || R.sub == 2) ar = 2; // Draconato, meio-orc ou an�o da montanha
        else if(R.n == 4) ar = 1; // Humano
    }
    else if(n == 2) {
        if(R.n == 2 || R.n == 3) ar = 2; // Elfo ou Halfing
        else if(R.n == 4) ar = 1; // Humano
    }
    else if(n == 3) {
        if(R.n == 1) ar = 2; // An�o
        else if(R.n == 4 || R.n == 8 || R.sub == 6) ar = 1; // Humano, meio-orc e haflings robustos
    }
    else if(n == 4) {
        if(R.n == 6) ar = 2; // Gnomo
        else if(R.n == 4 || R.n == 9 || R.sub == 3) ar = 1; // Humano, Tielfing, Alto Elfo
    }
    else if(n == 5) {
        if(R.n == 4 || R.sub == 4 || R.sub == 1) ar = 1; // Humano, elfo da floresta e an�o da colina
    }
    else if(n == 6) {
        if(R.n == 7 || R.n == 9) ar = 2; // Meio-elfo e Tiefling
        else if(R.n == 4 || R.n == 5 || R.sub == 5) ar = 1; // Humano, Draconato e haflings p�s leves
    }

    mod = (v-10+ar)/2; // opera��o para descobrir o valor do modificador
    
    switch(H.n) {
        case 1:
            H.nome = (char *) malloc(6*sizeof(char));
            strcpy(H.nome, "For�a");
            H.mod = mod;
            break;
        case 2:
            H.nome = (char *) malloc(9*sizeof(char));
            H.nome = "Destreza";
            H.mod = mod;
            break;
        case 3:
            H.nome = (char *) malloc(15*sizeof(char));
            H.nome = "Constitui��o";
            H.mod = mod;
            break;
        case 4:
            H.nome = (char *) malloc(14*sizeof(char));
            H.nome = "Intelig�ncia";
            H.mod = mod;
            break;
        case 5:
            H.nome = (char *) malloc(10*sizeof(char));
            H.nome = "Sabedoria";
            H.mod = mod;
            break;
        case 6:
            H.nome = (char *) malloc(8*sizeof(char));
            H.nome = "Carisma";
            H.mod = mod;
            break;
        default:
            printf("Op��o inv�lida.\n");
    }

    return H;
}

// Fun��o que deixa as habilidades na ordem certa
void ordena_hab(Habilidade *H) {
    Habilidade aux;
    int i, j;
    for(i=0; i<5; i++) {
        for(j=i+1; j<6; j++) { // bubble sort
            if(H[i].n > H[j].n) {
                aux = H[i];
                H[i] = H[j];
                H[j] = aux;
            }
        }
    }
}

// A Fun��o o menu com os �ndices de cada habilidade 
char print_hab_select_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    char opcao;

    printf("\n=========== Escolhendo as Habilidades de D&D =============\n\n");
    printf("�ndices:\n");
    printf("1) For�a\n");
    printf("2) Destreza\n");
    printf("3) Constitui��o\n");
    printf("4) Intelig�ncia\n");
    printf("5) Sabedoria\n");
    printf("6) Carisma\n\n");

    printf("Deseja saber mais sobre cada atributo? Digite S para sim e outro caracter para n�o.\n$ ");
    scanf("%c%*c", &opcao);

    return opcao;
}

// A Fun��o printa mais informa��es das habilidades
void print_hab_help_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    printf("\n============ Informa��es Adicionais ================\n\n");
    printf("Os atributos s�o as caracter�sticas b�sicas de um personagem, que retratam suas capacidades e defici�ncias e influenciam nas demais caracter�sticas que possui.\n");
    printf("Muitas das jogadas realizadas em uma aventura ter�o como base um dos seis atributos do personagem:\n\n");
    printf("1) A For�a define a pot�ncia muscular e f�sica, e esse atributo pode ser utilizado para jogadas que envolvam escalar, saltar e nadar.\nA For�a tamb�m influencia na capacidade de carga do personagem.\n\n");
    printf("2) A Destreza representa agilidade, a mira e a capacidade de evitar um golpe.\nEsse atributo pode ser utilizado para jogadas que envolvam equil�brio, uso de cordas ou outros objetos que envolvam precis�o.\n\n");
    printf("3) A Constitui��o refere-se ao vigor, � sa�de do personagem, e � capacidade de resistir a efeitos como afogamento e intoxica��o.\n� importante para todos, independente da classe.\n\n");
    printf("4) A Intelig�ncia mede a capacidade de aprendizagem e a capacidade de lan�ar magias arcanas.\nA Intelig�ncia tamb�m pode ser utilizado em jogadas de avalia��o de itens, decifrar escritas e para saber se o personagem det�m algum tipo espec�fico de conhecimento.\n\n");
    printf("5) A Sabedoria � o conhecimento, o senso comum, o discernimento e a capacidade de lan�ar magias divinas.\nEla pode ser utilizada em jogadas de cura e sentir motiva��o.\n\n");
    printf("6) O Carisma determina o quanto um personagem � socialmente atrativo, amig�vel, charmoso e a habilidade de afastar mortos-vivos.\nEsse atributo pode ser utilizado para jogadas de blefe, diplomacia, disfarce, reunir informa��es e performance.\n\n\n");

    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
    STATUS = STATUS_HAB_SELECT;
}

// A Fun��o abaixo aleatoriza os valores que poder�o ser usados nas habilidades
int rand_hab() {
    // A fun��o vai receber 4 valores de um d6 aleat�rios em um vetor
    // Depois vai calcular qual a maior soma de 3 entre os 4 
    int stotal = 0, smaior = 0, menor;
    int dado[4];
    int i; 

    srand(time(NULL));

    for(i=0; i<4; i++) dado[i] = 0; // limpa os valores

    // Gera 4 valores aleat�rios
    for(i=0; i<4; i++) {
        dado[i] = 1 + rand() % 6;
    }
    // Calcula a soma dos 3 maiores valores
    stotal = dado[0] + dado[1] + dado[2] + dado[3];
    menor = dado[0];
    for(i=0; i<4; i++) {
        if(dado[i] < menor) {
            menor = dado[i];
        }
    }
    smaior = stotal - menor;

    return smaior;
}

//Fun��o que checa se os �ndices fornecidos no scanf para compor as habilidades s�o diferentes
int checa_indice(int *h) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int i, j, flag = 0; // se forem iguais, a flag recebe 1

    for(i=0; i<5; i++) {
        for(j=i+1; j<6; j++) {
            if(h[i] == h[j]) flag = 1;
        }
    }

    return flag;
}

// Fun��o para o sleep
void sleep_function(int n) {
    #ifdef _WIN64
    Sleep(n); // n = 500 � meio segundo
    #elif __linux__
    usleep(n*1000);
    #endif
}

// Aparece enquanto os valores ainda est�o sendo gerados, fun��o visual
void rolar_dados() { 
    #ifdef _WIN64
    sleep_function(1600);
    printf("\n.");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf("R"); 
    sleep_function(500);
    printf("o");
    sleep_function(500);
    printf("l");
    sleep_function(500);
    printf("a");
    sleep_function(500);
    printf("n");
    sleep_function(500);
    printf("d");
    sleep_function(500);
    printf("o");
    sleep_function(500);
    printf(" ");
    sleep_function(500);
    printf("o");
    sleep_function(500);
    printf("s");
    sleep_function(500);
    printf(" ");
    sleep_function(500);
    printf("d");
    sleep_function(500);
    printf("a");
    sleep_function(500);
    printf("d");
    sleep_function(500);
    printf("o");
    sleep_function(500);
    printf("s");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf(".");
    sleep_function(500);
    printf(".\n");  
    #elif __linux__
    printf("\nRolando os dados... Por favor, aguarde um momento.\n");
    #endif
}

// A fun��o define o antecedente
Anteced define_background(int n){
    setlocale(LC_ALL, "portuguese-brazilian");
    Anteced A;
    A.n = n;
    if(A.n==1){
        A.nome = (char*)malloc(9*sizeof(char));
        A.nome = "Ac�lito";
    }else if(A.n==2){
        A.nome = (char*)malloc(19*sizeof(char));
        A.nome = "Artes�o de Guilda";
    }else if(A.n==3){
        A.nome = (char*)malloc(8*sizeof(char));
        A.nome = "Artista";
    }else if(A.n==4){
        A.nome = (char*)malloc(11*sizeof(char));
        A.nome = "Charlat�o";
    }else if(A.n==5){
        A.nome = (char*)malloc(10*sizeof(char));
        A.nome = "Criminoso";
    }else if(A.n==6){
        A.nome = (char*)malloc(8*sizeof(char));
        A.nome = "Eremita";
    }else if(A.n==7){
        A.nome = (char*)malloc(11*sizeof(char));
        A.nome = "Forasteiro";
    }else if(A.n==8){
        A.nome = (char*)malloc(15*sizeof(char));
        A.nome = "Her�i do Povo";
    }else if(A.n==9){
        A.nome = (char*)malloc(11*sizeof(char));
        A.nome = "Marinheiro";
    }else if(A.n==10){
        A.nome = (char*)malloc(6*sizeof(char));
        A.nome = "Nobre";
    }else if(A.n==11){
        A.nome = (char*)malloc(8*sizeof(char));
        A.nome = "�rf�o";
    }else if(A.n==12){
        A.nome = (char*)malloc(7*sizeof(char));
        A.nome = "S�bio";
    }else if(A.n==13){
        A.nome = (char*)malloc(8*sizeof(char));
        A.nome = "Soldado";
    }
    return A;
}

// A fun��o imprime o menu de sele��o de antecedente
int print_bg_select_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    clear_terminal();
    int escolha;
    printf("\n=========== Escolhendo o Antecedente de D&D =============\n\n");
    printf("Toda hist�ria tem um in�cio. Os antecedentes de seus personagens revela de onde eles vieram, como se tornaram aventureiros e seu lugar no mundo.\n");
    printf("Selecione um dos antecedentes abaixo digitando seu respectivo n�mero.\n");
    printf("Caso n�o tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada um.\n\n");
    printf("1) Ac�lito\n");
    printf("2) Artes�o de Guilda\n");
    printf("3) Artista\n");
    printf("4) Charlat�o\n");
    printf("5) Criminoso\n");
    printf("6) Eremita\n");
    printf("7) Forasteiro\n");
    printf("8) Her�i do Povo\n");
    printf("9) Marinheiro\n");
    printf("10) Nobre\n");
    printf("11) �rf�o\n");
    printf("12) S�bio\n");
    printf("13) Soldado\n");
    printf("14) Ajuda\n");
    printf("\n");
    printf("Op��o selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inv�lida, acontecer� um loop de scanfs
    while(escolha < 1 || escolha > 14) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 15) break;
    }
    if(escolha < 14) {
        STATUS = STATUS_ANT_DEFINED;
    }   
    clear_terminal();
    return escolha;
}

// A fun��o abaixo recebe um id de antecedente n e printa sua frase de ajuda
void print_bg_help(int n){
    setlocale(LC_ALL, "portuguese-brazilian");
    if(n==1) printf("Voc� servia a uma ou mais divindades e tem h�bitos relacionados a isso.\nDica: Isso n�o significa que voc� � um cl�rigo, porque � poss�vel servir um deus e n�o ser capaz de canalizar seu poder.\n");
    else if(n==2) printf("Voc� era um artes�o bem estabelecido no mercado que cresceu com a ajuda de uma guilda. Voc� consegue criar itens e usar ferramentas.\n");
    else if(n==3) printf("Voc� se apresentava em frente a grandes p�blicos e sabe entreter audi�ncias com acrobacias e atua��o.\n");
    else if(n==4) printf("Voc� vendia produtos duvidosos, para n�o dizer completamente enganosos. Gra�as a isso, sabe convencer pessoas das coisas mais improv�veis.\n");
    else if(n==5) printf("Voc� desprezava as leis e vivia no mundo do crime, onde aprendeu a agir furtivamente e escapar de situa��es ruins.\n");
    else if(n==6) printf("Voc� vivia absolutamente isolado da sociedade em uma calmaria sem igual.\nEsse tempo em reclus�o pode ter te dado respostas reveladoras e conhecimento inegual�vel ou te deixado maluco - voc� decide!\n");
    else if(n==7) printf("Voc� cresceu longe das grandes civiliza��es, est� acostumado com ambientes mais selvagens e sabe se virar em locais novos melhor do que a maioria.\n");
    else if(n==8) printf("Voc� era uma pessoa comum at� cometer um grandioso ato e ser reconhecido por seu povo. Tem as habilidades de um trabalhador e a reputa��o de um her�i.\n");
    else if(n==9) printf("Voc� passou boa parte de sua vida em um navio em alto mar. Conhece embarca��es de forma mais t�cnica e tem uma boa no��o de dire��o.\n");
    else if(n==10) printf("Voc� nasceu em ber�o de ouro. Carrega consigo o peso de um nome influente e em troca exerce uma autoridade que poucos podem desafiar.\n");
    else if(n==11) printf("Voc� cresceu pobre e sem fam�lia em meio �s ruas. Seus instintos de sobreviv�ncia s�o apurados, mas a carga emocional � dif�cil de carregar.\n");
    else if(n==12) printf("Voc� se dedicou a estudar intensamente um campo do conhecimento e tem um hist�rico acad�mico invej�vel.\n");
    else if(n==13) printf("Voc� lutou e treinou durante a maior parte de sua vida e tem experi�ncia com o sofrimento da guerra.\n");
    
    printf("\n");
    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
}

// A fun��o abaixo printa o menu de escolhas de ajuda de antecedentes
void print_bg_help_menu(void){
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    printf("\nSobre qual antecedente deseja saber mais?\n\n");
    printf("1) Ac�lito\n");
    printf("2) Artes�o de Guilda\n");
    printf("3) Artista\n");
    printf("4) Charlat�o\n");
    printf("5) Criminoso\n");
    printf("6) Eremita\n");
    printf("7) Forasteiro\n");
    printf("8) Her�i do Povo\n");
    printf("9) Marinheiro\n");
    printf("10) Nobre\n");
    printf("11) �rf�o\n");
    printf("12) S�bio\n");
    printf("13) Soldado\n");
    printf("14) Voltar\n");
    printf("\n");
    printf("Op��o selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inv�lida, acontecer� um loop de scanfs
    while(escolha < 1 || escolha > 14) {
        printf("Op��o inv�lida. Por favor, digite um n�mero v�lido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 14) break;
    }
    if(escolha == 14) {
        STATUS = STATUS_ANT_SELECT;
        clear_terminal();
        return;
    }
    clear_terminal();
    print_bg_help(escolha);
}

// A fun��o abaixo limpa a struct de Ra�a
void free_race(Raca R) {
    R.n = R.sub = 0;
    free(R.nome);
    R.tend1 = R.tend2 = R.h = R.des =  0;
    free(R.idioma);
    // Limpa todas as vari�veis
}

//A fun��o abaixo limpa a struct de Classe
void free_class(Classe C) {
    C.n = 0;
    free(C.nome);
    free(C.prof_res);
    C.dvida = 0;
    // Limpa todas as vari�veis
}

// A fun��o abaixo limpa a struct de Antecedente
void free_ant(Anteced A) {
    A.n = 0;
    free(A.nome);
    // Limpa todas as vari�veis
}

// A fun��o abaixo limpa a struct de nome
void free_name(char nomes[][20]) {
    int l, c; //linhas e colunas
    for(l=0; l<12; l++) {
        for(c=0; c<20; c++) {
            memset(nomes[l], 0, 20);
        }
    }
}

// Fun��o que printa o menu inicial
void print_start_menu(char *file_name, char *player_name) {
    setlocale(LC_ALL, "portuguese-brazilian");
    clear_terminal();
    printf("\n========== Bem-vindo(a) a M.A.N.A. ==============\n");
    printf("Pronto para criar sua ficha de personagem de Dungeons and Dragons?\n\n");
    printf("Antes de tudo, qual o nome do jogador? ");
    scanf("%[^\n]%*c", player_name);
    printf("E o nome da sua nova ficha? (Aten��o: N�o use o mesmo nome para mais de uma ficha!)\n");
    scanf("%[^\n]%*c", file_name);
    printf("\nA cria��o de um personagem pode parecer complicada demais para quem n�o conhece o sistema, mas n�o se preocupe, te guiarei por tudo que precisa saber!\n");
    printf("\nAs etapas para compor uma ficha s�o:\n");
    printf("1) Escolha da Ra�a\n");
    printf("2) Escolha da Classe\n");
    printf("3) Defini��o das Habilidades\n");
    printf("4) Escolha de um Antecedente\n");
    printf("5) Defini��o de um Nome\n\n");
    printf("Aperte ENTER para come�ar!\n");
    getchar();
}

// Fun��o principal da raca
Raca rmain(void) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolhaR, escolhaS; // escolha de raca e subraca
    Raca R;
    STATUS = STATUS_RACE_SELECT;

    while(STATUS == STATUS_RACE_SELECT) { // Enquanto n�o decidir a ra�a, o menu vai ser printado
        escolhaR = print_race_select();
        if(escolhaR == 10) STATUS = STATUS_RACE_HELP; // Se escolher a op��o de ajuda, o status muda
        while(STATUS == STATUS_RACE_HELP) { // Esse menu ficar� sendo printado at� que a op��o de 'voltar' seja selecionada
            print_race_help_menu(); // Essa fun��o chama a que descreve no final
        }
        if(STATUS == STATUS_RACE_DEFINED) {
            if(escolhaR==1 || escolhaR==2 || escolhaR==3) { // Caso a escolha tenha subra�as
                STATUS = STATUS_SUBRACE_SELECT; // Muda o status
                while(STATUS == STATUS_SUBRACE_SELECT) {
                    escolhaS = print_sub_race_select(escolhaR); // Baseado na ra�a, uma escolha de subra�a pode ser feita
                }
                while(STATUS == STATUS_SUBRACE_HELP) { // Se a op��o selecionada for de ajuda, o while come�a
                    print_sub_race_help_menu(escolhaR);
                }
                if(STATUS == STATUS_SUBRACE_DEFINED) R = define_race(escolhaR, escolhaS); // Se for definida, a fun��o 'define' � chamada
            }
            else R = define_race(escolhaR, 0); // Caso a ra�a escolhida n�o tenha subra�as, ela � definida diretamente
        }
    }
    printf("Ra�a '%s' selecionada com sucesso!\nAperte ENTER para continuar.\n", R.nome);
    getchar();
    clear_terminal();
    return R;
}

// Fun��o principal de classe
Classe cmain(void) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    Classe C;
    STATUS = STATUS_CLASS_SELECT;
    while(STATUS == STATUS_CLASS_SELECT) { // Enquanto o status n�o mudar da sele��o, o print_class_select continuar� rodando
        escolha = print_class_select_menu();
        if(escolha == 13) STATUS = STATUS_CLASS_HELP; // Se a ajuda for selecionada, o status muda para help
        while(STATUS == STATUS_CLASS_HELP) {
            print_class_help_menu(); // Aqui, se a pessoa voltar para a tela de escolha, o status muda pra SELECT e o if N�o acontece
        }
        if(STATUS == STATUS_CLASS_DEFINED) { // Se ao voltar para a escolha e ela for definitiva, o status muda para DEFINED_CLASS e o if acontece
            C = define_class(escolha);
        }
        // Se o if acontecer, o status n�o ser� mais de select e ent�o o loop quebra
    }
    printf("Classe '%s' selecionada com sucesso!\nAperte ENTER para continuar.\n", C.nome);
    getchar();
    return C;
}

// Fun��o principal de habilidade
void hmain(Raca raca, Habilidade *H) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int indice[6], *valores = NULL;
    char escolha;
    int i, checagem;

    STATUS = STATUS_HAB_SELECT;
    clear_terminal();

    valores = (int *) calloc (6, sizeof(int));

    while(STATUS == STATUS_HAB_SELECT) {
        escolha = print_hab_select_menu();
        if(escolha == 'S' || escolha == 's') {
            STATUS = STATUS_HAB_HELP; // O status muda para help no final da ajuda, quando isso ocorrer, a tela de sele��o volta
            while(STATUS == STATUS_HAB_HELP) { // Se ajuda for selecionada, o status muda e a fun��o que printa a ajuda aparece
                clear_terminal();
                print_hab_help_menu();     
            }
        }
        else {
            STATUS = STATUS_HAB_DEFINED;
            printf("\nVamos come�ar ent�o!\n");
            printf("Inicialmente, s�o gerados 6 (seis) valores de forma aleat�ria, assim como descrito no Livro do Jogador.\n");
            rolar_dados(); // Fun��o visual para aparecer enquanto os numeros s�o gerados

            for(i=0; i<6; i++) {
                valores[i] = rand_hab(); // Fun��o que randomiza um valor
                sleep_function(900); // Necess�rio para o n�mero na randomiza��o n�o se repetir
            }

            printf("\nOs pontos a serem distribu�dos entre seus atributos s�o:\n");
            for(i=0; i<6; i++) {
                printf("%d ", valores[i]);
            }
            printf("\n\n");

            while(1) {
                printf("Para quais habilidades voc� quer destinar cada um dos seus valores? Digite o respectivo �ndice a seguir:\n");
                for(i=0; i<6; i++) {
                    printf("O valor %d ser� usado na habilidade: ", valores[i]);
                    scanf("%d%*c", &indice[i]);
                    while(indice[i] < 1 || indice[i] > 6) {
                        printf("Op��o inv�lida. Por favor, digite novamente: ");
                        scanf("%d", &indice[i]);
                    }
                }
                checagem = checa_indice(indice); // Fun��o que checa se os �ndices s�o diferentes
                if(checagem == 1) { // Se houver �ndices iguais, uma mensagem de erro aparece e o loop de scanf continua
                    printf("\nErro no preenchimento dos �ndices. Por favor, tente novamente. Lembre-se de que cada valor recebe um �ndice diferente.\n\n");   
                }
                else break;
            }

            STATUS = STATUS_HAB_DEFINED;
        
            for(i=0; i<6; i++) {
                H[i] = define_hab(raca, valores[i], indice[i]); 
            }

            ordena_hab(H); // Ordena as habilidades por ordem crescente de �ndice
            printf("\n\nHabilidades definidas com sucesso!\nAperte ENTER para continuar.\n");
            getchar();
        }
    
    }
}

// Fun��o principal de antecedente
Anteced amain(void) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    Anteced A;
    STATUS = STATUS_ANT_SELECT;
    while(STATUS == STATUS_ANT_SELECT) { // Enquanto o status n�o mudar da sele��o, o print_ant_select continuar� rodando
        escolha = print_bg_select_menu();
        if(escolha == 14) STATUS = STATUS_ANT_HELP; // Se a ajuda for selecionada, o status muda para help
        while(STATUS == STATUS_ANT_HELP) {
            print_bg_help_menu(); // Aqui, se a pessoa voltar para a tela de escolha, o status muda pra SELECT e o if N�o acontece
        }
        if(STATUS == STATUS_ANT_DEFINED) { // Se ao voltar para a escolha e ela for definitiva, o status muda para ANT_DEFINED e o if acontece
            A = define_background(escolha);
        }
        // Se o if acontecer, o status n�o ser� mais de select e ent�o o loop quebra
    }
    printf("Antecedente '%s' selecionado com sucesso!\n", A.nome);
    printf("Aperte ENTER para continuar\n");
    getchar();
    clear_terminal();
    return A;

}


// Fun��o que limpa o terminal
void clear_terminal() {
    #ifdef _WIN64
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}

// Fun��o que imprime as profici�ncias em armaduras
void print_prof_in_file(FILE *arq, Classe C) {
    fprintf(arq, "Profici�ncia em:");
    if(C.n==1) fprintf(arq, "\n - Armaduras leves e m�dias, escudos, armas simples e marciais\n");
    else if(C.n==2) fprintf(arq, "\n - Armaduras leves, armas simples, bestas de m�o, espadas longas, rapieiras, espadas curtas\n");
    else if(C.n==3) fprintf(arq, "\n - Armaduras leves, armas simples\n");
    else if(C.n==4) fprintf(arq, "\n - Armaduras leves e m�dias, escudos, armas simples\n");
    else if(C.n==5) fprintf(arq, "\n - Armaduras leves e m�dias (N�o-met�licas), escudos (N�o-met�licos), clavas, adagas, dardos, azagaias, ma�as, bord�es, cimitarras, foices, fundas e lan�as\n");
    else if(C.n==6) fprintf(arq, "\n - Adagas, dardos, fundas, bord�es, bestas leves.\n");
    else if(C.n==7) fprintf(arq, "\n - Todas as armaduras, armas simples e marciais\n");
    else if(C.n==8) fprintf(arq, "\n - Armaduras leves, armas simples, bestas de m�o, espadas longas, rapieiras, espadas curtas\n");
    else if(C.n==9) fprintf(arq, "\n - Adagas, dardos, fundas, bast�es, bestas leves\n");
    else if(C.n==10) fprintf(arq, "\n - Armas simples, espadas curtas\n");
    else if(C.n==11) fprintf(arq, "\n - Todas as armaduras, escudos, armas simples e marciais\n");
    else if(C.n==12) fprintf(arq, "\n - Armaduras leves, escudos, armas simples e marciais\n");
}

// Fun��o que imprime os equipamentos na ficha
void print_equip_in_file(FILE *arq, Classe C, Anteced A) {
    fprintf(arq, "Equipamentos: ");
    // Equipamentos por Classe
    if(C.n==1) fprintf(arq, "\n - (a) um machado grande ou (b) qualquer arma marcial corpo-a-corpo\n - (a) dois machados de m�o ou (b) qualquer arma simples\n - Um pacote de aventureiro e quatro azagaias");
    else if(C.n==2) fprintf(arq, "\n - (a) uma rapieira, (b) uma espada longa ou (c) qualquer arma simples\n - (a) um pacote de diplomata ou (b) um pacote de artista\n - (a) um lute ou (b) qualquer outro instrumento musical\n - Armadura de couro e uma adaga\n");
    else if(C.n==3) fprintf(arq, "\n - (a) uma besta leve e 20 virotes ou (b) qualquer armasimples\n - (a) uma bolsa de componentes ou (b) um foco arcano\n - (a) um pacote de estudioso ou (b) um pacote deexplorador\n - Armadura de couro, qualquer arma simples e duas adagas\n");
    else if(C.n==4) fprintf(arq, "\n - (a) uma ma�a ou (b) um martelo de guerra (se for proficiente)\n - (a) brunea, (b) armadura de couro ou (c) cota de malha(se for proficiente)\n - (a) um besta leve e 20 virotes ou (b) qualquer arma simples\n - (a) um pacote de sacerdote ou (b) um pacote deaventureiro\n - Um escudo e um s�mbolo sagrado\n");
    else if(C.n==5) fprintf(arq, "\n - (a) um escudo de madeira ou (b) qualquer arma simples\n - (a) uma cimitarra ou (b) qualquer arma corpo-a-corpo simples\n - (a) um pacote de estudioso ou (b) um pacote de explorador\n - Armadura de couro, um pacote de aventureiro e um foco dru�dico\n");
    else if(C.n==6) fprintf(arq, "\n - (a) uma besta leve e 20 virotes ou (b) qualquer arma simples\n - (a) uma bolsa de componentes ou (b) um foco arcano\n - (a) um pacote de explorador ou (b) um pacote de aventureiro\n");
    else if(C.n==7) fprintf(arq, "\n - (a) cota de malha ou (b) gib�o de peles, arco longo e 20 flechas\n - (a) uma arma marcial e um escudo ou (b) duas armas marciais\n - (a) uma besta leve e 20 virotes ou (b) dois machados de arremesso\n - (a) uma pacote de aventureiro ou (b) um pacote de explorador\n");
    else if(C.n==8) fprintf(arq, "\n - (a) uma rapieira ou (b) uma espada longa\n - (a) um arco curto e uma aljava com 20 flechas ou (b)uma espada curta\n - (a) um pacote de assaltante ou (b) um pacote deaventureiro ou (c) um pacote de explorador\n - Armadura de couro, duas adagas e ferramentas de ladr�o\n");
    else if(C.n==9) fprintf(arq, "\n - (a) um bord�o ou (b) uma adaga\n - (a) uma bolsa de componentes ou (b) um foco arcano\n - (a) um pacote de estudioso ou (b) um pacote de explorador\n - Um grim�rio\n");
    else if(C.n==10) fprintf(arq, "\n - (a) uma espada curta ou (b) qualquer arma simples\n - (a) um pacote de explorador ou (b) um pacote de aventureiro\n - 10 dardos\n");
    else if(C.n==11) fprintf(arq, "\n - (a) uma arma marcial e um escudo ou (b) duas armas marciais\n - (a) cinco azagaias ou (b) qualquer arma simples corpo-a-corpo\n - (a) um pacote de sacerdote ou (b) um pacote de aventureiro\n - Cota de malha e um s�mbolo sagrado\n");
    else if(C.n==12) fprintf(arq, "\n - (a) camis�o de malha ou (b) armadura de couro\n - (a) duas espadas curtas ou (b) duas armas simples corpo-a-corpo\n - (a) um pacote de explorador ou (b) um pacote de aventureiro\n - Um arco longo e uma aljava com 20 flechas\n");

    // Equipamentos por Antecedente
    if(A.n==1) fprintf(arq, " - Um s�mbolo sagrado\n - Um livro de preces ou uma conta de ora��es\n - 5 varetas de incenso\n - Vestimentas\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 15 po\n");
    else if(A.n==2) fprintf(arq, " - Um conjunto de ferramentas de artes�o (� sua escolha)\n - Uma carta de apresenta��o da sua guilda\n - Um conjunto de roupas de viajante\n - Uma algibeira com 15 po\n");
    else if(A.n==3) fprintf(arq, " - Um instrumento musical (� sua escolha)\n - Um presente de um admirador\n - Um traje\n - Uma algibeira contendo 15 po\n");
    else if(A.n==4) fprintf(arq, " - Um conjunto de roupas finas\n - Um kit de disfarce\n - Ferramentas de trapa�a (� sua escolha)\n - Uma algibeira contendo 15po\n");
    else if(A.n==5) fprintf(arq, " - Um p� de cabra\n - Um conjunto de roupas escuras comuns com capuz\n - Uma algibeira contendo 15 po\n");
    else if(A.n==6) fprintf(arq, " - Um estojo de pergaminho cheio de notas dos seus estudos e ora��es\n - Um cobertor de inverno\n - Um conjunto de roupas comuns\n - Um kit de herbalismo\n - 5 po\n");
    else if(A.n==7) fprintf(arq, " - Um bord�o\n - Uma armadilha de ca�a\n - Um fetiche de um animal que voc� matou\n - Um conjunto de roupas de viajante\n - Uma algibeira contendo 10 po\n");
    else if(A.n==8) fprintf(arq, " - Um conjunto de ferramentas de artes�o (� sua escolha)\n - Uma p�\n - Um pote de ferro\n - Um conjunto de roupas comuns\n- Uma algibeira contendo 10 po\n");
    else if(A.n==9) fprintf(arq, " - Uma malagueta (clava)\n - 15 metros de corda de seda\n - Um amuleto da sorte como um p� de coelho ou uma pequena pedra com um furo no centro\n - Um conjunto de trajes comuns\n - Uma algibeira contendo 10 po\n");
    else if(A.n==10) fprintf(arq, " - Um conjunto de trajes finos\n - Um anel de sinete\n - Um pergaminho de linhagem\n - Uma algibeira contendo 25 po\n");
    else if(A.n==11) fprintf(arq, " - Uma faca pequena\n - Um mapa da cidade em que voc� cresceu\n - Um rato de estima��o\n - Um pequeno objeto para lembrar dos seus pais\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 10 po\n");
    else if(A.n==12) fprintf(arq, " - Um vidro de tinta escura\n - Uma pena\n - Uma faca pequena\n - Uma carta de um falecido colega perguntando a voc� algo que voc� nunca ter� a chance de responder\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 10 po\n");
    else if(A.n==13) fprintf(arq, " - Uma ins�gnia de patente\n - Um fetiche obtido de um inimigo ca�do (uma adaga, l�mina partida ou tira de estandarte)\n - Um conjunto de dados de osso ou baralho\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 10 po\n");
}

// Fun��o que imprime as capacidades das ra�as e classes na ficha
void print_capacity_in_file(FILE* arq, Raca R, Classe C){ 
    if(R.n!=4 || (C.n!=4 && C.n!=3 && C.n!=6 && C.n!=9))fprintf(arq, "\nCaracter�sticas:\n");
    if(R.n==1){
        fprintf(arq, "- Vis�o no escuro: Em at� 18 metros, voc� enxerga na penumbra como na luz plena e no escuro como na penumbra, mas n�o pode discernir cores.\n");
        fprintf(arq, "- Resili�ncia an�: Voc� tem vantagem ao resistir a veneno e dano de veneno.\n");
        fprintf(arq, "- Especializa��o em rochas: Voc� tem o dobro do seu valor de profici�ncia ao fazer um teste relacionado � trabalhos em pedra.\n");
        if(R.sub==1){
            fprintf(arq, "- Tenacidade an�: Voc� recebe um ponto de vida adicional ao subir de n�vel.\n");
        }
    }else if(R.n==2){
        fprintf(arq, "- Vis�o no escuro: Em at� 18 metros, voc� enxerga na penumbra como na luz plena e no escuro como na penumbra, mas n�o pode discernir cores.\n");
        fprintf(arq, "- Ancestral Fe�rico: Voc� tem vantagem ao resistir a ser enfeiti�ado e magias n�o podem coloc�-lo para dormir.\n");
        fprintf(arq, "- Transe: Voc� medita em vez de dormir e cada hora meditando equivale a duas horas de sono humano.\n");
        if(R.sub==4){
            fprintf(arq, "- M�scara da natureza: Voc� pode tentar se esconder mesmo que esteja apenas ligeiramente coberto por folhagem, neve e outras coisas naturais.\n");
        }
    }else if(R.n==3){
        fprintf(arq, "- Sortudo: Quando tirar 1 no dado ao atacar, usar uma habilidade ou resistir, voc� joga o dado de novo.\n");
        fprintf(arq, "- Bravura: Voc� tem vantagem ao resistir a ser amedrontado.\n");
        fprintf(arq, "- Agilidade halfling: Voc� pode atravessar o espa�o ocupado por uma criatura maior que voc�.\n");
        if(R.sub==5){
            fprintf(arq, "- Furtividade natural: Voc� pode tentar se esconder mesmo quando estiver apensar coberto por uma criatura de, no m�nimo, um tamanho a mais que voc�.\n");
        }else if(R.sub==6){
            fprintf(arq, "- Resili�ncia dos robustos: Voc� tem vantagem ao resistir a veneno e dano de veneno.\n");
        }
    }else if(R.n==5){
        fprintf(arq, "- Arma de sopro: Voc� pode expelir energia que causa 2d6 de dano quando o alvo n�o resiste (ou 1d6 quando resiste) de acordo com seu ancestral, mas s� pode fazer isso novamente ap�s descansar.\n");
        fprintf(arq, "- Ancestral drac�nico: Voc� pode escolher um tipo de drag�o para seu ancestral, o qual definir� o tipo de ataque e dano de sua arma de sopro. Consulte seu Mestre para decidir um ancestral apropriado.\n");
        fprintf(arq, "- Resist�ncia a dano: Voc� tem resist�ncia ao tipo de dano associado ao seu ancestral drac�nico.\n");
    }else if(R.n==6){
        fprintf(arq, "- Vis�o no escuro: Em at� 18 metros, voc� enxerga na penumbra como na luz plena e no escuro como na penumbra, mas n�o pode discernir cores.\n");
        fprintf(arq, "- Esperteza gn�mica: Voc� tem vantagem ao usar Intelig�ncia, Sabedoria ou Carisma para resistir a magia.\n");
    }else if(R.n==7){
        fprintf(arq, "- Vis�o no escuro: Em at� 18 metros, voc� enxerga na penumbra como na luz plena e no escuro como na penumbra, mas n�o pode discernir cores.\n");
        fprintf(arq, "- Ancestral Fe�rico: Voc� tem vantagem ao resistir a ser enfeiti�ado e magias n�o podem coloc�-lo para dormir.\n");
    }else if(R.n==8){
        fprintf(arq, "- Vis�o no escuro: Em at� 18 metros, voc� enxerga na penumbra como na luz plena e no escuro como na penumbra, mas n�o pode discernir cores.\n");
        fprintf(arq, "- Resist�ncia implac�vel: Se ficar com 0 de vida mas n�o for totalmente morto, pode voltar a ter 1 ponto de vida. Entretanto, n�o pode fazer isso de novo antes de ter um descanso longo.\n");
        fprintf(arq, "- Ataques selvagens: Quando acerta um cr�tico usando uma arma corpo a corpo, role um dado de dano extra e adicione seu resultado ao dano final.\n");
    }else if(R.n==9){
        fprintf(arq, "- Vis�o no escuro: Em at� 18 metros, voc� enxerga na penumbra como na luz plena e no escuro como na penumbra, mas n�o pode discernir cores.\n");
        fprintf(arq, "- Resist�ncia infernal: Voc� tem vantagem ao resistir a dano de fogo.\n");
    }
    if(C.n==1){
        fprintf(arq, "- F�ria: Voc� pode escolher entrar em f�ria como a��o b�nus durante o seu turno em um combate, mas n�o mais que duas vezes antes de ter um descanso longo. Caso n�o esteja vestindo uma armadura pesada,\n");
        fprintf(arq, "    Voc� tem vantagem em testes que usam For�a;\n");
        fprintf(arq, "    Se acertar um ataque corpo a corpo usando For�a, adicione 2 ao dano causado;\n");
        fprintf(arq, "    Voc� tem resist�ncia a dano de concuss�o, corte e perfura��o.\n");
        fprintf(arq, "  Esse efeito dura 1 minuto a menos que voc� caia inconsciente, n�o ataque nenhuma criatura hostil durante um turno, sofra dano ou gaste uma a��o b�nus para encerr�-lo.\n");
        fprintf(arq, "- Defesa sem armadura: Mesmo que n�o esteja vestindo armadura ou tenha apenas um escudo, sua Classe de Armadura � 10+Destreza+Constitui��o.\n");
    }else if(C.n==2){
        fprintf(arq, "- Inspira��o de Bardo: Voc� pode usar uma a��o b�nus para inspirar uma criatura que n�o seja voc� a no m�ximo 18 metros de dist�ncia durante o seu turno. Pelos pr�ximos 10 minutos, a criatura pode rolar 1d6 e adicionar esse resultado a um de seus testes. Quando ela faz isso, o efeito passa. A mesma criatura n�o pode ser inspirada outra vez antes do efeito acabar. Voc� pode usar sua inspira��o um n�mero de vezes igual ao seu Carisma antes de ter que descansar.\n");
    }else if(C.n==5){
        fprintf(arq, "- Dru�dico: Voc� conhece o idioma secreto dos druidas e consegue se comunicar nele e deixar mensagens escondidas.\n");
    }else if(C.n==7){
        fprintf(arq, "- Retomar o f�lego: Voc� pode usar uma a��o b�nus para recuperar pontos de vida durante o seu turno. O valor recuperado � 1d10+seu n�vel. Essa a��o n�o pode ser feita mais de uma vez sem descanso.\n");
    }else if(C.n==8){
        fprintf(arq, "- Especializa��o: Escolha duas de suas per�cias que seja proficiente, ou uma per�cia que seja proficiente e ferramentas de ladr�o, e seu b�nus em testes de habilidade com elas � dobrado.\n");
        fprintf(arq, "- Ataque Furtivo: Uma vez por turno, se acertar um ataque com uma arma de acuidade ou de dist�ncia em que voc� tinha vantagem, voc� pode adicionar 1d6 de dano.\n");
        fprintf(arq, "- G�ria de ladr�o: Voc� conhece dialetos secretos dos ladr�es e consegue se comunicar em c�digo e deixar mensagens escondidas. Entretanto, o tempo para transmitir uma mensagem usando g�rias de ladr�es � quatro vezes maior do que usando idiomas tradicionais.\n");
    }else if(C.n==10){
        fprintf(arq, "- Defesa sem armadura: Quando n�o estiver vestindo armadura nem usando escudo, sua Classe de Armadura � 10+Destreza+Sabedoria.\n");
        fprintf(arq, "- Artes Marciais: Enquanto estiver desarmado (ou empunhando uma arma de monge) e sem armadura ou escudo,\n");
        fprintf(arq, "    Voc� pode usar Destreza em vez de For�a ao atacar;\n");
        fprintf(arq, "    Voc� pode causar 1d4 de dano em vez do dano que causaria ao atacar;\n");
        fprintf(arq, "    Ap�s atacar, voc� pode fazer um ataque extra desarmado como a��o b�nus.\n");
    }else if(C.n==11){
        fprintf(arq, "- Sentido divino: Voc� pode usar uma a��o para expandir sua consci�ncia. At� o final do seu pr�ximo turno, numa �rea de 18 metros, voc� � capaz de detectar seres celestiais, corruptores ou mortos-vivos e seus tipos desde que n�o estejam em cobertural total; al�m de qualquer coisa consagrada ou conspurcada. Essa caracter�stica s� pode ser usada 1+Carisma vezes antes que voc� tenha que descansar.\n");
        fprintf(arq, "- Cura pelas m�os: Voc� tem um po�o de poder que guarda 5 pontos de vida que voc� pode usar para se curar e que s�o gastos quando usados. Um descanso longo restaura seu po�o. Voc� tamb�m pode usar esses pontos para restaurar os pontos de vida de outros seres ou curar uma doen�a ou veneno.\n");
    }else if(C.n==12){
        fprintf(arq, "- Inimigo favorito: Escolha um tipo de inimigo favorito. Voc� tem vantagem em testes para rastre�-los ou lembrar de informa��es sobre eles e aprende um idioma que seja falado por eles (se eles forem capazes de falar algum).\n");
        fprintf(arq, "- Explorador natural: Escolha um terreno favorito. Em testes de Intelig�ncia ou Sabedoria relacionados a ele, seu b�nus de profici�ncia � dobrado. Al�m disso, em viagens longas nesse terreno,\n");
        fprintf(arq, "    Sua viagem n�o � retardada por terreno dif�cil;\n");
        fprintf(arq, "    Seu grupo n�o se perde, a menos que por meios m�gicos;\n");
        fprintf(arq, "    Voc� se mant�m alerta ao perigo mesmo que esteja fazendo outra coisa enquanto viaja;\n");
        fprintf(arq, "    Voc� pode se mover furtivamente com um ritmo normal se estiver viajando sozinho;\n");
        fprintf(arq, "    Voc� encontra o dobro da comida que normalmente encontraria quando forrageia;\n");
        fprintf(arq, "    Quando rastrear criaturas, voc� descobre a quantidade exata delas, seus tamanhos e quanto tempo passaram na �rea.\n");
    }
}

// Fun��o que cria o arquivo txt
void create_file(Raca R, Classe C, Habilidade *H, Anteced A, FILE *arq, char *player_name, char *chara_name, int HP) {
    int i;
    fprintf(arq, "~ Dungeons and Dragons ~ Ficha \n\n");
    fprintf(arq, "Nome do Personagem: %s\n", chara_name); //erro
    fprintf(arq, "Classe: %s", C.nome);
    fprintf(arq, " | N�vel: 1\n");
    fprintf(arq, "Ra�a: %s\n", R.nome);
    if(R.tend1 == 1 && R.tend2 == 1) fprintf(arq, "Tend�ncia: Leal e Bom\n");
    else if(R.tend1 == 1 && R.tend2 == 2) fprintf(arq, "Tend�ncia: Leal e Mau\n");
    else if(R.tend1 == 1 && R.tend2 == 3) fprintf(arq, "Tend�ncia: Leal e Neutro\n");
    else if(R.tend1 == 2 && R.tend2 == 1) fprintf(arq, "Tend�ncia: Ca�tico e Bom\n");
    else if(R.tend1 == 2 && R.tend2 == 2) fprintf(arq, "Tend�ncia: Ca�tico e Mau\n");
    else if(R.tend1 == 2 && R.tend2 == 3) fprintf(arq, "Tend�ncia: Ca�tico e Neutro\n");
    else if(R.tend1 == 3 && R.tend2 == 1) fprintf(arq, "Tend�ncia: Neutro e Bom\n");
    else if(R.tend1 == 3 && R.tend2 == 2) fprintf(arq, "Tend�ncia: Neutro e Mau\n");
    else fprintf(arq, "Tend�ncia: Neutro e Neutro\n");
    fprintf(arq, "Antecedente: %s\n", A.nome);
    fprintf(arq, "\nNome do Jogador: %s\n\n", player_name);
    fprintf(arq, "B�nus de Profici�ncia: +2\n");
    fprintf(arq, "Profici�ncia nos Testes de Resist�ncia de: %s\n\n", C.prof_res);

    for(i=0; i<6; i++) {
        if(H[i].n == 1)fprintf(arq, "For�a: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 2)fprintf(arq, "Destreza: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 3)fprintf(arq, "Constitui��o: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 4)fprintf(arq, "Intelig�ncia: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 5)fprintf(arq, "Sabedoria: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 6)fprintf(arq, "Carisma: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
    }

    fprintf(arq, "\nIdiomas: Comum%s\n", R.idioma);
    print_prof_in_file(arq, C); // imprime as proficiencias    
    fprintf(arq, "\nDeslocamento: %.2f metros\n", R.des);
    fprintf(arq, "Pontos de Vida Totais: %d\n", HP);
    fprintf(arq, "Dados de Vida: 1d%d\n\n", C.dvida);
    print_equip_in_file(arq, C, A); // imprime os equipamentos
    print_capacity_in_file(arq, R, C); // imprime as capacidades
}

// Fun��o que imprime a tela final
void print_end() {
    clear_terminal();
    printf("\n========== Sua ficha est� pronta ==========\n\n");
    printf("Ela j� est� na sua pasta!\n");
    printf("Importante: As per�cias n�o ser�o encontradas aqui, consulte o seu mestre para mais informa��es.\n\n");

    printf("Esperamos que tenha se divertido criando sua ficha.\n");
    printf("A M.A.N.A agradece por utilizar o nosso criador de fichas para D&D.\n\n");

    printf("At� a pr�xima aventura!\n");
    printf("\n\n");
    printf("                        ,-,-      \n");
    printf("                       / / |      \n");
    printf("     ,-'             _/ / /       \n");
    printf("    (-_          _,-' `Z_/        \n");
    printf("     '#:      ,-'_,-.    |_\\      \n");
    printf("      #'    _(_-' (.)\\      |_     \n");
    printf("    ,--_,--'                 |    \n");
    printf("   / ""                      L-'|_ \n");
    printf("   |,--^---v--v-._        /     |_ \n");
    printf("     |_________________,-'       |_ \n");
    printf("                      |_           \n");
    printf("                        |_          \n");
    printf("                         |_ \n");
    printf("                                     \n\n");
}

#endif