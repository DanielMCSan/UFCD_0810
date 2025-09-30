// instrução para permitir ultrapassar a mensagem de erro
// do scanf()
#define _CRT_SECURE_NO_WARNINGS

//importar bilbiotecas para o nosso projeto
#include <stdio.h>
#include <stdlib.h>


//Procedimento do exercício1
void exercicio_1() {
    //Criar ponteiro para trabalhar com ficheiros
    FILE* fp;

    //Criar variável do tipo caracter
    char texto[1000];

    //Estrutura de decisão dupla (if/else)
    fp = fopen("ficheiro_tp3.txt", "r");  //abrir para leitura

    if (fp == NULL) {
        printf("Erro ao ler a informação do ficheiro\n");
    }
    else {
        //Estrutura de repetição while para ler até o final
        while (fgets(texto, sizeof(texto), fp) != NULL) {
            printf("%s", texto); //mostra linha a linha
        }

        //Fechar o ficheiro
        fclose(fp);
    }
}
//Procedimento do exercício2
void exercicio_2() {
    //Criar ponteiro para ficheiros
    FILE* fp;

    //Abrir ficheiro no modo "w" (write)
    fp = fopen("ficheiro_tp3_escrita.txt", "w");

    if (fp == NULL) {
        printf("Erro ao criar o ficheiro\n");
    }
    else {
        //Criar variável de texto e atribuir conteúdo
        char texto[100] = "Este é um exemplo de texto com mais de vinte caracteres.";

        //Escrever no ficheiro com puts()
        //puts escreve uma string + '\n' no ficheiro
        puts(texto);  //escreve na saída padrão (console)
        fputs(texto, fp); //escreve dentro do ficheiro corretamente

        //Fechar o ficheiro
        fclose(fp);

        printf("Dados gravados no ficheiro com sucesso.\n");
    }
}
//Procedimento do exercício3
void exercicio_3() {
    //Criar ponteiro para ficheiros
    FILE* fp;

    //Abrir ficheiro no modo "a" (append)
    fp = fopen("ficheiro_tp3_escrita.txt", "a");

    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro\n");
    }
    else {
        //Criar variável de texto e atribuir conteúdo (mínimo 35 caracteres)
        char expressao[150] = "Esta é uma nova linha de texto que será acrescentada ao ficheiro.";

        //Escrever no ficheiro com puts()
        fputs(expressao, fp);   //grava dentro do ficheiro
        fputs("\n", fp);        //acrescenta uma quebra de linha

        //(opcional: também mostrar no ecrã o que foi escrito)
        puts(expressao);

        //Fechar o ficheiro
        fclose(fp);

        printf("Dados adicionados ao ficheiro com sucesso.\n");
    }
}

//Programa principal
int main() {
    //exercicio_1(); //invocar o exercicio1
    //exercicio_2(); //invocar o exercicio2
    exercicio_3(); //invocar o exercicio3
    return 0;
}