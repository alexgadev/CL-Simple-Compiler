# Instrucciones de compilación:
1) make o make all -> compila todo el proyecto generando archivos intermedios guardados en ./gen/ y el ejecutable como ./calculadora
2) make clean -> elimina los archivos intermedios y el ejecutable ./calculadora
3) make fullclean -> lo mismo que make clean además de eliminar los archivos de log guardados en ./log/


# Instrucciones de ejecución: 
Para cualquiera de las dos opciones de ejecución, compilar primero con una de las instrucciones de arriba.
1) Con archivo de entrada -> 1. ejecutar "./calculadora" seguido del nombre del archivo de entrada.
2) Por línea de comando -> 1. ejecutar "./calculadora" 2. escribir sentencia a sentencia separada por saltos de línea.


# Archivos de ejemplo
Hay una carpeta en el directorio del proyecto llamada tests en la que se encontraran todos los archivos de test que se le pueden pasar a la calculadora.
Los archivos de test por lo general tendran las sentencias a probar junto a un comentario del resultado esperado.
Se pueden añadir los archivos que sean necesarios.


# Descripción de la práctica
En general es una práctica bastante completa, me habría gustado poder hacer mejor limpieza del código pero no tengo el suficiente entendimiento de C como para hacer un mejor trabajo.
Es probable que los métodos auxiliares sean implementaciones pobres o que haya maneras mucho mejores de hacer lo que yo hago, pero una vez más en C es lo mejor que puedo hacer.

Sobre las opciones, únicamente he añadido la constante PI, aunque me habría gustado añadir más constantes, funciones trigonométricas y otros tipos como los complejos o cuaterniones.
También se me había ocurrido guardar en una pila o cola, cada token recibido para más tarde reconstruir la sentencia recibida y poder escribirla en los archivos de log para tener más información pero he pensado que sería más trabajo del que ahora puedo ocuparme.

En general la mayoria de reglas del ./source/parse.y hacen en gran parte exactamente el mismo guión de instrucciones y se repite constantemene el mismo patrón de: comprobación de tipos númericos, identificar el tipo de operación númerico según su tipo y ejecutar la operación de la regla en base al tipo de operación, si la comprobación de tipos númericos falla, comprobar si eran strings o booleanos y lanzar error semantico. Seguro que hay una manera de evitar esta repetición de código en C pero no se me ocurre nada mejor.

Fuera de todo esto, no he encontrado errores en el funcionamiento de la calculadora y se ocupa correctamente de toda excepción que pueda ocurrir.
