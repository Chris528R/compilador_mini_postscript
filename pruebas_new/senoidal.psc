begin "onda_senoidal.ps"

// Configuración de la gráfica
eje_y = 400
inicio_x = 0
fin_x = 600
paso = 5
amplitud = 100
frecuencia = 0.02

setlinewidth(2)
rojo = color(255, 0, 0)
azul = color(0, 0, 255)

// Dibujar eje central
linea_eje = line(0, eje_y, 600, eje_y)
stroke(linea_eje, azul)

// Variable para recorrer X
x = inicio_x

// Usaremos un WHILE para recorrer la pantalla horizontalmente
while (x < fin_x) {
    
    // CALCULO MATEMÁTICO: y = centro + amplitud * sin(x * frecuencia)
    // Nota: Tu gramática convierte radianes a grados automáticamente en la línea 128
    angulo = x * frecuencia
    seno_val = sin(angulo) 
    
    // Calculamos la altura Y
    y = eje_y + (seno_val * amplitud)

    // Dibujamos un pequeño punto (círculo) en esa coordenada
    punto = circle(x, y, 2)
    fill(punto, rojo)

    // Avanzamos X
    x = x + paso
}

fuente(HELVETICA, 20)
texto(50, 700, "Prueba de Math: Funcion Seno", azul)

end