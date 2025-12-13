/* symbol.c - Implementación de la tabla de símbolos */

#include "symbol.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"

void execerror(char *s, char *t);
char *emalloc(unsigned n);

static Symbol *symlist = 0;    /* tabla de símbolos: lista ligada */

/* 
 * lookup - Buscar un símbolo en la tabla
 * Retorna: puntero al símbolo si existe, NULL si no existe
 */
Symbol *lookup(char *s)
{
    Symbol *sp;
    
    // Recorrer toda la lista ligada
    for (sp = symlist; sp != (Symbol *)0; sp = sp->next) {
        if (strcmp(sp->name, s) == 0)
            return sp;
    }
    
    return 0; /* 0 ==> no se encontró */
}

/* 
 * install - Instalar un nuevo símbolo en la tabla
 * s: nombre del símbolo
 * t: tipo (INDEF_TYPE, VAR_NUM, VAR_SHAPE, VAR_COLOR, etc.)
 * Retorna: puntero al símbolo creado
 */
Symbol *install(char *s, int t)
{
    Symbol *sp;
    
    // Reservar memoria para el símbolo
    sp = (Symbol *)malloc(sizeof(Symbol));
    if (!sp) {
        execerror("out of memory", (char *)0);
    }
    
    // Reservar memoria para el nombre (+1 para '\0')
    sp->name = (char *)malloc(strlen(s) + 1);
    if (!sp->name) {
        execerror("out of memory", (char *)0);
    }
    
    strcpy(sp->name, s);
    sp->type = t;
    
    // Inicialización por defecto según el tipo
    switch (t) {
        case VAR_NUM:
            sp->u.v = 0.0;
            break;
        case VAR_SHAPE:
            sp->u.shape = NULL;
            break;
        case VAR_COLOR:
            sp->u.color = NULL;
            break;
        default:
            sp->u.v = 0.0;
            sp->u.shape = NULL;
    }
    
    // Insertar al frente de la lista
    sp->next = symlist;
    symlist = sp;
    
    return sp;
}

/* 
 * emalloc - malloc con verificación de error
 * n: número de bytes a reservar
 * Retorna: puntero a memoria reservada
 */
char *emalloc(unsigned n)
{
    char *p = (char *)malloc(n);
    
    if (p == 0)
        execerror("out of memory", (char *)0);
    
    return p;
}

/* 
 * print_symbol_table - Función de debug (opcional)
 * Imprime toda la tabla de símbolos
 */
void print_symbol_table(void)
{
    Symbol *sp;
    
    printf("\n=== Tabla de Símbolos ===\n");
    printf("%-20s %-15s %s\n", "Nombre", "Tipo", "Valor");
    printf("----------------------------------------------\n");
    
    for (sp = symlist; sp != NULL; sp = sp->next) {
        printf("%-20s ", sp->name);
        
        switch (sp->type) {
            case INDEF_TYPE:
                printf("%-15s %s\n", "INDEFINIDO", "-");
                break;
            case VAR_NUM:
                printf("%-15s %.4g\n", "NUMERO", sp->u.v);
                break;
            case VAR_SHAPE:
                printf("%-15s %p\n", "FORMA", (void*)sp->u.shape);
                break;
            case VAR_COLOR:
                printf("%-15s %p\n", "COLOR", (void*)sp->u.color);
                break;
            case FUNCTION:
                printf("%-15s %p\n", "FUNCION", (void*)sp->u.defn);
                break;
            case PROCEDURE:
                printf("%-15s %p\n", "PROCEDIMIENTO", (void*)sp->u.defn);
                break;
            default:
                printf("%-15s %s\n", "DESCONOCIDO", "-");
        }
    }
    
    printf("=========================\n\n");
}

/* 
 * clear_symbol_table - Limpiar toda la tabla (opcional)
 * Útil para resetear entre compilaciones
 */
void clear_symbol_table(void)
{
    Symbol *sp, *next;
    
    for (sp = symlist; sp != NULL; sp = next) {
        next = sp->next;
        free(sp->name);
        
        // Liberar memoria de formas/colores si es necesario
        // (Cuidado: puede haber referencias compartidas)
        
        free(sp);
    }
    
    symlist = NULL;
}