#include "biblioteca.h"
#include<stdio.h>
#include "quebrador-senha.h"

int quebradorExaust(char aux[], char senha[], int tamAux, int tamSenha) {

    int j;
    
    if(tamSenha == 6) {
        if(login(senha) == 1) {
            return 1;
        }    
        return 0;
    }     
    
    for(j = 0; j <= tamAux; j++) {
        senha[tamSenha] = aux[j];
        if(quebradorExaust(aux, senha, tamAux, tamSenha+1) == 1)
            return 1;
    }

}

int quebradorPoda(char aux[], char senha[], int tamAux, int tamSenha, int tamLet, int tamNums) {

    int j;
    
    if(tamSenha == 6) {
        if(login(senha) == 1) {
            return 1;
        }    
        return 0;
    }

    for(j = 0; j <=tamAux; j++) {
        if(aux[j] != 47){
            senha[tamSenha] = aux[j];
            aux[j] = 47; /* adiciona um caractere especial no lugar de outro caractere do vetor auxiliar para evitar repeticoes */

            if(senha[tamSenha] < 96) {
                if(tamNums < 4) 
                    if(quebradorPoda(aux, senha, tamAux, tamSenha+1, tamLet, tamNums+1))
                        return 1;
            } else {
                if(tamLet < 4)
                    if(quebradorPoda(aux, senha, tamAux, tamSenha+1, tamLet+1, tamNums))
                        return 1;
            }
            aux[j] = senha[tamSenha]; /* se a senha der errado, coloca os caracteres ja utilizados de volta no vetor aux */
        }
        
    }

    return 0;

}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebradorSenhaExaustivo() {

    char aux[] = "p0o9i8u7ytr6e5w4qasdf3ghjkl2z1xcvbnm";
    char senha[7];
    int tamAux = 35;
    
    return quebradorExaust(aux, senha, tamAux, 0);

}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebradorSenhaPoda() {

    char aux[] = "p0o9i8u7ytr6e5w4qasdf3ghjkl2z1xcvbnm";
    char senha[7];
    int tamAux = 35;
    
    return quebradorPoda(aux, senha, tamAux, 0, 0, 0);

}




