begin "flor_completa"

// --- Configuración de Colores ---
verde = color(34, 139, 34)
rojo = color(220, 20, 60)
amarillo = color(255, 215, 0)
cielo = color(135, 206, 235)
negro = color(0, 0, 0)

// Centro de la flor
cx = 306
cy = 500

// --- 1. FONDO ---
fondo = circle(cx, cy, 1000)
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

    c = circle(cx, y, radio_tallo)
    fill(c, verde)
    
    // Avanzamos hacia arriba
    y = y + 10 
}

// --- 3. HOJAS (Círculos desplazados) ---
// Hoja izquierda
for (i = 0; i < 5; i = i + 1) {
    hx = cx - 10 - (i * 12)
    hy = 200 + (i * 8)
    // Nota: en el original era 20-i, aquí mantenemos la lógica
    radio_hoja = 20 - i
    hoja = circle(hx, hy, radio_hoja)
    fill(hoja, verde)
}

// Hoja derecha
for (j = 0; j < 5; j = j + 1) {
    hx = cx + 10 + (j * 12)
    hy = 250 + (j * 8)
    radio_hoja = 20 - j
    hoja = circle(hx, hy, radio_hoja)
    fill(hoja, verde)
}

// --- 4. LOS PÉTALOS (Coordenadas Polares) ---
radio_distancia = 70  // Qué tan lejos del centro están los pétalos
num_petalos = 12      
radio_petalo = 40     

// Paso en radianes (2 * PI / 12)
paso = 6.2832 / num_petalos 

for (k = 0; k < num_petalos; k = k + 1) {
    angulo = k * paso
    
    // Tu transpilador convierte 'angulo' (radianes) a grados internamente
    // así que cos(angulo) funciona correctamente.
    offset_x = radio_distancia * cos(angulo)
    offset_y = radio_distancia * sin(angulo)
    
    px = cx + offset_x
    py = cx + offset_y
    // correccion: usamos cy para la altura
    py = cy + offset_y
    
    petalo = circle(px, py, radio_petalo)
    fill(petalo, rojo)
}

// --- 5. EL CENTRO ---
centro = circle(cx, cy, 55)
fill(centro, amarillo)

// Firma
fuente(HELVETICA, 20)
texto(50, 50, "Flor hecha solo con Circulos", negro)

end