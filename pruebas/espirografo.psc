begin "espirografo.ps"

// --- Configuración Estética ---
negro = color(0, 0, 0)
azul_neon = color(0, 100, 255)
morado = color(180, 0, 255)
setlinewidth(0.8)

// --- Parámetros del Espirógrafo ---
R = 220    // Radio del círculo fijo (grande)
r = 65     // Radio del círculo móvil (pequeño)
d = 120    // Distancia del punto de dibujo al centro del círculo móvil

// Centro de la hoja
cx = 306
cy = 396

// --- Variables de iteración ---
// Vamos de 0 a 100 radianes (muchas vueltas para cerrar la figura)
// Paso pequeño (0.1) para que la curva se vea suave
t = 0
max_t = 100
step = 0.05

// Primer punto (para no trazar línea desde el origen 0,0)
first = 1
prev_x = 0
prev_y = 0

// --- Bucle de Dibujo ---
while (t < max_t) {
    
    // Fórmulas del Hipotrocoide:
    // x = (R-r)*cos(t) + d*cos( ((R-r)/r) * t )
    // y = (R-r)*sin(t) - d*sin( ((R-r)/r) * t )
    
    diff = R - r
    term1_x = diff * cos(t)
    term2_x = d * cos( (diff / r) * t )
    x = cx + term1_x + term2_x
    
    term1_y = diff * sin(t)
    term2_y = d * sin( (diff / r) * t )
    y = cy + term1_y - term2_y

    // Dibujar segmento
    if (first == 0) {
        // Usamos variables locales para la línea
        l = linea(prev_x, prev_y, x, y)
        
        // Efecto degradado simple: cambiar color según el ángulo t
        if (sin(t) > 0) {
            stroke(l, azul_neon)
        } else {
            stroke(l, morado)
        }
    }
    
    // Actualizar estado
    prev_x = x
    prev_y = y
    first = 0
    t = t + step
}

fuente(HELVETICA, 16)
texto(50, 50, "Hipotrocoide Generado", negro)

end