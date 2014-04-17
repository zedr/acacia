#include <stdlib.h>

#define ALPHABET_SIZE 127
#define MAX_KEY_SIZE 1024

struct Node {
	struct Node *ks[ALPHABET_SIZE];
	char *cargo;
};


struct Node *cache_init() {
	struct Node *head = malloc(sizeof(struct Node));
	return head;
}


struct Node *set_key(char *str, struct Node *parent, int write)
{
	char ch;
	int idx;
	struct Node *current = parent;

	//printf("%p", current);
	for (idx = 0; idx < MAX_KEY_SIZE; idx++) {
		ch = *(str+idx);

		if (ch == '\0')
			break;
		//printf(" ~> (%c:%d)", ch, ch);

		if (!(current->ks[ch])) {
			if (write == 1) {
				current->ks[ch] = malloc(sizeof(struct Node));
			} else {
				current = NULL;
				break;
			}
		}
		current = current->ks[ch];
		//printf(" %p", current);
	}
	//printf(".\n", current);
	return current;
}

int cache_set(char *key, char *value, struct Node *cache)
{
	struct Node *current = set_key(key, cache, 1);
	current->cargo = value;
	return 0;
}

char *cache_get(char *key, struct Node *cache)
{
	struct Node *current = set_key(key, cache, 0);

	if (current == NULL) {
		return NULL;
	} else {
		return current->cargo;
	}
}

