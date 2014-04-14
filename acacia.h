#define ALPHABET_SIZE sizeof(char)


int cache_set(char *key, char *value);


struct Node {
	struct Node *alphabet[ALPHABET_SIZE];
	char *cargo;
};
