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

// A estrutura abaixo define características básicas de cada raça
typedef struct{
    int n; // Numero inteiro usado como codigo para representar a classe
    char *nome; // Nome da raça int age; 
    int tend1; // Tendencia mais comum, em que 1 Leal, 2 Caos, 3 Qualquer;
    int tend2; // Tendencia maias comum, em que 1 Bom, 2 Mau, 3 Qualquer;
    int h; // Categoria de altura, em que 1 Pequeno, 2 Medio, 3 Grande
    int sub; // Índice da subraça, caso tiver
    float des; // Deslocamento permitido em metros
    char *idioma;
} Raca;

// Estrutura que define as caracteristicas basicas de cada classe
typedef struct {
    int n; //inteiro que representa o índice de seleção de cada classe
    char *nome; //nome da classe
    int dvida; //dado de vida
    char *prof_res; //proficiencias em teste de resistencia
} Classe;

// Estrutura das habilidades
typedef struct {
    int n; // índice da habilidade
    char *nome; // nome da habilidade
    int pontos;
    int mod; // qual o modificador proporcionado pela habilidade
}   Habilidade;

// A struct abaixo define características básicas de antecedentes
typedef struct{
    int n; // Inteiro usado como código para representar o antecedente
    char* nome; // Nome do antecedente
} Anteced;

// As Função retornam as structs definidas
Raca define_race(int n, int sr);
Classe define_class (int n);
Habilidade define_hab(Raca R, int v, int n); // v - valor, n - idx das hab a receber o valor
Anteced define_background(int n);

// Raças
int print_race_select();
void print_race_help_menu();
void print_race_help(int n);
//Sub raças
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

// Função principal da raca
Raca rmain(void);
// Função principal de classe
Classe cmain(void);
// Função principal de habilidade
void hmain(Raca raca, Habilidade *H);
// Função principal dos antecedentes
Anteced amain(void);

// Função que limpa o terminal
void clear_terminal(); 
// Função sleep multiplataforma
void sleep_function(int n); 
// Função visual
void rolar_dados();

// Funções free
void free_race(Raca R);
void free_class(Classe C);
void free_ant(Anteced A);
void free_name(char nomes[][20]);

// Funções FILE
void create_file(Raca R, Classe C, Habilidade *H, Anteced A, FILE *arq, char *player_name, char *chara_name, int HP);
void print_prof_in_file(FILE *arq, Classe C);
void print_equip_in_file(FILE *arq, Classe C, Anteced A);
void print_capacity_in_file(FILE* arq, Raca R, Classe C);

// Função que printa o menu inicial e a tela final
void print_start_menu(char *file_name, char *player_name);
void print_end();



// A Função retorna uma struct de Raca
Raca define_race(int n, int sr){ // indice da e indice da subraca
    setlocale(LC_ALL, "portuguese-brazilian");
    Raca R;
    R.n = n;
    if(R.n==1 && sr==1){
        R.nome = (char*)malloc(16*sizeof(char));
        R.nome = "Anão da Colina";
        R.h = 2;
        R.tend1 = 1;
        R.tend2 = 1;
        R.des = 7.5;
        R.sub = 1;
        R.idioma = (char*) malloc(9*sizeof(char));
        R.idioma = " e Anão";
    }
    else if(R.n==1 && sr==2){
        R.nome = (char*)malloc(18*sizeof(char));
        R.nome = "Anão da Montanha";
        R.h = 2;
        R.tend1 = 1;
        R.tend2 = 1;
        R.des = 7.5;
        R.sub = 2;
        R.idioma = (char*) malloc(9*sizeof(char));
        R.idioma = " e Anão";
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
        R.idioma = ", Élfico e mais um idioma de sua escolha";
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
        R.idioma = " e Élfico";
    }else if(R.n==3 && sr==5){
        R.nome = (char*)malloc(20*sizeof(char));
        R.nome = "Halfling-Pés-Leves";
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
        R.idioma = " e Dracônico";
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
        R.idioma = ", Élfico e mais um";
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

// Função que apresenta os nomes
void choose_name(Raca R, char *nome) { // dando erro
    char names[12][20];
    int g; // genero
    int eh; // escolha exclusiva dos humanos
    int fav; //tamanho da string e nome favorito
    int l, c; // linha e coluna da matriz

    // Aloca dinamicamente o espaço gasto pelos nomes

    printf("\n============== Parte Final ================\n\n");
    printf("Seu personagem está quase pronto para suas aventuras. Falta apenas receber um nome que o represente!\n");
    printf("Em Dungeons and Dragons, o nome de um personagem está ligado à sua raça, sendo passado de geração em geração.\n");
    printf("O seu personagem será do sexo: ");
    printf("\n\n1) Masculino\n2) Feminino\n\n");
    printf("Insira o respectivo índice: ");
    scanf("%d", &g);

    // De acordo com a raça e gênero, uma lista de possíveis nomes diferentes vai aparecer
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
        printf("Como você é um humano, sinta-se livre para escolher um nome de sua preferência.\nDigite '1' se deseja digitar um nome, ou digite '2' caso queira escolher da lista de opções: ");
        scanf("%d%*c", &eh); //escaneia a escolha
        if(eh == 1) {
            printf("Seu nome será: ");
            scanf("%[^\n]", nome);
            printf("\nÓtima escolha, %s\n!", nome);
        }
        else {
            printf("Nomes disponíveis para escolha:\n");
            for(l=0; l<12; l++) {
                c = 0;
                printf("%d) ", l+1);
                while(names[l][c] != '\0') {
                    printf("%c", names[l][c]);
                    c++;
            }
                printf("\n");
            }
            printf("Digite o índice do seu nome favorito para selecioná-lo: ");
            scanf("%d%*c", &fav);
            strcpy(nome, names[fav-1]);
            printf("\nÓtima escolha, %s!\n", nome);
        }
    }
    else {
        printf("\nNomes disponíveis para escolha:\n");
        for(l=0; l<12; l++) {
            c = 0;
            printf("%d) ", l+1);
            while(names[l][c] != '\0') {
                printf("%c", names[l][c]);
                c++;
            }
            printf("\n");
        }
        printf("\nDigite o índice do seu nome favorito para selecioná-lo: ");
        scanf("%d%*c", &fav);
        strcpy(nome, names[fav-1]);
        printf("\nÓtima escolha, %s!\n", nome);
    }
    printf("Aperte ENTER para finalizar\n");
    getchar();
    clear_terminal();
}

// A função abaixo printa o menu de escolhas de raças
int print_race_select(){
    int escolha;
    clear_terminal();
    setlocale(LC_ALL, "portuguese-brazilian");
    printf("\n=========== Escolhendo a Raça de D&D =============\n\n");
    printf("Vamos começar escolhendo a raça do seu personagem!\nEssa será a espécie dele, que pode variar de um simples humano a seres mágicos como elfos e halflings.\n");
    printf("Ela não só afeta seus valores de habilidade e traços raciais, mas também fornece sugestões para a construção da história do seu personagem.\n");
    printf("Selecione uma das raças abaixo digitando o seu respectivo número. Caso não tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada uma.\n\n");
    printf("1) Anão\n");
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
    printf("Opção selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inválida, acontecerá um loop de scanfs
    while(escolha < 1 || escolha > 11) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 11) break;
    }
    if(escolha < 10) {
        STATUS = STATUS_RACE_DEFINED;
    }
    clear_terminal();
    return escolha;
}

