#include <stdio.h>

void soma(double a, double b) {
    double s = a + b;
    printf("\nResultado: %lf + %lf = %lf\n", a, b, s);
}

void sub(double a, double b) {
    double s = a - b;
    printf("\nResultado: %lf - %lf = %lf\n", a, b, s);
}

void mult(double a, double b) {
    double s = a * b;
    printf("\nResultado: %lf * %lf = %lf\n", a, b, s);
}
void parar(int *lista) {
    printf("Deseja realizar outra operação? (s/n):\n");
    char loop;
    scanf(" %c", &loop);
    if (loop == 's' || loop == 'S') {
        *lista = 0;
    }
    else if (loop == 'n' || loop == 'N') {
        *lista = 1;
        printf("Obrigado por usar a calculadora! Até a próxima.\n");
    }
    else {
        while (loop != 's' && loop != 'S' && loop != 'n' && loop != 'N') {
            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não: ");
            scanf(" %c", &loop);
        }
    
        if (loop == 's' || loop == 'S') {
            *lista = 0;
        }
        else if (loop == 'n' || loop == 'N') {
            *lista = 1;
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
        }
    }
    
}
void div(double a, double b, int *lista ) {
    if (b == 0) {
        printf("Erro: Divisão por zero não é permitida.\n");
        printf("Deseja realizar outra operação? (s/n):");
        char loop;
        scanf(" %c", &loop);
        if (loop == 's' || loop == 'S') {
            *lista = 0;
        }
        else if (loop == 'n' || loop == 'N') {
            *lista = 1;
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
        }
        else {
            while (loop != 's' && loop != 'S' && loop != 'n' && loop != 'N') {
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não: ");
                scanf(" %c", &loop);
            }
    
            if (loop == 's' || loop == 'S') {
                *lista = 0;
            }
            else if (loop == 'n' || loop == 'N') {
                *lista = 1;
                printf("Obrigado por usar a calculadora! Até a próxima.\n");
            }
        }
        
    }
    else{
        double s = a / b;
        printf("\nResultado: %lf / %lf = %lf\n", a, b, s);
        parar(lista);
    }

}


int main(){
    int lista = 0;
    while (lista == 0){

        printf("===============================\nCalculadora Simples\n===============================\nSelecione uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\nOpção:");
        int option, papoi, papi, retornoMenu;
        char extra = '\0';
        double a, b;
        retornoMenu = scanf("%d%c", &option, &extra);

        while (retornoMenu != 2 || extra != '\n' || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)) {
            if (retornoMenu == 0 || extra != '\n') {
                while (getchar() != '\n'); // Limpa o resto da linha presa no teclado
            }
            printf("Escolha uma das opções fornecidas.\n");
            printf("===============================\nCalculadora Simples\n===============================\nSelecione uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\nOpção: ");
            extra = '\0';
            retornoMenu = scanf("%d%c", &option, &extra);
        }
        if (option == 5) {
            lista = 1;
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        }
        printf("\nDigite o primeiro número: ");
        papoi = scanf("%lf", &a);
        while (papoi != 1) {
            while (getchar() != '\n'); // Limpa a letra presa no teclado
            printf("Entrada inválida, digite um número.\n");
            printf("Digite o primeiro número: ");
            papoi = scanf("%lf", &a);
            
        }
        printf("\nDigite o segundo número: ");
        papi = scanf("%lf", &b);
        while (papi != 1) {
            while (getchar() != '\n'); // Limpa a letra presa no teclado
            printf("Entrada inválida, digite um número.\n");
            printf("Digite o segundo número: ");
            papi = scanf("%lf", &b);
            
        }
       
        if(option == 1){
            soma(a,b);
            parar(&lista);
        }
        else if(option == 2){
            sub(a,b);
            parar(&lista);
        }
        else if(option == 3){
            mult(a,b);
            parar(&lista);
        }
        else if(option == 4) {
            div(a, b, &lista);

        }
    }
    return 0;
}   
