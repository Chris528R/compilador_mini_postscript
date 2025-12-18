begin "demo_dashboard.ps"

// 1. Colores Corporativos
fondo = color(240, 240, 240)
azul_oscuro = color(0, 50, 100)
rojo_alerta = color(200, 50, 50)
verde_exito = color(50, 150, 50)
negro = color(0, 0, 0)

// 2. Fondo del reporte 
bg = rectangulo(0, 0, 612, 792)
fill(bg, fondo)

// 3. Encabezado
fuente(HELVETICA, 30)
texto(50, 700, "REPORTE DE VENTAS 2025", azul_oscuro)
fuente(TIMES, 14)
texto(50, 670, "Generado automaticamente por TuCompilador v1.0", negro)

// 4. Ejes de la gráfica
eje_y = linea(100, 100, 100, 500)
eje_x = linea(100, 100, 500, 100)
setlinewidth(3)
stroke(eje_y, negro)
stroke(eje_x, negro)

// 5. Datos simulados (Barras)
// Barra 1: Enero (Baja venta)
h1 = 150
b1 = rectangulo(120, 103, 50, h1)
fill(b1, rojo_alerta)
fuente(COURIER, 12)
texto(125, 80, "ENE", negro)
texto(125, 110 + h1, "150k", rojo_alerta)

// Barra 2: Febrero (Media)
h2 = 250
b2 = rectangulo(220, 103, 50, h2)
fill(b2, azul_oscuro)
texto(225, 80, "FEB", negro)
texto(225, 110 + h2, "250k", azul_oscuro)

// Barra 3: Marzo (Alta)
h3 = 380
b3 = rectangulo(320, 103, 50, h3)
fill(b3, verde_exito)
texto(325, 80, "MAR", negro)
texto(325, 110 + h3, "380k", verde_exito)

end