// A função abaixo printa o menu de escolhas de ajuda das raças
void print_race_help_menu(){
    int escolha;
    setlocale(LC_ALL, "portuguese-brazilian");
    printf("\nSobre qual raça deseja saber mais?\n\n");
    printf("1) Anão\n");
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
    // Loop caso a escolha seja inválida
    while(escolha < 1 || escolha > 10) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
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

// A função abaixo recebe um id de raça n e printa sua frase de ajuda.
void print_race_help(int n){
    setlocale(LC_ALL, "portuguese-brazilian");
    if(n==1) printf("Anões são seres leais e que prezam pelo bem de seus clãs e tradições. São ótimos mineradores e guerreiros e conseguem usar uma variedade de ferramentas como ninguém!\n");
    else if(n==2) printf("Elfos são graciosos, mágicos, belos, elegantes e caóticos. Geralmente vivem em torres brilhantes no meio de lindas florestas.\nSão muito habilidosos com magia, valorizam a natureza e podem chegar a viver 750 anos.\n");
    else if(n==3) printf("Halflings são pequenos, girando em torno de 90cm de altura, e discretos. Tentam se afastar de conflitos e dão muito valor a um lar pacífico e alegre. Esses exploradores são afáveis e rápidos.\n");
    else if(n==4) printf("Humanos são... Humanos como nós! São conhecidos por serem ambiciosos e flexíveis. Não há um padrão para humanos como há para as outras raças, sinta-se livre para se aventurar no que quiser.\n");
    else if(n==5) printf("Draconatos são orgulhosos descendentes de dragões, apesar de terem uma forma humanoide. Um draconato se dedica totalmente ao seu clã e aos seus deuses.\n");
    else if(n==6) printf("Gnomos são hiperativos, engenhoso, pequenos e extremamente divertidos. Enxergam a vida com uma paixão admirável, são curiosos e fariam coisas perigosíssimas por joias brilhantes.\nVocê pode escolher cuspir fogo, gelo, veneno etc de acordo com o ancestral dracônico que escolher\n");
    else if(n==7) printf("Meio-elfos são incomuns e solitários. Não se sentem acolhidos em meio aos humanos e muito menos em meio aos elfos.\nAdoram viajar e se aproveitam de seu carisma nato aonde quer que vão, mas geralmente só apreciam a companhia de outros meio-elfos.\n");
    else if(n==8) printf("Meio-orcs são altos, intensos e muito fortes. Costumam viver em tribos orcs, mas podem viver entre os humanos sem problemas. Resolvem muitos problemas com os punhos.\n");
    else if(n==9) printf("Tieflings são descendentes de humanos que cometeram um grande pecado e pagam por isso. Com chifres, caldas e dentes pontudos, tieflings são alvos de insultos em todo lugar.\nDificilmente fazem amigos, mas valorizam muito quem os dá um voto de confiança.\n");
    printf("\n");
    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
}

// A função abaixo printa o menu de escolhas de subraças
int print_sub_race_select(int n){
    int escolha, sub;
    setlocale(LC_ALL, "portuguese-brazilian");
    clear_terminal();
    printf("\nA raça escolhida possui sub-raças. Escolha uma delas para o seu personagem!\nCaso não tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada sub-raça.\n\n");
        if(n==1){
            printf("1) Anão da colina\n");
            printf("2) Anão da montanha\n");
            printf("3) Ajuda\n");
        }

        else if(n==2){
            printf("1) Alto elfo\n");
            printf("2) Elfo da floresta\n");
            printf("3) Ajuda\n");
        }
        else if(n==3){
            printf("1) Halfling pés-leves\n");
            printf("2) Halfling robusto\n");
            printf("3) Ajuda\n");
        }

    printf("\n");
    printf("Opção selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inválida, acontecerá um loop de scanfs
    while(escolha < 1 || escolha > 3) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
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

// A Função printa o menu de ajuda das subraças
void print_sub_race_help_menu(int n) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha, sub;
    printf("\nSobre qual sub-raça deseja saber mais?\n\n");
        if(n==1){
            printf("1) Anão da colina\n");
            printf("2) Anão da montanha\n");
            printf("3) Voltar\n");
        }

        else if(n==2){
            printf("1) Alto elfo\n");
            printf("2) Elfo da floresta\n");
            printf("3) Voltar\n");
        }
        else if(n==3){
            printf("1) Halfling pés leves\n");
            printf("2) Halfling robusto\n");
            printf("3) Voltar\n");
        }
    printf("\n");
    printf("Opção selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inválida, acontecerá um loop de scanfs
    while(escolha < 1 || escolha > 3) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
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

// A funcao abaixo recebe um id de sub-raça sr e printa sua frase de ajuda.
void print_sub_race_help(int n, int sr){
    setlocale(LC_ALL, "portuguese-brazilian");
    if(n==1){
        if(sr==1){
            printf("Anões da colina possuem os sentidos aguçados, inclusive o sexto sentido, e se adaptam muito bem às mais diversas situações.\n");
        }
        else if(sr==2){
            printf("Anões da montanha são fortes e resistentes por serem acostumados à vida em terrenos dificeis.\n");
        }
    }
    else if(n==2){
        if(sr==3){
            printf("Altos elfos possuem um domínio de magia básico e uma mente afiada. Podem ser arrogantes e egocêntricos ou mais amigáveis.\nAlém disso, são muito habilidosos com espadas e arcos.\n");

        }
        else if(sr==4){
            printf("Elfos da floresta possuem os sentidos e intuição aguçados, então podem ser um pouco desconfiados.\nAlém disso, conhecem bem suas florestas nativas e são habilidosos com espadas e arcos.\n");
        }
    }
    else if(n==3){
        if(sr==5){
            printf("Halflings pés-leves são simpáticos e gostam de conhecer novos lugares ao lado de seus companheiros, sejam eles halflings ou não.\nAlém disso, conseguem se esconder facilmente em qualquer ambiente.\n");

        }
        else if(sr==6){
            printf("Halflings robustos são resistentes a danos de veneno e honram o nome que levam.\n");
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
Haflings pés leves - 5
Haflings robustos - 6
*/

// Função que define a classe escolhida
Classe define_class (int n) {
    setlocale(LC_ALL, "portuguese-brazilian");
    Classe C;
    C.n = n;
    switch(n) {
        case 1:
            C.nome = (char*) calloc(9, sizeof(char)); 
            C.nome = "Bárbaro"; 
            C.dvida = 12;
            C.prof_res = (char*) calloc(24, sizeof(char));
            C.prof_res = "Força & Constituição";
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
            C.nome = "Clérigo";
            C.dvida = 8;
            C.prof_res = (char*) calloc(20, sizeof(char));
            C.prof_res = "Sabedoria & Carisma";
            break;
        case 5:
            C.nome = (char*) calloc(7, sizeof(char));
            C.nome = "Druida";
            C.dvida = 8;
            C.prof_res = (char*) calloc(26, sizeof(char));
            C.prof_res = "Inteligência & Sabedoria";
            break;
        case 6:
            C.nome = (char*) calloc(11, sizeof(char));
            C.nome = "Feiticeiro";
            C.dvida = 6;
            C.prof_res = (char*) calloc(25, sizeof(char));
            C.prof_res = "Constituição & Carisma";
            break;
        case 7:
            C.nome = (char*) calloc(24, sizeof(char));
            C.nome = "Guerreiro";
            C.dvida = 10;
            C.prof_res = (char*) calloc(25, sizeof(char));
            C.prof_res = "Força & Constituição";
            break;
        case 8:
            C.nome = (char*) calloc(7, sizeof(char));
            C.nome = "Ladino";
            C.dvida = 8;
            C.prof_res = (char*) calloc(25, sizeof(char));
            C.prof_res = "Destreza & Inteligência";
            break;
        case 9:
            C.nome = (char*) calloc(5, sizeof(char));
            C.nome = "Mago";
            C.dvida = 6;
            C.prof_res = (char*) calloc(26, sizeof(char));
            C.prof_res = "Inteligência & Sabedoria";
            break;
        case 10:
            C.nome = (char*) calloc(6, sizeof(char));
            C.nome = "Monge";
            C.dvida = 8;
            C.prof_res = (char*) calloc(18, sizeof(char));
            C.prof_res = "Força & Destreza";
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
            C.prof_res = "Força & Destreza";
            break;
    }
    return C;
}

// Função que printa o menu de seleção
int print_class_select_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha = 0;
    clear_terminal();
    printf("\n=========== Escolhendo a Classe de D&D =============\n\n");
    printf("Em Dungeons & Dragons, as classes são conjuntos de habilidades e características que determinam o papel e o estilo de jogo de um personagem.\n");
    printf("Selecione uma das classes abaixo digitando o seu respectivo número.\n");
    printf("Caso não tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada uma.\n\n");
    printf("1) Bárbaro\n");
    printf("2) Bardo\n");
    printf("3) Bruxo\n");
    printf("4) Clérigo\n");
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
    printf("Opção selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inválida, acontecerá um loop de scanfs
    while(escolha < 1 || escolha > 13) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 14) break;
    }
    if(escolha < 13) {
        STATUS = STATUS_CLASS_DEFINED;
    }
    clear_terminal();
    return escolha;
}

// Função que printa o menu de ajuda
void print_class_help_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    printf("\nSobre qual classe deseja saber mais?\n\n");
    printf("1) Bárbaro\n");
    printf("2) Bardo\n");
    printf("3) Bruxo\n");
    printf("4) Clérigo\n");
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
    // Loop caso a escolha seja inválida
    while(escolha < 1 || escolha > 13) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
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

// Função que descreve a classe pedida
void print_class_help (int n) { 
    setlocale(LC_ALL, "portuguese-brazilian");
    Classe C;
    C.n = n;
    switch(C.n) {
        case 1:
        printf("Bárbaros são combatentes brutais e selvagens que podem entrar em fúria durante uma batalha.\nA fúria permite que um bárbaro sofra menos e cause mais dano ao seu adversário.\n");
        printf("Dica: A Força de um bárbaro é a sua habilidade mais importante.\n");
        break;
        case 2:
        printf("Bardos são seres místicos inspiradores que possuem poderes que ecoam a música da criação.\nSuas habilidades são úteis tanto a distância, quanto em combates corpo à corpo.\n");
        printf("Dica: O Carisma de um bardo é a sua habilidade mais importante.\n");
        break;
        case 3:
        printf("Bruxos são conjuradores cuja magia e derivada de um pacto com alguma entidade.\nEstão dispostos a tudo para ter conhecimento e poder.\n");
        printf("Dica: O Carisma de um bruxo é a sua habilidade mais importante.\n");
        break;
        case 4:
        printf("Clérigos são conjuradores que recebem magia através de preces a divindade a qual veneram.\nSuas magias tendem a inspirar, curar e proteger seus aliados.\n");
        printf("Dica: A Sabedoria de um clérigo é a sua habilidade mais importante.\n");
        break;
        case 5:
        printf("Druidas são conjuradores de magia intimamente ligados com as forcas elementais da natureza.\nSão capazes de adotarem formas animais.\n");
        printf("Dica: A Sabedoria de um druida é a sua habilidade mais importante.\n");
        break;
        case 6:
        printf("Feiticeiros são conjuradores que possuem magia latente advinda de um dom ou linhagem.\nSuas magias podem ser usadas para causar danos a inimigos, conceder habilidades e a defender a si ou a aliados.\n");
        printf("Dica: O Carisma de um feiticeiro é a sua habilidade mais importante.\n");
        break;
        case 7:
        printf("Guerreiros são mestres do combate e peritos em uma vasta gama de armas e armaduras.\nUsam de seus conhecimentos em técnicas de combate para lutar.\n");
        printf("Dica: A Força e a Destreza de um guerreiro são as suas habilidades mais importantes.\n");
        break;
        case 8:
        printf("Ladinos são trapaceiros que usam de furtividade e astúcia para sobrepujar os obstáculos e inimigos.\nNão são combatentes tão poderosos, mas seus meios sorrateiros os igualam a outras classes.\n");
        printf("Dica: A Destreza de um ladino é a sua habilidade mais importante.\n");
        break;
        case 9:
        printf("Magos são conjuradores estudiosos, capazes de manipular as estruturas da realidade.\nPossuem a maior quantidade de magia entre todas as classes.\n");
        printf("Dica: A Inteligência de um mago é a sua habilidade mais importante.\n");
        break;
        case 10:
        printf("Monges são mestres das artes marciais e utilizam do poder corporal para atingir a perfeição física e espiritual.\nEstudam a si mesmos e conhecem a energia mística presente em cada um.\n");
        printf("Dica: A Destreza e a Sabedoria de um monge são as suas habilidades mais importantes.\n");
        break;
        case 11:
        printf("Paladinos são guerreiros divinos vinculados a um juramento sagrado.\nCombinam técnicas de combate a alguma habilidade de conjuração.\n");
        printf("Dica: A Força e o Carisma de um paladino são as suas habilidades mais importantes.\n");
        break;
        case 12:
        printf("Patrulheiros são guerreiros que utilizam de poderio marcial e magia natural para combater ameaças nos limites da civilização.\n");
        printf("Dica: A Destreza e a Sabedoria de um patrulheiro são as suas habilidades mais importantes.\n");
        break;
    }
    printf("\n");
    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
}

// Função que retorna a struct de Habilidade
Habilidade define_hab(Raca R, int v, int n) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int mod, ar = 0; // modificador e atributo racial
    Habilidade H;
    H.pontos = v;
    H.n = n;

    if(n == 1) {
        if(R.n == 5 || R.n == 8 || R.sub == 2) ar = 2; // Draconato, meio-orc ou anão da montanha
        else if(R.n == 4) ar = 1; // Humano
    }
    else if(n == 2) {
        if(R.n == 2 || R.n == 3) ar = 2; // Elfo ou Halfing
        else if(R.n == 4) ar = 1; // Humano
    }
    else if(n == 3) {
        if(R.n == 1) ar = 2; // Anão
        else if(R.n == 4 || R.n == 8 || R.sub == 6) ar = 1; // Humano, meio-orc e haflings robustos
    }
    else if(n == 4) {
        if(R.n == 6) ar = 2; // Gnomo
        else if(R.n == 4 || R.n == 9 || R.sub == 3) ar = 1; // Humano, Tielfing, Alto Elfo
    }
    else if(n == 5) {
        if(R.n == 4 || R.sub == 4 || R.sub == 1) ar = 1; // Humano, elfo da floresta e anão da colina
    }
    else if(n == 6) {
        if(R.n == 7 || R.n == 9) ar = 2; // Meio-elfo e Tiefling
        else if(R.n == 4 || R.n == 5 || R.sub == 5) ar = 1; // Humano, Draconato e haflings pés leves
    }

    mod = (v-10+ar)/2; // operação para descobrir o valor do modificador
    
    switch(H.n) {
        case 1:
            H.nome = (char *) malloc(6*sizeof(char));
            strcpy(H.nome, "Força");
            H.mod = mod;
            break;
        case 2:
            H.nome = (char *) malloc(9*sizeof(char));
            H.nome = "Destreza";
            H.mod = mod;
            break;
        case 3:
            H.nome = (char *) malloc(15*sizeof(char));
            H.nome = "Constituição";
            H.mod = mod;
            break;
        case 4:
            H.nome = (char *) malloc(14*sizeof(char));
            H.nome = "Inteligência";
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
            printf("Opção inválida.\n");
    }

    return H;
}

// Função que deixa as habilidades na ordem certa
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

// A Função o menu com os índices de cada habilidade 
char print_hab_select_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    char opcao;

    printf("\n=========== Escolhendo as Habilidades de D&D =============\n\n");
    printf("Índices:\n");
    printf("1) Força\n");
    printf("2) Destreza\n");
    printf("3) Constituição\n");
    printf("4) Inteligência\n");
    printf("5) Sabedoria\n");
    printf("6) Carisma\n\n");

    printf("Deseja saber mais sobre cada atributo? Digite S para sim e outro caracter para não.\n$ ");
    scanf("%c%*c", &opcao);

    return opcao;
}

// A Função printa mais informações das habilidades
void print_hab_help_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    printf("\n============ Informações Adicionais ================\n\n");
    printf("Os atributos são as características básicas de um personagem, que retratam suas capacidades e deficiências e influenciam nas demais características que possui.\n");
    printf("Muitas das jogadas realizadas em uma aventura terão como base um dos seis atributos do personagem:\n\n");
    printf("1) A Força define a potência muscular e física, e esse atributo pode ser utilizado para jogadas que envolvam escalar, saltar e nadar.\nA Força também influencia na capacidade de carga do personagem.\n\n");
    printf("2) A Destreza representa agilidade, a mira e a capacidade de evitar um golpe.\nEsse atributo pode ser utilizado para jogadas que envolvam equilíbrio, uso de cordas ou outros objetos que envolvam precisão.\n\n");
    printf("3) A Constituição refere-se ao vigor, à saúde do personagem, e à capacidade de resistir a efeitos como afogamento e intoxicação.\nÉ importante para todos, independente da classe.\n\n");
    printf("4) A Inteligência mede a capacidade de aprendizagem e a capacidade de lançar magias arcanas.\nA Inteligência também pode ser utilizado em jogadas de avaliação de itens, decifrar escritas e para saber se o personagem detém algum tipo específico de conhecimento.\n\n");
    printf("5) A Sabedoria é o conhecimento, o senso comum, o discernimento e a capacidade de lançar magias divinas.\nEla pode ser utilizada em jogadas de cura e sentir motivação.\n\n");
    printf("6) O Carisma determina o quanto um personagem é socialmente atrativo, amigável, charmoso e a habilidade de afastar mortos-vivos.\nEsse atributo pode ser utilizado para jogadas de blefe, diplomacia, disfarce, reunir informações e performance.\n\n\n");

    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
    STATUS = STATUS_HAB_SELECT;
}

// A Função abaixo aleatoriza os valores que poderão ser usados nas habilidades
int rand_hab() {
    // A função vai receber 4 valores de um d6 aleatórios em um vetor
    // Depois vai calcular qual a maior soma de 3 entre os 4 
    int stotal = 0, smaior = 0, menor;
    int dado[4];
    int i; 

    srand(time(NULL));

    for(i=0; i<4; i++) dado[i] = 0; // limpa os valores

    // Gera 4 valores aleatórios
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

//Função que checa se os índices fornecidos no scanf para compor as habilidades são diferentes
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

// Função para o sleep
void sleep_function(int n) {
    #ifdef _WIN64
    Sleep(n); // n = 500 é meio segundo
    #elif __linux__
    usleep(n*1000);
    #endif
}

// Aparece enquanto os valores ainda estão sendo gerados, função visual
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

// A função define o antecedente
Anteced define_background(int n){
    setlocale(LC_ALL, "portuguese-brazilian");
    Anteced A;
    A.n = n;
    if(A.n==1){
        A.nome = (char*)malloc(9*sizeof(char));
        A.nome = "Acólito";
    }else if(A.n==2){
        A.nome = (char*)malloc(19*sizeof(char));
        A.nome = "Artesão de Guilda";
    }else if(A.n==3){
        A.nome = (char*)malloc(8*sizeof(char));
        A.nome = "Artista";
    }else if(A.n==4){
        A.nome = (char*)malloc(11*sizeof(char));
        A.nome = "Charlatão";
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
        A.nome = "Herói do Povo";
    }else if(A.n==9){
        A.nome = (char*)malloc(11*sizeof(char));
        A.nome = "Marinheiro";
    }else if(A.n==10){
        A.nome = (char*)malloc(6*sizeof(char));
        A.nome = "Nobre";
    }else if(A.n==11){
        A.nome = (char*)malloc(8*sizeof(char));
        A.nome = "Órfão";
    }else if(A.n==12){
        A.nome = (char*)malloc(7*sizeof(char));
        A.nome = "Sábio";
    }else if(A.n==13){
        A.nome = (char*)malloc(8*sizeof(char));
        A.nome = "Soldado";
    }
    return A;
}

// A função imprime o menu de seleção de antecedente
int print_bg_select_menu() {
    setlocale(LC_ALL, "portuguese-brazilian");
    clear_terminal();
    int escolha;
    printf("\n=========== Escolhendo o Antecedente de D&D =============\n\n");
    printf("Toda história tem um início. Os antecedentes de seus personagens revela de onde eles vieram, como se tornaram aventureiros e seu lugar no mundo.\n");
    printf("Selecione um dos antecedentes abaixo digitando seu respectivo número.\n");
    printf("Caso não tenha certeza do que escolher, selecione Ajuda para ler mais detalhes sobre cada um.\n\n");
    printf("1) Acólito\n");
    printf("2) Artesão de Guilda\n");
    printf("3) Artista\n");
    printf("4) Charlatão\n");
    printf("5) Criminoso\n");
    printf("6) Eremita\n");
    printf("7) Forasteiro\n");
    printf("8) Herói do Povo\n");
    printf("9) Marinheiro\n");
    printf("10) Nobre\n");
    printf("11) Órfão\n");
    printf("12) Sábio\n");
    printf("13) Soldado\n");
    printf("14) Ajuda\n");
    printf("\n");
    printf("Opção selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inválida, acontecerá um loop de scanfs
    while(escolha < 1 || escolha > 14) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
        scanf("%d%*c", &escolha);
        if(escolha > 0 && escolha < 15) break;
    }
    if(escolha < 14) {
        STATUS = STATUS_ANT_DEFINED;
    }   
    clear_terminal();
    return escolha;
}

// A função abaixo recebe um id de antecedente n e printa sua frase de ajuda
void print_bg_help(int n){
    setlocale(LC_ALL, "portuguese-brazilian");
    if(n==1) printf("Você servia a uma ou mais divindades e tem hábitos relacionados a isso.\nDica: Isso não significa que você é um clérigo, porque é possível servir um deus e não ser capaz de canalizar seu poder.\n");
    else if(n==2) printf("Você era um artesão bem estabelecido no mercado que cresceu com a ajuda de uma guilda. Você consegue criar itens e usar ferramentas.\n");
    else if(n==3) printf("Você se apresentava em frente a grandes públicos e sabe entreter audiências com acrobacias e atuação.\n");
    else if(n==4) printf("Você vendia produtos duvidosos, para não dizer completamente enganosos. Graças a isso, sabe convencer pessoas das coisas mais improváveis.\n");
    else if(n==5) printf("Você desprezava as leis e vivia no mundo do crime, onde aprendeu a agir furtivamente e escapar de situações ruins.\n");
    else if(n==6) printf("Você vivia absolutamente isolado da sociedade em uma calmaria sem igual.\nEsse tempo em reclusão pode ter te dado respostas reveladoras e conhecimento inegualável ou te deixado maluco - você decide!\n");
    else if(n==7) printf("Você cresceu longe das grandes civilizações, está acostumado com ambientes mais selvagens e sabe se virar em locais novos melhor do que a maioria.\n");
    else if(n==8) printf("Você era uma pessoa comum até cometer um grandioso ato e ser reconhecido por seu povo. Tem as habilidades de um trabalhador e a reputação de um herói.\n");
    else if(n==9) printf("Você passou boa parte de sua vida em um navio em alto mar. Conhece embarcações de forma mais técnica e tem uma boa noção de direção.\n");
    else if(n==10) printf("Você nasceu em berço de ouro. Carrega consigo o peso de um nome influente e em troca exerce uma autoridade que poucos podem desafiar.\n");
    else if(n==11) printf("Você cresceu pobre e sem família em meio às ruas. Seus instintos de sobrevivência são apurados, mas a carga emocional é difícil de carregar.\n");
    else if(n==12) printf("Você se dedicou a estudar intensamente um campo do conhecimento e tem um histórico acadêmico invejável.\n");
    else if(n==13) printf("Você lutou e treinou durante a maior parte de sua vida e tem experiência com o sofrimento da guerra.\n");
    
    printf("\n");
    printf("Aperte ENTER para voltar\n");
    getchar();
    clear_terminal();
}

// A função abaixo printa o menu de escolhas de ajuda de antecedentes
void print_bg_help_menu(void){
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    printf("\nSobre qual antecedente deseja saber mais?\n\n");
    printf("1) Acólito\n");
    printf("2) Artesão de Guilda\n");
    printf("3) Artista\n");
    printf("4) Charlatão\n");
    printf("5) Criminoso\n");
    printf("6) Eremita\n");
    printf("7) Forasteiro\n");
    printf("8) Herói do Povo\n");
    printf("9) Marinheiro\n");
    printf("10) Nobre\n");
    printf("11) Órfão\n");
    printf("12) Sábio\n");
    printf("13) Soldado\n");
    printf("14) Voltar\n");
    printf("\n");
    printf("Opção selecionada: ");
    scanf("%d%*c", &escolha);

    // Se a escolha for inválida, acontecerá um loop de scanfs
    while(escolha < 1 || escolha > 14) {
        printf("Opção inválida. Por favor, digite um número válido: \n"); 
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

// A função abaixo limpa a struct de Raça
void free_race(Raca R) {
    R.n = R.sub = 0;
    free(R.nome);
    R.tend1 = R.tend2 = R.h = R.des =  0;
    free(R.idioma);
    // Limpa todas as variáveis
}

//A função abaixo limpa a struct de Classe
void free_class(Classe C) {
    C.n = 0;
    free(C.nome);
    free(C.prof_res);
    C.dvida = 0;
    // Limpa todas as variáveis
}

// A função abaixo limpa a struct de Antecedente
void free_ant(Anteced A) {
    A.n = 0;
    free(A.nome);
    // Limpa todas as variáveis
}

// A função abaixo limpa a struct de nome
void free_name(char nomes[][20]) {
    int l, c; //linhas e colunas
    for(l=0; l<12; l++) {
        for(c=0; c<20; c++) {
            memset(nomes[l], 0, 20);
        }
    }
}

// Função que printa o menu inicial
void print_start_menu(char *file_name, char *player_name) {
    setlocale(LC_ALL, "portuguese-brazilian");
    clear_terminal();
    printf("\n========== Bem-vindo(a) a M.A.N.A. ==============\n");
    printf("Pronto para criar sua ficha de personagem de Dungeons and Dragons?\n\n");
    printf("Antes de tudo, qual o nome do jogador? ");
    scanf("%[^\n]%*c", player_name);
    printf("E o nome da sua nova ficha? (Atenção: Não use o mesmo nome para mais de uma ficha!)\n");
    scanf("%[^\n]%*c", file_name);
    printf("\nA criação de um personagem pode parecer complicada demais para quem não conhece o sistema, mas não se preocupe, te guiarei por tudo que precisa saber!\n");
    printf("\nAs etapas para compor uma ficha são:\n");
    printf("1) Escolha da Raça\n");
    printf("2) Escolha da Classe\n");
    printf("3) Definição das Habilidades\n");
    printf("4) Escolha de um Antecedente\n");
    printf("5) Definição de um Nome\n\n");
    printf("Aperte ENTER para começar!\n");
    getchar();
}

// Função principal da raca
Raca rmain(void) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolhaR, escolhaS; // escolha de raca e subraca
    Raca R;
    STATUS = STATUS_RACE_SELECT;

    while(STATUS == STATUS_RACE_SELECT) { // Enquanto não decidir a raça, o menu vai ser printado
        escolhaR = print_race_select();
        if(escolhaR == 10) STATUS = STATUS_RACE_HELP; // Se escolher a opção de ajuda, o status muda
        while(STATUS == STATUS_RACE_HELP) { // Esse menu ficará sendo printado até que a opção de 'voltar' seja selecionada
            print_race_help_menu(); // Essa função chama a que descreve no final
        }
        if(STATUS == STATUS_RACE_DEFINED) {
            if(escolhaR==1 || escolhaR==2 || escolhaR==3) { // Caso a escolha tenha subraças
                STATUS = STATUS_SUBRACE_SELECT; // Muda o status
                while(STATUS == STATUS_SUBRACE_SELECT) {
                    escolhaS = print_sub_race_select(escolhaR); // Baseado na raça, uma escolha de subraça pode ser feita
                }
                while(STATUS == STATUS_SUBRACE_HELP) { // Se a opção selecionada for de ajuda, o while começa
                    print_sub_race_help_menu(escolhaR);
                }
                if(STATUS == STATUS_SUBRACE_DEFINED) R = define_race(escolhaR, escolhaS); // Se for definida, a função 'define' é chamada
            }
            else R = define_race(escolhaR, 0); // Caso a raça escolhida não tenha subraças, ela é definida diretamente
        }
    }
    printf("Raça '%s' selecionada com sucesso!\nAperte ENTER para continuar.\n", R.nome);
    getchar();
    clear_terminal();
    return R;
}

// Função principal de classe
Classe cmain(void) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    Classe C;
    STATUS = STATUS_CLASS_SELECT;
    while(STATUS == STATUS_CLASS_SELECT) { // Enquanto o status não mudar da seleção, o print_class_select continuará rodando
        escolha = print_class_select_menu();
        if(escolha == 13) STATUS = STATUS_CLASS_HELP; // Se a ajuda for selecionada, o status muda para help
        while(STATUS == STATUS_CLASS_HELP) {
            print_class_help_menu(); // Aqui, se a pessoa voltar para a tela de escolha, o status muda pra SELECT e o if Não acontece
        }
        if(STATUS == STATUS_CLASS_DEFINED) { // Se ao voltar para a escolha e ela for definitiva, o status muda para DEFINED_CLASS e o if acontece
            C = define_class(escolha);
        }
        // Se o if acontecer, o status não será mais de select e então o loop quebra
    }
    printf("Classe '%s' selecionada com sucesso!\nAperte ENTER para continuar.\n", C.nome);
    getchar();
    return C;
}

// Função principal de habilidade
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
            STATUS = STATUS_HAB_HELP; // O status muda para help no final da ajuda, quando isso ocorrer, a tela de seleção volta
            while(STATUS == STATUS_HAB_HELP) { // Se ajuda for selecionada, o status muda e a função que printa a ajuda aparece
                clear_terminal();
                print_hab_help_menu();     
            }
        }
        else {
            STATUS = STATUS_HAB_DEFINED;
            printf("\nVamos começar então!\n");
            printf("Inicialmente, são gerados 6 (seis) valores de forma aleatória, assim como descrito no Livro do Jogador.\n");
            rolar_dados(); // Função visual para aparecer enquanto os numeros são gerados

            for(i=0; i<6; i++) {
                valores[i] = rand_hab(); // Função que randomiza um valor
                sleep_function(900); // Necessário para o número na randomização não se repetir
            }

            printf("\nOs pontos a serem distribuídos entre seus atributos são:\n");
            for(i=0; i<6; i++) {
                printf("%d ", valores[i]);
            }
            printf("\n\n");

            while(1) {
                printf("Para quais habilidades você quer destinar cada um dos seus valores? Digite o respectivo índice a seguir:\n");
                for(i=0; i<6; i++) {
                    printf("O valor %d será usado na habilidade: ", valores[i]);
                    scanf("%d%*c", &indice[i]);
                    while(indice[i] < 1 || indice[i] > 6) {
                        printf("Opção inválida. Por favor, digite novamente: ");
                        scanf("%d", &indice[i]);
                    }
                }
                checagem = checa_indice(indice); // Função que checa se os índices são diferentes
                if(checagem == 1) { // Se houver índices iguais, uma mensagem de erro aparece e o loop de scanf continua
                    printf("\nErro no preenchimento dos índices. Por favor, tente novamente. Lembre-se de que cada valor recebe um índice diferente.\n\n");   
                }
                else break;
            }

            STATUS = STATUS_HAB_DEFINED;
        
            for(i=0; i<6; i++) {
                H[i] = define_hab(raca, valores[i], indice[i]); 
            }

            ordena_hab(H); // Ordena as habilidades por ordem crescente de índice
            printf("\n\nHabilidades definidas com sucesso!\nAperte ENTER para continuar.\n");
            getchar();
        }
    
    }
}

