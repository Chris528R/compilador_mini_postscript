begin "test_n_params.ps"

// Ejemplo 1: Procedimiento con 3 parámetros nombrados
// Dibuja un rectángulo relleno
proc dibujar_caja(pos_x, pos_y, tamano) {
    // Usamos los nombres directamente, el compilador los pasará como /pos_x, etc.
    mi_rect = rect(pos_x, pos_y, tamano, tamano)
    
    // Condicion usando un parametro
    if (tamano > 50) {
        azul = color(0, 0, 200)
        fill(mi_rect, azul)
    } else {
        rojo = color(200, 0, 0)
        fill(mi_rect, rojo)
    }
}

// Ejemplo 2: Procedimiento con 0 parámetros
proc saludo() {
    fuente(HELVETICA, 20)
    negro = color(0,0,0)
    texto(100, 600, "Hola desde funcion sin params", negro)
}

// LLAMADAS

// Llamada con 3 argumentos
dibujar_caja(100, 100, 40)   // Rojo (pequeño)
dibujar_caja(200, 100, 100)  // Azul (grande)

// Llamada sin argumentos
saludo()

end