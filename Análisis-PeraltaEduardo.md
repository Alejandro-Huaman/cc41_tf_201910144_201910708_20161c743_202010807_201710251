# Análisis Preliminar de posible Algoritmo

El algoritmo en el que se basara  la resolución propuesta para el problema será el algoritmo BFS.
Para este problema tenemos un conjunto de puntos de entrega (puntos azules) y un conjunto de almacenes (puntos rojos), como se ve en el gráfico.
![enter image description here](https://i.ibb.co/ydDfzKQ/algo1.png)

 - Puntos de almacén (1;4) (6;6)
 - Puntos de entrega (2;5) (2;2) (6;1) (1;3) (8;3) (1;1) (3;0) (6;3)

Para lograr que los camiones que parten de los almacenes logren recorrer la mayor cantidad de puntos de entrega con el menor costo posible, se les indicara que deben dirigirse primero al punto de entrega mas cercano en el eje x, luego de esta acción deberán dirigirse al punto de entrega mas cercano que quede en el mismo punto x, de esta forma, lograremos un recorrido por niveles, lo cual hará que el recorrido de los camiones sea mas efectivo, debido a que estos no podrán volver al mismo punto de entrega 2 veces.

Luego de aplicar lo mencionado anteriormente, esperamos un resultado como el mostrado a continuación:
![enter image description here](https://i.ibb.co/B2nRJ3m/algo2.png)

Como vemos se logro recorrer todos los puntos de entrega partiendo de 2 almacenes, sin repetir el camino.
Este algoritmo podría saltarse algunos caminos mas cortos, pero nos asegura el recorrido total de los puntos de entrega, así como el no pasar de nuevo por un mismo punto, aumentando el costo. Ya que este recorrido es por niveles, el bigO dependerá de estos, siendo el mismo O(n), siendo n el numero de niveles que recorrera.
