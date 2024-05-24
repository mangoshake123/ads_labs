#include <stdio.h>
#include <stdlib.h>

struct poly *add(struct poly *p1, struct poly *p2);
struct poly *createPolynomial(int n);
void printPolynomial(struct poly *p);

struct poly
{
    int coeff;
    int exponent;
    struct poly *next;
};

int main()
{
    int n1, n2;
    struct poly *poly1, *poly2, *poly3;

    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n1);
    poly1 = createPolynomial(n1);
    printPolynomial(poly1);

    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n2);
    poly2 = createPolynomial(n2);
    printPolynomial(poly2);

    poly3 = add(poly1, poly2);
    printf("\nFinal polynomial: ");
    printPolynomial(poly3);

    return 0;
}

struct poly *add(struct poly *p1, struct poly *p2)
{
    struct poly *head = NULL, *p3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (head == NULL)
        {
            head = p3 = (struct poly *)malloc(sizeof(struct poly));
            p3->next = NULL;
        }
        else
        {
            p3->next = (struct poly *)malloc(sizeof(struct poly));
            p3 = p3->next;
            p3->next = NULL;
        }
        if (p1->exponent == p2->exponent)
        {
            p3->coeff = p1->coeff + p2->coeff;
            p3->exponent = p1->exponent;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exponent > p2->exponent)
        {
            p3->coeff = p1->coeff;
            p3->exponent = p1->exponent;
            p1 = p1->next;
        }
        else
        {
            p3->coeff = p2->coeff;
            p3->exponent = p2->exponent;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        p3->coeff = p1->coeff;
        p3->exponent = p1->exponent;
        p1 = p1->next;
        p3->next = (struct poly *)malloc(sizeof(struct poly));
        p3 = p3->next;
        p3->next = NULL;
    }

    while (p2 != NULL)
    {
        p3->coeff = p2->coeff;
        p3->exponent = p2->exponent;
        p2 = p2->next;
       
        p3->next = (struct poly *)malloc(sizeof(struct poly));
        p3 = p3->next;
        p3->next = NULL;
        
    }

    return head;
}

struct poly *createPolynomial(int n)
{
    struct poly *head, *p;
    head = p = (struct poly *)malloc(sizeof(struct poly));
    p->next = NULL;
    for (int i = 0; i < n+1; i++)
    {
        printf("Enter the coefficient and exponent values : ");
        scanf("%d %d", &(p->coeff), &(p->exponent)); 
        if (i < n+1)
        {
            p->next = (struct poly *)malloc(sizeof(struct poly));
            p = p->next;
            p->next = NULL;
        }
    }
    return head;
}

void printPolynomial(struct poly *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
        {
            if (poly->coeff >= 0)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}
