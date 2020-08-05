# Aim of the proyect
[42 school][1] project about replicating the PRINTF function in C.

**Conversions:** `c`, `s`, `d`, `i`, `u`, `p`, `x` and `X`.

**Flags:** `-` and `0`.

**Width, precision, lenght**.

## Rules
The proyect is coded complying with the conventions and restrictions of 42 school so probably you will see different (and probably easier) ways to do the same.

[The 42 norme][2]

# Usage
First, clone the repo:

    git clone https://github.com/Gtalavero/ft_printf.git

Compile to create `libfprintf.a`:
 
    make

Add ft_printf.h to your main

    #include "ft_printf.h"
    
Compile it with a program

    gcc main.c libfprintf.a

## How I have approached the project and how you can do it
### 1.- Familiarize with printf:
I took my time to study the manual (man 3 printf) and I took a lot of notes to understand printf (you can see those [notes](NOTES.md) where I have summarized the manual with the necessary information).

### 2.- Learn the basics
To face the proyect you should know about structures, variadic arguments, pointers, memory allocations... don't try to bypass that steps or you are going to have a bad time.

### 3.- Raise the proyect
When I understood what printf do, I decided to follow the order bellow. I encourage you not to follow mine and decide your own.
1. Loop the format until you meet a `%`
2. Save in the structure the flag, width, precision and conversion specifier (the type)
3. Do the conversion and save in `raw_str`
4. Modify raw_str to fit with the data saved in the structure and fill `final_str` with the result
5. Print

## Tips and tools
### Again...
Read my [notes](NOTES.md). I promise that the notes will help you.

### Keep in mind all the time the memory leaks. 
Don't make my same mistake and leave it for last. Same for overflows, segmentation faults, bus error...
I have used different methods to check the memory leaks:
1. Add `system("leaks a.out")` at the end of the main just before the return.
2. With valgrind (RTFM)

        valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./a.out

### Test your proyect
I used the 745 tests of [pft_2019][3] from @cclaude42

[1]: https://www.42madrid.com/ "42 Madrid"
[2]: https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf
[3]: https://github.com/cclaude42/PFT_2019



