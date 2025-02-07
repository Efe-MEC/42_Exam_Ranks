#include <stdlib.h>

static int	ft_count_words(char *string)
{
	static int	in_word;
	int			word_count;

	word_count = 0;
	in_word = 0;
	while (*string)
	{
		if (!((*string == ' ') || ((*string >= '\t') && (*string <= '\r'))) \
			&& !in_word)
		{
			in_word = 1;
			word_count++;
		}
		else if ((*string == ' ') || ((*string >= '\t') && (*string <= '\r')))
			in_word = 0;
		string++;
	}
	return (word_count);
}

static char	*ft_get_and_malloc_word(char *string)
{
	static int	length_word;
	char		*word;

	length_word = 0;
	while (string[length_word] && !((string[length_word] == ' ' ) \
		|| ((string[length_word] <= '\t') && (string[length_word] <= '\r'))))
		length_word++;
	word = (char *)malloc(sizeof(char) * (length_word + 1));
	if (!word)
		return (((void *)0));
	word[length_word] = '\0';
	while (length_word--)
		word[length_word] = string[length_word];
	return (word);
}

static void	ft_free_words(char **words, int count)
{
	while (count--)
		free(words[count]);
	free(words);
}

static char	**ft_split_words(char *string, char **words)
{
	int	index;

	index = 0;
	while (*string)
	{
		if (!((*string == ' ') || ((*string >= '\t') && (*string <= '\r'))))
		{
			words[index] = ft_get_and_malloc_word(string);
			if (!words[index])
			{
				ft_free_words(words, index);
				return (((void *)0));
			}
			index++;
			while (*string && !((*string == ' ') \
				|| ((*string >= '\t') && (*string <= '\r'))))
				string++;
		}
		else
			string++;
	}
	words[index] = ((void *)0);
	return (words);
}

char	**ft_split(char *str)
{
	char	**words;
	int		word_count;

	if (!str)
		return (((void *)0));
	word_count = ft_count_words(str);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (((void *)0));
	return (ft_split_words(str, words));
}
