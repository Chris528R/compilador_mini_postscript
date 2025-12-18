begin "demo_arte.ps"

negro = color(0, 0, 0)
blanco = color(255, 255, 255)
rojo = color(255, 0, 0)

// Fondo negro
bg = rectangulo(0, 0, 612, 792)
fill(bg, negro)

cx = 306
cy = 396
radio = 300 

// Bucle principal: Círculos concéntricos
for (i = 0; i < 20; i = i + 1) {
    
    // Alternar color basado en si 'i' es par o impar
    // (Simulamos modulo con if, ya que no implementamos %)
    // Usamos una variable auxiliar para calcular paridad
    
    c = circulo(cx, cy, radio)
    
    // Si i es menor que 10 pintamos blanco, sino rojo (ejemplo simple)
    // O mejor: Alternamos stroke y fill para efecto artistico
    
    if (radio > 150) {
        fill(c, blanco)
        c_inner = circulo(cx, cy, radio - 10)
        fill(c_inner, negro) // Efecto anillo
    } else {
        stroke(c, rojo)
    }
    
    radio = radio - 15
}

// Texto central
fuente(COURIER, 24)
texto(240, 390, "GENERATED", rojo)

end