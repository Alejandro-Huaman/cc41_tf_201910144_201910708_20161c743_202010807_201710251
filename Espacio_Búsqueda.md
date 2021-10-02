# Espacio de búsquedas

En este trabajo se tendrá que solucionar el problema VRP (Vehicle Routing Problem) y para poder solucionarlo de manera efectiva se tendrá que definir los espacios de búsqueda partiendo de un punto de distribución cualquiera.

  

Para empezar, se plantea contar entre 50 y 100 puntos de distribución, 2500 y 500 puntos de entrega y contar con una cantidad ilimitada de vehículos, considerando el costo por tiempo y distancia de cada uno de ellos.

  

Se considerará que el punto de distribución será el punto de partida y  el punto de llegada será el ultimo punto de entrega final del recorrido.Para las transiciones,se usarán los vehículos que partirán desde el punto desde el inicio y se irán trasladando entre los puntos de entrega hasta llegar al punto de destino del mismo modo podrán pasar solo una vez por un mismo punto.

  

Para una solución más efectiva planteamos usar los siguientes algoritmos:

  

 - BFS

  

	Es un algoritmo por amplitud y nos permite realizar un recorrido según cada nivel del 					grafo, logrando recorrer primero 1 nivel para luego ir al otro. Este algoritmo nos ayudará a resolver el problema debido a que es completo y eficiente al momento de recorrer cada nodo para llegar a un estado final.
	![enter image description here](https://www.encora.com/hs-fs/hubfs/Avantacia/FREESTANDING/Screen%20Shot%202020-05-15%20at%206.55.32%20PM.png?width=900&name=Screen%20Shot%202020-05-15%20at%206.55.32%20PM.png)

 
 - Dijkstra

	Este algoritmo nos permite calcular el recorrido de menor distancia. Calcula el recorrido de las aristas de cada nodo según su peso de este, teniendo en cuenta el tiempo y la distancia hacia el estado final logrando mostrar el recorrido más eficiente y con menor distancia. Este algoritmo nos ayudará a resolver el problema debido a que es un algoritmo enfocado en la búsqueda del recorrido más eficiente, además que tiene en cuenta el tiempo y la distancia que necesitaremos para la solución exitosa de dicho problema.
	
  ![enter image description here](https://www.wextensible.com/temas/voraces/ejemplos/dijkstra.png)
