#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variáveis globais
char* nomes[5] = {"Guerreiro", "Mago", "Cacador", "Paladino", "Barbaro"};

// Cada personagem deve ter 3 atributos (força, defesa, habilidade especial)
int Guerreiro[3] = {20, 10, 20};
int Mago[3] = {30, 5, 25};
int Cacador[3] = {18, 8, 15};
int Paladino[3] = {15, 12, 30};
int Barbaro[3] = {25, 6, 0};

int* principal[5] = {Guerreiro, Mago, Cacador, Paladino, Barbaro};

int time_1[5] = {20, 20, 20, 20, 20};
int time_2[5] = {20, 20, 20, 20, 20};

int falha_def = 1;
float razao = 0;

// Variáveis globais para jogadas (para imprimir depois)
int selec_personagem;
int sorteia_inimigo;
int sorteia_erro_atq;
int sorteia_erro_def;
int habilidade_especial;
int vida_antiga;

int mortos_T1 = 0;
int mortos_T2 = 0;

// Função jogada_T1
void jogada_T1() {
    falha_def = 1;
    razao = 0;
    for (int i = 0; i < 5; i++) {
        if ((float)time_1[i] / principal[i][0] > razao) {
            razao = (float)time_1[i] / principal[i][0];
            selec_personagem = i;
        }
    }

    sorteia_inimigo = rand() % 5;
    while (time_2[sorteia_inimigo] == 0) {
        sorteia_inimigo = rand() % 5;
    }

    vida_antiga = time_2[sorteia_inimigo];

    sorteia_erro_atq = rand() % 101;
    sorteia_erro_def = rand() % 101;
    habilidade_especial = rand() % 101;

    if (sorteia_erro_def <= 20) falha_def = 0;

    
    if (selec_personagem == 4) {
        time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
        if (time_2[sorteia_inimigo] < 0) time_2[sorteia_inimigo] = 0;
        return;
    }

    if (sorteia_erro_atq <= 20) return;


    if (habilidade_especial <= principal[selec_personagem][2]) {
        if (selec_personagem == 0) {
            time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - (principal[selec_personagem][0] * 2);
        } else if (selec_personagem == 1) {
            time_2[sorteia_inimigo] = time_2[sorteia_inimigo] - principal[selec_personagem][0];
        } else if (selec_personagem == 2) {
            time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + ((principal[sorteia_inimigo][1] * falha_def) * 2)) - (principal[selec_personagem][0] * 2);
        }
           else if (selec_personagem == 3) {
            time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
            if (time_2[sorteia_inimigo] < 0) time_2[sorteia_inimigo] = 0;
    }
    } else {
        time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
    }

    if (time_2[sorteia_inimigo] <= 0) {
        time_2[sorteia_inimigo] = 0; 
        mortos_T2 += 1;
        return;
    }

    
    else{
    if (habilidade_especial <= principal[sorteia_inimigo][2] && sorteia_inimigo == 3) {
    time_2[3] = 1.20 * (time_2[3] );
        }
    }
}

// Função jogada_T2
void jogada_T2() {
    falha_def = 1;
    razao = 0;
    for (int i = 0; i < 5; i++) {
        if ((float)time_2[i] / principal[i][0] > razao) {
            razao = (float)time_2[i] / principal[i][0];
            selec_personagem = i;
        }
    }

    sorteia_inimigo = rand() % 5;
    while (time_1[sorteia_inimigo] == 0) {
        sorteia_inimigo = rand() % 5;
    }

    vida_antiga = time_1[sorteia_inimigo];

    sorteia_erro_atq = rand() % 101;
    sorteia_erro_def = rand() % 101;
    habilidade_especial = rand() % 101;


    if (sorteia_erro_def <= 20) falha_def = 0;


    if (selec_personagem == 4) {
        time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
        if (time_1[sorteia_inimigo] < 0) time_1[sorteia_inimigo] = 0;
        return;
    }

    if (sorteia_erro_atq <= 20) return;




    if (habilidade_especial <= principal[selec_personagem][2]) {
        if (selec_personagem == 0) {
            time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - (principal[selec_personagem][0] * 2);
        } else if (selec_personagem == 1) {
            time_1[sorteia_inimigo] = time_1[sorteia_inimigo] - principal[selec_personagem][0];
        } else if (selec_personagem == 2) {
            time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + ((principal[sorteia_inimigo][1] * falha_def) * 2)) - (principal[selec_personagem][0] * 2);
        }
        else if (selec_personagem == 3) {
        time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
        if (time_1[sorteia_inimigo] < 0) time_1[sorteia_inimigo] = 0;
    }

    } else {
        time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
    }

    if (time_1[sorteia_inimigo] <= 0) {
        time_1[sorteia_inimigo] = 0;
        mortos_T1 += 1;
        return;
    }
        else{
    if (habilidade_especial <= principal[sorteia_inimigo][2] && sorteia_inimigo == 3) {
    time_1[3] = 1.20 * (time_2[3] );
        }
    }    
}

