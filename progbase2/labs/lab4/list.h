//
// Created by tgifr on 19.02.17.
//

#ifndef LAB3_LIST_H
#define LAB3_LIST_H



typedef struct List List;
typedef struct dino dino;
int dino_count(struct List *self);
struct List * createDinoList();

struct dino * List_elementAt(struct List *self, int position);
struct dino * dino_new();
void List_free(struct List **self);

#endif //LAB3_LIST_H
