#include <stdlib.h>

#define ALPHABET_SIZE sizeof(char)
#define MAX_KEY_SIZE 1024

struct Node {
	struct Node *ks[ALPHABET_SIZE];
	char *cargo;
};


struct Node *cache_init() {
	struct Node *head = malloc(sizeof(struct Node));
	return head;
}

struct Node *walk(char *str, struct Node *parent)
{
	char ch;
	int idx;
	struct Node *current = parent;

	printf("%p", current);
	for (idx = 0; idx < MAX_KEY_SIZE; idx++) {
		ch = *str++;

		if (ch == '\0')
			break;

		if (!(current->ks[ch])) {
			current->ks[ch] = malloc(sizeof(struct Node));
		}
		current = current->ks[ch];
		printf(" ~> %p (%c)", current, ch);
	}
	printf(".\n", current);
	return current;
}

int cache_set(char *key, char *value, struct Node *cache)
{
	struct Node *current = walk(key, cache);
	current->cargo = value;
	return 0;
}

char *cache_get(char *key, struct Node *cache)
{
	struct Node *current = walk(key, cache);
	return current->cargo;
}

