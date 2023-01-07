# ft_printf

## About
At Hive Helsinki, a 42 Network school, students must write projects according to the "norme". Many formats are restricted, so the code may look surprising in some places.

The built-in C Library functions we are allowed to use for almost all of our projects are highly limited. Generally, we can only use the following:

* write
* malloc
* free
* exit

ft_printf is a project that involves recreating the C function printf. It is a useful exercise in understanding how the printf function works and how to use variadic functions in C as well as learn about a great example of a basic “dispatcher” in C via the use of an array of function’s pointers.

## Objectives
The goal of this project is to recreate the printf function with the following features:

```
Support for the following conversion specifiers: c, s, p, d, i, u, x, X, %
Support for the following flags: #, 0, -, +, and space
Support for minimum field width and precision
Support for the h, hh, l, and ll length modifiers
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, world!\n");
    ft_printf("The value of pi is approximately %f.\n", 3.14159);
    ft_printf("We have %d oranges and %d apples.\n", 4, 6);
    return 0;
}
```

# Description
printf is prototyped as:
```
int printf(const char *format, ...);
```
The ``printf`` function is a way to format and print output to the console. It takes a string called ``format`` as its first argument, which contains special directives that specify how subsequent arguments should be formatted and printed.

``format`` is a string made up of ordinary characters, which are printed as is, and conversion specifications, which are used to print the values of subsequent arguments. A conversion specification starts with the ``%`` character and ends with a conversion specifier, which determines how the argument will be printed. Between the ``%`` and the conversion specifier, there may be:

* Zero or more flags, which modify the behavior of the conversion specification
* An optional minimum field width, which determines the minimum width of the printed value
* An optional precision, which specifies the number of digits to print after the decimal point (for floating point values) or the maximum number of characters to print (for strings)
* An optional length modifier, which specifies the size of the argument

The overall syntax of a conversion specification is 
```
%[$][flags][width][.precision][length modifier]conversion.
```

```c
// Print a character
ft_printf("%c", 'a'); // prints "a"

// Print a string
ft_printf("%s", "hello world"); // prints "hello world"

// Print an integer
ft_printf("%d", 42); // prints "42"

// Print an unsigned integer in octal format
ft_printf("%o", 42); // prints "52"

// Print an unsigned integer in hexadecimal format
ft_printf("%x", 42); // prints "2a"

// Print an unsigned integer in hexadecimal format (uppercase)
ft_printf("%X", 42); // prints "2A"

// Print a floating point number
ft_printf("%f", 3.14159265358979323846); // prints "3.141593"

// Print a floating point number with 3 digits after the decimal point
ft_printf("%.3f", 3.14159265358979323846); // prints "3.142"

// Print a percent sign
ft_printf("%%"); // prints "%"

// Print an integer with a minimum field width of 10
ft_printf("%10d", 42); // prints "        42"

// Print an integer with left-justification and a minimum field width of 10
ft_printf("%-10d", 42); // prints "42        "

// Print a floating point number with a minimum field width of 10 and 3 digits after the decimal point
ft_printf("%10.3f", 3.14159265358979323846); // prints "     3.142"

// Print a floating point number with left-justification, a minimum field width of 10, and 3 digits after the decimal point
ft_printf("%-10.3f", 3.14159265358979323846); // prints "3.142     "
```
