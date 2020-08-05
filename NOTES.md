## STRUCTURE
	%[FLAG][WIDTH][.PRECISION][LENGHT][TYPE]

### FLAGS
	`-`	Align to the left. If by default it is "  hello" it will be "hello  "
	`0`	It will be padded with zeros to the left up to the value of the digit..
		For conversions: `d`, `i`, `u`, `x`, `X`.
		If `-` is used, `0` is ignored.
		If there is precision in a decimal conversion (`d, i, u, x, X`) is also ignored

### WIDTH
	Minimum field size where the value will be printed
	Optional.
	`*`	The width will be specified in the next argument. If we put a number `n` after the `*`
			the width will be specified in the `n` argument
	If the value to convert has less length than the width, it will be left padded with spaces,
		or right padded if the flag '-' exists
	NEVER a small or non-existent width will truncate a field.

### PRECISION
	
	Optional
	Will follow a `.` or will be specified in other argument with `*` as the width.
	Minimum number of digits for: (d, i, u, x y X).
	Número de caracteres a imprimir para cadenas de texto (s)
	*	Indicaremos que la precision se especificará en el siguiente argumento. Si ponemos un número
			después	del '*' indicaremos en qué argumento especificaremos la precisión
	Si tan solo ponemos '.' sin un número, la precisión = 0
	Si es negativa se interpretará como si se hubiera omitido
	Primará sobre el width
	Si existe, se omitirá el flag '0'

### TYPES
	c		Imprime el carácter ASCII correspondiente. Imprime char
	s		Cadena de caracteres (terminada en '\0'). Imprime string
	p		Dirección de memoria (puntero) en dígitos hexadecimales
	d, i	Conversión decimal con signo de un entero. Imprime int
	u		Conversión decimal sin signo de un entero. Imprime int
	x, X	Conversión hexadecimal sin signo. Imprime int. La minúscula imprime en minúscula y la
			mayúscula en mayúscula.

## ORDER
	1. Loop the format until you meet a `%`
	2. Save in the structure the flag, width, precision and conversion specifier (the type)
	3. Do the conversion and save in `raw_str`
	4. Modify raw_str to fit with the data saved in the structure and fill `final_str` with the result
	5. Print







