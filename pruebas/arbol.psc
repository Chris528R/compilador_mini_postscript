begin "demo_fractal_arbol"

negro = color(0, 0, 0)
verde = color(0, 128, 0)
cafe = color(139, 69, 19)
setlinewidth(1)

// Procedimiento Recursivo del Árbol
proc dibujar_rama(x, y, ancho, alto) {
    // Condición de parada: si el ancho es muy delgado, paramos
    if (ancho > 5) {
        
        r = rect(x, y, ancho, alto)
        
        // Si la rama es gruesa es tronco (café), si es delgada es hoja (verde)
        if (ancho > 20) {
            fill(r, cafe)
        } else {
            fill(r, verde)
        }
        
        // Calcular dimensiones para las siguientes ramas (70% del tamaño)
        nuevo_ancho = ancho * 0.7
        nuevo_alto = alto * 0.7
        
        // Calcular nuevas posiciones
        // Rama Izquierda: Se mueve a la izquierda y sube
        x_izq = x - nuevo_ancho
        y_sig = y + alto
        dibujar_rama(x_izq, y_sig, nuevo_ancho, nuevo_alto)
        
        // Rama Derecha: Se mueve a la derecha y sube
        x_der = x + ancho
        dibujar_rama(x_der, y_sig, nuevo_ancho, nuevo_alto)
    }
}

// Suelo
suelo = rect(0, 0, 612, 50)
fill(suelo, verde)

// Iniciar el árbol
// Base en X=280, Y=50, Ancho=50, Alto=150
dibujar_rama(280, 50, 50, 150)

fuente(HELVETICA, 20)
texto(400, 20, "Fractal Tree", negro)

end