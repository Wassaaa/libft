#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

//cc main.c -Wall -Wextra -Werror -g -I . -L . -l ft

#define SIZE_ARRAY 6

void printArray(char arr[], int n) {
	int i = -1;
	while (++i < n)
		printf("%d %c\n", arr[i], arr[i]);
	printf("\n");
}

void	print_compare_array(char *ft, char *std, int n, char *desc)
{
	int i;
	int	ft_val;
	int	std_val;
	i = -1;
	printf("%s\nFT	--	STD\n", desc);
	while (++i < n)
	{
		if (ft)
			ft_val = ft[i];
		else
			ft_val = -1;
		if (std)
			std_val = std[i];
		else
			std_val = -1;
		printf("%d %c	--	%d %c\n", ft_val, ft_val, std_val, std_val);
	}
}

int	test_calloc(size_t count, size_t size, char *desc)
{
	char *ft_val;
	size_t i;

	ft_val = (char *)ft_calloc(count, size);
	printf("%s\n", desc);
	printArray(ft_val, count * size);
	i = 0;
	while (count * size > i)
	{
		if (ft_val[i] != 0)
		{
			free(ft_val);
			printf("wasn't initialized to 0s");
			return (0);
		}
		//if this segfaults, then memory area is not writable
		ft_val[i] = 'A';
		ft_val[i] = 0;
		i++;
	}
	free (ft_val);
	return (1);
}

int test_atoi(const char *input) {
	int result = ft_atoi(input);
	int expected = atoi(input);
	if (result == expected) {
		printf("Pass: ft_atoi(\"%s\") = %d\n", input, result);
		return 1;
	} else {
		printf("Fail: ft_atoi(\"%s\") expected %d but got %d\n", input, expected, result);
		return 0;
	}
}

int	test_strncmp(char *s1, char *s2, int n, char *desc)
{
	printf("Test: %s\n", desc);
	printf("Comparing '%s' and '%s' up to %d bytes:\n", s1, s2, n);
	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
	printf("strncmp: %d\n\n", strncmp(s1, s2, n));

	if (ft_strncmp(s1, s2, n) != strncmp(s1, s2, n))
		return (0);
	return (1);
}

int	test_strnstr(char *dest, char *src, int len, char *desc)
{
	char	ft_dest[256];
	char	std_dest[256];

	strncpy(ft_dest, dest, sizeof(ft_dest));
	strncpy(std_dest, dest, sizeof(std_dest));

	char *ft_ret = ft_strnstr(ft_dest, src, len);
	char *std_ret = strnstr(std_dest, src, len);

	printf("Test: finding '%s' in '%s' up to %d bytes | %s\n", src, ft_dest, len, desc);
	printf("\tft_strnstr returns:\n%s\n", ft_ret);
	printf("\tstrnstr returns:\n%s\n\n", std_ret);
	if (ft_ret == NULL && std_ret == NULL)
		return (1);
	if (ft_ret == NULL || std_ret == NULL)
		return (0);
	if (strcmp(ft_ret, std_ret) != 0)
		return (0);
	return (1);
}

int test_strlcat(char *dest, char *src, unsigned int size, char *desc)
{
	char	ft_dest[256];
	char	std_dest[256];

	strncpy(ft_dest, dest, sizeof(ft_dest));
	strncpy(std_dest, dest, sizeof(std_dest));

	unsigned int ft_ret = ft_strlcat(ft_dest, src, size);
	unsigned int std_ret = strlcat(std_dest, src, size);

	printf("Test: %s\n", desc);
	printf("\tft_strlcat returns:%u, Result: %s\n", ft_ret, ft_dest);
	printf("\tstrlcat returns:%u, Result: %s\n\n", std_ret, std_dest);
	if (ft_ret == 0 && std_ret == 0)
		return (1);
	if (ft_ret == 0 || std_ret == 0)
		return (0);
	if (ft_ret != std_ret && strcmp(ft_dest, std_dest) != 0)
		return (0);
	return (1);
}

