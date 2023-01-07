# ft_printf
ft_printf is a project that involves recreating the C function printf. It is a useful exercise in understanding how the printf function works and how to use variadic functions in C.

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
}```
