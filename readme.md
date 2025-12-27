# 🎨 Transpilador de Gráficos Vectoriales (DSL a PostScript)

Este proyecto es un **transpilador** que convierte un **Lenguaje de Dominio Específico (DSL)** diseñado para gráficos vectoriales y algoritmos recursivos a código **PostScript (PS)** estándar.

El compilador permite generar figuras geométricas complejas, fractales y gráficas matemáticas utilizando una sintaxis sencilla similar a **C**, manejando automáticamente la gestión de memoria y el renderizado.

---

## 📋 Características

- **Tipado dinámico e inferencia**  
  Distingue automáticamente entre `Líneas`, `Rectángulos` y `Círculos` para optimizar los comandos de dibujo (`rectstroke` vs `lineto`).

- **Recursividad real**  
  Implementación de pila de llamadas con diccionarios locales (`dict stack`) para soportar algoritmos recursivos complejos (Fractales, Hilbert, Árboles).

- **Primitivas gráficas**  
  Soporte nativo para colores, grosores de línea y transformaciones.

- **Matemáticas**  
  Librería completa de funciones (`sin`, `cos`, `sqrt`, `pow`, etc.).

- **Modularidad**  
  Código fuente estructurado en cabeceras, lógica y gramática.

---

## 🚀 Instalación y Compilación

Este proyecto utiliza **Flex** (Lexer), **Bison/Yacc** (Parser) y **GCC**.

### Requisitos

- GCC  
- Flex  
- Yacc  

### Compilación

El proyecto se compila de la siguiente forma:

```bash
yacc -d postsctip.y
flex postsctip.l
gcc -o transpilador ./lex.yy.c ./y.tab.c ./compilador.c -lm 
```
## 🛠️ Uso
Para transpilar un archivo fuente (`.dsl` o `.psc`):
```bash
./transpilador pruebas/curva_hilbert.dsl
```

El programa generará automáticamente un archivo .ps con el nombre indicado en el bloque begin o basado en el archivo de entrada.

## 👁️ Visualización

El archivo PostScript generado puede abrirse con:

* Ghostscript (gs)

* Okular / Evince (Linux)

* Adobe Acrobat Distiller / Illustrator

* PS Viewer Online

📂 Estructura del Proyecto
```markdown
.
├── compiler.h
├── compiler.c
├── postscript.l
├── postscript.y
└── pruebas/
    ├── curva_hilbert.psc
    ├── vicsek.psc
    ├── arbol.psc
    ├── espirografo.psc
    └── dashboard.psc
```
**Ejemplos incluidos**

* curva_hilbert.psc – Recursividad avanzada

* vicsek.psc – Fractal de caja

* arbol.psc – Árbol binario recursivo

* espirografo.psc – Matemáticas y ciclos

* dashboard.psc – Texto y gráficas de barras

## 🔍 Traducción de Código (Ejemplos)
### 1️⃣ Ciclo for

**PSC**
```C
for (i = 0; i < 10; i = i + 1) {
    c = circle(i, i, 5)
    stroke(c, negro)
}
```

PostScript
```postscript
/i 0 def            % Inicialización
{
  i 10 lt           % Condición
  not { exit } if   % Si es falso, salir
  
  % Cuerpo del bucle
  /c [ i i 5 ] def
  gsave negro aload pop setrgbcolor
  c aload pop 0 360 arc stroke grestore
  
  /i i 1 add def    % Incremento
} loop
```
### 2️⃣ Condicional if / else

**DSL**
```C
if (radio > 50) {
    fill(c, rojo)
} else {
    stroke(c, azul)
}
```

**PostScript**
```
radio 50 gt
{   
    % Bloque True
    gsave rojo aload pop setrgbcolor
    c aload pop 0 360 arc fill grestore
}
{   
    % Bloque False
    gsave azul aload pop setrgbcolor
    c aload pop 0 360 arc stroke grestore
} ifelse
```
### 3️⃣ Procedimientos y Recursividad

**DSL**
```C
proc mi_funcion(x, y) {
    nuevo_x = x + 10
    mi_funcion(nuevo_x, y)
}
```

**PostScript**
```
/mi_funcion {
  20 dict begin       % Crear Scope Local
  /y exch def         % Recuperar parámetro 2
  /x exch def         % Recuperar parámetro 1
  
  /nuevo_x x 10 add def
  
  nuevo_x y mi_funcion % Llamada recursiva
  
  end                 % Destruir Scope Local
} def
```
### 4️⃣ Ciclo while

**DSL**
```C
while (t < 100) {
    t = t + 1
}
```

**PostScript**
```
{
  t 100 lt          % Evaluar condición
  not { exit } if   % Salir si falso
  
  /t t 1 add store  % Cuerpo
} loop
```
