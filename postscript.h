#ifndef POSTSCRIPT_H
#define POSTSCRIPT_H

#include <stdio.h>

//*************************************************************************/
// TIPOS
//*************************************************************************/
// Tipos de datos extendidos
typedef enum {
    TYPE_UNDEF,
    TYPE_NUM,
    TYPE_SHAPE,
    TYPE_COLOR
} PSDataType;

// Color RGB
typedef struct {
    double r, g, b;  // valores 0-255
} PSColor;

// Tipos de formas
typedef enum {
    SHAPE_LINE,
    SHAPE_CIRCLE,
    SHAPE_RECT
} PSShapeType;

// Estructura de forma geométrica
typedef struct {
    PSShapeType type;
    union {
        struct {
            double x1, y1, x2, y2;
        } line;
        struct {
            double x, y, radius;
        } circle;
        struct {
            double x, y, width, height;
        } rect;
    } geom;
} PSShape;

// Datum extendido para la pila
typedef struct {
    PSDataType type;
    union {
        double num;
        PSShape *shape;
        PSColor *color;
        void *sym;  // Symbol pointer
    } u;
} PSDatum;

// Documento PostScript
typedef struct {
    char *filename;
    char *code_buffer;
    size_t buffer_size;
    size_t buffer_capacity;
    int is_open;
} PSDocument;

// Funciones para crear elementos
PSShape *create_line(double x1, double y1, double x2, double y2);
PSShape *create_circle(double x, double y, double r);
PSShape *create_rect(double x, double y, double w, double h);
PSColor *create_color_rgb(double r, double g, double b);

// Funciones de dibujo
void ps_draw_stroke(PSShape *shape, PSColor *color);
void ps_draw_fill(PSShape *shape, PSColor *color);


//*************************************************************************/
// FUNCIONES PARA GENERAR CÓDIGO POSTSCRIPT
//*************************************************************************/

// Inicialización
void ps_init(void);

// Control de documento
void ps_begin_document(const char *filename);
void ps_end_document(void);
void ps_append(const char *format, ...);

// Funciones de la máquina virtual para PostScript
void create_line_shape(void);      // Crea línea desde 4 números en pila
void create_circle_shape(void);    // Crea círculo desde 3 números
void create_rect_shape(void);      // Crea rectángulo desde 4 números
void create_color(void);           // Crea color desde 3 números RGB

void assign_shape(void);           // Asigna forma a variable
void assign_color(void);           // Asigna color a variable

void ps_stroke(void);              // stroke(shape, color)
void ps_fill(void);                // fill(shape, color)
void ps_setlinewidth(void);        // setlinewidth(num)

// Generación de código PostScript
void generate_line_ps(PSShape *shape);
void generate_circle_ps(PSShape *shape);
void generate_rect_ps(PSShape *shape);
void generate_color_ps(PSColor *color);

#endif /*  POSTSCRIPT_H */