int test_strchr(char *src, char c, char *desc)
{
	char	ft_src[256];
	char	std_src[256];

	strncpy(ft_src, src, sizeof(ft_src));
	strncpy(std_src, src, sizeof(std_src));

	char *ft_ret = ft_strchr(ft_src, c);
	char *std_ret = strchr(std_src, c);

	printf("Test: %s\n", desc);
	printf("\tft_strchr returns: %s\n", ft_ret);
	printf("\tstrchr returns: %s\n\n", std_ret);

	if (ft_ret == NULL && std_ret == NULL)
		return (1);
	if (ft_ret == NULL || std_ret == NULL)
		return (0);
	if (strcmp(ft_ret, std_ret) != 0)
		return (0);
	return (1);
}

int test_strrchr(char *src, char c, char *desc)
{
	char	ft_src[256];
	char	std_src[256];

	strncpy(ft_src, src, sizeof(ft_src));
	strncpy(std_src, src, sizeof(std_src));

	char *ft_ret = ft_strrchr(ft_src, c);
	char *std_ret = strrchr(std_src, c);

	printf("Test: %s\n", desc);
	printf("\tft_strrchr returns: %s\n", ft_ret);
	printf("\tstrrchr returns: %s\n\n", std_ret);

	if (ft_ret == 0 && std_ret == 0)
		return (1);
	if (ft_ret == 0 || std_ret == 0)
		return (0);
	if (strcmp(ft_ret, std_ret) != 0)
		return (0);
	return (1);
}

int	test_bzero(char *arr, int size, int print, char *desc)
{
	char	*std_arr;
	char	*ft_arr;

	std_arr = malloc(size);
	ft_arr = malloc(size);
	strcpy(std_arr, arr);
	strcpy(ft_arr, arr);
	ft_bzero(ft_arr, size);
	bzero(std_arr, size);
	print_compare_array(ft_arr, std_arr, print, desc);
	if (strcmp(ft_arr, std_arr) != 0) {
		printf("Test failed for ft_bzero vs. bzero\n");
		return (0);
	}
	free(std_arr);
	free(ft_arr);
	return (1);
}
int	test_memchr(char *str, char c, int size, int print, char *desc)
{
	char *ft_str = (char *)ft_memchr(str, c, size);
	char *std_str = (char *)memchr(str, c, size);

	print_compare_array(ft_str, std_str, print, desc);

	if (std_str != ft_str) {
		printf("Test failed for ft_memchr vs. memchr\n");
		return (0);
	}
	return (1);
}
int normalize_result(int result) {
	if (result < 0)
		return -1;
	if (result > 0)
		return 1;
	return 0;
}

int	test_memcmp(char *str1, char *str2, int size, char *desc)
{
	int ft_res = normalize_result(ft_memcmp(str1, str2, size));
	int std_res = normalize_result(memcmp(str1, str2, size));

	printf("%s\n", desc);
	printf("ft_memcmp result --> %d vs %d <-- memcmp result\n\n", ft_res, std_res);

	if (ft_res != std_res) {
		printf("Test failed for ft_memcmp vs. memcmp\n");
		return (0);
	}
	return (1);
}

int test_memcpy(char *dest, char *src, size_t size, char *desc)
{
	char	ft_dest[256];
	char	std_dest[256];

	strncpy(ft_dest, dest, sizeof(ft_dest));
	strncpy(std_dest, dest, sizeof(std_dest));

	char *ft_ret = ft_memcpy(ft_dest, src, size);
	char *std_ret = memcpy(std_dest, src, size);
	printf("copying '%s' into '%s' for the first %ld bytes\n", src, dest, size);
	print_compare_array(ft_ret, std_ret, size + 1, desc);

	if (memcmp(ft_ret, std_ret, size) != 0)
		return (0);
	return (1);
}

int test_memmove(char *src, int dest_offset, int src_offset, size_t size, char *desc) {
	char ft_src[256];
	char std_src[256];
	strncpy(ft_src, src, sizeof(ft_src));
	strncpy(std_src, src, sizeof(std_src));

	printf("copying '%s' into '%s' for the first %ld bytes\n", ft_src + src_offset, ft_src + dest_offset, size);
	char *ft_ret = ft_memmove(ft_src + dest_offset, ft_src + src_offset, size);
	char *std_ret = memmove(std_src + dest_offset, std_src + src_offset, size);
	print_compare_array(ft_ret, std_ret, strlen(src), desc);

	if (memcmp(ft_ret, std_ret, size) != 0)
		return 0;
	return 1;
}

