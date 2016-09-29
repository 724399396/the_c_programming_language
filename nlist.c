#include <stdlib.h>
#include <string.h>
#define HASHSIZE 1000

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *lookup(char *name);
struct nlist *install(char *name, char *defn);
void undef(char *name);
unsigned hash(char *name);

struct nlist *hashtab[HASHSIZE];

void main(){}

struct nlist *lookup(char *name) {
  struct nlist *np;
  
  for (np = hashtab[hash(name)]; np != NULL; np = np->next)
      if (strcmp(name, np->name) == 0)
          return np;
  return NULL;
}

struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned h;

  if ((np = lookup(name)) == NULL) {
    np = malloc(sizeof (struct nlist));
    if (np == NULL || (np->name = strdup(name)) == NULL)
        return NULL;
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    h = hash(name);
    np->next = hashtab[h];
    hashtab[h] = np;
  } else {
    if ((np->defn = strdup(defn)) == NULL)
       return NULL;
  }
  return np;
}

unsigned hash(char *name) {
  unsigned i;

  for (i = 0; *name++; ) {
    i = *name * 31 + i;
  }
  
  return i % HASHSIZE;
}

void undef(char *name) {
  struct nlist *np;
  unsigned h;
  
  if ((np = lookup(name)) != NULL) {      
      install(name, NULL);
  }
}
