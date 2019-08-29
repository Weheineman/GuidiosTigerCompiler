# Primer Laboratorio de Compiladores

Bienvenidos!!

En la primer clase vamos a repasar un poco todo el proyecto.

Para agarrarle la mano a Tiger deberán completar unos pequeños ejercicios, y
para correrlos se les proveerá un compilador andando de Tiger para arquitectura
x86_64.

Técnicamente pueden utilizar los esqueletos que se les proveen en
[SML](https://git.dcc.fceia.unr.edu.ar/Compiladores/TigerMl) y en [Haskell]
(https://git.dcc.fceia.unr.edu.ar/Compiladores/TigerHaskell) pero no serán de
mucha utilidad ya que lo único que hacen es hacer un chequeo de sintaxis.

Para utilizar el compilador que se les provee, el binario *tiger*, deberán tener
instalado el compilador [MosML](http://mosml.org/) y necesitaran el precompilado
*runtime.o*. Se provee además el código fuente del runtime (*runtime.c*) por si acaso.

Una vez que puede correr sin problemas el ejecutable *tiger* tiene dos opciones:
+ Modo interprete
```
$./tiger [Enter]
let var a := 1 in print("Hola") ; a end [CTL + d]
```
+ Modo compilador indicando una código fuente en Tiger.
```
$./tiger ~/Compiladores/Ejercicio0/ejemplo.tig
```

Saludos!
