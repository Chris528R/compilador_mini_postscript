begin "test_completo.ps"
//comentario
rojo = color(255, 0, 0)
azul = color(0, 0, 255)
verde = color(0, 255, 0)
negro = color(0, 0, 0)
setlinewidth(2)
proc dibujar_diana() {
    grande = circulo($1, $2, $3)
    stroke(grande, negro)
    
    pequeno = circulo($1, $2, $3 / 2)
    fill(pequeno, rojo)
}
func siguiente_salto() {
    return $1 + 100
}
x = 100
y = 400
for (i = 0; i < 5; i = i + 1) {
    if (i < 3) {
        dibujar_diana(x, y, 40)
    } else {
        r = rectangulo(x - 40, y - 40, 80, 80)
        fill(r, azul)
        stroke(r, verde)
    }
    x = siguiente_salto(x)
}
end