begin "flor.ps"

// --- Configuración de Colores ---
verde = color(34, 139, 34)
rojo = color(220, 20, 60)
amarillo = color(255, 215, 0)
cielo = color(135, 206, 235)

// Centro de la flor
cx = 306
cy = 500

// --- 1. FONDO (Opcional, hecho con un círculo gigante) ---
fondo = circulo(cx, cy, 1000)
fill(fondo, cielo)

// --- 2. EL TALLO ---
// Usamos un WHILE para apilar círculos verdes verticalmente
y = 50
while (y < cy) {
    // El radio disminuye ligeramente mientras sube para afinar el tallo
    radio_tallo = 15 - (y / 60) 
    if (radio_tallo < 6) { 
        radio_tallo = 6 
    }
        

    c = circulo(cx, y, radio_tallo)
    fill(c, verde)
    
    // Avanzamos hacia arriba
    y = y + 10 
}

// --- 3. HOJAS (Hechas con círculos desplazados) ---
// Hoja izquierda
for (i = 0; i < 5; i = i + 1) {
    // Desplazamos X a la izquierda y Y hacia arriba
    hx = cx - 10 - (i * 12)
    hy = 200 + (i * 8)
    hoja = circulo(hx, hy, 20 - i) // Círculos decrecientes
    fill(hoja, verde)
}

// Hoja derecha
for (j = 0; j < 5; j = j + 1) {
    hx = cx + 10 + (j * 12)
    hy = 250 + (j * 8)
    hoja = circulo(hx, hy, 20 - j)
    fill(hoja, verde)
}

// --- 4. LOS PÉTALOS (Coordenadas Polares) ---
// Usamos FOR para rotar alrededor del centro
radio_distancia = 70  // Qué tan lejos del centro están los pétalos
num_petalos = 12      // Cantidad de pétalos
radio_petalo = 40     // Tamaño de cada pétalo

// 2 * PI = 6.28318...
paso = 6.2832 / num_petalos 

for (k = 0; k < num_petalos; k = k + 1) {
    angulo = k * paso
    
    // Matemáticas para encontrar la posición (x,y) en el borde del círculo imaginario
    px = cx + radio_distancia * cos(angulo)
    py = cy + radio_distancia * sin(angulo)
    
    petalo = circulo(px, py, radio_petalo)
    fill(petalo, rojo)
}

// --- 5. EL CENTRO ---
centro = circulo(cx, cy, 55)
fill(centro, amarillo)

// Firma
fuente(HELVETICA, 20)
negro = color(0, 0, 0)
texto(50, 50, "Flor hecha solo con Circulos", negro)

end