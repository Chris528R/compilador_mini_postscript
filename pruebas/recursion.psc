begin "recursivo.ps"
negro = color(0, 0, 0)
rojo = color(255, 0, 0)
setlinewidth(1.5)
proc tunel_recursivo() {
    
    if ($4 > 0) {
        
        rect = rectangulo($1, $2, $3, $3)
        stroke(rect, negro)
        tunel_recursivo($1 + 20, $2 + 20, $3 - 40, $4 - 1)

        
        marcador = circulo($1 + 5, $2 + 5, 3)
        fill(marcador, rojo)
    }
}

tunel_recursivo(50, 50, 500, 12)

end