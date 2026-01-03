begin "demo_arte.ps"

negro = color(0, 0, 0)
blanco = color(255, 255, 255)
rojo = color(255, 0, 0)

// Fondo negro
bg = rect(0, 0, 612, 792)
fill(bg, negro)

cx = 306
cy = 396
radio = 300 

// Bucle principal: Círculos concéntricos
for (i = 0; i < 20; i = i + 1) {
    
    c = circle(cx, cy, radio)
  
    // Lógica artística:
    // Los círculos grandes son anillos blancos
    // Los círculos pequeños (centro) son bordes rojos
    if (radio > 150) {
        // Dibujamos círculo blanco
        fill(c, blanco)
        
        // Dibujamos círculo negro un poco más pequeño encima
        // Esto crea el efecto de "anillo"
        radio_interno = radio - 10
        c_inner = circle(cx, cy, radio_interno)
        fill(c_inner, negro) 
    } else {
        stroke(c, rojo)
    }
   
    radio = radio - 15
}

// Texto central
fuente(COURIER, 24)
texto(240, 390, "GENERATED", rojo)

end