// Função principal de antecedente
Anteced amain(void) {
    setlocale(LC_ALL, "portuguese-brazilian");
    int escolha;
    Anteced A;
    STATUS = STATUS_ANT_SELECT;
    while(STATUS == STATUS_ANT_SELECT) { // Enquanto o status não mudar da seleção, o print_ant_select continuará rodando
        escolha = print_bg_select_menu();
        if(escolha == 14) STATUS = STATUS_ANT_HELP; // Se a ajuda for selecionada, o status muda para help
        while(STATUS == STATUS_ANT_HELP) {
            print_bg_help_menu(); // Aqui, se a pessoa voltar para a tela de escolha, o status muda pra SELECT e o if Não acontece
        }
        if(STATUS == STATUS_ANT_DEFINED) { // Se ao voltar para a escolha e ela for definitiva, o status muda para ANT_DEFINED e o if acontece
            A = define_background(escolha);
        }
        // Se o if acontecer, o status não será mais de select e então o loop quebra
    }
    printf("Antecedente '%s' selecionado com sucesso!\n", A.nome);
    printf("Aperte ENTER para continuar\n");
    getchar();
    clear_terminal();
    return A;

}


// Função que limpa o terminal
void clear_terminal() {
    #ifdef _WIN64
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}

// Função que imprime as proficiências em armaduras
void print_prof_in_file(FILE *arq, Classe C) {
    fprintf(arq, "Proficiência em:");
    if(C.n==1) fprintf(arq, "\n - Armaduras leves e médias, escudos, armas simples e marciais\n");
    else if(C.n==2) fprintf(arq, "\n - Armaduras leves, armas simples, bestas de mão, espadas longas, rapieiras, espadas curtas\n");
    else if(C.n==3) fprintf(arq, "\n - Armaduras leves, armas simples\n");
    else if(C.n==4) fprintf(arq, "\n - Armaduras leves e médias, escudos, armas simples\n");
    else if(C.n==5) fprintf(arq, "\n - Armaduras leves e médias (Não-metálicas), escudos (Não-metálicos), clavas, adagas, dardos, azagaias, maças, bordões, cimitarras, foices, fundas e lanças\n");
    else if(C.n==6) fprintf(arq, "\n - Adagas, dardos, fundas, bordões, bestas leves.\n");
    else if(C.n==7) fprintf(arq, "\n - Todas as armaduras, armas simples e marciais\n");
    else if(C.n==8) fprintf(arq, "\n - Armaduras leves, armas simples, bestas de mão, espadas longas, rapieiras, espadas curtas\n");
    else if(C.n==9) fprintf(arq, "\n - Adagas, dardos, fundas, bastões, bestas leves\n");
    else if(C.n==10) fprintf(arq, "\n - Armas simples, espadas curtas\n");
    else if(C.n==11) fprintf(arq, "\n - Todas as armaduras, escudos, armas simples e marciais\n");
    else if(C.n==12) fprintf(arq, "\n - Armaduras leves, escudos, armas simples e marciais\n");
}

