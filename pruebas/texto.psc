begin "texto_color.ps"

rojo = color(255, 0, 0)
azul = color(0, 0, 255)
titulo_font = 24

fuente(HELVETICA, titulo_font)
texto(50, 700, "Hola Mundo", rojo)

fuente(TIMES, 18)
texto(50, 650, "Esto es azul", azul)

end