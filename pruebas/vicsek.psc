begin "vicsek"

negro = color(0, 0, 0)
rojo = color(180, 0, 0)
setlinewidth(1)

// Procedimiento Recursivo con nombres claros
proc fractal(cx, cy, lado, nivel) {
    if (nivel > 0) {
        
        // Dibujar cuadrado central
        mitad = lado / 2
        esquina_x = cx - mitad
        esquina_y = cy - mitad
        
        r = rect(esquina_x, esquina_y, lado, lado)
        
        if (lado < 40) {
            stroke(r, rojo)
        } else {
            stroke(r, negro)
        }

        // --- Recursividad ---
        nuevo_lado = lado * 0.45
        nuevo_nivel = nivel - 1
        
        // Calcular offsets para las 4 esquinas
        // Superior Izquierda
        fractal(esquina_x, esquina_y + lado, nuevo_lado, nuevo_nivel)
        
        // Superior Derecha
        fractal(esquina_x + lado, esquina_y + lado, nuevo_lado, nuevo_nivel)
        
        // Inferior Derecha
        fractal(esquina_x + lado, esquina_y, nuevo_lado, nuevo_nivel)
        
        // Inferior Izquierda
        fractal(esquina_x, esquina_y, nuevo_lado, nuevo_nivel)
        
        // Centro (Vicsek en cruz también lleva centro, opcional)
        fractal(cx, cy, nuevo_lado, nuevo_nivel)
    }
}

// Fondo blanco
bg = rect(0, 0, 612, 792)
blanco = color(255, 255, 255)
fill(bg, blanco)

fuente(HELVETICA, 20)
texto(50, 750, "Fractal de Vicsek", negro)

// Iniciar en el centro de la hoja
fractal(306, 396, 200, 4)

end