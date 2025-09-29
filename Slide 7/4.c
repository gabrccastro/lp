#include <stdio.h>

union valor{
    float real;
    float dolar;
    float euro;
};

struct preco{
    char tipo;
    union valor valor;
};

void exibe(struct preco p){
       switch (p.tipo) {
        case 'R':
            printf("Preço: %.2f R$\n", p.valor.real);
            break;
        case 'D':
            printf("Preço: %.2f $\n", p.valor.dolar);
            break;
        case 'E':
            printf("Preço: %.2f €\n", p.valor.euro);
            break;
        default:
            printf("Tipo de moeda inválido!\n");
    }
}

void altera(struct preco *p, char novoTipo) {
    float valorEmReais;
    
    switch (p->tipo) {
        case 'R':
            valorEmReais = p->valor.real;
            break;
        case 'D':
            valorEmReais = p->valor.dolar * 5.35; // 1$ = 5.35 R$
            break;
        case 'E':
            valorEmReais = p->valor.euro * 6.26; // 1€ = 6.26 R$
            break;
        default:
            printf("Tipo de moeda atual inválido!\n");
            return;
    }
  
    p->tipo = novoTipo; // atualiza o tipo e converte para o novo subtipo
    switch (novoTipo) {
        case 'R':
            p->valor.real = valorEmReais;
            break;
        case 'D':
            p->valor.dolar = valorEmReais / 5.0;
            break;
        case 'E':
            p->valor.euro = valorEmReais / 5.5;
            break;
        default:
            printf("Novo tipo inválido!\n");
    }
}

int main() {
    struct preco p;

    p.tipo = 'R'; // Preço inicial em reais
    p.valor.real = 100.0;
    exibe(p);

    altera(&p, 'D'); // Converte para dólares
    exibe(p);

    altera(&p, 'E'); // Converte para euros
    exibe(p);
    
    altera(&p, 'R'); // Converte de volta para reais
    exibe(p);

    return 0;
}
