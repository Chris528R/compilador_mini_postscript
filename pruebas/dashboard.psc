begin "dashboard_ventas.ps"

// 1. Colores Corporativos
fondo = color(240, 240, 240)
azul_oscuro = color(0, 50, 100)
rojo_alerta = color(200, 50, 50)
verde_exito = color(50, 150, 50)
negro = color(0, 0, 0)

// 2. Fondo del reporte 
bg = rect(0, 0, 612, 792)
fill(bg, fondo)

// 3. Encabezado
fuente(HELVETICA, 30)
texto(50, 700, "REPORTE DE VENTAS 2025", azul_oscuro)

fuente(TIMES, 14)
texto(50, 670, "Generado por Transpilador Final", negro)

// 4. Ejes de la gráfica
// linea(x1, y1, x2, y2)
eje_y = line(100, 100, 100, 500)
eje_x = line(100, 100, 500, 100)

setlinewidth(3)
stroke(eje_y, negro)
stroke(eje_x, negro)

// 5. Datos simulados (Barras)
fuente(COURIER, 12)

// Barra 1: Enero (Baja venta)
h1 = 150
// rect(x, y, ancho, alto)
b1 = rect(120, 103, 50, h1)
fill(b1, rojo_alerta)

// Etiquetas Barra 1
pos_texto_y = 110 + h1
texto(125, 80, "ENE", negro)
texto(125, pos_texto_y, "150k", rojo_alerta)

// Barra 2: Febrero (Media)
h2 = 250
b2 = rect(220, 103, 50, h2)
fill(b2, azul_oscuro)

// Etiquetas Barra 2
pos_texto_y = 110 + h2
texto(225, 80, "FEB", negro)
texto(225, pos_texto_y, "250k", azul_oscuro)

// Barra 3: Marzo (Alta)
h3 = 380
b3 = rect(320, 103, 50, h3)
fill(b3, verde_exito)

// Etiquetas Barra 3
pos_texto_y = 110 + h3
texto(325, 80, "MAR", negro)
texto(325, pos_texto_y, "380k", verde_exito)

end