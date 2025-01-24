void
_swap(unsigned len, char * s1, char * s2)
{
	register char	c;

	while(len--) {
		c = *s1;
		*s1++ = *s2;
		*s2++ = c;
	}
}
