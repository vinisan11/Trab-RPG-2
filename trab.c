#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
srand(time(NULL));

char* nomes [5] ={"Guerreiro" , "Mago", "Caçador", "Paladino", "Bárbaro"};

int Guerreiro [3] = {20,10, 20} ;
int Mago [3] = {30,5, 25};
int Cacador [3] = {18,8, 15};
int Paladino [3] = {20,10, 30};
int Barbaro [3] = {20,10, 20};

int* principal[5] = {Guerreiro, Mago, Cacador, Paladino, Barbaro};
    
int time_1 [5] = {100,100,100,100,100};
int time_2 [5] = {100,100,100,100,100}; 
int time_joga_1 = 0 ;
int time_joga_2 = 0 ;   


int rodadas;
char resposta ;

float razao = 0; 


int soeterio_batalha = 5;


int falha_def = 1;
int vida_antiga;






// JOGADAS TIME 1 e 2 ----------------------------------------------------------------------------------------------------
void jogada_T1(int selec_personagem, int sorteia_inimigo , int sorteia_erro_atq , int sorteia_erro_def , int habilidade_especial){
for ( int i = 0; i < 5; i++)
{
    
    if ((float)time_1[i] / principal[i][0] > razao)
    {
        razao = (float)time_1[i] / principal[i][0]  ;
        selec_personagem = i ; 
    }
    
}

 sorteia_inimigo = rand() % (4 - 0 + 1) + 0;

if (time_2[sorteia_inimigo ] == 0){

while (time_2[sorteia_inimigo ] == 0)
    {
     sorteia_inimigo = rand() % (4 - 0 + 1) + 0;
    }
}
    
vida_antiga = time_2[sorteia_inimigo] ;
    


   sorteia_erro_atq = rand() % (100 - 0 + 1) + 0;
   sorteia_erro_def = rand() % (100 - 0 + 1) + 0;
   habilidade_especial = rand() % (100 - 0 + 1) + 0;


   // ATAQUE TIME Barbaro 
    if (selec_personagem == 4)
    {
        return  time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
    }

    // ATAQUE TIME Barbaro 


   if (sorteia_erro_atq < 20)
    {
    return;  
    }
    if (sorteia_erro_def < 20)
    {
        falha_def = 0;
    }

 if (habilidade_especial <= principal[sorteia_inimigo][2] && sorteia_inimigo == 3)
    {
        return time_2[3] = 1.20*((time_2[3] + (principal[3][1] * falha_def)) - (principal[selec_personagem][0]));
    }

    if (habilidade_especial <= principal[selec_personagem][2])
    {
               if (selec_personagem == 0)
        {
               return time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def))  - (principal[selec_personagem][0]*2);    
        }
               else if (selec_personagem == 1)
        {
               return time_2[sorteia_inimigo] = time_2[sorteia_inimigo]  - principal[selec_personagem][0];    
        }
               else if (selec_personagem == 2)
        {
               return time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + ((principal[sorteia_inimigo][1] * falha_def)*2)) - (principal[selec_personagem][0]*2);
        }

             
   
        
        
    }    

    else { 
        return time_2[sorteia_inimigo] = (time_2[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
    }
    


}

void jogada_T2(int selec_personagem, int sorteia_inimigo , int sorteia_erro_atq , int sorteia_erro_def , int habilidade_especial) {

    // Escolhe o melhor atacante do time_2
    for (int i = 0; i < 5; i++) {
        if (time_2[i] / principal[i][0] > razao) {
            razao = time_2[i] / principal[i][0];
            selec_personagem = i;
        }
    }

    // Sorteia um inimigo vivo no time_1
    sorteia_inimigo = rand() % 5;
    while (time_1[sorteia_inimigo] == 0) {
        sorteia_inimigo = rand() % 5;
    }

    int vida_antiga = time_1[sorteia_inimigo];

    // Sorteia os eventos da rodada
    sorteia_erro_atq = rand() % 101;
    sorteia_erro_def = rand() % 101;
    habilidade_especial = rand() % 101;

    // ATAQUE do Bárbaro (não tem falha de ataque)
    if (selec_personagem == 4) {
        time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];

        if (time_1[sorteia_inimigo] < 0) {
            time_1[sorteia_inimigo] = 0;
        }
        return;
    }

    // Verifica falha de ataque (exceto Bárbaro)
    if (sorteia_erro_atq < 20 && selec_personagem != 4) {
        return;
    }

    // Verifica falha de defesa
    if (sorteia_erro_def < 20) {
        falha_def = 0;
    }

    // Habilidade especial Paladino do time_1 sendo atacado
    if (habilidade_especial <= principal[sorteia_inimigo][2] && sorteia_inimigo == 3) {
        time_1[3] = 1.20 * ((time_1[3] + (principal[3][1] * falha_def)) - (principal[selec_personagem][0]));

        if (time_1[3] < 0) {
            time_1[3] = 0;
        }
        return;
    }

    // Habilidade especial do atacante do time_2
    if (habilidade_especial <= principal[selec_personagem][2]) {
        if (selec_personagem == 0) {
            time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - (principal[selec_personagem][0] * 2);
        } else if (selec_personagem == 1) {
            time_1[sorteia_inimigo] = time_1[sorteia_inimigo] - principal[selec_personagem][0];
        } else if (selec_personagem == 2) {
            time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + ((principal[sorteia_inimigo][1] * falha_def) * 2)) - (principal[selec_personagem][0] * 2);
        }
    } else {
        // Ataque normal
        time_1[sorteia_inimigo] = (time_1[sorteia_inimigo] + (principal[sorteia_inimigo][1] * falha_def)) - principal[selec_personagem][0];
    }


}


