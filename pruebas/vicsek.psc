begin "vicsek.ps"

// Configuración
negro = color(0, 0, 0)
rojo = color(180, 0, 0)
setlinewidth(1)

// Procedimiento Recursivo
// $1 = Centro X
// $2 = Centro Y
// $3 = Tamaño del lado
// $4 = Nivel de profundidad
proc fractal() {
    if ($4 > 0) {
        
        // 1. DIBUJAR EL CUADRADO ACTUAL
        // rectangulo recibe (esquina_x, esquina_y, ancho, alto)
        // Convertimos el centro ($1, $2) a esquina restando la mitad del lado
        
        r = rectangulo($1 - $3/2, $2 - $3/2, $3, $3)
        
        // Un toque artístico: si es pequeño rojo, si es grande negro
        if ($3 < 40) {
            stroke(r, rojo)
        } else {
            stroke(r, negro)
        }

        // 2. LLAMADAS RECURSIVAS A LAS 4 ESQUINAS
        // La lógica: La esquina del actual es el CENTRO del nuevo.
        // Nuevo tamaño: $3 * 0.45 (un poco menos de la mitad para que se vea bien)
        // Nuevo nivel: $4 - 1
        
        // Esquina Superior Izquierda (X - mitad, Y + mitad)
        fractal($1 - $3/2, $2 + $3/2, $3 * 0.45, $4 - 1)
        
        // Esquina Superior Derecha (X + mitad, Y + mitad)
        fractal($1 + $3/2, $2 + $3/2, $3 * 0.45, $4 - 1)
        
        // Esquina Inferior Derecha (X + mitad, Y - mitad)
        fractal($1 + $3/2, $2 - $3/2, $3 * 0.45, $4 - 1)
        
        // Esquina Inferior Izquierda (X - mitad, Y - mitad)
        fractal($1 - $3/2, $2 - $3/2, $3 * 0.45, $4 - 1)
    }
}

// Fondo blanco para limpiar
bg = rectangulo(0, 0, 612, 792)
blanco = color(255, 255, 255)
fill(bg, blanco)

// Título
fuente(HELVETICA, 20)
texto(50, 750, "Fractal de Vicsek Recursivo", negro)

// INICIAR FRACTAL
// Centro de la hoja (aprox), Tamaño inicial 180, 5 Niveles
fractal(306, 396, 180, 5)

end