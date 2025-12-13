#include "postscript.h"
#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static PSDocument *current_doc = NULL;

// Funciones auxiliares de la pila
extern void push(Datum d);
extern Datum pop(void);
void execerror(char *s, char *t);

void ps_init(void) {
    current_doc = NULL;
}

void ps_begin_document(const char *filename) {
    current_doc = (PSDocument *)malloc(sizeof(PSDocument));
    current_doc->filename = strdup(filename);
    current_doc->buffer_capacity = 4096;
    current_doc->buffer_size = 0;
    current_doc->code_buffer = (char *)malloc(current_doc->buffer_capacity);
    current_doc->code_buffer[0] = '\0';
    current_doc->is_open = 1;
    
    // Header PostScript
    ps_append("%%!PS-Adobe-3.0\n");
    ps_append("%%%%BoundingBox: 0 0 612 792\n");
    ps_append("%%%%Title: %s\n", filename);
    ps_append("%%%%Creator: PS Compiler\n");
    ps_append("%%%%EndComments\n\n");
}

void ps_end_document(void) {
    if (!current_doc || !current_doc->is_open) {
        execerror("No hay documento abierto", (char *)0);
        return;
    }
    
    ps_append("\nshowpage\n");
    ps_append("%%%%EOF\n");
    
    // Guardar en archivo
    FILE *f = fopen(current_doc->filename, "w");
    if (!f) {
        execerror("No se puede crear archivo", current_doc->filename);
        return;
    }
    
    fwrite(current_doc->code_buffer, 1, current_doc->buffer_size, f);
    fclose(f);
    
    // Liberar memoria
    free(current_doc->code_buffer);
    free(current_doc->filename);
    current_doc->is_open = 0;
    free(current_doc);
    current_doc = NULL;
}

void ps_append(const char *format, ...) {
    if (!current_doc || !current_doc->is_open) {
        return;
    }
    
    va_list args;
    va_start(args, format);
    
    // Calcular tamaño necesario
    va_list args_copy;
    va_copy(args_copy, args);
    int needed = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);
    
    // Expandir buffer si es necesario
    while (current_doc->buffer_size + needed + 1 > current_doc->buffer_capacity) {
        current_doc->buffer_capacity *= 2;
        current_doc->code_buffer = (char *)realloc(current_doc->code_buffer, 
                                                     current_doc->buffer_capacity);
    }
    
    // Agregar texto
    vsnprintf(current_doc->code_buffer + current_doc->buffer_size,
              needed + 1, format, args);
    current_doc->buffer_size += needed;
    
    va_end(args);
}

// Funciones para crear elementos gráficos

PSShape *create_line(double x1, double y1, double x2, double y2) {
    PSShape *s = (PSShape *)malloc(sizeof(PSShape));
    s->type = SHAPE_LINE;
    s->geom.line.x1 = x1;
    s->geom.line.y1 = y1;
    s->geom.line.x2 = x2;
    s->geom.line.y2 = y2;
    return s;
}

PSShape *create_circle(double x, double y, double r) {
    PSShape *s = (PSShape *)malloc(sizeof(PSShape));
    s->type = SHAPE_CIRCLE;
    s->geom.circle.x = x;
    s->geom.circle.y = y;
    s->geom.circle.radius = r;
    return s;
}

PSShape *create_rect(double x, double y, double w, double h) {
    PSShape *s = (PSShape *)malloc(sizeof(PSShape));
    s->type = SHAPE_RECT;
    s->geom.rect.x = x;
    s->geom.rect.y = y;
    s->geom.rect.width = w;
    s->geom.rect.height = h;
    return s;
}

PSColor *create_color_rgb(double r, double g, double b) {
    PSColor *c = (PSColor *)malloc(sizeof(PSColor));
    c->r = r / 255.0;  // Normalizar a 0-1
    c->g = g / 255.0;
    c->b = b / 255.0;
    return c;
}

// Funciones de la VM para crear shapes desde la pila

void create_line_shape(void) {
    Datum d4 = pop();  // y2
    Datum d3 = pop();  // x2
    Datum d2 = pop();  // y1
    Datum d1 = pop();  // x1
    
    PSShape *shape = create_line(d1.u.val, d2.u.val, d3.u.val, d4.u.val);
    
    Datum result;
    result.type = VAR_NUM;  // Usar tipo compatible con sistema existente
    result.u.val = (double)(long)shape;  // Guardar puntero como double
    push(result);
}

