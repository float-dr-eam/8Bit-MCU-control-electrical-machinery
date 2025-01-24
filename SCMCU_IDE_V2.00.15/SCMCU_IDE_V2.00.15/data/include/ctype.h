#if	defined(_MPC_) || defined(__18CXX) 

#define _CTYPE_BIT_FUNCS_
extern __bit isalpha(char);
extern __bit isupper(char);
extern __bit islower(char);
extern __bit isdigit(char);
extern __bit isxdigit(char);
extern __bit isspace(char);
extern __bit ispunct(char);
extern __bit isalnum(char);
extern __bit isprint(char);
extern __bit isgraph(char);
extern __bit iscntrl(char);

#define _CTYPE_CHAR_PARAM_
extern char	toupper(char);
extern char	tolower(char);
#else

#define	_UCASE	0x01
#define	_LCASE	0x02
#define	_DIGIT	0x04
#define	_WHTSP	0x08
#define _PUNCT	0x10
#define _CNTRL	0x20
#define	_HEXAD	0x40
#define	_PRINT	0x80

extern const unsigned char _ctype_[257];

#define	isalpha(c)	((_ctype_+1)[(unsigned char)(c)]&(_UCASE|_LCASE))
#define	isupper(c)	((_ctype_+1)[(unsigned char)(c)]&_UCASE)
#define	islower(c)	((_ctype_+1)[(unsigned char)(c)]&_LCASE)
#define	isdigit(c)	((_ctype_+1)[(unsigned char)(c)]&_DIGIT)
#define	isxdigit(c)	((_ctype_+1)[(unsigned char)(c)]&(_DIGIT|_HEXAD))
#define	isspace(c)	((_ctype_+1)[(unsigned char)(c)]&_WHTSP)
#define ispunct(c)	((_ctype_+1)[(unsigned char)(c)]&_PUNCT)
#define isalnum(c)	((_ctype_+1)[(unsigned char)(c)]&(_UCASE|_LCASE|_DIGIT))
#define isprint(c)	((_ctype_+1)[(unsigned char)(c)]&(_PUNCT|_UCASE|_LCASE|_DIGIT|_PRINT))
#define isgraph(c)	((_ctype_+1)[(unsigned char)(c)]&(_PUNCT|_UCASE|_LCASE|_DIGIT))
#define iscntrl(c)	((_ctype_+1)[(unsigned char)(c)]&_CNTRL)

extern char	toupper(int);
extern char	tolower(int);
#endif

#define isascii(c)	(!((c)&~0x7F))
#define toascii(c)	((c)&0x7F)

