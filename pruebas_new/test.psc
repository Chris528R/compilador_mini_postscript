begin "test_fix.ps"

// Rectangulo: x=50, y=50, w=100, h=50
r1 = rect(50, 50, 100, 50)
rojo = color(255, 0, 0)
stroke(r1, rojo)

// Circulo: x=200, y=75, radio=25
c1 = circle(200, 75, 25)
azul = color(0, 0, 255)
fill(c1, azul)

// Prueba superpuesta para verificar coordenadas
// Este rectangulo debe empezar exactamente donde termina el rojo
r2 = rect(150, 50, 50, 50)
verde = color(0, 255, 0)
fill(r2, verde)

end