// Função que imprime os equipamentos na ficha
void print_equip_in_file(FILE *arq, Classe C, Anteced A) {
    fprintf(arq, "Equipamentos: ");
    // Equipamentos por Classe
    if(C.n==1) fprintf(arq, "\n - (a) um machado grande ou (b) qualquer arma marcial corpo-a-corpo\n - (a) dois machados de mão ou (b) qualquer arma simples\n - Um pacote de aventureiro e quatro azagaias");
    else if(C.n==2) fprintf(arq, "\n - (a) uma rapieira, (b) uma espada longa ou (c) qualquer arma simples\n - (a) um pacote de diplomata ou (b) um pacote de artista\n - (a) um lute ou (b) qualquer outro instrumento musical\n - Armadura de couro e uma adaga\n");
    else if(C.n==3) fprintf(arq, "\n - (a) uma besta leve e 20 virotes ou (b) qualquer armasimples\n - (a) uma bolsa de componentes ou (b) um foco arcano\n - (a) um pacote de estudioso ou (b) um pacote deexplorador\n - Armadura de couro, qualquer arma simples e duas adagas\n");
    else if(C.n==4) fprintf(arq, "\n - (a) uma maça ou (b) um martelo de guerra (se for proficiente)\n - (a) brunea, (b) armadura de couro ou (c) cota de malha(se for proficiente)\n - (a) um besta leve e 20 virotes ou (b) qualquer arma simples\n - (a) um pacote de sacerdote ou (b) um pacote deaventureiro\n - Um escudo e um símbolo sagrado\n");
    else if(C.n==5) fprintf(arq, "\n - (a) um escudo de madeira ou (b) qualquer arma simples\n - (a) uma cimitarra ou (b) qualquer arma corpo-a-corpo simples\n - (a) um pacote de estudioso ou (b) um pacote de explorador\n - Armadura de couro, um pacote de aventureiro e um foco druídico\n");
    else if(C.n==6) fprintf(arq, "\n - (a) uma besta leve e 20 virotes ou (b) qualquer arma simples\n - (a) uma bolsa de componentes ou (b) um foco arcano\n - (a) um pacote de explorador ou (b) um pacote de aventureiro\n");
    else if(C.n==7) fprintf(arq, "\n - (a) cota de malha ou (b) gibão de peles, arco longo e 20 flechas\n - (a) uma arma marcial e um escudo ou (b) duas armas marciais\n - (a) uma besta leve e 20 virotes ou (b) dois machados de arremesso\n - (a) uma pacote de aventureiro ou (b) um pacote de explorador\n");
    else if(C.n==8) fprintf(arq, "\n - (a) uma rapieira ou (b) uma espada longa\n - (a) um arco curto e uma aljava com 20 flechas ou (b)uma espada curta\n - (a) um pacote de assaltante ou (b) um pacote deaventureiro ou (c) um pacote de explorador\n - Armadura de couro, duas adagas e ferramentas de ladrão\n");
    else if(C.n==9) fprintf(arq, "\n - (a) um bordão ou (b) uma adaga\n - (a) uma bolsa de componentes ou (b) um foco arcano\n - (a) um pacote de estudioso ou (b) um pacote de explorador\n - Um grimório\n");
    else if(C.n==10) fprintf(arq, "\n - (a) uma espada curta ou (b) qualquer arma simples\n - (a) um pacote de explorador ou (b) um pacote de aventureiro\n - 10 dardos\n");
    else if(C.n==11) fprintf(arq, "\n - (a) uma arma marcial e um escudo ou (b) duas armas marciais\n - (a) cinco azagaias ou (b) qualquer arma simples corpo-a-corpo\n - (a) um pacote de sacerdote ou (b) um pacote de aventureiro\n - Cota de malha e um símbolo sagrado\n");
    else if(C.n==12) fprintf(arq, "\n - (a) camisão de malha ou (b) armadura de couro\n - (a) duas espadas curtas ou (b) duas armas simples corpo-a-corpo\n - (a) um pacote de explorador ou (b) um pacote de aventureiro\n - Um arco longo e uma aljava com 20 flechas\n");

    // Equipamentos por Antecedente
    if(A.n==1) fprintf(arq, " - Um símbolo sagrado\n - Um livro de preces ou uma conta de orações\n - 5 varetas de incenso\n - Vestimentas\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 15 po\n");
    else if(A.n==2) fprintf(arq, " - Um conjunto de ferramentas de artesão (à sua escolha)\n - Uma carta de apresentação da sua guilda\n - Um conjunto de roupas de viajante\n - Uma algibeira com 15 po\n");
    else if(A.n==3) fprintf(arq, " - Um instrumento musical (à sua escolha)\n - Um presente de um admirador\n - Um traje\n - Uma algibeira contendo 15 po\n");
    else if(A.n==4) fprintf(arq, " - Um conjunto de roupas finas\n - Um kit de disfarce\n - Ferramentas de trapaça (à sua escolha)\n - Uma algibeira contendo 15po\n");
    else if(A.n==5) fprintf(arq, " - Um pé de cabra\n - Um conjunto de roupas escuras comuns com capuz\n - Uma algibeira contendo 15 po\n");
    else if(A.n==6) fprintf(arq, " - Um estojo de pergaminho cheio de notas dos seus estudos e orações\n - Um cobertor de inverno\n - Um conjunto de roupas comuns\n - Um kit de herbalismo\n - 5 po\n");
    else if(A.n==7) fprintf(arq, " - Um bordão\n - Uma armadilha de caça\n - Um fetiche de um animal que você matou\n - Um conjunto de roupas de viajante\n - Uma algibeira contendo 10 po\n");
    else if(A.n==8) fprintf(arq, " - Um conjunto de ferramentas de artesão (à sua escolha)\n - Uma pá\n - Um pote de ferro\n - Um conjunto de roupas comuns\n- Uma algibeira contendo 10 po\n");
    else if(A.n==9) fprintf(arq, " - Uma malagueta (clava)\n - 15 metros de corda de seda\n - Um amuleto da sorte como um pé de coelho ou uma pequena pedra com um furo no centro\n - Um conjunto de trajes comuns\n - Uma algibeira contendo 10 po\n");
    else if(A.n==10) fprintf(arq, " - Um conjunto de trajes finos\n - Um anel de sinete\n - Um pergaminho de linhagem\n - Uma algibeira contendo 25 po\n");
    else if(A.n==11) fprintf(arq, " - Uma faca pequena\n - Um mapa da cidade em que você cresceu\n - Um rato de estimação\n - Um pequeno objeto para lembrar dos seus pais\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 10 po\n");
    else if(A.n==12) fprintf(arq, " - Um vidro de tinta escura\n - Uma pena\n - Uma faca pequena\n - Uma carta de um falecido colega perguntando a você algo que você nunca terá a chance de responder\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 10 po\n");
    else if(A.n==13) fprintf(arq, " - Uma insígnia de patente\n - Um fetiche obtido de um inimigo caído (uma adaga, lâmina partida ou tira de estandarte)\n - Um conjunto de dados de osso ou baralho\n - Um conjunto de roupas comuns\n - Uma algibeira contendo 10 po\n");
}

