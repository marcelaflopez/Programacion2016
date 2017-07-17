<b>Ejercicio 5:</b> Desarrollar los siguientes módulos:<br>
* a) Crear un módulo que determine la cantidad de divisores positivos de un número natural (sin contar los divisores triviales) ¿En qué tipo de problemas podría utilizar este módulo? Brinde un ejemplo.<br>
* b) Crear un módulo que dado un número natural NUM y una base B < 10 calcule el equivalente de NUM en base B.<br>
* c) Crear un módulo que determine si un número NUM de tipo natural es primo.
<br>

Realizar un programa utilizando los módulos anteriores en el que para dado un número entero calcule su equivalente a base 2 si la cantidad de divisores del número es primo y calcule su equivalente a base 9 si la cantidad de divisores no es primo.<br>

<b>Ejercicio 6:</b> Desarrollar los siguientes módulos:
* 1. Dados dos números naturales determine si éstos son amigos.<br>
Los números son amigos, si cada uno de ellos es igual a la suma de los divisores del otro (tener en cuenta que no se debe tomar al mismo número como divisor). Por ejemplo, 220 y 284 son amigos, ya que:<br>
Suma de divisores de 284: 1 + 2 + 4 + 71 + 142 = 220<br>
Suma de divisores de 220: 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284<br>
<b>Nota:</b> Si para la solución de este problema detecta alguna otra tarea que deba ser un módulo debe implementarse.<br>
* 2. Dado un número natural determine si es un número deficiente, abundante o perfecto.<br>
Un número natural N se dice que es deficiente si la suma de sus divisores (sin contarse a sí mismo) es menor a N. Si la suma de sus divisores es mayor a N se dice que el número es abundante y si es igual a N se dice que es perfecto.
Para una lista de N números naturales aleatorios en el rango [A, B] con A y B naturales, realizar un programa que muestre de esos números aleatorios los que poseen un número amigo en ese mismo rango. No considere a los números deficientes.
<br>

<b>Ejercicio 7:</b><br>
Para X e i dados, diseñar un módulo que calcule la siguiente sucesión:<br>
Si = 1 + X + X2/2! + X3/3! +...+ Xi/i!<br>
Realizar otro módulo en el que dado un valor para X y un error, como parámetros, (por ejemplo 0.001) devuelva el primer valor i que cumpla una aproximación de eX.<br>
Se cumple que lim S i= eX
(cuando i -->+∞)<br>
¿Reutilizó el primer módulo desarrollado?
<br>

<b>Ejercicio 8:</b> Crear un módulo que manipule dos números enteros suprimiendo la última cifra del primero y añadiéndola al final del segundo. Realizar un programa que utilice dicho módulo para invertir un número.<br>

<b>Ejercicio 9:</b> Crear dos módulos, el primero para que reciba un número real positivo y lo modifique expresando ese número en notación científica, es decir, determinando el valor de la mantisa normalizada y el valor del exponente. El segundo módulo para que, dado una mantisa y un exponente, determine el número real, en notación de punto fijo.<br>
Realizar un programa tal que dada una lista de N números reales positivos mostrar el menor y el mayor número analizando el valor del exponente y en caso de igualdad comparar las mantisas normalizadas. Además calcular y mostrar el promedio de esos dos valores sin normalizar.
<br>

<b>Ejercicio 10:</b> Piedra, papel o tijeras: Este es un juego muy antiguo en el que intervienen dos personas.<br>
Cada jugador hace su elección entre las tres alternativas existentes (piedra, papel o tijeras) y el ganador se determina atendiendo a las siguientes reglas:<br>
* I. La piedra gana a las tijeras.
* II. Las tijeras ganan al papel
* III. El papel gana a la piedra.
* IV. Si las dos elecciones son iguales se produce un empate.<br>
Escribe un programa que permita a la máquina jugar contra un humano todas las veces que el quiera. Máquina y humano harán su elección y la máquina será la que decida quién gana.
<br>

<b>Ejercicio 11:</b> Desarrollar los siguientes módulos:<br>
* a) Crear un módulo que genere una fecha al azar (considerar que los años no son bisiesto).
* b) Crear un módulo que calcule la cantidad de días que existe entre dos fechas.
* d) Crear un módulo que permita el ingreso de una fecha por el usuario.<br>
Realizar un programa utilizando módulos anteriores en el que dadas N fechas, se pide generar una fecha al azar y luego indicar la cantidad de días promedio entre cada una las fechas ingresadas y la fecha generada al azar.<br>
<b>Nota:</b> El formato para trabajar con las fechas debe ser día, mes y año en variables separadas.
