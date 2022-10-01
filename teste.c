#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "biblioteca.h"
#include "quebrador-senha.h"

void testarQuebradorSenhas(){
    unsigned int backtracking, exaustiva;
    double pctLogin;
    double backtrackingTempo, exaustTempo;
    double pctTempo;

    while(proximaSenha()){
        printf("------------------------------------------\n");
        printf("Testando senha: %s\n",senhaAtual());

        printf("Rodando Backtracking com Poda: \n");
        zerarContadores();
        iniciarTempo();
        if (!quebradorSenhaPoda())
	        printf("Erro, senha nao encontrada!\n");
        finalizarTempo();
        backtracking =  totalLogins();
        backtrackingTempo = tempoDecorrido();
        printf("\t%u tentativas de login\n",backtracking);
        printf("\tTempo decorrido: %lf s\n",backtrackingTempo);

        printf("Rodando Backtracking de Forca Bruta: \n");
        zerarContadores();
        iniciarTempo();
        if(!quebradorSenhaExaustivo())
	        printf("Erro, senha nao encontrada!\n");
        finalizarTempo();
        exaustiva = totalLogins();
        exaustTempo = tempoDecorrido();
        printf("\t%u tentativas de login\n",exaustiva);
        printf("\tTempo decorrido: %lf s\n",exaustTempo);

        pctLogin =  (double)backtracking/exaustiva * 100;
        pctTempo =  backtrackingTempo/exaustTempo * 100;
        printf("\nBacktracking com poda reduziu as tentativas de login para %.2f%% e o tempo para %.2f%%\n", pctLogin, pctTempo);
    }
}

int main(){
    carregarSenhas("senhas.txt");
    testarQuebradorSenhas();
    return 0;
}