int test_memset(char *src, char c, size_t size, char *desc)
{
	char ft_src[256];
	char std_src[256];

	strncpy(ft_src, src, sizeof(ft_src));
	strncpy(std_src, src, sizeof(std_src));

	printf("replacing %ld bytes in '%s' with '%c'\n", size, src, c);
	char *ft_ret = ft_memset(ft_src, c, size);
	char *std_ret = memset(std_src, c, size);
	print_compare_array(ft_ret, std_ret, strlen(src), desc);
	if (memcmp(ft_ret, std_ret, size) != 0)
		return 0;
	return 1;
}

int test_strdup(char *src, char *desc)
{
	char *ft_ret = ft_strdup(src);
	char *std_ret = strdup(src);

	printf("Test: %s\n", desc);
	if (strcmp(ft_ret, std_ret) != 0) {
		printf("Fail: ft_strdup(\"%s\") expected %s but got %s\n", src, std_ret, ft_ret);
		free(ft_ret);
		free(std_ret);
		return (0);
	} else {
		printf("Pass: ft_strdup(\"%s\") = '%s'\n", src, ft_ret);
		free(ft_ret);
		free(std_ret);
		return (1);
	}
}

int test_strlen(const char *src, char *desc) {
	size_t ft_ret = ft_strlen(src);
	size_t std_ret = strlen(src);

	printf("Test: %s\n", desc);
	if (ft_ret != std_ret) {
		printf("Fail: ft_strlen(\"%s\") expected %zu but got %zu\n", src, std_ret, ft_ret);
		return 0;
	} else {
		printf("Pass: ft_strlen(\"%s\") = '%zu'\n", src, ft_ret);
		return 1;
	}
}

typedef	struct {
	void *input;
	void *expected_output;
	char* descsription;
} test_case;

void increment_char(char *c)
{
	(*c)++;
}

void	cap_alternate(unsigned int i, char *str)
{
	if (i % 2 == 0)
		*str = toupper((int)(unsigned char)*str);
	else
		*str = tolower((int)(unsigned char)*str);
}
int	test_striteri(char *test_str, void (*f)(unsigned int, char *), char *expected, char *desc)
{
	char *str;

	str = strdup(test_str);
	if (!str)
	{
		printf("Failed to allocate memory for str in striteri");
		return (0);
	}
	printf("%s\n", desc);
	printf("Original string: %s\n", str);
	ft_striteri(str, f);
	printf("Modified string: %s\n", str);
	printf("Ret	--	Expected");
	print_compare_array(str, expected, strlen(test_str), "");
	if (strcmp(str, expected) != 0)
		return(0);
	return (1);
}
char	char_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

char	cap_even(unsigned int i, char c)
{
	if (i % 2 == 1)
		return (ft_toupper(c));
	return (c);
}

int	test_strmapi(char *test_str, char (*f)(unsigned int, char), char *expected, char *desc)
{
	char *str;

	str = ft_strdup(test_str);
	if (!str)
	{
		printf("Failed to allocate memory for str in strmap");
		return (0);
	}
	printf("%s\n", desc);
	printf("Original string: %s\n", str);
	str = ft_strmapi(str, f);
	printf("Modified string: %s\n", str);
	printf("Ret	--	Expected");
	print_compare_array(str, expected, strlen(test_str), "");
	if (strcmp(str, expected) != 0)
	{
		free(str);
		return(0);
	}
	free(str);
	return (1);

}

int	test_substr(char *str, unsigned int start, size_t len, char *expected, char *desc)
{
	char *substring;
	printf("%s\n", desc);
	printf("substring starting from index '%d' for %ld bytes in '%s'\n", start, len, str);
	substring = ft_substr(str, start, len);
	printf("my substring:	'%s'\nexpected:	'%s'\n", substring, expected);
	if (strcmp(substring, expected) == 0)
	{
		free(substring);
		return (1);
	}
	free(substring);
	return (0);
}

