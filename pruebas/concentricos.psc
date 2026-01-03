begin "concentric_circles.ps"

// Configuración inicial
cx = 300
cy = 400
radio = 20
paso = 20
max_radio = 200

// Colores
azul_oscuro = color(0, 0, 150)
cyan = color(0, 200, 200)

// Grosor de linea
setlinewidth(2)

// Bucle para dibujar círculos
// Mientras el radio sea menor al máximo...
while (radio < max_radio) {
    
    // 1. Definir el círculo actual
    temp_circ = circle(cx, cy, radio)
    
    // 2. Alternar colores basado en el tamaño (truco simple)
    if (radio > 100) {
        stroke(temp_circ, azul_oscuro)
    } else {
        stroke(temp_circ, cyan)
    }

    // 3. Incrementar el radio (IMPORTANTE para no crear loop infinito)
    radio = radio + paso
}

fuente(HELVETICA, 16)
texto(cx, cy, "Ciclo While OK", azul_oscuro)

end