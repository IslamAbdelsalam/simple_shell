char **tokenize(char *line)
{
	char *token, **tokens;
	unsigned int i = 0;
	tokens = malloc(sizeof(char) * 1024);
	if (tokens == NULL)
	{
		return (-1);
	}
	token = strtok(line, " \n\t\r");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtrok(NULL, " \n\t\r");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
