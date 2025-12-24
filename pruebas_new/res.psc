begin "resultado_prueba.ps"

// 1. Definimos variables globales
val = 10         // Cambia este valor a 1 para probar el ELSE
cx = 300
cy = 400
radio = 100

// 2. Definimos colores
rojo = color(255, 50, 50)
verde = color(50, 255, 50)
negro = color(0, 0, 0)
azul = color(50, 50, 255)

// 3. Definimos formas
mi_circulo = circle(cx, cy, radio)
mi_borde = rect(cx, cy, 220, 220)

// 4. Configuramos la fuente (requerido antes de usar texto)
fuente(HELVETICA, 20)

// 5. PRUEBA CRÍTICA DEL IF/ELSE
// Si aplicaste el fix de las llaves '{', esto debe compilar y dibujar correctamente.
if (val > 5) {
    // Caso VERDADERO: Dibuja verde
    fill(mi_circulo, verde)
    texto(cx, cy, "Condicion: VERDADERA (>5)", negro)
} else {
    // Caso FALSO: Dibuja rojo
    fill(mi_circulo, rojo)
    texto(cx, cy, "Condicion: FALSA (<=5)", negro)
}

// 6. Dibujamos un borde extra para verificar que el programa continúa después del if
stroke(mi_borde, azul)

end