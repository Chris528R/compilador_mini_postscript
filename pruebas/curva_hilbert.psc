begin "curva_hilbert.ps"

// --- Configuración ---
negro = color(0, 0, 0)
rojo = color(255, 0, 0)
setlinewidth(1.5)

// Estado Global
x = 50
y = 50
dir = 0     // 0=Derecha, 1=Arriba, 2=Izquierda, 3=Abajo

// Procedimiento para avanzar y dibujar
proc avanzar(dist) {
    nx = x
    ny = y

    if (dir == 0) { nx = x + dist }
    if (dir == 1) { ny = y + dist }
    if (dir == 2) { nx = x - dist }
    if (dir == 3) { ny = y - dist }

    l = line(x, y, nx, ny)
    stroke(l, negro)

    x = nx
    y = ny
}

// Procedimiento para girar
proc girar(sentido) {
    dir = dir + sentido
    if (dir > 3) { dir = 0 }
    if (dir < 0) { dir = 3 }
}

// Hilbert B
proc hilbertB(nivel, paso) {
    if (nivel > 0) {
        girar(-1)
        prev = nivel - 1
        hilbertA(prev, paso)
        avanzar(paso)
        girar(1)
        hilbertB(prev, paso)
        avanzar(paso)
        hilbertB(prev, paso)
        girar(1)
        avanzar(paso)
        hilbertA(prev, paso)
        girar(-1)
    }
}

// Hilbert A
proc hilbertA(nivel, paso) {
    if (nivel > 0) {
        girar(1)
        prev = nivel - 1
        hilbertB(prev, paso)
        avanzar(paso)
        girar(-1)
        hilbertA(prev, paso)
        avanzar(paso)
        hilbertA(prev, paso)
        girar(-1)
        avanzar(paso)
        hilbertB(prev, paso)
        girar(1)
    }
}

// --- MAIN ---
fuente(HELVETICA, 20)
texto(50, 750, "Curva de Hilbert (Nivel 5)", rojo)

x = 50
y = 200
dir = 0

// Iniciar recursividad
hilbertA(5, 12)

end