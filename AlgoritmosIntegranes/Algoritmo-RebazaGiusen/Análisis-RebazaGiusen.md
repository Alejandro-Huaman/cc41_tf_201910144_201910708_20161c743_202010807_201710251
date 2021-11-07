# Análisis Preliminar de posible Algoritmo
Se presenta una variación al problema de enrutamiento de vehículos. Para esta situación tenemos un conjunto de almacenes y un conjunto de puntos de entrega. En base a esto se describirá un posible algoritmo para resolver el problema.

En primer lugar, se inicia con el punto de inicio que en este caso es el almacén. Luego, se analizará cuáles son los puntos de entrega que debe recorrer. Por consiguiente, se hará una lista de esos puntos y se ordenara según la cercanía que se tiene con el almacén, para determinar la cercanía se empleara el eje X. Por ejemplo, los más cercanos serán los que tengan el eje X igual que el almacén, los siguientes serán los tengan el eje Y sumado más un valor dependiendo de la situación. Tras tener la lista se empezara por los más cercanos en el caso que uno o más puntos tengan la misma cercanía se tomara el punto con mayor cercanía en relación a los ejes Y.

![enter image description here](https://i.postimg.cc/HkLq59h0/Imagen1.png)

Punto de almacén:(1,4)

Punto de entrega: (1,2),(2,2,),(2,5),(2,6),(4,3),(4,6)

X=1

(1,2)

X=2

(2,2,), (2,5), (2,6)

X=4

(4,3), (4,6)

Recorrido :

![enter image description here](https://i.postimg.cc/ZKb2tL4k/Imagen2.png)

 Una vez terminado el proceso se obtiene en una lista el recorrido que se empleó. A pesar de esto, existe la posibilidad de que se ignoren algunos caminos más eficientes. Entonces, esta idea de solución puede ser mejorada o cambiada. Para el desarrollo de la solución, existió la inspiración del algoritmo BFS ,debido a que igual  a lo explicado anteriormente se recorre dependiendo el nivel del mismo modo su bigO podría ser O(n) que en esta caso n es el numero de puntos a recorrer.
