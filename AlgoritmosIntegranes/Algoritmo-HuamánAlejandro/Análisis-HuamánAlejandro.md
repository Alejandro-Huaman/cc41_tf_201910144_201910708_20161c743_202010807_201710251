#  Análisis Preliminar de posible Algoritmo
Para el uso del posible algoritmo, en este caso el algoritmo de Dijkstra, necesitamos realizar unos cuantos pasos. En primer lugar, a las aristas que serían el recorrido de nuestro punto de distribución al punto de entrega le tenemos que dar un peso o coste. Luego, aplicando el algoritmo iremos sumando todos los posibles recorridos desde el nodo de distribución hacia el nodo de entrega según su coste que le hemos asignado obteniendo una suma total del coste de cada recorrido. Finalmente, comparamos cada suma total de los recorridos eligiendo el menor y obteniendo el recorrido mas eficiente y con menor coste.

![](https://lh5.googleusercontent.com/NTzLVTq5_c84YY1-86G0G237Ljn7s131t-jg19FLyZK_2-ZwMxyU0rsB9NdDKOCFw_ASVDtVj-hmgL6QgPNv5mJHKHmFsn8g6QRVBblD-_76nhJKOJ4bA5btkaUiNK_kAg-NWbqP=s0)

  

En este caso para colocar el coste en las aristas se utilizará la distancia según las coordenadas de nuestro punto de distribución a otro punto azul y así hasta llegar al punto de entrega.

  

![](https://lh6.googleusercontent.com/djxLZdh-c2k_JAESlosj9lujN8ckoZx9_6zC8oGZVcBZAF7eWzK6LOfn2JCId4D-dXRDHGbBE6KsWSmnxNGuGYwlq4nWglOYqS4GOAE1qK_H1Hd0Wo0a21vcDh4GpcV6JMgY6g6Z=s0)

  

Luego, con una función repetitiva “for” iremos recorriendo los nodos del recorrido del grafo, teniendo en cuenta que si llegamos a un punto azul que no es el punto de entrega lo contamos como un nodo propio del recorrido. Gracias a eso logramos que nuestro número de coste permanezca en una arista y así ir sumando los costes mediante una variable contador que almacenará la suma de los costes, así hasta llegar al punto de entrega.

![](https://lh5.googleusercontent.com/xTDcQVwGQJb6BkZHRmIZZ8lmQNRZIeEKn61slEDqYY6CbU2uDPS1nzWmYju-fAPu2gGw2xW1BdlmnkvptSSJGX5pBMfKN8u3d3MrcDglpUmS5-ZVqtBkhLuHEH5G9WOQf-0l4dSo=s0)

  
  

Finalmente, la suma total de los costes de un recorrido lo almacenaremos dentro de una lista y recursivamente llamaremos a la misma función para hacer el mismo procedimiento para cada recorrido posible hacia el punto de entrega. Comparamos la suma total de costes dentro de la lista y sacamos el coste menor, en donde retornaremos el recorrido de ese coste menor mediante una lista.

  

![](https://lh6.googleusercontent.com/wSztMvaJ8MKjyC5Dhqg9wiyr97iFsEPNbm3SZFuFvy0WT5qvc5LSdMzM2fTsBpZ8jKOP1TpA73EeaSiDjL_N7LKaKCxcZCl_BP92CFI8ldHo_98v2zn3czcpAP5Avd3i7N6xJbhW=s0)

  

Con este planteamiento del algoritmo podemos obtener el recorrido mas eficiente por el cual el problema VRP (Vehicle Routing Problem) será solucionado tomando en cuenta el tiempo y la distancia de recorrido. Explicado con anterioridad, este algoritmo nos ayuda a identificar el recorrido mas corto según su coste o peso de las aristas y tiene un Big O de O(n^2) debido a que realiza las operaciones de suma y comparación.
