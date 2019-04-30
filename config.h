#ifndef CONFIG_H_
#define CONFIG_H_

#include <float.h>

const char *PROG_BEG = "#include <stdio.h>\n\nstatic float text[] =\n{\n";
const char *PROG_END = "};\n\nint main(void)\n{\n    puts((char*)text);\n}\n";
const char *TEXT_BEG = "    ";
const char *TEXT_END = ",\n";
const int     DIGITS = FLT_DECIMAL_DIG;

#endif
