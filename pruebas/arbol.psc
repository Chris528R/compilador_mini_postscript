begin "demo_fractal.ps"

negro = color(0, 0, 0)
verde = color(0, 128, 0)
cafe = color(139, 69, 19)
setlinewidth(1)

proc dibujar_rama() {
    if ($3 > 5) {
        
        r = rectangulo($1, $2, $3, $4)
        
        if ($3 > 20) {
            fill(r, cafe)
        } else {
            fill(r, verde)
        }
        nuevo_ancho = $3 * 0.7
        nuevo_alto = $4 * 0.7
        dibujar_rama($1 - nuevo_ancho, $2 + $4, nuevo_ancho, nuevo_alto)
        
        dibujar_rama($1 + $3, $2 + $4, nuevo_ancho, nuevo_alto)
    }
}

suelo = rectangulo(0, 0, 612, 50)
fill(suelo, verde)

dibujar_rama(280, 50, 50, 150)

fuente(HELVETICA, 20)
texto(400, 20, "Fractal Tree", negro)

end