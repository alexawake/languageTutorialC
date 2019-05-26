void addWord(char * pword)
{
	Box * current = &topBox;
	while (current->next != 0)
	{
		if (strcmp(current->next->word, pword) > 0)
		{
			Box *neu = (Box *)malloc(sizeof(Box));
			strcpy(neu->word,pword);
			neu->counter = 1;
			neu->next = current->next;
			current->next = neu;
			return;
		}
		if (strcmp(current->next->word, pword) == 0)
		{
			current->next->counter++;
			return;
		}
		current = current->next;
	}
	Box *neu = (Box *)malloc(sizeof(Box));
	strcpy(neu->word, pword);
	neu->counter = 1;
	neu->next = 0;
	current->next = neu;
	return;

}
