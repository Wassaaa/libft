char *ft_strchr(const char *src, int c)
{
	while (*src && *src != c)
		src++;
	if (*src == 0 && c != 0)
		return ('\0');
	return ((char *)src);
}
