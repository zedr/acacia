#include "acacia.h"


struct Node *make_node()
{
	struct Node *s = malloc(sizeof *s);
	if (s == NULL)
		return NULL;
	*s = (struct Node) {{0}, 0};
	return s;
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
	unsigned char ch;
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