// Função que imprime as capacidades das raças e classes na ficha
void print_capacity_in_file(FILE* arq, Raca R, Classe C){ 
    if(R.n!=4 || (C.n!=4 && C.n!=3 && C.n!=6 && C.n!=9))fprintf(arq, "\nCaracterísticas:\n");
    if(R.n==1){
        fprintf(arq, "- Visão no escuro: Em até 18 metros, você enxerga na penumbra como na luz plena e no escuro como na penumbra, mas não pode discernir cores.\n");
        fprintf(arq, "- Resiliência anã: Você tem vantagem ao resistir a veneno e dano de veneno.\n");
        fprintf(arq, "- Especialização em rochas: Você tem o dobro do seu valor de proficiência ao fazer um teste relacionado à trabalhos em pedra.\n");
        if(R.sub==1){
            fprintf(arq, "- Tenacidade anã: Você recebe um ponto de vida adicional ao subir de nível.\n");
        }
    }else if(R.n==2){
        fprintf(arq, "- Visão no escuro: Em até 18 metros, você enxerga na penumbra como na luz plena e no escuro como na penumbra, mas não pode discernir cores.\n");
        fprintf(arq, "- Ancestral Feérico: Você tem vantagem ao resistir a ser enfeitiçado e magias não podem colocá-lo para dormir.\n");
        fprintf(arq, "- Transe: Você medita em vez de dormir e cada hora meditando equivale a duas horas de sono humano.\n");
        if(R.sub==4){
            fprintf(arq, "- Máscara da natureza: Você pode tentar se esconder mesmo que esteja apenas ligeiramente coberto por folhagem, neve e outras coisas naturais.\n");
        }
    }else if(R.n==3){
        fprintf(arq, "- Sortudo: Quando tirar 1 no dado ao atacar, usar uma habilidade ou resistir, você joga o dado de novo.\n");
        fprintf(arq, "- Bravura: Você tem vantagem ao resistir a ser amedrontado.\n");
        fprintf(arq, "- Agilidade halfling: Você pode atravessar o espaço ocupado por uma criatura maior que você.\n");
        if(R.sub==5){
            fprintf(arq, "- Furtividade natural: Você pode tentar se esconder mesmo quando estiver apensar coberto por uma criatura de, no mínimo, um tamanho a mais que você.\n");
        }else if(R.sub==6){
            fprintf(arq, "- Resiliência dos robustos: Você tem vantagem ao resistir a veneno e dano de veneno.\n");
        }
    }else if(R.n==5){
        fprintf(arq, "- Arma de sopro: Você pode expelir energia que causa 2d6 de dano quando o alvo não resiste (ou 1d6 quando resiste) de acordo com seu ancestral, mas só pode fazer isso novamente após descansar.\n");
        fprintf(arq, "- Ancestral dracônico: Você pode escolher um tipo de dragão para seu ancestral, o qual definirá o tipo de ataque e dano de sua arma de sopro. Consulte seu Mestre para decidir um ancestral apropriado.\n");
        fprintf(arq, "- Resistência a dano: Você tem resistência ao tipo de dano associado ao seu ancestral dracônico.\n");
    }else if(R.n==6){
        fprintf(arq, "- Visão no escuro: Em até 18 metros, você enxerga na penumbra como na luz plena e no escuro como na penumbra, mas não pode discernir cores.\n");
        fprintf(arq, "- Esperteza gnômica: Você tem vantagem ao usar Inteligência, Sabedoria ou Carisma para resistir a magia.\n");
    }else if(R.n==7){
        fprintf(arq, "- Visão no escuro: Em até 18 metros, você enxerga na penumbra como na luz plena e no escuro como na penumbra, mas não pode discernir cores.\n");
        fprintf(arq, "- Ancestral Feérico: Você tem vantagem ao resistir a ser enfeitiçado e magias não podem colocá-lo para dormir.\n");
    }else if(R.n==8){
        fprintf(arq, "- Visão no escuro: Em até 18 metros, você enxerga na penumbra como na luz plena e no escuro como na penumbra, mas não pode discernir cores.\n");
        fprintf(arq, "- Resistência implacável: Se ficar com 0 de vida mas não for totalmente morto, pode voltar a ter 1 ponto de vida. Entretanto, não pode fazer isso de novo antes de ter um descanso longo.\n");
        fprintf(arq, "- Ataques selvagens: Quando acerta um crítico usando uma arma corpo a corpo, role um dado de dano extra e adicione seu resultado ao dano final.\n");
    }else if(R.n==9){
        fprintf(arq, "- Visão no escuro: Em até 18 metros, você enxerga na penumbra como na luz plena e no escuro como na penumbra, mas não pode discernir cores.\n");
        fprintf(arq, "- Resistência infernal: Você tem vantagem ao resistir a dano de fogo.\n");
    }
    if(C.n==1){
        fprintf(arq, "- Fúria: Você pode escolher entrar em fúria como ação bônus durante o seu turno em um combate, mas não mais que duas vezes antes de ter um descanso longo. Caso não esteja vestindo uma armadura pesada,\n");
        fprintf(arq, "    Você tem vantagem em testes que usam Força;\n");
        fprintf(arq, "    Se acertar um ataque corpo a corpo usando Força, adicione 2 ao dano causado;\n");
        fprintf(arq, "    Você tem resistência a dano de concussão, corte e perfuração.\n");
        fprintf(arq, "  Esse efeito dura 1 minuto a menos que você caia inconsciente, não ataque nenhuma criatura hostil durante um turno, sofra dano ou gaste uma ação bônus para encerrá-lo.\n");
        fprintf(arq, "- Defesa sem armadura: Mesmo que não esteja vestindo armadura ou tenha apenas um escudo, sua Classe de Armadura é 10+Destreza+Constituição.\n");
    }else if(C.n==2){
        fprintf(arq, "- Inspiração de Bardo: Você pode usar uma ação bônus para inspirar uma criatura que não seja você a no máximo 18 metros de distância durante o seu turno. Pelos próximos 10 minutos, a criatura pode rolar 1d6 e adicionar esse resultado a um de seus testes. Quando ela faz isso, o efeito passa. A mesma criatura não pode ser inspirada outra vez antes do efeito acabar. Você pode usar sua inspiração um número de vezes igual ao seu Carisma antes de ter que descansar.\n");
    }else if(C.n==5){
        fprintf(arq, "- Druídico: Você conhece o idioma secreto dos druidas e consegue se comunicar nele e deixar mensagens escondidas.\n");
    }else if(C.n==7){
        fprintf(arq, "- Retomar o fôlego: Você pode usar uma ação bônus para recuperar pontos de vida durante o seu turno. O valor recuperado é 1d10+seu nível. Essa ação não pode ser feita mais de uma vez sem descanso.\n");
    }else if(C.n==8){
        fprintf(arq, "- Especialização: Escolha duas de suas perícias que seja proficiente, ou uma perícia que seja proficiente e ferramentas de ladrão, e seu bônus em testes de habilidade com elas é dobrado.\n");
        fprintf(arq, "- Ataque Furtivo: Uma vez por turno, se acertar um ataque com uma arma de acuidade ou de distância em que você tinha vantagem, você pode adicionar 1d6 de dano.\n");
        fprintf(arq, "- Gíria de ladrão: Você conhece dialetos secretos dos ladrões e consegue se comunicar em código e deixar mensagens escondidas. Entretanto, o tempo para transmitir uma mensagem usando gírias de ladrões é quatro vezes maior do que usando idiomas tradicionais.\n");
    }else if(C.n==10){
        fprintf(arq, "- Defesa sem armadura: Quando não estiver vestindo armadura nem usando escudo, sua Classe de Armadura é 10+Destreza+Sabedoria.\n");
        fprintf(arq, "- Artes Marciais: Enquanto estiver desarmado (ou empunhando uma arma de monge) e sem armadura ou escudo,\n");
        fprintf(arq, "    Você pode usar Destreza em vez de Força ao atacar;\n");
        fprintf(arq, "    Você pode causar 1d4 de dano em vez do dano que causaria ao atacar;\n");
        fprintf(arq, "    Após atacar, você pode fazer um ataque extra desarmado como ação bônus.\n");
    }else if(C.n==11){
        fprintf(arq, "- Sentido divino: Você pode usar uma ação para expandir sua consciência. Até o final do seu próximo turno, numa área de 18 metros, você é capaz de detectar seres celestiais, corruptores ou mortos-vivos e seus tipos desde que não estejam em cobertural total; além de qualquer coisa consagrada ou conspurcada. Essa característica só pode ser usada 1+Carisma vezes antes que você tenha que descansar.\n");
        fprintf(arq, "- Cura pelas mãos: Você tem um poço de poder que guarda 5 pontos de vida que você pode usar para se curar e que são gastos quando usados. Um descanso longo restaura seu poço. Você também pode usar esses pontos para restaurar os pontos de vida de outros seres ou curar uma doença ou veneno.\n");
    }else if(C.n==12){
        fprintf(arq, "- Inimigo favorito: Escolha um tipo de inimigo favorito. Você tem vantagem em testes para rastreá-los ou lembrar de informações sobre eles e aprende um idioma que seja falado por eles (se eles forem capazes de falar algum).\n");
        fprintf(arq, "- Explorador natural: Escolha um terreno favorito. Em testes de Inteligência ou Sabedoria relacionados a ele, seu bônus de proficiência é dobrado. Além disso, em viagens longas nesse terreno,\n");
        fprintf(arq, "    Sua viagem não é retardada por terreno difícil;\n");
        fprintf(arq, "    Seu grupo não se perde, a menos que por meios mágicos;\n");
        fprintf(arq, "    Você se mantém alerta ao perigo mesmo que esteja fazendo outra coisa enquanto viaja;\n");
        fprintf(arq, "    Você pode se mover furtivamente com um ritmo normal se estiver viajando sozinho;\n");
        fprintf(arq, "    Você encontra o dobro da comida que normalmente encontraria quando forrageia;\n");
        fprintf(arq, "    Quando rastrear criaturas, você descobre a quantidade exata delas, seus tamanhos e quanto tempo passaram na área.\n");
    }
}

