# Compilador y herramientas
CC      = gcc
YACC    = yacc
FLEX    = flex

# Archivos
TARGET  = post
YFILE   = postscript.y
LFILE   = postscript.l
CFILES  = compilador.c
YGEN    = y.tab.c y.tab.h
LGEN    = lex.yy.c

# Flags
CFLAGS  = -lm

# Regla por defecto
all: $(TARGET)

# Construcción del ejecutable
$(TARGET): $(YGEN) $(LGEN) $(CFILES)
	$(CC) -o $(TARGET) $(LGEN) y.tab.c $(CFILES) $(CFLAGS)

# Yacc genera el parser
y.tab.c y.tab.h: $(YFILE)
	$(YACC) -d $(YFILE)

# Flex genera el lexer
lex.yy.c: $(LFILE) y.tab.h
	$(FLEX) $(LFILE)

# Limpieza
clean:
	rm -f $(TARGET) $(YGEN) $(LGEN)
