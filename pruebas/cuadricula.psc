begin "cuadricula.ps"

// Configuración
ancho = 50
alto = 50
limite_x = 500
limite_y = 600

// Colores
color_linea = color(100, 100, 100)
color_relleno = color(255, 200, 200) // Rojo claro

setlinewidth(1)

// Definimos la variable x antes del loop para asegurar su existencia
x = 0
y = 0

// Bucle externo: Recorre el eje Y
// Nota: Empezamos en -50 para que, al incrementarse primero, la primera fila sea Y=0
for (y = -50; y < limite_y; y = y + 50) {

    // Bucle interno: Recorre el eje X
    // Nota: Empezamos en -50 por la misma razón del incremento previo
    for (x = -50; x < limite_x; x = x + 50) {
        
        // 1. Dibujar un rectángulo en la posición actual
        mi_rect = rect(x, y, 40, 40)
        
        // 2. Condicional para hacer un patrón de ajedrez simple
        // Si X + Y es mayor a un valor arbitrario, lo rellenamos
        suma = x + y
        if (suma > 500) {
             fill(mi_rect, color_relleno)
        } else {
             stroke(mi_rect, color_linea)
        }
    }
}

// Texto final
fuente(HELVETICA, 20)
negro = color(0,0,0)
texto(50, 700, "Prueba de Loops FOR anidados", negro)

end