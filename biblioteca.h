#ifndef _BIBLIOTECA_H_
#define _BIBLIOTECA_H_

unsigned int login(char *senha);
void carregarSenhas(char *nome_arquivo);
char *senhaAtual();
unsigned int proximaSenha();

void zerarContadores();
unsigned int totalLogins();
void iniciarTempo();
void finalizarTempo();
double tempoDecorrido();

#endif
