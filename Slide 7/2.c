#include <stdio.h>
#include <string.h>

union cidadao {
    char cpf[12];
    char rg[15];
    char nome[100];
};

int main() {
    union cidadao alguem;

    strcpy(alguem.nome, "47886052285");
    printf("CPF: %s\n", alguem.cpf);
    
    strcpy(alguem.nome, "789230476275682"); 
    printf("RG: %s\n", alguem.rg);

    strcpy(alguem.nome, "Gabriel de Castro");
    printf("Nome: %s\n", alguem.nome);

    printf("Dados sobrescritos:\n");
    printf("%s %s %s", alguem.cpf, alguem.rg, alguem.nome); //como todos são char, será impresso o mesmo conteúdo

    return 0;

}