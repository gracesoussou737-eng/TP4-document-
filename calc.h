/* calc.h - TP3 questions 2 et 3 */
#ifndef CALC_H
#define CALC_H
/* Evalue une expression postfixee, ex : "3 4 + 5 *"
   Retour : 0 = ok, -1 = mal formee, -2 = division par zero */
int evaluer_postfixe(const char *expr, int *resultat);
/* Verifie le parenthesage () [] {}
   Retour : 1 = bien parenthese, 0 = sinon */
int parentheses_bien_formees(const char *expr);
#endif
