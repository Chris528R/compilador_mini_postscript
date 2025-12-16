#include "symbol.h"
#include "postscript.h"
#include "y.tab.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NSTACK 10000
static Datum stack[NSTACK]; /* la pila */
static Datum *stackp;       /* siguiente lugar libre en la pila */

#define NPROG 50000
Inst prog[NPROG]; /* la RAM de la máquina VP*/
Inst *progp;      /* siguiente lugar libre para la generación de código */
Inst *pc;         /* contador de programa durante la ejecución */
Inst *progbase = prog;
int returning;

typedef struct Frame {
    Symbol *sp;
    Inst *retpc;
    Datum *argn;
    int nargs;
} Frame;

#define NFRAME 10000
Frame frame[NFRAME];
Frame *fp;

void execerror(char *s, char *t);

void initcode() {
    stackp = stack;
    progp = progbase;
    fp = frame;
    returning = 0;
}

void push(Datum d) {
    if (stackp >= &stack[NSTACK])
        execerror("stack overflow", (char *)0);
    *stackp++ = d;
}

Datum pop() {
    if (stackp <= stack)
        execerror("stack underflow", (char *)0);
    return *--stackp;
}

void pop1() {
    if (stackp <= stack)
        execerror("stack underflow", (char *)0);
    --stackp;
}

/* Push de constante numérica */
void constpush_n() {
    Datum d;
    d.type = VAR_NUM;
    d.u.val = *(double *)pc;
    pc = (Inst *)((double *)pc + 1);
    push(d);
}

/* Push de variable (símbolo) */
void varpush() {
    Datum d;
    d.type = INDEF_TYPE; // El tipo real se resolverá en 'eval'
    d.u.sym = (Symbol *)(*pc++);
    push(d);
}

/* Evaluar una variable */
void eval() {
    Datum d = pop();
    if (d.u.sym->type == INDEF_TYPE)
        execerror("undefined variable", d.u.sym->name);

    Datum result;
    result.type = d.u.sym->type;
    
    switch (result.type) {
        case VAR_NUM:
            result.u.val = d.u.sym->u.v;
            break;
        case VAR_SHAPE:
            result.u.shape = d.u.sym->u.shape; /* <--- ESTO FALTABA */
            break;
        case VAR_COLOR:
            result.u.color = d.u.sym->u.color; /* <--- ESTO FALTABA */
            break;
        default:
            execerror("invalid variable type", d.u.sym->name);
    }
    push(result);
}

/* Operaciones aritméticas - solo para números */
void add() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("type mismatch for '+'", (char *)0);
    
    Datum result;
    result.type = VAR_NUM;
    result.u.val = d1.u.val + d2.u.val;
    push(result);
}

void sub() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("type mismatch for '-'", (char *)0);
    
    Datum result;
    result.type = VAR_NUM;
    result.u.val = d1.u.val - d2.u.val;
    push(result);
}

void mul() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("type mismatch for '*'", (char *)0);

    Datum result;
    result.type = VAR_NUM;
    result.u.val = d1.u.val * d2.u.val;
    push(result);
}

void divide() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("type mismatch for '/'", (char *)0);
    
    if (d2.u.val == 0.0)
        execerror("division by zero", (char *)0);
    
    Datum result;
    result.type = VAR_NUM;
    result.u.val = d1.u.val / d2.u.val;
    push(result);
}

void negate() {
    Datum d = pop();
    if (d.type != VAR_NUM)
        execerror("type mismatch for unary '-'", (char *)0);
    
    d.u.val = -d.u.val;
    push(d);
}

/* Asignación genérica */
void assign() {
    Datum d1 = pop(); // La variable (Symbol)
    Datum d2 = pop(); // El valor (Shape, Color, Num...)
    Symbol *s = d1.u.sym;

    /* Si la variable tenía un tipo definido y es diferente, error */
    if (s->type != INDEF_TYPE && s->type != d2.type)
        execerror("type mismatch in assignment to", s->name);

    s->type = d2.type;
    
    switch (d2.type) {
        case VAR_NUM:
            s->u.v = d2.u.val;
            break;
        case VAR_SHAPE:
            s->u.shape = d2.u.shape;
            break;
        case VAR_COLOR:
            s->u.color = d2.u.color;
            break;
        default:
            execerror("invalid type in assignment", s->name);
    }
    
    push(d2); // Devolver el valor a la pila
}

