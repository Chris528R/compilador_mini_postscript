begin "espirografo.ps"

negro = color(0, 0, 0)
azul_neon = color(0, 100, 255)
morado = color(180, 0, 255)
setlinewidth(1)

// Parámetros
R = 220
r = 65
d = 120
cx = 306
cy = 396

t = 0
max_t = 100
step = 0.1  // Paso un poco más grande para no saturar el output

// Control del primer punto
first = 1
prev_x = 0
prev_y = 0

while (t < max_t) {
    // Fórmulas
    diff = R - r
    cociente = diff / r
    arg1 = cociente * t
    
    // Terminos X
    t1x = diff * cos(t)
    t2x = d * cos(arg1)
    x = cx + t1x + t2x
    
    // Terminos Y
    t1y = diff * sin(t)
    t2y = d * sin(arg1)
    // Nota: en PS Y crece hacia arriba, la fórmula matemática resta
    y = cy + t1y - t2y

    if (first == 0) {
        l = line(prev_x, prev_y, x, y)
        
        // Efecto de color
        check = sin(t)
        if (check > 0) {
            stroke(l, azul_neon)
        } else {
            stroke(l, morado)
        }
    }
    
    prev_x = x
    prev_y = y
    first = 0
    t = t + step
}

fuente(HELVETICA, 16)
texto(50, 50, "Hipotrocoide con Math", negro)

end