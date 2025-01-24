#ifndef ___UNSUPPORTED_H_
#define ___UNSUPPORTED_H_

#define __unsupported(f)	__attribute__((unsupported("function \""  # f  "\" is not supported by this device. Its minimum memory usage exceeds the maximum available")));

#endif

