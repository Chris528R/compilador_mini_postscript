begin "test_recursividad.ps"

// Definimos la función factorial recursiva
// Recibe: $1 (n)
// Retorna: Dibuja una barra de altura proporcional al factorial
proc factorial(n, x_pos) {
    
    // Caso Base: si n <= 1, terminamos (dibujamos base pequeña)
    if (n <= 1) {
        // Nada que hacer matemáticamente en este ejemplo visual,
        // pero es el punto de parada de la recursión.
        c = circle(x_pos, 50, 5)
        negro = color(0,0,0)
        fill(c, negro)
    } else {
        // Paso Recursivo:
        // 1. Calcular n - 1
        prev = n - 1
        
        // 2. Llamada recursiva (mueve la posición X un poco a la derecha)
        next_x = x_pos + 40
        factorial(prev, next_x)
        
        // 3. Dibujar resultado DESPUÉS de volver de la recursión (Post-order)
        // Altura = n * 20
        altura = n * 20
        
        // Dibujar barra
        barra = rect(x_pos, 100, 30, altura)
        azul = color(0, 0, 200)
        fill(barra, azul)
        
        // Escribir el numero
        fuente(HELVETICA, 12)
        texto(x_pos, 80, "n", azul)
    }
}

// Llamamos al factorial visual con n=5
// Debería dibujar 5 barras de alturas crecientes (o decrecientes según se mire)
factorial(5, 100)

fuente(HELVETICA, 20)
negro = color(0,0,0)
texto(50, 700, "Prueba de Recursividad (Pila de llamadas)", negro)

end