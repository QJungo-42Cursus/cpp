#include <stdio.h>
    
void showbits( unsigned int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
	   if (i % 4 == 0)
		  putchar(' ');
    }
    printf("\n");
}

typedef union puning {
	unsigned int	integer;
	char			chars[4];
}	t_puning;

static void print_pun(t_puning pun)
{
	/*
	printf("pun.integer  %12u %12d\n", pun.integer, pun.integer);
	printf("pun.chars[0] %12u %12d\n", pun.chars[0], pun.chars[0]);
	printf("pun.chars[1] %12u %12d\n", pun.chars[1], pun.chars[1]);
	printf("pun.chars[2] %12u %12d\n", pun.chars[2], pun.chars[2]);
	printf("pun.chars[3] %12u %12d\n", pun.chars[3], pun.chars[3]);
	*/
	printf("integer %12u \t chars { %u, %u, %u, %u }\n", pun.integer, pun.chars[0], pun.chars[1], pun.chars[2], pun.chars[3]);
	printf("integer %12d \t chars { %d, %d, %d, %d }\n", pun.integer, pun.chars[0], pun.chars[1], pun.chars[2], pun.chars[3]);
    showbits(pun.integer);
	printf("--\n");
}

static void new_int_pp(unsigned int value)
{
	t_puning	pun;
	pun.integer = value;
	print_pun(pun);
}

static void new_chars_pp(char char0, char char1, char char2, char char3)
{
	char chars[4] = { char0, char1, char2, char3 };
	t_puning	pun;
	pun.chars[0] = chars[0];
	pun.chars[1] = chars[1];
	pun.chars[2] = chars[2];
	pun.chars[3] = chars[3];
	print_pun(pun);
}

int main() {
	/*
	int			i = 1;
	while (i < 260)
	{
		new_int_pp(i);
		i*=2;
	}
	*/
	new_int_pp(126);
	new_int_pp(127);
	new_int_pp(128);
	new_int_pp(256);

	new_chars_pp(0, 0, 0, 1);
	new_chars_pp(0, 0, 1, 0);
	new_chars_pp(0, 1, 0, 0);
	new_chars_pp(1, 0, 0, 0);


	printf("size of a char: %lu\n", sizeof(char));
	printf("size of a int: %lu\n", sizeof(int));
	printf("size of a float: %lu\n", sizeof(float));
	printf("size of a long: %lu\n", sizeof(long));
	printf("size of a `t_puning`: %lu\n", sizeof(t_puning));
}

