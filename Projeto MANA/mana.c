/*Autoras do projeto: 
Alice Cavalcanti Lopez
Ana Júlia Lima Tolêdo
Mickelly Matias de Torres
Nicole Cabral Lopes Dantas
*/

#include "mana.h"

int main(void) {
    Raca raca;
    Classe class;
    Habilidade *hab = (Habilidade*) calloc(6, sizeof(Habilidade));
    Anteced ant;
    FILE *file = NULL;
    char file_name[32], player_name[32];
    char *chara_name;
    int HP;

    chara_name = (char*) calloc (20, sizeof(char));

    print_start_menu(file_name, player_name); // Aparece um menu de boas vindas

    // Main das Categorias
    raca = rmain(); // executa a main das raças
    class = cmain(); // executa a main das classes
    hmain(raca, hab); // executa a main das habilidades
    ant = amain(); // executa a main dos antecedentes
    choose_name(raca, chara_name); // executa a função de nomes, não está funcionando

    HP = class.dvida + hab[2].mod; // fórmula para os pontos de vida

    // Criação do Arquivo
    file = fopen(strcat(file_name, ".txt"), "w"); // cria arquivo com o nome dado pelo usuário
    if(file == NULL) printf("ERRO\n"); // checagem da criagem do arquivo
    create_file(raca, class, hab, ant, file, player_name, chara_name, HP);
    fclose(file);
    print_end();

    // Free das funções
    free_race(raca);
    free_class(class);
    free(hab);
    free_ant(ant);
    HP = 0;
    memset(file_name, 0, 32);
    memset(player_name, 0, 32);
    memset(chara_name, 0, 20);

    return 0;
}