int	test_strjoin(char *s1, char *s2, char *expected, char *desc)
{
	char *my_str;

	printf("%s\n", desc);
	printf("concatenating '%s' and '%s'\n", s1, s2);
	my_str = ft_strjoin(s1, s2);
	printf("my strjoin:	'%s'\nexpected:	'%s'\n", my_str, expected);
	if (strcmp(my_str, expected) == 0)
	{
		free(my_str);
		return (1);
	}
	free(my_str);
	return (0);
}

int	test_strtrim(char *str, char *expected, char *desc)
{
	char *my_str;

	printf("%s\n", desc);
	printf("trimming '%s'\n", str);
	my_str = ft_strtrim(str);
	printf("my strtrim:	'%s'\nexpected:	'%s'\n", my_str, expected);
	if (strcmp(my_str, expected) == 0)
	{
		free(my_str);
		return (1);
	}
	free(my_str);
	return (0);
}

int test_strsplit(char *str, char c, char **expected, char *desc)
{
	char **my_str_arr;
	size_t i;

	printf("%s\n", desc);
	printf("splitting '%s' with delimiter '%c'\n", str, c);
	my_str_arr = ft_split(str, c);
	if (!my_str_arr)
	{
		printf("null array");
		return (0);
	}
	i = 0;
	while (my_str_arr[i] && expected[i])
	{
		printf("my_str_arr[%zu]: '%s', expected[%zu]: '%s'\n", i, my_str_arr[i], i, expected[i]);
		if (strcmp(my_str_arr[i], expected[i]) != 0)
		{
			size_t j = 0;
			while (my_str_arr[j])
			{
				free(my_str_arr[j]);
				j++;
			}
			free(my_str_arr);
			return (0);
		}
		i++;
	}
	if (my_str_arr[i] != NULL || expected[i] != NULL)
	{
		size_t j = 0;
		while (my_str_arr[j])
		{
			free(my_str_arr[j]);
			j++;
		}
		free(my_str_arr);
		return (0);
	}
	i = 0;
	while (my_str_arr[i])
	{
		free(my_str_arr[i]);
		i++;
	}
	free(my_str_arr);

	return (1);
}

