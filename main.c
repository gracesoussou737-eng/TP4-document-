/* main.c - petite demo */
#include <stdio.h>
#include "calc.h"
int main(void) {
    int r;
    if (evaluer_postfixe("3 4 + 5 *", &r) == 0) {
        printf("3 4 + 5 * = %d\n", r);
    }
    printf("(a + [b*c]) : %s\n", parentheses_bien_formees("(a + [b*c])") ? "OK" : "ERREUR");
    printf("([)] : %s\n", parentheses_bien_formees("([)]") ? "OK" : "ERREUR");
    return 0;
}
