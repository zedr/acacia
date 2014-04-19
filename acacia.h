#include <stdlib.h>

#define ALPHABET_SIZE 127
#define MAX_KEY_SIZE 1024



struct Node *make_node();
struct Node *cache_init();
void cache_close(struct Node *head);
struct Node *set_key(char *str, struct Node *parent, int write);
int cache_set(char *key, char *value, struct Node *cache);
char *cache_get(char *key, struct Node *cache);

struct Node {
	struct Node *ks[ALPHABET_SIZE];
	char *cargo;
};
