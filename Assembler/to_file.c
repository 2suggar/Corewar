#include "asm.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	unsigned char	*new;
	unsigned char	*frm;

	new = (unsigned char*)dst;
	frm = (unsigned char*)src;
	while (n-- > 0)
		*(new++) = frm[n];
	return (dst);
}

static char	the_code(char me)
{
	if (me == T_DIR)
		return (2);
	if (me == T_REG)
		return (1);
	if (me == T_IND)
		return (3);
	return (0);
}

void code_to_bytes(t_tokens *tokens, t_out *out)
{
	int i;	
	int j;
	unsigned char a;
	unsigned char b;
	unsigned char c;

	i = 0;
	while (tokens)
	{
		//код операции
		out->code[i++] = tokens->command->opcode;
		//код типов аргументов
		if (tokens->command->a_typecode)
		{
			a = the_code(tokens->types[0]);
			b = the_code(tokens->types[1]);
			c = the_code(tokens->types[2]);
			out->code[i++] = 0 | ((a << 6) & 192) | ((b << 4) & 48) | ((c << 2) & 12);
		}
		//аргументы
		j = 0;
		while (j < 3)
		{
			if (tokens->types[j] == 1)
				ft_memcpy_rev(&(out->code[i++]), &(tokens->values[j]), 1);
			else if (tokens->types[j] == 2)
			{
				printf("HERE:%d\n", tokens->values[j]);
				if (tokens->command->dir_size == 2)
				{
					ft_memcpy_rev(&(out->code[i]), &(tokens->values[j]), 2);
					i += 2;
				}
				else
				{
					ft_memcpy_rev(&(out->code[i]), &(tokens->values[j]), 4);
					i += 4;
				}
			}
			else if (tokens->types[j] == 3)
			{
				ft_memcpy_rev(&(out->code[i]), &(tokens->values[j]), 2);
				i += 2;
			}
			j++;
		}
		tokens = tokens->next;
	}
	//размер
	ft_memcpy_rev(out->code_size, &i, sizeof(int));
	out->code_size_int = i;
}

void to_file(t_out	*output, char *filename)
{
	int		fd;
	int		i;
	
    if ((fd = open(filename, O_WRONLY | O_CREAT, 0600)) < 3)
			printf("oops"); //edit
			//g_error.id = 1; //edit
	write(fd, &output->head, 4);
	write(fd, &output->name, PROG_NAME_LENGTH);
	write(fd, &output->name_null, 4);
	write(fd, output->code_size, 4);
	write(fd, output->comm, COMMENT_LENGTH);
	write(fd, output->com_null, 4);
	write(fd, output->code, output->code_size_int);
    close(fd);
}