/* Imprimir valor */
void print() {
    Datum d;
    if(stackp > stack){
        d = pop();
        switch (d.type) {
            case VAR_NUM:
                printf("\t= %.8g\n", d.u.val);
                break;
            case VAR_SHAPE:
                printf("\t[Shape]\n");
                break;
            case VAR_COLOR:
                printf("\t[Color: R=%.2f G=%.2f B=%.2f]\n", 
                       d.u.color->r * 255, 
                       d.u.color->g * 255, 
                       d.u.color->b * 255);
                break;
            default:
                printf("\t[Unknown type]\n");
        }
    }
}

/* Operadores de comparación */
void gt() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for comparison", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val > d2.u.val;
    push(res);
}

void lt() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for comparison", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val < d2.u.val;
    push(res);
}

void ge() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for comparison", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val >= d2.u.val;
    push(res);
}

void le() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for comparison", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val <= d2.u.val;
    push(res);
}

void eq() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for comparison", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val == d2.u.val;
    push(res);
}

void ne() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for comparison", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val != d2.u.val;
    push(res);
}

/* Operadores lógicos */
void and_op() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for logical operator", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val != 0.0 && d2.u.val != 0.0;
    push(res);
}

void or_op() {
    Datum d2 = pop(), d1 = pop();
    if (d1.type != VAR_NUM || d2.type != VAR_NUM)
        execerror("bad type for logical operator", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val != 0.0 || d2.u.val != 0.0;
    push(res);
}

void not_op() {
    Datum d1 = pop();
    if (d1.type != VAR_NUM)
        execerror("bad type for logical operator", (char *)0);
    Datum res; 
    res.type = VAR_NUM; 
    res.u.val = d1.u.val == 0.0;
    push(res);
}

/* Estructuras de control */
void whilecode() {
    Datum d;
    Inst *savepc = pc;
    execute(savepc+2);     /* condición */ 
    d = pop(); 
    while (d.u.val) {
        execute(*((Inst **)(savepc)));     /* cuerpo */
        if(returning) break;
        execute(savepc+2);
        d = pop(); 
    } 
    if(!returning)
        pc = *((Inst **)(savepc+1));     /* siguiente proposición */
}

void ifcode(){
    Datum d;
    Inst *savepc = pc;
    execute(savepc+3);    /* condición */
    d = pop(); 
    if (d.u.val)
        execute(*((Inst **)(savepc))); 
    else if (*((Inst **)(savepc+1)))   /* ¿parte else? */
        execute(*((Inst **)(savepc+1)));
    if (!returning)
        pc = *((Inst **)(savepc+2));    /* siguiente proposición */ 
}

void forcode(){
    Datum d;
    Inst* savepc = pc;
    execute(*((Inst **)(savepc))); /* stmt antes del bucle */
    execute(*((Inst **)(savepc + 1))); /* condición */
    d = pop();
    while(d.u.val){
        execute(*((Inst **)(savepc + 3)));   /* cuerpo */
        if(returning) break;
        execute(*((Inst **)(savepc + 2)));   /* stmt al final de cada iteración */
        execute(*((Inst **)(savepc + 1)));   /* condición */
        d = pop();
    }
    if(!returning)
        pc = *((Inst **)(savepc + 4));
}

/* Funciones y procedimientos */
void define(Symbol *sp) {
    sp->u.defn = (void (*)(void))progbase;
    progbase = progp;
}

void call() {
    Symbol *sp = (Symbol *)pc[0];
    if(fp++ >= &frame[NFRAME-1])
        execerror(sp->name, "call nested too deeply");
    fp->sp = sp;
    fp->nargs = (int)(long)pc[1];
    fp->retpc = pc + 2;
    fp->argn = stackp - 1;
    execute((Inst *)sp->u.defn);
    returning = 0;
}

void ret() {
    int i;
    for (i = 0; i < fp->nargs; i++)
        pop();  /* sacar argumentos de la pila */
    pc = (Inst *)fp->retpc;
    --fp;
    returning = 1; 
}

void funcret(){
    Datum d;
    if (fp->sp->type == TYPE_PROCEDURE)
        execerror(fp->sp->name, "(proc) returns value");
    d = pop();      /* conservar el valor de retorno */
    ret();
    push(d); 
}

void procret(){
    if (fp->sp->type == TYPE_FUNCTION)
        execerror(fp->sp->name, "(func) returns no value"); 
    ret(); 
}

Datum *getarg() {
    int narg = (int)(long)*pc++;
    if (narg > fp->nargs)
        execerror(fp->sp->name, "not enough arguments");
    return &fp->argn[narg - fp->nargs]; 
}

void arg() {
    Datum d;
    d = *getarg();
    push(d); 
}

void argassign() {
    Datum d;
    d = pop();
    push(d);       /* dejar valor en la pila */
    *getarg() = d; 
}

/* Generación de código */
Inst *code(Inst f) {
    Inst *oprogp = progp;
    if (progp >= &prog[NPROG])
        execerror("program too big", (char *)0);
    *progp++ = f;
    return oprogp;
}

void code_double(double d) {
    if ((char*)progp + sizeof(double) > (char*)&prog[NPROG])
        execerror("program too big", (char *)0);
    *(double *)progp = d;
    progp = (Inst *)((double *)progp + 1);
}

/* Función para leer el string desde el código y empujarlo a la pila */
void constpush_str() {
    Datum d;
    d.type = VAR_STRING;
    
    /* Leemos el char* que guardamos justo en la siguiente posición del PC */
    d.u.str = *(char **)pc;
    
    /* Saltamos ese espacio en memoria para que la siguiente instrucción sea válida */
    pc = (Inst *)((char **)pc + 1);
    
    push(d);
}

/* Configura la fuente en el documento PS */
void ps_setup_font() {
    Datum font_id = pop(); 
    Datum size = pop();
    
    if (size.type != VAR_NUM || font_id.type != VAR_NUM)
        execerror("Tipos incorrectos en fuente()", 0);

    char *fontName;
    int id = (int)font_id.u.val;
    
    /* Mapeo de índices a nombres reales de PostScript */
    switch(id) {
        case 0: fontName = "Helvetica"; break;
        case 1: fontName = "Times-Roman"; break;
        case 2: fontName = "Courier"; break;
        default: fontName = "Helvetica"; break;
    }
    
    ps_append("/%s findfont %.2f scalefont setfont\n", fontName, size.u.val);
}

/* Genera el comando para dibujar texto */
void ps_draw_text() {
    Datum d_color = pop(); //color
    Datum d_str = pop(); //strijg
    Datum d_y = pop(); //Y
    Datum d_x = pop(); //X
    
    /* Validaciones */
    if (d_str.type != VAR_STRING) 
        execerror("El tercer argumento de texto() debe ser una cadena", 0);
    
    /* Configurar Color en PS */
    PSColor *c;
    
    /* Manejo robusto: Si es VAR_NUM (puntero) o VAR_COLOR */
    if (d_color.type == VAR_NUM) {
        c = (PSColor *)(long)d_color.u.val;
    } else if (d_color.type == VAR_COLOR) {
        c = d_color.u.color;
    } else {
        execerror("El cuarto argumento debe ser un color válido", 0);
    }
    
    ps_append("%.3f %.3f %.3f setrgbcolor\n", c->r, c->g, c->b);

    /* Dibujar Texto */
    ps_append("%.2f %.2f moveto\n", d_x.u.val, d_y.u.val);
    ps_append("(%s) show\n", d_str.u.str);
}

void execute(Inst *p) {
    for (pc = p; pc && *pc != STOP && !returning; )
        (*pc++)();
}