void create_circle_shape(void) {
    Datum d3 = pop();  // r
    Datum d2 = pop();  // y
    Datum d1 = pop();  // x
    
    PSShape *shape = create_circle(d1.u.val, d2.u.val, d3.u.val);
    
    Datum result;
    result.type = VAR_NUM;
    result.u.val = (double)(long)shape;
    push(result);
}

void create_rect_shape(void) {
    Datum d4 = pop();  // h
    Datum d3 = pop();  // w
    Datum d2 = pop();  // y
    Datum d1 = pop();  // x
    
    PSShape *shape = create_rect(d1.u.val, d2.u.val, d3.u.val, d4.u.val);
    
    Datum result;
    result.type = VAR_NUM;
    result.u.val = (double)(long)shape;
    push(result);
}

void create_color(void) {
    Datum d3 = pop();  // b
    Datum d2 = pop();  // g
    Datum d1 = pop();  // r
    
    PSColor *color = create_color_rgb(d1.u.val, d2.u.val, d3.u.val);
    
    Datum result;
    result.type = VAR_NUM;
    result.u.val = (double)(long)color;
    push(result);
}

void assign_shape(void) {
    Datum d_var = pop();   // Symbol
    Datum d_shape = pop(); // Shape pointer
    
    Symbol *s = d_var.u.sym;
    s->type = VAR_NUM;  // Guardamos como número (puntero)
    s->u.v = d_shape.u.val;
    
    push(d_shape);  // Devolver valor
}

void assign_color(void) {
    Datum d_var = pop();
    Datum d_color = pop();
    
    Symbol *s = d_var.u.sym;
    s->type = VAR_NUM;
    s->u.v = d_color.u.val;
    
    push(d_color);
}

// Generación de código PostScript

void generate_color_ps(PSColor *color) {
    ps_append("%.3f %.3f %.3f setrgbcolor\n", color->r, color->g, color->b);
}

void generate_line_ps(PSShape *shape) {
    ps_append("newpath\n");
    ps_append("%.2f %.2f moveto\n", shape->geom.line.x1, shape->geom.line.y1);
    ps_append("%.2f %.2f lineto\n", shape->geom.line.x2, shape->geom.line.y2);
}

void generate_circle_ps(PSShape *shape) {
    ps_append("newpath\n");
    ps_append("%.2f %.2f %.2f 0 360 arc\n", 
              shape->geom.circle.x, 
              shape->geom.circle.y, 
              shape->geom.circle.radius);
}

void generate_rect_ps(PSShape *shape) {
    ps_append("newpath\n");
    ps_append("%.2f %.2f moveto\n", shape->geom.rect.x, shape->geom.rect.y);
    ps_append("%.2f %.2f lineto\n", shape->geom.rect.x + shape->geom.rect.width, 
              shape->geom.rect.y);
    ps_append("%.2f %.2f lineto\n", shape->geom.rect.x + shape->geom.rect.width, 
              shape->geom.rect.y + shape->geom.rect.height);
    ps_append("%.2f %.2f lineto\n", shape->geom.rect.x, 
              shape->geom.rect.y + shape->geom.rect.height);
    ps_append("closepath\n");
}

// Funciones de dibujo (llamadas desde la VM)

void ps_stroke(void) {
    Datum d_color = pop();
    Datum d_shape = pop();
    
    PSShape *shape = (PSShape *)(long)d_shape.u.val;
    PSColor *color = (PSColor *)(long)d_color.u.val;
    
    generate_color_ps(color);
    
    switch (shape->type) {
        case SHAPE_LINE:
            generate_line_ps(shape);
            break;
        case SHAPE_CIRCLE:
            generate_circle_ps(shape);
            break;
        case SHAPE_RECT:
            generate_rect_ps(shape);
            break;
        default:
            execerror("Tipo de forma desconocido", (char *)0);
    }
    
    ps_append("stroke\n\n");
}

void ps_fill(void) {
    Datum d_color = pop();
    Datum d_shape = pop();
    
    PSShape *shape = (PSShape *)(long)d_shape.u.val;
    PSColor *color = (PSColor *)(long)d_color.u.val;
    
    generate_color_ps(color);
    
    switch (shape->type) {
        case SHAPE_CIRCLE:
            generate_circle_ps(shape);
            break;
        case SHAPE_RECT:
            generate_rect_ps(shape);
            break;
        default:
            execerror("fill solo aplica a círculos y rectángulos", (char *)0);
    }
    
    ps_append("fill\n\n");
}

void ps_setlinewidth(void) {
    Datum d = pop();
    ps_append("%.2f setlinewidth\n", d.u.val);
}