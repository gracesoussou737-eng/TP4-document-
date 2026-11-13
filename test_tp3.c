/* test_tp3.c - tests demandes dans le TP3 */
#include <assert.h>
#include <stdio.h>
#include "pile.h"
#include "file.h"
#include "calc.h"
int main(void) {
    /* --- Test pile : LIFO --- */
    Pile p;
    pile_init(&p);
    pile_empiler(&p, 10);
    pile_empiler(&p, 20);
    int x;
    assert(pile_depiler(&p, &x) == 0 && x == 20);
    assert(pile_depiler(&p, &x) == 0 && x == 10);
    assert(pile_depiler(&p, &x) == -1); /* pile vide */
    pile_detruire(&p);
    printf("test pile : OK\n");
    /* --- Test file : FIFO --- */
    File f;
    file_init(&f);
    file_enfiler(&f, 1);
    file_enfiler(&f, 2);
    file_enfiler(&f, 3);
    assert(file_defiler(&f, &x) == 0 && x == 1);
    assert(file_defiler(&f, &x) == 0 && x == 2);
    assert(file_defiler(&f, &x) == 0 && x == 3);
    assert(file_defiler(&f, &x) == -1); /* file vide */
    file_detruire(&f);
    printf("test file : OK\n");
    /* --- Test postfixe : valides --- */
    int r;
    assert(evaluer_postfixe("3 4 + 5 *", &r) == 0 && r == 35); /* cours */
    assert(evaluer_postfixe("6 2 / 3 - 4 *", &r) == 0 && r == 0); /* TD3 Q3 */
    assert(evaluer_postfixe("10 2 + 3 *", &r) == 0 && r == 36);
    assert(evaluer_postfixe("-5 3 +", &r) == 0 && r == -2);
    /* --- Test postfixe : invalides + division par zero --- */
    assert(evaluer_postfixe("3 +", &r) != 0);
    assert(evaluer_postfixe("3 4", &r) != 0);
    assert(evaluer_postfixe("3 4 $", &r) != 0);
    assert(evaluer_postfixe("3 0 /", &r) == -2);
    printf("test postfixe : OK\n");
    /* --- Test parentheses --- */
    assert(parentheses_bien_formees("(a + [b * c])") == 1);
    assert(parentheses_bien_formees("([{}])") == 1);
    assert(parentheses_bien_formees("([)]") == 0); /* mal imbriquees */
    assert(parentheses_bien_formees("((a + b)") == 0); /* pas fermee */
    assert(parentheses_bien_formees("a + b)") == 0); /* fermante seule */
    printf("test parentheses : OK\n");
    printf("Tous les tests TP3 : OK\n");
    return 0;
}
