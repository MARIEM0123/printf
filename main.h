#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define NDS(x) (void)(x)
#define BUFF_SIZE 1024
#define S_LONG 2
#define S_SHORT 1
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - the structure
 * @fmt: The format
 * @fn: The function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - structure
 * @fmt: The format
 * @fm_t: The function
 */
typedef struct fmt fmt_t;
int _char(va_list t, char b[], int f,
		int width, int prec, int size);
int _string(va_list t, char b[],
		int f, int width, int prec, int size);
int _percent(va_list t, char b[],
		int f, int width, int prec, int size);
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list,
		char b[], int f, int width, int prec, int size);
int _int(va_list t, char b[], int f,
		int width, int precision, int size);
int _binary(va_list t, char b[], int f,
		int width, int prec, int size);
int _unsigned(va_list t, char b[],
		int f, int width, int prec, int size);
int _octal(va_list t, char b[],
		int f, int w, int prec, int size);
int _hexa_upper(va_list t, char b[],
		int f, int width, int prec, int size);
int _hexadecimal(va_list t, char b[],
		int f, int width, int prec, int size);
int _flags(const char *a, int *i);
int _width(const char *a, int *i, va_list ls);
int _precision(const char *a, int *i, va_list ls);
int _size(const char *a, int *i);
int _non_printable(va_list t, char b[], int f,
		int width, int prec, int size);
int _hexa(va_list t, char a[],
char b[], int f, char d, int width, int prec, int size);
int _pointer(va_list t, char b[],
		int f, int width, int prec, int size);
int _reverse(va_list t, char b[], int f,
		int width, int prec, int size);
int _rot13(va_list t, char b[], int f,
		int width, int prec, int size);
int is_printable(char);
int ah_code(char, char[], int);
int is_digit(char);
int hw_char(char c, char b[], int f, int width, int prec, int size);
int hw_number(int n, int k, char b[], int f, int width,
		int precision, int size);
int hw_num(int k, char b[], int f, int width, int prec, int l,
		char d, char c);
int hw_pointer(char b[], int k, int l, int width,
		int f, char d, char c, int init);
long int cvt_size_num(long int a, int size);
long int cvt_size_unsigned(unsigned long int n, int size);
int hw_unsgnd(int i, int k, char b[], int f, int w, int prec, int s);

#endif

