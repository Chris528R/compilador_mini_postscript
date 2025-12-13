begin "salida.ps"
rojo = color(255, 0, 0)
azul = color(0, 0, 255)
verde = color(0, 255, 0)
negro = color(0, 0, 0)
setlinewidth(2)
linea1 = linea(100, 100, 300, 100)
stroke(linea1, rojo)
linea2 = linea(100, 100, 100, 300)
stroke(linea2, azul)
circ1 = circulo(200, 400, 50)
fill(circ1, verde)
circ2 = circulo(300, 400, 30)
stroke(circ2, negro)
rect1 = rectangulo(400, 300, 100, 80)
fill(rect1, azul)
x = 50
for (i = 0; i < 5; i = i + 1) {
    circ = circulo(x, 500, 20)
    stroke(circ, rojo)
    x = x + 60
}
ancho = 50
if (ancho > 40) {
    rect_grande = rectangulo(100, 550, ancho, ancho)
    fill(rect_grande, verde)
} else {
    circ_peq = circulo(125, 575, 10)
    fill(circ_peq, azul)
}
end
func dibujar_cuadricula {
    y = 50
    for (j = 0; j < 3; j = j + 1) {
        x = 50
        for (i = 0; i < 3; i = i + 1) {
            cuad = rectangulo(x, y, 40, 40)
            stroke(cuad, negro)
            x = x + 50
        }
        y = y + 50
    }
}
begin "cuadricula.ps"
    negro = color(0, 0, 0)
    setlinewidth(1)
    dibujar_cuadricula()
end