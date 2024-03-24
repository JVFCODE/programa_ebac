#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 40
#define MAX_USERS 100

// Estrutura para armazenar informações do usuário
typedef struct {
    char usuario[MAX_LENGTH];
    char senha[MAX_LENGTH];
} Conta;

// Variáveis globais
Conta contas[MAX_USERS];
int numContas = 0;
bool loggedIn = false; // Variável para rastrear se o usuário está logado

void criarConta();
bool fazerLogin();
void registro();
void consulta();
void deletar();

int main() {
    int opcao = 0;

    // Exibir opções de login primeiro
    while (!loggedIn) {
        system("cls");
        setlocale(LC_ALL, "portuguese");

        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada: \n\n");
        printf("\t1  - Criar conta \n");
        printf("\t2  - Fazer login \n");
        printf("\t3  - Sair do sistema \n\n");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                criarConta();
                break;

            case 2:
                loggedIn = fazerLogin();
                break;

            case 3:
                printf("Obrigado por utilizar o sistema! \n");
                return 0;

            default:
                printf("Número inválido, tente novamente.\n");
                break;
        }

        system("pause");
    }

    // opções após login
    do {
        system("cls");
        setlocale(LC_ALL, "portuguese");

        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1  - Registrar nomes \n");
        printf("\t2  - Consultar nomes \n");
        printf("\t3  - Deletar nomes \n");
        printf("\t4  - Sair do sistema \n\n");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;
                
            case 4:
                printf("Obrigado por utilizar o sistema! \n");
                return 0;

            default:
                printf("Número inválido, tente novamente.\n");
                break;
        }

        system("pause");
    } while (true);

    return 0;
}

void criarConta() {
    if (numContas >= MAX_USERS) {
        printf("Número máximo de contas atingido.\n");
        return;
    }

    Conta novaConta;

    printf("Digite o nome de usuário para a nova conta: ");
    scanf("%39s", novaConta.usuario);

    printf("Digite a senha para a nova conta: ");
    scanf("%39s", novaConta.senha);

    contas[numContas++] = novaConta;

    printf("Conta criada com sucesso.\n");
}

bool fazerLogin() {
    char usuario[MAX_LENGTH];
    char senha[MAX_LENGTH];

    printf("Digite o nome de usuário: ");
    scanf("%39s", usuario);

    printf("Digite a senha: ");
    scanf("%39s", senha);

    for (int i = 0; i < numContas; i++) {
        if (strcmp(usuario, contas[i].usuario) == 0 && strcmp(senha, contas[i].senha) == 0) {
            printf("Login bem-sucedido!\n");
            return true;
        }
    }

    printf("Nome de usuário ou senha incorretos.\n");
    return false;
}

void registro() {
   
}

void consulta() {
    
}

void deletar() {
    
}
