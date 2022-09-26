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

    //O 'do' está executando o código, apartir da função while, que significa 'enquanto',
    //enquanto a informação que está no while for 'true' o do será executado.
    //mesmo que a informação contida no while seja 'false', o programa irá rodar ao menos uma vez,
    //até chegar no while no fim do código, confirmando o 'false' o programa irá parar.
    do {
        //variável específica para os casos de erro no programa
        int hasError = 0;

        printf("\n+ SUM\n- SUBTRACTION\n* MULTIPLICATION\n/ DIVISION\n^ POTENTIATION\nr SQUARE ROOT \n");
        fflush(stdin);
        scanf("%c", &option);

       

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
                //tendo em mente que não é possível dividir um número por 0, foi necessário uma mensagem de erro caso o usuário digite o valor de 0
                //na variável 'value2'.
                printf("\nEnter a value:");
                scanf("%f", &value1);

                printf("Enter another value:");
                scanf("%f", &value2);
                if (value2 == 0) {
                    hasError = 1;
                    printf("\nERROR\n");
                    option = '1';
                } else {
                    result = value1 / value2;
                }


                break;

                //Tanto o case ^ e o case r, que respectivamente representam a exponenciação e raiz quadrada,
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
                //'default' que serve como se fosse um 'else' do switch case, está dizend que a variável destinada ao erro, é 'true'
                // e apartir dai a variável 'option' vale 1
            default:
                hasError = 1;
                option = '1';
                printf("Invalid option, retype \n");

        }

     
        //Eu quis que minha calculadora reiniciasse logo após o programa printar o resultado,
        //coloquei então, duas opções para continuar 1 ou 2, e caso o usuário digite algum valor diferente desses dois
        //o programa mostrará uma mensagem de opção inválida e pedirá que o usuário digite novamente.

        if (!hasError) {
            printf("\nThe result is: %.2f\n", result);

            printf("\nTo continue press '1' to end press '2'\n");
            fflush(stdin);
            scanf("%c", &option);

            while (option != '1' && option != '2') {
                printf("Invalid option, retype \n");
                fflush(stdin);
                scanf("%c", &option);
            }
        }

    } while (option == '1');


    return 0;
}

