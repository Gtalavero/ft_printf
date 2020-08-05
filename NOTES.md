## STRUCTURE
	%[FLAG][WIDTH][.PRECISION][LENGHT][TYPE]

### FLAGS
	-	Align to the left. If by default it is "  hello" it will be "hello  "
	0	It will be padded with zeros to the left up to the value of the digit..
		For d, i, u, x, X conversions.
		If '-' is used, '0' is ignored.
		If there is precision in a decimal conversion (d, i, u, x, X) is also ignored

### WIDTH
	Minimum field size where the value will be printed
	Optional.
	*	The width will be specified in the next argument. If we put a number 'n' after the '*'
			the width will be specified in the 'n' argument
	If the value to convert has less length than the width, it will be left padded with spaces,
		or right padded if the flag '-' exists
	NEVER a small or non-existent width will truncate a field.

### PRECISION
	
	Optional
	Will follow a '.' or will be specified in other argument with '*' in the same way as the width.
	Minimum number of digits for: (d, i, u, x y X).
	Number of characters to print for text strings (s)
	If we just put '.' without a number, the precision = 0
	If it is negative, it will be interpreted as if it had been omitted (when omitted, is equal to -1).
	Will take precedence over width
	If it exists, the flag '0' will be omitted

### TYPES
	c	Prints the corresponding ASCII character. Print char
	s	Character string (ending in '\ 0'). Print string
	p	Memory address (pointer) in hexadecimal digits
	d, i	Both are exactly the same. Signed decimal conversion of an integer. Print int
	u	Unsigned decimal conversion of an integer. Print unsigned int
	x, X	Hexadecimal unsigned conversion. 'x' prints lowercase and 'X' uppercase. Print int. 

## ORDER
	1. Loop the format until you meet a `%`
	2. Save in the structure the flag, width, precision and conversion specifier (the type)
	3. Do the conversion and save in `raw_str`
	4. Modify raw_str to fit with the data saved in the structure and fill `final_str` with the result
	5. Print







