/*
 * Stub functions used express that the macros T1RD16ON and T3RD16ON are no longer supported.
 * To express the associated "unsupported" warning we define special symbols with inline assembly.
 * Previously the macros could be used in an expression, therefore we must encapsulate the inline assembly in
 * a function with a simialr return type.
 */

unsigned char
__t1rd16on(void)
{
	asm("GLOBAL nosup@@T1RD16ON\nnosup@@T1RD16ON EQU 0");
	return 0;
}

unsigned char
__t3rd16on(void)
{
	asm("GLOBAL nosup@@T3RD16ON\nnosup@@T3RD16ON EQU 0");
	return 0;
}

