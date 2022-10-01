#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "biblioteca.h"


#define MAX_SENHAS 100

static unsigned int numLogins = 0;       /* número de tentativas de login */
static char segredo[MAX_SENHAS][7];    /* matriz com senhas que devem ser quebradas   */
static unsigned int numSenhas = 0;      /* quantidade de senhas lidas do arquivo */
static unsigned int senhaCorrente = -1;  /* qual a senha que estamos testado atualmente */
static struct timespec inicio, fim;    /* contagem de tempo             */


/* -------------------------------------------------------------------------- */
void iniciarTempo(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);
}
/* -------------------------------------------------------------------------- */
void finalizarTempo(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);
}
/* -------------------------------------------------------------------------- */
/* devolve o tempo decorrido em segundos                                      */
double tempoDecorrido(){
	double ts = (double)(fim.tv_sec - inicio.tv_sec) +
              (double)(fim.tv_nsec - inicio.tv_nsec) / 1.0e9;
	return ts;
}
/* -------------------------------------------------------------------------- */
void zerarContadores() {
  numLogins = 0;
}
/* -------------------------------------------------------------------------- */
unsigned int totalLogins() {
  return numLogins;
}
/* -------------------------------------------------------------------------- */
unsigned int proximaSenha() {
  senhaCorrente++;
  if (senhaCorrente < numSenhas)
      return 1;
  return 0;
}
/* -------------------------------------------------------------------------- */
unsigned int login(char *senha){
    ++numLogins;
	if (strcmp(senha, segredo[senhaCorrente]) == 0)
        return 1;
    return 0;
}
/* -------------------------------------------------------------------------- */
void carregarSenhas(char *nome_arquivo){
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    FILE *fp = fopen(nome_arquivo, "r");

    if (fp == NULL){
         printf("Nao foi possivel ler o arquivo de senhas\n");
         exit(EXIT_FAILURE);
    }

    numSenhas = 0;
    while ((read = getline(&line, &len, fp)) != -1  && (numSenhas < MAX_SENHAS)) {
        line[strlen(line)-1] = '\0';
        strcpy(segredo[numSenhas] , line);
        numSenhas++;
    }
    printf("leitura das senhas completadas, %d senhas lidas\n",numSenhas);

    fclose(fp);
}
/* -------------------------------------------------------------------------- */
char *senhaAtual(){
    return segredo[senhaCorrente];
}

