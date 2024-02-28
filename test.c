
enum
{
	E_FAIL_OPEN,
	E_FAIL_GNL,
};



int	test(char *file_path, int *ret)
{
	int		fd;
	char	*line;

	fd = open(file_path);
	if (fd < 0)
		return (E_FAIL_OPEN);
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), E_FAIL_GNL);

	*ret = ft_strlen(line);
	return (0);
}

int	main(void)
{
	int	error_code;
	int	return_value;

	error_code = test("file.txt", &return_value);
	if (error_code)
		return (error_code);
	
	return (1);
}