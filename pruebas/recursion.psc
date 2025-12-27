begin "recursivo"

negro = color(0, 0, 0)
rojo = color(255, 0, 0)
setlinewidth(1.5)

// Hemos actualizado esto para usar PARAMETROS NOMBRADOS
// x, y: Coordenadas
// tam: Tamaño del lado
// nivel: Profundidad de recursión
proc tunel_recursivo(x, y, tam, nivel) {
    
    if (nivel > 0) {
        
        // Dibujar el marco actual
        mi_rect = rect(x, y, tam, tam)
        stroke(mi_rect, negro)
        
        // Calcular nuevos valores para la siguiente iteración
        nuevo_x = x + 20
        nuevo_y = y + 20
        nuevo_tam = tam - 40
        nuevo_nivel = nivel - 1

        // Llamada Recursiva
        tunel_recursivo(nuevo_x, nuevo_y, nuevo_tam, nuevo_nivel)

        // Esto se ejecuta DESPUÉS de volver de la recursión (Post-order)
        // Dibuja un punto rojo en la esquina superior izquierda de cada cuadro
        mx = x + 5
        my = y + 5
        marcador = circle(mx, my, 3)
        fill(marcador, rojo)
    }
}

// Iniciar recursión
tunel_recursivo(50, 50, 500, 12)

end