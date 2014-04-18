#include <stdlib.h>

#define ALPHABET_SIZE 127
#define MAX_KEY_SIZE 1024


struct Node {
	struct Node *ks[ALPHABET_SIZE];
	char *cargo;
};

struct Node *make_node()
{
	struct Node *head = malloc(sizeof(struct Node));
	int idx;
	for (idx = 0; idx < ALPHABET_SIZE; idx++)
		head->ks[idx] = NULL;

	return head;
}

struct Node *cache_init()
{
	return make_node();
}

void cache_close(struct Node *head)
{
	int idx;

	for (idx = 0; idx < ALPHABET_SIZE; idx++) {
		if (head->ks[idx] != NULL)
			cache_close(head->ks[idx]);
	}
	free(head);
}

struct Node *set_key(char *str, struct Node *parent, int write)
{
	char ch;
	int idx;
	struct Node *current = parent;

	for (idx = 0; idx < MAX_KEY_SIZE; idx++) {
		ch = *(str+idx);

		if (ch == '\0')
			break;

		if (!(current->ks[ch])) {
			if (write == 1) {
				current->ks[ch] = make_node();
			} else {
				current = NULL;
				break;
			}
		}
		current = current->ks[ch];
	}
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

