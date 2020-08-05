## STRUCTURE
	%[FLAG][WIDTH][.PRECISION][LENGHT][TYPE]

### FLAGS
	`-`	Alinear a la izquierda. Si por defecto es "  hola" será "hola  "
	`0`	Se rellenará con ceros a la izq hasta el valor del nº.
		Para conversiones: d, i, u, x, X, y de BONUS: e, f, g(BONUS).
		Si se usa '-', el '0' se ignora.
		Si hay precisión en una conv decimal (d, i, u, x, X) también se ignora el '0'.
	`.`	(Ver precisión)
	`*`	(Ver width)

### WIDTH 
	Tamaño mínimo del campo donde se imprimirá el valor
	Es opcional
	Si el valor a convertir tiene menos longitud que el width, será "padded" con espacios a la izq,
		o a la derecha si existe el flag '-'
	`*`	Indicaremos que el tamaño se especificará en el siguiente argumento. Si ponemos un número
			después	del '*' indicaremos en qué argumento especificaremos el width
	NUNCA un width pequeño o inexistente truncará un field.

### PRECISION
	Es opcional
	Número mínimo de dígitos para: (d, i, u, x y X).
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