int test_itoa(int nbr, char *expected, char *desc)
{
	char *mynbr;

	printf("%s\n", desc);
	printf("itoa on number: %d\n", nbr);
	mynbr = ft_itoa(nbr);
	printf("my itoa: %s\nexpected: %s\n\n", mynbr, expected);
	if (strcmp(mynbr, expected) != 0)
		return (0);
	return (1);
}
#include <strings.h>
int main() {
	int success = 1;
	char fails[2048];
	bzero(fails, 2048);

	success = 1;
	// Test ft_calloc
	printf("\n-----ft_calloc------\n");
	success *= test_calloc(10, sizeof(char), "10 times characters");
	success *= test_calloc(5, sizeof(int), "5 integers");
	success *= test_calloc(0, 50, "0 times 50byte objects");
	success *= test_calloc(1, sizeof(char), "1 character");
	if (!success)
	{
		printf("Test failed for ft_calloc\n");
		strcat(fails, "ft_calloc, ");
	}

	// Test ft_bzero vs. bzero
	printf("\n-----ft_bzero vs. bzero------\n");
	success *= test_bzero("ABCDE", 6, 6, "ABCDE to 0s, 6 bytes");
	success *= test_bzero("", 1, 1, "empty string, 1 byte");
	success *= test_bzero("TESTINGIT", 3, 10, "TESTINGIT but only first 3 bytes");
	success *= test_bzero("TESTINGIT", 0, 10, "TESTINGIT but 0 bytes");
	if (!success)
	{
	printf("Test failed for ft_bzero\n");
	strcat(fails, "ft_bzero, ");
	}

	success = 1;
	// Test ft_memchr vs. memchr
	printf("\n-----ft_memchr vs. memchr------\n");
	success *= test_memchr("Hello World", 'W', 11, 11, "standard test, finding 'W' in 'Hello World'");
	success *= test_memchr("testerly", 'l', 5, 11, "looking for 'l' in 'testerly' but only first 5 bytes, so should be NULL");
	if (!success)
	{
		printf("Test failed for ft_memchr\n");
		strcat(fails, "ft_memchr, ");
	}

	success = 1;
	// Test ft_memcmp vs. memcmp
	printf("\n-----ft_memcmp vs. memcmp------\n");
	success *= test_memcmp("Hello", "Hello", 5, "basic test, all correct, same string");
	success *= test_memcmp("Hello", "Herlo", 5, "basic test, difference in 3rd letter");
	success *= test_memcmp("Hello", "Helko", 3, "difference out of reach cause of size");
	success *= test_memcmp("Hello", "Helko", 0, "size 0");
	success *= test_memcmp("", "Helko", 5, "first string empty");
	success *= test_memcmp("Helko", "", 5, "2nd string empty");
	success *= test_memcmp("", "", 0, "both empty");
	if (!success)
	{
		printf("Test failed for ft_memcmp\n");
		strcat(fails, "ft_memcmp, ");
	}

	success = 1;
	// Test ft_memcpy vs. memcpy
	printf("\n-----ft_memcpy vs. memcpy------\n");
	char overlap[] = "to this copy this";
	success *= test_memcpy("testing this copy thing", "12345", 5, "");
	success *= test_memcpy("hello world", "world hello", 11, "");
	success *= test_memcpy("", "", 0, "");
	success *= test_memcpy(overlap, overlap + 8, 8, "overlap test");
	if (!success)
	{
		printf("Test failed for ft_memcpy\n");
		strcat(fails, "ft_memcpy, ");
	}

	success = 1;
	// Test ft_memmove vs. memmove
	printf("\n-----ft_memmove vs. memmove------\n");
	success *= test_memmove("Hello World!", 5, 0, 7, "Overlap backward memmove");
	success *= test_memmove("Hello World!", 0, 5, 7, "Overlap forward memmove");
	success *= test_memmove("Hello World!", 0, 0, 12, "No overlap memmove");
	if (!success)
	{
		printf("Test failed for ft_memmove\n");
		strcat(fails, "ft_memmove, ");
	}

	success = 1;
	// Test ft_memset vs. memset
	printf("\n-----ft_memset vs. memset------\n");
	success *= test_memset("Hello World!", 'X', 5, "Set first 5 chars to 'X'");
	success *= test_memset("Hello World!", 'X', 11, "");
	if (!success)
	{
		printf("Test failed for ft_memset\n");
		strcat(fails, "ft_memset, ");
	}

	success = 1;
	// Test ft_strdup vs. strdup
	printf("\n-----ft_strdup vs. strdup------\n");
	success *= test_strdup("Hello World!", "Basic strdup");
	success *= test_strdup("", "Empty string strdup");
	if (!success)
	{
		printf("Test failed for ft_strdup\n");
		strcat(fails, "ft_strdup, ");
	}

	success = 1;
	// Test ft_strlen vs. strlen
	printf("\n-----ft_strlen vs. strlen------\n");
	success *= test_strlen("Hello World!", "Basic strlen");
	success *= test_strlen("", "Empty string strlen");
	if (!success)
	{
		printf("Test failed for ft_strlen\n");
		strcat(fails, "ft_strlen, ");
	}

	success = 1;
	// Test ft_strlcat vs. strlcat
	printf("\n-----ft_strlcat vs. strlcat------\n");
	success *= test_strlcat("Hello", " World", 256, "Normal case");
	success *= test_strlcat("Hello", " World", 3, "Size less than dest length");
	success *= test_strlcat("Hello", " World", 0, "Size 0");
	success *= test_strlcat("", " World", 256, "Empty dest");
	success *= test_strlcat("Hello", "", 256, "Empty src");
	success *= test_strlcat("", "", 256, "Both dest and src empty");
	success *= test_strlcat("Hello", " World", 1, "Size 1");
	if (!success)
	{
		printf("Test failed for ft_strlcat\n");
		strcat(fails, "ft_strlcat, ");
	}

	success = 1;
	// Test ft_strchr vs. strchr
	printf("\n-----ft_strchr vs. strchr------\n");
	success *= test_strchr("find this thing", 't', "Normal case");
	success *= test_strchr("find from here", '\0', "find terminator");
	success *= test_strchr("", 'a', "find something from nothing");
	success *= test_strchr("abc\0def", '\0', "Find null terminator mid");
	success *= test_strchr("abcdef", 'g', "Character not in the string");
	success *= test_strchr("abcdef", 'a', "Find the first character");
	success *= test_strchr("abcabcdef", 'f', "Find the last character");
	success *= test_strchr("abcdefgh", 'e', "Find a character near the middle");
	success *= test_strchr("abracadabra", 'a', "Find a character occurring multiple times");
	if (!success)
	{
		printf("Test failed for ft_strchr\n");
		strcat(fails, "ft_strchr, ");
	}

	success = 1;
	// Test ft_strrchr vs. strrchr
	printf("\n-----ft_strrchr vs. strrchr------\n");
	success *= test_strrchr("find this thing", 't', "Normal case");
	success *= test_strrchr("abcdef", 'g', "Character not in the string");
	success *= test_strrchr("find from here", '\0', "find terminator");
	success *= test_strrchr("abc\0def", '\0', "Find null terminator mid");
	success *= test_strrchr("", 'a', "find something from nothing");
	success *= test_strrchr("abcdef", 'a', "Find the first character");
	success *= test_strrchr("abcabcdef", 'f', "Find the last character");
	success *= test_strrchr("abcdefgh", 'e', "Find a character near the middle");
	success *= test_strrchr("abracadabra", 'a', "Find a character occurring multiple times");
	if (!success)
	{
		printf("Test failed for ft_strrchr\n");
		strcat(fails, "ft_strrchr, ");
	}

	success = 1;
	// Test ft_strncmp vs. strncmp
	printf("\n-----ft_strncmp vs. strncmp------\n");
	success *= test_strncmp("abcde", "abcd", 4, "Identical up to 4 chars");
	success *= test_strncmp("abcde", "abcd", 3, "Identical up to 3 chars");
	success *= test_strncmp("abcde", "abcd", 5, "Different at 5th char");
	success *= test_strncmp("abcde", "bbcde", 1, "Different at 1st char");
	success *= test_strncmp("abcde", "bbcde", 5, "Different at 1st char but compared up to 5 chars");
	success *= test_strncmp("abc", "abcd", 3, "Identical up to 3 chars");
	success *= test_strncmp("abc", "abcd", 4, "Different at 4th char");
	success *= test_strncmp("abcd", "abc", 4, "Different at 4th char");
	success *= test_strncmp("abc\0def", "abc\0dgh", 7, "Include null terminator in middle");
	success *= test_strncmp("abc\0def", "abc\0dgh", 4, " Stop at null terminator");
	success *= test_strncmp("hello", "world", 5, "Different right from start");
	success *= test_strncmp("", "", 5, "both empty");
	success *= test_strncmp("abc", "", 3, "one empty");
	success *= test_strncmp("A", "ý", 1, "extended ascii");
	if (!success)
	{
		printf("Test failed for ft_strncmp\n");
		strcat(fails, "ft_strncmp, ");
	}

	success = 1;
	// Test ft_strnstr vs. strnstr
	printf("\n-----ft_strnstr vs. strnstr------\n");
	success *= test_strnstr("Hello, world!", "world", 13, "Found substring in the middle");
	success *= test_strnstr("Hello, world!", "universe", 13, "Substring not found");
	success *= test_strnstr("Hello, world!", "", 13, "Empty src");
	success *= test_strnstr("world", "Hello, world!", 5, "src longer than dest");
	success *= test_strnstr("Hello, world!", "world", 0, "Zero len");
	success *= test_strnstr("", "world", 5, "Empty dest");
	success *= test_strnstr("", "", 0, "Both empty");
	success *= test_strnstr("Hello, world!", "Hello", 20, "Len greater than dest length");
	success *= test_strnstr("Hello, world!", "wor", 9, "len too short for the full needle");
	success *= test_strnstr("Hello, world!", "wor", 10, "len JUST enough");
	if (!success)
	{
		printf("Test failed for ft_strnstr\n");
		strcat(fails, "ft_strnstr, ");
	}

	success = 1;
	// Test ft_atoi vs atoi
	printf("\n-----ft_atoi vs. atoi------\n");
	success *= test_atoi("123");
	success *= test_atoi("-456");
	success *= test_atoi("   789");
	success *= test_atoi("0");
	success *= test_atoi("+42");
	success *= test_atoi("+-42");
	success *= test_atoi("abc42");
	success *= test_atoi("   -123abc");
	success *= test_atoi("  123  456");
	success *= test_atoi("  +1000");
	success *= test_atoi("  0001420");
	success *= test_atoi("-2147483648");
	success *= test_atoi("2147483647");
	if (!success)
	{
		printf("Test failed for ft_atoi\n");
		strcat(fails, "ft_atoi, ");
	}

	printf("----- Testing Character Functions isdigit, isalpha etc-----\n");

	success = 1;
	// Test cases for ft_isdigit
	success *= ft_isdigit('5') == 1;
	success *= ft_isdigit('a') == 0;
	success *= ft_isdigit(' ') == 0;

	// Test cases for ft_isalpha
	success *= ft_isalpha('A') == 1;
	success *= ft_isalpha('h') == 1;
	success *= ft_isalpha('3') == 0;
	success *= ft_isalpha('$') == 0;

	// Test cases for ft_isalnum
	success *= ft_isalnum('A') == 1;
	success *= ft_isalnum('3') == 1;
	success *= ft_isalnum('z') == 1;
	success *= ft_isalnum('j') == 1;
	success *= ft_isalnum('$') == 0;

	// Test cases for ft_isascii
	success *= ft_isascii(65) == 1;
	success *= ft_isascii(128) == 0;

	// Test cases for ft_isprint
	success *= ft_isprint('A') == 1;
	success *= ft_isprint(7) == 0;

	// Test cases for ft_tolower
	printf("ft_tolower('H'): Expected 'h', Actual '%c'\n", ft_tolower('H'));
	success *= ft_tolower('H') == 'h';

	printf("ft_tolower('5'): Expected '5', Actual '%c'\n", ft_tolower('5'));
	success *= ft_tolower('5') == '5';

	printf("ft_tolower('k'): Expected 'k', Actual '%c'\n", ft_tolower('k'));
	success *= ft_tolower('k') == 'k';

	// Test cases for ft_toupper
	printf("ft_toupper('H'): Expected 'H', Actual '%c'\n", ft_toupper('H'));
	success *= ft_toupper('H') == 'H';

	printf("ft_toupper('5'): Expected '5', Actual '%c'\n", ft_toupper('5'));
	success *= ft_toupper('5') == '5';

	printf("ft_toupper('k'): Expected 'K', Actual '%c'\n", ft_toupper('k'));
	success *= ft_toupper('k') == 'K';


	if (success) {
		printf("All tests passed for character functions\n");
	} else {
		printf("Some tests failed for character functions\n");
		strcat(fails, "character functions, ");
	}

	//PART 2 Additional Functions

	success = 1;
	// Test ft_striteri
	printf("\n-----ft_striteri------\n");
	success *= test_striteri("hello world", cap_alternate, "HeLlO WoRlD", "cap all even characters in 'hello world'");
	if (!success)
	{
		printf("Test failed for ft_striteri\n");
		strcat(fails, "ft_striteri, ");
	}

	success = 1;
	// Test ft_strmapi
	printf("\n-----ft_strmapi------\n");
	success *= test_strmapi("hello world", cap_even, "hElLo wOrLd", "capitalize all letters");
	if (!success)
	{
		printf("Test failed for ft_strmapi\n");
		strcat(fails, "ft_strmapi, ");
	}

	success = 1;
	// Test ft_substr
	printf("\n-----ft_substr------\n");
	success *= test_substr("hello world", 6, 5, "world", "Extract 'world' from 'hello world'");
	success *= test_substr("hello world", 0, 5, "hello", "Extract from the start of the string");
	success *= test_substr("hello world", 6, 5, "world", "Extract from the end of the string");
	success *= test_substr("hello world", 0, 11, "hello world", "Extract the entire string");
	success *= test_substr("hello world", 6, 0, "", "Extract with length 0");
	success *= test_substr("", 0, 5, "", "Extract from an empty string");
	success *= test_substr("hello", 0, 10, "hello", "Extract beyond the string's length");
	if (!success)
	{
		printf("Test failed for ft_substr\n");
		strcat(fails, "ft_substr, ");
	}

	success = 1;
	// Test ft_strjoin
	printf("\n-----ft_strjoin------\n");
	success *= test_strjoin("Hello ", "World", "Hello World", "simple basic test");
	success *= test_strjoin("", "World", "World", "Empty prefix");
	success *= test_strjoin("Hello ", "", "Hello ", "Empty suffix");
	success *= test_strjoin("", "", "", "Both strings empty");
	success *= test_strjoin("A really long string to test buffer overflows ", "and potential memory issues.", "A really long string to test buffer overflows and potential memory issues.", "Long string test");
	if (!success)
	{
		printf("Test failed for ft_strjoin\n");
		strcat(fails, "ft_strjoin, ");
	}

	success = 1;
	// Test ft_strtrim
	printf("\n-----ft_strtrim------\n");
	success *= test_strtrim("   Hello World   ", "Hello World", "Trimming spaces");
	success *= test_strtrim("\tHello World\t", "Hello World", "Trimming tabs");
	success *= test_strtrim("\nHello World\n", "Hello World", "Trimming newlines");
	success *= test_strtrim("", "", "Empty string");
	success *= test_strtrim("    ", "", "String with only spaces");
	success *= test_strtrim("HelloWorld", "HelloWorld", "No spaces to trim");
	success *= test_strtrim(" \t\nHello World \t\n", "Hello World", "Mixed whitespace characters");
	if (!success)
	{
		printf("Test failed for ft_strtrim\n");
		strcat(fails, "ft_strtrim, ");
	}

	success = 1;
	// Test ft_split
	printf("\n-----ft_split------\n");
	char *expected1[] = {"test", "this", "thing", "now", NULL};
	success *= test_strsplit("test this thing now", ' ', expected1, "Basic test");
	char *expected2[] = {"test", "this", "thing", "now", NULL};
	success *= test_strsplit("   test this thing now", ' ', expected2, "Leading spaces test");
	char *expected3[] = {"test", "this", "thing", "now", NULL};
	success *= test_strsplit("test this thing now   ", ' ', expected3, "Trailing spaces test");
	char *expected4[] = {"test", "this", "thing", "now", NULL};
	success *= test_strsplit("test   this thing now", ' ', expected4, "Multiple spaces test");
	char *expected5[] = {"test", NULL};
	success *= test_strsplit("test", ' ', expected5, "Single word test");
	char *expected6[] = {NULL};
	success *= test_strsplit("", ' ', expected6, "Empty string test");
	if (!success)
	{
		printf("Test failed for ft_split\n");
		strcat(fails, "ft_split, ");
	}

	success = 1;
	// Test ft_itoa
	printf("\n-----ft_itoa------\n");
	success *= test_itoa(-2147483648, "-2147483648", "int min");
	success *= test_itoa(2147483647, "2147483647", "int max");
	success *= test_itoa(2512354, "2512354", "just some number");
	success *= test_itoa(-55231, "-55231", "just some negative number");
	success *= test_itoa(0, "0", "zero");
	//success *= test_itoa(-2147483649, "-2147483649", "invalid int");
	if (!success)
	{
		printf("Test failed for ft_itoa\n");
		strcat(fails, "ft_itoa, ");
	}

	printf("\n-----Final Result------\n");
	if (fails[0]=='\0') {
		printf("All tests were successful\n");
	} else {
		printf("tests failed on following functions: %s\n", fails);
	}

	return 0;
}
