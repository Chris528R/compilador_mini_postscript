#ifndef SYMBOL_H
#define SYMBOL_H

#include "postscript.h"

// Tipos para los símbolos en la tabla y los datos en la pila
typedef enum {
    INDEF_TYPE,     // No definido
    VAR_NUM,        // Variable numérica
    VAR_SHAPE,      // Variable de forma geométrica
    VAR_COLOR,      // Variable de color
    TYPE_FUNCTION,       // Función (retorna valor)
    TYPE_PROCEDURE,      // Procedimiento (no retorna valor)
    BLTIN_TYPE,      // Built-in function
    VAR_STRING     // Variable de texto
} SymbolType;

typedef struct Symbol { /* entrada de la tabla de símbolos */
    char   *name;
    short   type;   /* INDEF_TYPE, VAR_NUM, VAR_SHAPE, VAR_COLOR, FUNCTION, PROCEDURE, BLTIN_TYPE */
    union {
        double      v;          /* si es VAR_NUM */
        PSShape     *shape;     /* si es VAR_SHAPE */
        PSColor     *color;     /* si es VAR_COLOR */
        double      (*ptr)(double);  /* si es BLTIN */
        void        (*defn)(void);   /* FUNCTION, PROCEDURE */
    } u;
    struct Symbol   *next;  /* para ligarse al siguiente */
} Symbol;

Symbol *install(char *s, int t);
Symbol *lookup(char *s);

typedef void (*Inst)(void);  /* instrucción de máquina virtual */

/* Tipo de dato en la pila (extendido) */
typedef struct Datum {
    short type; /* VAR_NUM, VAR_SHAPE, VAR_COLOR, o INDEF_TYPE para símbolos */
    union {
        double      val;        /* valor numérico */
        PSShape     *shape;     /* puntero a forma */
        PSColor     *color;     /* puntero a color */
        Symbol      *sym;       /* puntero a símbolo */
        char *str;              /* puntero a texto */
    } u;
} Datum;

void execute(Inst *p);
Inst *code(Inst f);
void code_double(double d);
void initcode(void);
void define(Symbol *sp);
void defnonly(char *s);

extern Inst prog[], *progp, *progbase;
extern Datum pop(void);

#define STOP    (Inst) 0

/* Funciones de la máquina virtual - Operaciones básicas */
extern void push(Datum d);
extern void eval(void);
extern void add(void);
extern void sub(void);
extern void mul(void);
extern void divide(void);
extern void negate(void);
extern void assign(void);
extern void varpush(void);
extern void constpush_n(void);  // push number constant
extern void print(void);
extern void pop1(void);

/* Funciones de comparación y lógica */
extern void gt(void);
extern void lt(void);
extern void ge(void);
extern void le(void);
extern void eq(void);
extern void ne(void);
extern void and_op(void);
extern void or_op(void);
extern void not_op(void);

/* Estructuras de control */
extern void ifcode(void);
extern void whilecode(void);
extern void forcode(void);

/* Funciones y procedimientos */
extern void call(void);
extern void arg(void);
extern void argassign(void);
extern void funcret(void);
extern void procret(void);

/* Funciones específicas de PostScript */
extern void constpush_shape(void);   // push shape constant
extern void constpush_color(void);   // push color constant
extern void assign_shape(void);      // asignar forma a variable
extern void assign_color(void);      // asignar color a variable

/* Funciones de creación de elementos gráficos */
extern void create_line_shape(void);
extern void create_circle_shape(void);
extern void create_rect_shape(void);
extern void create_color(void);

/* Funciones de dibujo PostScript */
extern void ps_stroke(void);
extern void ps_fill(void);
extern void ps_setlinewidth(void);

/* Funciones para la creación y utilización de Textos */
extern void constpush_str(void);  // Para empujar strings literales
extern void ps_setup_font(void);  // Configurar fuente
extern void ps_draw_text(void);   // Dibujar texto

#endif /* SYMBOL_H */
