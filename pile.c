/* pile.c - implementation de la pile */
#include "pile.h"
#include <stdlib.h>
void pile_init(Pile *p) {
    p->sommet = NULL;
    p->taille = 0;
}
/* On empile au sommet : O(1) */
int pile_empiler(Pile *p, int v) {
    PNoeud *n = malloc(sizeof *n);
    if (n == NULL) {
        return -1;
    }
    n->v = v;
    n->suiv = p->sommet;
    p->sommet = n;
    p->taille++;
    return 0;
}
/* On depile du sommet : O(1) */
int pile_depiler(Pile *p, int *out) {
    if (p->sommet == NULL) {
        return -1; /* pile vide */
    }
    PNoeud *n = p->sommet;
    if (out != NULL) {
        *out = n->v;
    }
    p->sommet = n->suiv;
    free(n);
    p->taille--;
    return 0;
}
int pile_est_vide(const Pile *p) {
    return p->sommet == NULL;
}
void pile_detruire(Pile *p) {
    int tmp;
    while (pile_depiler(p, &tmp) == 0) {
    }
}
