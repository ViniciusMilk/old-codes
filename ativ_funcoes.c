// Questão 1.

#include <stdio.h>
#include <stdlib.h>

int dobro(int dob)
{
    int dobro = dob * 2;
    printf("O dobro do valor digitado eh %d", dobro);
}
int main()
{
    int a;
    printf("Digite um numero e Aperte enter para saber o dobro desse numero. \n");
    scanf("%d", &a);

    dobro(a);
    return 0;
}

// Questão 2.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void positivo(int posi);
    int a;
    printf("Digite um numero real inteiro\n");
    scanf("%d", &a);
    positivo(a);
    return 0;
}
void positivo(int posi)
{

    if (posi < 0)
    {
        printf("O numero digitado eh negativo");
    }
    else if (posi == 0)
    {
        printf("o nuemro digitado eh 0");
    }
    else if (posi > 0)
    {
        printf("O numero digitado eh positivo");
    }
}
// Questão 3.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    void quadrado(float quad);
    float valor;
    printf("Digite um valor: ");
    scanf("%f", &valor);
    quadrado(valor);
    return 0;
}
void quadrado(float quad)
{
    float n = sqrt(quad);
    printf("A raiz quadrada do numero digitado eh %.2f\n", n);
    int n1 = n;
    float n2 = n - n1;
    if (n2 == 0)
    {
        printf("O valor eh quadrado perfeito.");
    }
    else
    {
        printf("O valor nao eh quadrado perfeito.");
    }
}

// Questão 4.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void transformacao(float pok);
    float a;
    printf("Digite uma temperatura em celsius: ");
    scanf("%f", &a);
    transformacao(a);
    return 0;
}
void transformacao(float pok)
{
    float x = (1.8 * pok) + 32;
    printf("A temperatura corresponde a %0.2f em graus graus farenheight", x);
}

// Questão 5.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float calhip(int c, int d);
    int c, d;
    printf("Digite um valor\n");
    scanf("%d", &c);
    printf("Digite outro valor\n");
    scanf("%d", &d);
    float e = calhip(c, d);
    printf("%.2f", e);
    calhip(c, d);

    return 0;
}
float calhip(int c, int d)
{
    return sqrt((c * c) + (d * d));
}

// Questão 6.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int somanum(a);

    int b, soma2 = 0;
    printf("Digite um numero inteiro.\n");
    scanf("%d", &b);

    soma2 = somanum(b);

    printf("%d", soma2);
    return 0;
}
int somanum(int a)
{
    int soma = 0;
    while (a > 0)
    {
        soma += a % 10;
        a = a / 10;
    }
    return soma;
}

// Questão 7.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    void hoje(int a, int b, char c);
    int a, b;
    char c;
    printf("Digite um numero:\n");
    scanf("%d", &a);
    printf("Digite outro numero:\n");
    scanf("%d", &b);
    printf("Digite o sinal de uma equacao\n");
    scanf(" %c", &c);
    hoje(a, b, c);
    return 0;
}
void hoje(int a, int b, char c)
{
    int d;
    if (c == '+')
    {
        d = a + b;
        printf("O resultado eh %d", d);
    }
    if (c == '-')
    {
        d = a - b;
        printf("O resultado eh %d", d);
    }
    if (c == '/')
    {
        d = a / b;
        printf("O resultado eh %d", d);
    }
    if (c == '*')
    {
        d = a * b;
        printf("O resultado eh %d", d);
    }
}

// Questão 8.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    void desenhalina(int a);
    int a;
    printf("quantas sinais de = devo desenhados? ");
    scanf("%d", &a);
    desenhalina(a);
    return 0;
}
void desenhalina(int a)
{
    int b;
    for (b = 0; b < a; b++)
    {
        printf("=");
    }
}

// Questão 9

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void ab(int a);
    int d;
    printf("Digite um numero;");
    scanf("%d", &d);
    ab(d);

    return 0;
}
void ab(int a)
{
    int maior;
    while (a != 1)
    {
        if (a % 2 == 0)
        {
            a = a / 2;
            maior = 2;
        }
        else
        {
            if (a % 3 == 0)
            {
                a = a / 3;
                maior = 3;
            }
            else
            {
                if (a % 5 == 0)
                {
                    a = a / 5;
                    maior = 5;
                }
                else
                {
                    if (a % 7 == 0)
                    {
                        a = a / 7;
                        maior = 7;
                    }
                    else
                    {
                        if (a % 11 == 0)
                        {
                            a = a / 11;
                            maior = 11;
                        }
                        else
                        {
                            if (a % 13 == 0)
                            {
                                a = a / 13;
                                maior = 13;
                            }
                            else
                            {
                                if (a % 17 == 0)
                                {
                                    a = a / 17;
                                    maior = 17;
                                }
                                else
                                {
                                    if (a % 19 == 0)
                                    {
                                        a = a / 19;
                                        maior = 19;
                                    }
                                    else
                                    {
                                        if (a % 23 == 0)
                                        {
                                            a = a / 23;
                                            maior = 23;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", maior);
}

// Questão 10.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void desenhalina(int a);
    int a;
    printf("quantas sinais de ! devo desenhados? ");
    scanf("%d", &a);
    desenhalina(a);
    return 0;
}
void desenhalina(int a)
{
    int b;
    char c = '!';
    for (b = 0; b < a; b++)
    {
        printf("%c", c);
        for (int f = 1; f <= b; f++)
        {
            printf(" %c", c);
        }
        printf("\n");
    }
}

// Questão 11.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void desenhalina(int a);
    int a;
    printf("quantas sinais de ! devo desenhados? ");
    scanf("%d", &a);
    desenhalina(a);
    return 0;
}
void desenhalina(int a)
{
    int b;
    int f;
    for (b = 0; b < a; b++)
    {
        printf("!");
        for (f = 1; f <= b; f++)
        {
            printf("!");
        }
        printf("\n");
    }
    for (b = a - 1; b > 0; b--)
    {
        printf("!");
        for (f = b - 1; f >= 1; f--)
        {
            printf("!");
        }
        printf("\n");
    }
}
