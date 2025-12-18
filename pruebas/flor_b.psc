begin "flor_simple.ps"
// Colores
amarillo = color(212, 224, 43)
morado = color(130, 43, 224)
negro = color(0, 0, 0)
setlinewidth(1.5)

// Centro de la hoja
cx = 306 
cy = 396

// Parámetros de la flor
radio_centro = 60
radio_petalo = 30
distancia_petalo = 70
cantidad_petalos = 8

// Paso angular (360 grados / 8 pétalos = 45 grados o 0.785 radianes)
paso = 6.28 / cantidad_petalos

for (i = 1; i < cantidad_petalos; i = i + 2) {
    angulo = i * paso
    
    px = cx + distancia_petalo * cos(angulo)
    py = cy + distancia_petalo * sin(angulo)
    
    petalo = circulo(px, py, radio_petalo)
    fill(petalo, morado)
    stroke(petalo, negro)
}

for (i = 0; i < cantidad_petalos; i = i + 2) {
    angulo = i * paso
    
    px = cx + distancia_petalo * cos(angulo)
    py = cy + distancia_petalo * sin(angulo)
    
    petalo = circulo(px, py, radio_petalo)
    fill(petalo, morado)
    stroke(petalo, negro)
}

// --- CENTRO ---
// Se dibuja al final para tapar la unión de todos los pétalos
centro = circulo(cx, cy, radio_centro)
fill(centro, amarillo)
stroke(centro, negro)

end