begin "curva_hilbert.ps"

// --- Configuración Inicial ---
negro = color(0, 0, 0)
rojo = color(255, 0, 0)
setlinewidth(1.5)

// --- ESTADO GLOBAL (La Tortuga) ---
x = 50      // Posición X actual
y = 50      // Posición Y actual
dir = 0     // 0=Derecha, 1=Arriba, 2=Izquierda, 3=Abajo

// --- Procedimiento AVANZAR ---
// Recibe: $1 = distancia
// Calcula la nueva posición según 'dir' y dibuja la linea
proc avanzar() {
    // Variables temporales para el destino
    nx = x
    ny = y

    // Calculamos destino según dirección
    if (dir == 0) { 
        nx = x + $1 
    }
    if (dir == 1) {
        ny = y + $1 
    }
    if (dir == 2) { 
        nx = x - $1 
    }
    if (dir == 3) { 
        ny = y - $1 
    }

    // AQUÍ USAMOS TU COMANDO LINEA
    l = linea(x, y, nx, ny)
    stroke(l, negro)

    // Actualizamos la posición global
    x = nx
    y = ny
}

// --- Procedimiento GIRAR ---
// Recibe: $1 = +1 (Izquierda) o -1 (Derecha)
proc girar() {
    dir = dir + $1
    
    // Corregir si nos pasamos de rango (ciclo 0-3)
    if (dir > 3) { 
        dir = 0 
    }
    if (dir < 0) {
        dir = 3
    }
}

// --- Algoritmo de Hilbert (Sistema-L) ---
// Requiere dos funciones recursivas A y B
// Regla A: + B F - A F A - F B +
// Regla B: - A F + B F B + F A -

// Función Hilbert B
// $1 = nivel, $2 = longitud_paso
proc hilbertB() {
    if ($1 > 0) {
        girar(-1)            // -
        hilbertA($1 - 1, $2) // A
        avanzar($2)          // F
        girar(1)             // +
        hilbertB($1 - 1, $2) // B
        avanzar($2)          // F
        hilbertB($1 - 1, $2) // B
        girar(1)             // +
        avanzar($2)          // F
        hilbertA($1 - 1, $2) // A
        girar(-1)            // -
    }
}

// Función Hilbert A
// $1 = nivel, $2 = longitud_paso
proc hilbertA() {
    if ($1 > 0) {
        girar(1)             // +
        hilbertB($1 - 1, $2) // B
        avanzar($2)          // F
        girar(-1)            // -
        hilbertA($1 - 1, $2) // A
        avanzar($2)          // F
        hilbertA($1 - 1, $2) // A
        girar(-1)            // -
        avanzar($2)          // F
        hilbertB($1 - 1, $2) // B
        girar(1)             // +
    }
}


// --- PROGRAMA PRINCIPAL ---

// Título
fuente(HELVETICA, 20)
texto(50, 750, "Curva de Hilbert (Nivel 5)", rojo)

// Posición inicial
x = 50
y = 200
dir = 0

// Ejecutar Hilbert Nivel 5, con pasos de 10 unidades
hilbertA(5, 12)

end