/* calc.c
   Postfixe (cours 5.3) :
   - nombre -> on empile
   - operateur -> on depile 2 nombres, on calcule, on empile le resultat
   Parenthesage (TD3 Q1) :
   - ouvrant -> on empile
   - fermant -> on depile et on verifie que ca correspond
   - a la fin la pile doit etre vide
*/
#include "calc.h"
#include "pile.h"
#include <stdlib.h>
#include <string.h>
static int est_ouvrant(char c) {
    return c == '(' || c == '[' || c == '{';
}
static int est_fermant(char c) {
    return c == ')' || c == ']' || c == '}';
}
static int vont_ensemble(char ouvrant, char fermant) {
    if (ouvrant == '(' && fermant == ')') return 1;
    if (ouvrant == '[' && fermant == ']') return 1;
    if (ouvrant == '{' && fermant == '}') return 1;
    return 0;
}
int parentheses_bien_formees(const char *expr) {
    Pile p;
    pile_init(&p);
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (est_ouvrant(c)) {
            if (pile_empiler(&p, c) != 0) {
                pile_detruire(&p);
                return 0;
            }
        } else if (est_fermant(c)) {
            int ouvert;
            if (pile_depiler(&p, &ouvert) != 0) {
                pile_detruire(&p);
                return 0; /* fermant sans ouvrant */
            }
            if (!vont_ensemble((char)ouvert, c)) {
                pile_detruire(&p);
                return 0; /* ex : ([)] */
            }
        }
    }
    int ok = pile_est_vide(&p);
    pile_detruire(&p);
    return ok;
}
int evaluer_postfixe(const char *expr, int *resultat) {
    Pile p;
    pile_init(&p);
    /* strtok modifie la chaine, donc on travaille sur une copie */
    char *copie = malloc(strlen(expr) + 1);
    if (copie == NULL) {
        return -1;
    }
    strcpy(copie, expr);
    int code = 0;
    char *tok = strtok(copie, " \t\n");
    while (tok != NULL && code == 0) {
        char *fin = NULL;
        long val = strtol(tok, &fin, 10);
        /* Cas 1 : c'est un nombre, meme negatif comme -5 */
        if (fin != tok && *fin == '\0') {
            if (pile_empiler(&p, (int)val) != 0) {
                code = -1;
            }
        }
        /* Cas 2 : c'est un operateur */
        else if (strlen(tok) == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/')) {
            int b, a;
            if (pile_depiler(&p, &b) != 0 || pile_depiler(&p, &a) != 0) {
                code = -1;
                break;
            }
            int r = 0;
            if (tok[0] == '+') r = a + b;
            if (tok[0] == '-') r = a - b;
            if (tok[0] == '*') r = a * b;
            if (tok[0] == '/') {
                if (b == 0) {
                    code = -2;
                    break;
                }
                r = a / b;
            }
            if (pile_empiler(&p, r) != 0) {
                code = -1;
            }
        }
        /* Cas 3 : autre chose, ex : $ */
        else {
            code = -1;
        }
        tok = strtok(NULL, " \t\n");
    }
    /* A la fin il doit rester exactement un nombre */
    if (code == 0) {
        if (pile_depiler(&p, resultat) != 0) {
            code = -1;
        } else if (!pile_est_vide(&p)) {
            code = -1; /* ex : "3 4" */
        }
    }
    pile_detruire(&p);
    free(copie);
    return code;
}
