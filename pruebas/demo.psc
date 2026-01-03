begin "demo.ps"
 	// Configuración
 	rojo = color(200, 0, 0)
 	c = circle(300, 400, 100)

 	// Dibujo
 	fill(c, rojo)

 	// Texto
 	fuente(HELVETICA, 20)
 	texto(250, 280, "Hola Mundo", rojo)
 end