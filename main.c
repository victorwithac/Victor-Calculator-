#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>


//Declarando minhas variavéis, valor 1, valor 2, resultado e opção
int main(void) {
    float value1, value2, result = 0;
    char option;

//Cabeçalho
    printf("Welcome to Victor Marques dos Santos Calculator\n");
    printf("N 202220936\n");
    printf("Algorithm and Programming Course\n");
    printf("La Salle University\n\n\n");

    //O 'do' está executando o código, apartir da informação atribuida na função while, que significa 'enquanto',
    //enquanto a informação que está no while for 'true' o do será executado.
    do {
        int hasError = 0;

        printf("\n+ SUM\n- SUBTRACTION\n* MULTIPLICATION\n/ DIVISION\n^ POTENTIATION\nr SQUARE ROOT \n");
        fflush(stdin);
        scanf("%c", &option);

        //Como a raiz quadrada só lida com um valor, foi preciso trazer uma condicional para meu código que caso
        // a opção escolhida pelo usuário fosse 'r' o terminal pedisse apenas um valor

        //else (se não), o programa pediria então dois valores para as demais opções de operações

        //switch que é outra forma de usar a condicional como o 'if', deixa de forma mais organizada
        //em algumas situações, cada caso representa a escolha do usário para a variável 'option'
        //No momento que ele digita o símbolo que representa a opção escolhida o switch entra com um dos 'case'
        //E então por sua vez, atribui um valor para a variável 'result'

        switch (option) {
            case '+':
                printf("\nEnter a value:");
                scanf("%f", &value1);

                printf("Enter another value:");
                scanf("%f", &value2);

                result = value1 + value2;
                break;
            case '-':
                printf("\nEnter a value:");
                scanf("%f", &value1);

                printf("Enter another value:");
                scanf("%f", &value2);

                result = value1 - value2;
                break;
            case '*':
                printf("\nEnter a value:");
                scanf("%f", &value1);

                printf("Enter another value:");
                scanf("%f", &value2);

                result = value1 * value2;

                break;
            case '/':
                printf("\nEnter a value:");
                scanf("%f", &value1);

                printf("Enter another value:");
                scanf("%f", &value2);
                //realmente precisa do if, else?
                if (value2 == 0) {
                    hasError = 1;
                    printf("\nERROR\n");
                    option = '1';
                } else {
                    result = value1 / value2;
                }


                break;

                //Tanto o case 5 e o case 6, que respectivamente representam a exponenciação e raiz quadrada,
                //foram tirados da biblioteca math.h com as funções 'pow' e 'sqrt'
            case '^':
                printf("\nEnter a value:");
                scanf("%f", &value1);

                printf("Enter another value:");
                scanf("%f", &value2);
                result = pow(value1, value2);
                break;
            case 'r':
                printf("\nEnter a value:");
                scanf("%f", &value1);

                result = sqrt(value1);
                break;
            default:
                hasError = 1;
                option = '1';
                printf("Invalid option, retype 1\n");

        }

        //Para que fosse possível que não desse algum tipo de erro na leitura do programa e na hora do meu código
        //rodar no terminal, tive que utilizar das funções if, else if e else para que dependendo do valor atribuido
        //as variáveis pelo usuário, o terminal mostrasse de forma correta.

        //Eu quis que minha calculadora reiniciasse logo após o programa printar o resultado,
        //coloquei então, duas opções para continuar 1 ou 2, e caso o usuário digite algum valor diferente desses dois
        //o programa mostrará uma mensagem de opção inválida e pedirá que o usuário digite novamente.

        if (!hasError) {
            printf("\nThe result is: %.2f\n", result);

            printf("\nTo continue press '1' to end press '2'\n");
            fflush(stdin);
            scanf("%c", &option);

            while (option != '1' && option != '2') {
                printf("Invalid option, retype 2\n");
                fflush(stdin);
                scanf("%c", &option);
            }
        }

    } while (option == '1');


    return 0;
}

