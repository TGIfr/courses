//
// Created by tgifr on 19.02.17.
//

#ifndef NLP_LISTP_H
#define NLP_LISTP_H

typedef struct Text Text;
typedef struct Sentence Sentence;
typedef struct Word Word;



int sentenceWordsLength(Sentence *sentence);

int wordLength(Word * word);

void sortedInsert(Text *self, struct Sentence *new_node);

Sentence *  Text_deleteFirst(Text * self);
Sentence *  Text_deleteAt(Text * self, int position);

Word * Sentence_getWordAt(Sentence * self, int position);
Sentence* Text_getSentenceAt(Text * self, int position);
int textLength(Text * text);
int sentenceLength(Sentence * sent);
char * Word_getStr (Word * word);

void Text_free(struct Text ** self);
void Sentence_addLast(struct Sentence *self, Word *newWord);
void Text_addLast(struct Text *self, Sentence *newSentence);

struct Word * Word_new(char* value);
struct Sentence * Sentence_new(void);
struct Text * Text_new(void);

void Word_free(struct Word ** self);
void Sentence_free(struct Sentence ** self);







#endif //NLP_LISTP_H
