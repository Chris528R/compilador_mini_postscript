begin "vicsek.ps"

negro = color(0, 0, 0)
rojo = color(180, 0, 0)
setlinewidth(1)

// Procedimiento recursivo: Fractal de Vicsek clásico
proc fractal(cx, cy, lado, nivel) {

    if (nivel == 0) {
        // Dibujar el cuadrado final
        mitad = lado / 2
        x = cx - mitad
        y = cy - mitad

        r = rect(x, y, lado, lado)
        stroke(r, negro)
    } else {

        nuevo_lado = lado / 3
        nuevo_nivel = nivel - 1
        offset = lado / 3

        // Centro
        fractal(cx, cy, nuevo_lado, nuevo_nivel)

        // Arriba
        fractal(cx, cy + offset, nuevo_lado, nuevo_nivel)

        // Abajo
        fractal(cx, cy - offset, nuevo_lado, nuevo_nivel)

        // Izquierda
        fractal(cx - offset, cy, nuevo_lado, nuevo_nivel)

        // Derecha
        fractal(cx + offset, cy, nuevo_lado, nuevo_nivel)
    }
}

// Fondo blanco
bg = rect(0, 0, 612, 792)
blanco = color(255, 255, 255)
fill(bg, blanco)

fuente(HELVETICA, 20)
texto(50, 750, "Fractal de Vicsek", negro)

// Iniciar en el centro de la hoja
fractal(306, 396, 243, 4)

end
