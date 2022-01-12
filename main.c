// USANDO A FUNCAO f(x) = xe^x-1,2
// TEMOS QUE f'(x) = e^x + xe^x
// E QUE f''(x) = 2e^x + xe^x
// verificando que f(x).f''(x) > 0
// intervalo (0.6;0.7)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define e 2.7182818284590452353602874
#define f(x, ex) (x * ex) - 1.2 // função f(x)
#define f1(x, ex) ex + (x * ex)// função f'(x)
#define f2(x, ex) (2 * ex) + (x * ex)// função f''(x)

/**
 *
 * @param A primeiro número do intervalo
 * @param B segundo número do intervalo
 * @return retorna qual dos números (A ou B) será o "chute inicial"
 */
double X0(double A, double B){
    double result1, result2, ex;
    ex = pow(e, A);
    result1 = f(A, ex);
    result2 = f2(A, ex);
    if (result1 * result2 > 0) return A;
    else{
        ex=pow(e, B);
        result1 = f(B, ex);
        result2 = f2(B, ex);
        if (result1 * result2 > 0) return B;
        else return 0;
    }
}
/**
 *
 * @param xn enézima iteração parao calculo da raiz x
 * @param ex é o valor do e^x
 * @param erro precisão para o calculo da raiz
 * @param it número de iterações feitas
 * @return retorna o valor aproximado da raiz
 */
double newtonMethod(double xn, double ex, double erro, int *it) {
    double verifica, x0 = xn;
    verifica = erro + 1.0; //forçando entrada no while

    printf("\tN\tf(Xn)\t\tf'(Xn)\t\tXn+1\t\t|Xn - Xn-1|\n");
    while (verifica > erro){
        ex = pow(e, x0);
        double f = f(x0, ex);
        double f1 = f1(x0, ex);
        xn = x0 - ((f) / (f1));
        verifica = fabs(xn - x0);
        if (verifica > erro) x0 = xn;
        printf("\n\t%d\t%lf\t%lf\t%lf\t%lf",*it, f, f1, xn, verifica);
        (*it)++;
    }
    return xn;
}
/**
 *
 * @param str string contendo o intervalo
 * @param A intervaloA
 * @param B intervaloB
 * A função desse procedimento, é pegar os valores do intervalo na string e substituir por um valor double
 */
void getInterval(char* str, double *A, double *B) {
    *A = atof(str + 1);
    *B = atof(strstr(str, ";") + 1);
}
int main() {
    char intervalo[25];
    double intervaloA, intervaloB, erro, x0, ex, xn, inicial;
    int i = 0;

    printf("Entre com o intervalo ex: (2.5;2.6): ");
    fgets(intervalo, sizeof(intervalo), stdin);
    getInterval(intervalo, &intervaloA, &intervaloB);

    printf("Entre com o valor do ERRO: ");
    scanf("%lf", &erro);

    x0 = X0(intervaloA, intervaloB);
    inicial = x0;

    xn = newtonMethod(x0, ex, erro, &i);

    printf("\n\nValor da Raiz: %.9lf\n"
           "X inicial: %lf\n"
           "Erro: %.9lf\n"
           "Foram necessarias %d iteracoes\n",xn, inicial, erro, i);

    return 0;
}