// JOGADAS TIME 1 e 2 ----------------------------------------------------------------------------------------------------




    printf("Quantas Rodads você quer jogar: ");
    scanf("%d", &rodadas);

while (soeterio_batalha == 5)
{
    soeterio_batalha = rand() % (10 - 0 + 1) + 0;
    
    if (soeterio_batalha > 5)
    {  
    int time_joga_1 = 1 ; 
    if else (soeterio_batalha < 5)
    {
    printf("Time 2 joga - ");
    int time_joga_2 = 1 ;
    } 

}

for (int i = 0; i < rodads; i++)
{
while (resposta != "S")
{
printf('Iniciar Rodada? ("S/N")');
scanf("%c", &resposta);
}
// VEREFICAR SE A VIDA ESTÀ ABAIXO de 0
    if (time_1[sorteia_inimigo] < 0) {
        time_1[sorteia_inimigo] = 0;
    }

        if (time_2[sorteia_inimigo] < 0) {
        time_2[sorteia_inimigo] = 0;
    }
// VEREFICAR SE A VIDA ESTÀ ABAIXO de 0
    if ( time_joga_1 == 1)
{
    
jogada_T2();





printf("Time 2 joga\n");

printf("%c (Vida: %d) ataca %c do Time 1 (Vida: %d)\n", 
       nomes[selec_personagem], 
       time_2[selec_personagem], 
       nomes[sorteia_inimigo], 
       vida_antiga);

if (sorteia_erro_atq < 20) {
    printf("Ataque mau-sucedido\n"); 
    return;
} else {
    printf("Ataque bem-sucedido\n"); 
    printf("Dano aplicado: %d\n", vida_antiga - time_1[sorteia_inimigo]); 

    if (habilidade_especial < principal[selec_personagem][2]) {
        printf("Habilidade especial do %c ativada\n", nomes[selec_personagem]);
    } else {
        printf("Habilidade especial do %c não ativada\n", nomes[selec_personagem]);
    }
}

printf("%c agora com %d de vida\n", 
       nomes[sorteia_inimigo], 
       time_1[sorteia_inimigo]);

jogada_T1();

printf("Time 1 joga");
printf("%c (Vida: %i) ataca %c do Time 2 (Vida:%i \n)" nomes[selec_personagem], time_1[selec_personagem],nomes[sorteia_inimigo], time_2[sorteia_inimigo]);
if (sorteia_erro_atq < 20)
    {
    printf("ataque mau-sucedido\n"); 
    return;
    }
else{
    printf("ataque bem-sucedido\n"); 
    printf("dano aplicado: %d \n"  (vida_antiga - time_2[sorteia_inimigo])); 

 if (habilidade_especial < principal[selec_personagem][2])    {
        printf("Habilidade especial do %c ativado", nomes[selec_personagem]);
    }
    else{
        printf("Habilidade especial do %c não ativada", nomes[selec_personagem]);
    }
    
    

}
printf("%c agora com %d de vida", nomes[sorteia_inimigo] , time_2[sorteia_inimigo] );



}

else if ( time_joga_2 == 1)
{

jogada_T1();

printf("Time 1 joga");
printf("%c (Vida: %d) ataca %c do Time 2 (Vida:%d \n)" nomes[selec_personagem], time_1[selec_personagem],nomes[sorteia_inimigo], time_2[sorteia_inimigo]);
if (sorteia_erro_atq < 20)
    {
    printf("ataque mau-sucedido\n"); 
    return;
    }
else{
    printf("ataque bem-sucedido\n"); 
    printf("dano aplicado: %d \n"  (vida_antiga - time_2[sorteia_inimigo])); 

 if (habilidade_especial < principal[selec_personagem][2])    {
        printf("Habilidade especial do %c ativado", nomes[selec_personagem]);
    }
    else{
        printf("Habilidade especial do %c não ativada", nomes[selec_personagem]);
    }
    
    

}
printf("%c agora com %d de vida", nomes[sorteia_inimigo] , time_2[sorteia_inimigo] );


jogada_T2();

printf("Time 2 joga\n");

printf("%c (Vida: %d) ataca %c do Time 1 (Vida: %d)\n", 
       nomes[selec_personagem], 
       time_2[selec_personagem], 
       nomes[sorteia_inimigo], 
       vida_antiga);

if (sorteia_erro_atq < 20) {
    printf("Ataque mau-sucedido\n"); 
    return;
} else {
    printf("Ataque bem-sucedido\n"); 
    printf("Dano aplicado: %d\n", vida_antiga - time_1[sorteia_inimigo]); 

    if (habilidade_especial < principal[selec_personagem][2]) {
        printf("Habilidade especial do %c ativada\n", nomes[selec_personagem]);
    } else {
        printf("Habilidade especial do %c não ativada\n", nomes[selec_personagem]);
    }
}

printf("%c agora com %d de vida\n", 
       nomes[sorteia_inimigo], 
       time_1[sorteia_inimigo]);



}

printf("Time: 1");

for ( i = 0; i < 5; i++)
{
    printf("%c: Vida %d", nomes[selec_personagem]  time_1[selec_personagem]);
}

printf("Time: 2");

for ( i = 0; i < 5; i++)
{
    printf("%c: Vida %d", nomes[sorteia_inimigo]  time_2[sorteia_inimigo]);
}


for ( i = 0; i < 5; i++)
{
if (time_1[i] == 0)
    {
        printf("Time 1 sem Personagens Vivos time 2 Ganhou!").
        return 1;
    }

    if (time_2[i] == 0)
    {
        printf("Time 2 sem Personagens Vivos time 1 Ganhou!");
        return 1;
    }
    
}


}

    printf("Jogo terminou!");

    return 0;
    }
}