// Função que cria o arquivo txt
void create_file(Raca R, Classe C, Habilidade *H, Anteced A, FILE *arq, char *player_name, char *chara_name, int HP) {
    int i;
    fprintf(arq, "~ Dungeons and Dragons ~ Ficha \n\n");
    fprintf(arq, "Nome do Personagem: %s\n", chara_name); //erro
    fprintf(arq, "Classe: %s", C.nome);
    fprintf(arq, " | Nível: 1\n");
    fprintf(arq, "Raça: %s\n", R.nome);
    if(R.tend1 == 1 && R.tend2 == 1) fprintf(arq, "Tendência: Leal e Bom\n");
    else if(R.tend1 == 1 && R.tend2 == 2) fprintf(arq, "Tendência: Leal e Mau\n");
    else if(R.tend1 == 1 && R.tend2 == 3) fprintf(arq, "Tendência: Leal e Neutro\n");
    else if(R.tend1 == 2 && R.tend2 == 1) fprintf(arq, "Tendência: Caótico e Bom\n");
    else if(R.tend1 == 2 && R.tend2 == 2) fprintf(arq, "Tendência: Caótico e Mau\n");
    else if(R.tend1 == 2 && R.tend2 == 3) fprintf(arq, "Tendência: Caótico e Neutro\n");
    else if(R.tend1 == 3 && R.tend2 == 1) fprintf(arq, "Tendência: Neutro e Bom\n");
    else if(R.tend1 == 3 && R.tend2 == 2) fprintf(arq, "Tendência: Neutro e Mau\n");
    else fprintf(arq, "Tendência: Neutro e Neutro\n");
    fprintf(arq, "Antecedente: %s\n", A.nome);
    fprintf(arq, "\nNome do Jogador: %s\n\n", player_name);
    fprintf(arq, "Bônus de Proficiência: +2\n");
    fprintf(arq, "Proficiência nos Testes de Resistência de: %s\n\n", C.prof_res);

    for(i=0; i<6; i++) {
        if(H[i].n == 1)fprintf(arq, "Força: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 2)fprintf(arq, "Destreza: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 3)fprintf(arq, "Constituição: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
        else if(H[i].n == 4)fprintf(arq, "Inteligência: %d | Modificador: %d\n", H[i].pontos, H[i].mod);
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

// Função que imprime a tela final
void print_end() {
    clear_terminal();
    printf("\n========== Sua ficha está pronta ==========\n\n");
    printf("Ela já está na sua pasta!\n");
    printf("Importante: As perícias não serão encontradas aqui, consulte o seu mestre para mais informações.\n\n");

    printf("Esperamos que tenha se divertido criando sua ficha.\n");
    printf("A M.A.N.A agradece por utilizar o nosso criador de fichas para D&D.\n\n");

    printf("Até a próxima aventura!\n");
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