// MAIN
int main() {
    srand(time(NULL));

    int rodadas;
    char resposta;


    printf("Quantas rodadas voce quer jogar: ");
    scanf("%d", &rodadas);

    for (int i = 0; i < rodadas; i++) {
        printf("\nRodada %d\n", i + 1);

        do {
            printf("Iniciar rodada? (S/N): ");
            scanf(" %c", &resposta);
        } while (resposta != 'S' && resposta != 's');

        // Time 1 joga
        jogada_T1();
        printf("\nTime 1 joga\n");
        printf("%d\n",mortos_T1);
        printf("%s (Vida: %d) ataca %s do Time 2 (Vida antes: %d)\n",
               nomes[selec_personagem], time_1[selec_personagem],
               nomes[sorteia_inimigo], vida_antiga);
        if (sorteia_erro_atq <= 20) {
            printf("Ataque mau-sucedido\n");
        } else {
            printf("Ataque bem-sucedido\n");
            if (sorteia_erro_def <= 20) {
                printf("Defesa Falhou\n");
            } else {
                printf("Defesa Completa\n");
            }

            printf("Dano aplicado: %d\n", vida_antiga - time_2[sorteia_inimigo]);
            if (habilidade_especial <= principal[selec_personagem][2]) {
                printf("Habilidade especial do %s ativada\n", nomes[selec_personagem]);
            } else {
                printf("Habilidade especial do %s não ativada\n", nomes[selec_personagem]);
            }
            if (sorteia_inimigo == 3 && habilidade_especial <= principal[sorteia_inimigo][2]) {
                printf("Habilidade especial do %s inimigo ativada\n", nomes[sorteia_inimigo]);
            }
            printf("%s agora com %d de vida\n", nomes[sorteia_inimigo], time_2[sorteia_inimigo]);
        }

        

            if (mortos_T1 == 5)
    {
        printf("\nTime 2 Ganhou!");
        return 1;
    }
            if (mortos_T2 == 5)
    {
        printf("\nTime 1 Ganhou!");
        return 1;
    }

// Verifica vida
        // Time 2 joga
        jogada_T2();
        printf("\nTime 2 joga\n");
        printf("%d\n",mortos_T2);
        printf("%s (Vida: %d) ataca %s do Time 1 (Vida antes: %d)\n",
               nomes[selec_personagem], time_2[selec_personagem],
               nomes[sorteia_inimigo], vida_antiga);
        if (sorteia_erro_atq <= 20) {
            printf("Ataque mau-sucedido\n");
        } else {
            printf("Ataque bem-sucedido\n");
            if (sorteia_erro_def <= 20) {
                printf("Defesa Falhou\n");
            } else {
                printf("Defesa Completa\n");
            }

            printf("Dano aplicado: %d\n", vida_antiga - time_1[sorteia_inimigo]);
            if (habilidade_especial <= principal[selec_personagem][2]) {
                printf("Habilidade especial do %s ativada\n", nomes[selec_personagem]);
            } else {
                printf("Habilidade especial do %s não ativada\n", nomes[selec_personagem]);
            }
            if (sorteia_inimigo == 3 && habilidade_especial <= principal[sorteia_inimigo][2]) {
                printf("Habilidade especial do %s inimigo ativada\n", nomes[sorteia_inimigo]);
            }
            printf("%s agora com %d de vida \n", nomes[sorteia_inimigo], time_1[sorteia_inimigo]);
        }

    if (mortos_T1 == 5)
    {
        printf("\nTime 2 Ganhou!");
        return 1;
    }
                if (mortos_T2 == 5)
    {
        printf("\nTime 1 Ganhou!");
        return 1;
    }

        // Mostrar vidas dos times após os dois ataques da rodada
        printf("\nStatus apos rodada %d:\n", i + 1);
        printf("Time 1:\n");
        for (int a = 0; a < 5; a++)
            printf("%s: Vida %d\n", nomes[a], time_1[a]);

        printf("\nTime 2:\n");
        for (int b = 0; b < 5; b++)
            printf("%s: Vida %d\n", nomes[b], time_2[b]);
    }
    
    
    if (mortos_T1 < mortos_T2 )
    {
        printf("\nTime 1 Ganhou!\n");
    }
    else if ( mortos_T2 < mortos_T1 )
    {
        printf("\nTime 2 Ganhou!\n");
    }
    else{  printf("\nEmpate!\n");}
    

    printf("\nFim da batalha!\n");
    return 0;
}
