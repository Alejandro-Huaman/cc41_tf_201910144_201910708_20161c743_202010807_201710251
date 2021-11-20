# CC41 - TRABAJO FINAL 2021 2
Trabajo final para el curso de Complejidad Algorítmica.

## Integrantes
- Alejandro Sebastián Huamán Ruiz
- Giusen Eduardo Rebaza Maticorena
- Jose Eduardo Peralta Saravia
- Franco Galindo Alvarez
- Ernesto Valdivia

## Introducción
El problema de enrutamiento de vehículos (VRP) es un problema de optimización combinatoria qué intenta responder a la pregunta "¿Cuál es el conjunto óptimo de rutas para una flota de vehículos que debe satisfacer las demandas de un conjunto dado de clientes?". La primera definición de este problema la realizaron George Dantzig y John Ramser en 1959, aplicando en la optimización de los costos en las rutas para la entrega de gasolina. Por lo que, a continuación, se presentará nuestra solución para este problema utilizando los algoritmos realizados en el curso.

## Objetivos

- Desarrollar la competencia general de razonamiento cuantitativo y la competencia

- Desarrollar un algoritmo que permita resolver completa o parcialmente el problema de enrutamiento de vehículos o VRP 

- Determinar la importancia de la aplicación de algoritmos eficientes a la hora de resolver un problema

- Analizar la eficiencia y complejidad de los algoritmos planteados

- Buscar un balance entre el tiempo y costo de entrega

## Marco Teorico

### Algoritmo Dijkstra
El algoritmo Dijkstra igualmente llamado algoritmo de caminos mínimos, es un algoritmo para la búsqueda del camino mínimo desde un nodo dado hacia el resto de nodos del grafo.
> Utiliza los pesos de cada arista en el grafo para poder encontrar su objetivo y fue diseñado por Edsger Dijkstra quien lo descubrió en 1959. Su complejidad del algoritmo Dijkstra es de O(n^2).

### Algoritmo Bellman Ford
Este algoritmo determina la ruta más corta desde un nodo origen hacia los demás nodos para esto se necesita que las aristas tengan un peso. Adicionalmente,este algoritmo posee una peculiaridad que es trabajar con pesos negativos, ya que este tiene la capacidad de detectar ciclos negativos. 
> Este algoritmo trabaja realizando relajaciones a todas las aristas haciéndolo V-1 veces siendo V el número de aristas.
> En el caso de la detección de ciclos negativos, se realiza la relajación una vez más y su complejidad es O(VE).

### Algoritmo Prim
El algoritmo Prim es un algoritmo de árbol de expansión mínima (MST), es uno de los mas sencillos de implementar y uno de los mejores de utilizar para grafos densos. Tiene un algoritmo idéntico al dijkstra, lo unico que varia sería su método de relajación que cambia a que el peso de la arista tiene que ser menor al coste del nodo a visitar (w < cost(v)) si esto se cumple entonces el nuevo coste del nodo a visitar sería el w y asi encontramos los caminos más eficientes de cada nodo. El algoritmo mientras se va ejecutando irá formando un árbol de expansión que irá creciendo de arista en arista encontrando su camino eficiente obteniendo al final el árbol de expansión mínima del grafo. 
> El algoritmo prim posee una complejidad de O(n^2) en donde es posible realizarlo más eficiente llegando a tener una complejidad de O(nlogn).

### Algoritmo Kruskal
Este Algoritmo emplea los algoritmos union y find que son parte de la estructura de datos que modela una colección de conjuntos disjuntos. El algoritmo Find consiste en detectar si dos elementos están en el mismo conjunto, en cambio el algoritmo Union consiste en crear un conjunto basado en dos elementos.
> Este algoritmo consiste en ordenar a las aristas del grafo según el peso de mayor a mayor. Entonces, si los vértices que contienen una arista que no está en el mismo componente y su complejidad es O(E +log V)

### Algoritmo DLS
El algoritmo trata acerca de la búsqueda en profundidad limitada que consiste en explorar vértices en un grafo. Este algoritmo funciona de la misma manera que la búsqueda en profundidad simple; pero en este caso se evita inconvenientes con respecto a la completitud, debido a que impone una limitación, por lo cual no hará caminos de profundidad infinita ni se atascara en ciclos.
> Su complejidad es O(V+E) 

### Algoritmo BFS
Este algoritmo examina todos los nodos de un árbol sistemáticamente para buscar el camino más corto partiendo de un punto específico.
> Su complejidad es O(V+E) BFS recorre una componente conexa de un grafo y define un árbol de expansión.

## Experimentación

Primero necesitamos obtener la lista de adjacencia junto al CSV de los puntos de entrega y almacenes. Por lo que se realizó una función `readAdjl` que leyera la lista de adyacencia. Además de `readCoords` que sirve para leer las coordenadas y devolverlas como un arreglo.

```python 
urlAdjList = 'https://raw.githubusercontent.com/Alejandro-Huaman/cc41_tf_201910144_201910708_20161c743_202010807_201710251/main/Lista%20de%20Adyacencia/adjList.in'
urlAlmacen = 'https://raw.githubusercontent.com/Alejandro-Huaman/cc41_tf_201910144_201910708_20161c743_202010807_201710251/main/almacenes.csv'
urlEntrega = 'https://raw.githubusercontent.com/Alejandro-Huaman/cc41_tf_201910144_201910708_20161c743_202010807_201710251/main/puntos_entrega.csv'

G = readAdjl(urlAdjList)
P_Almacen = readCoords(urlAlmacen, 1000)
P_Entrega = readCoords(urlEntrega, 1000)
```

Después de ello se realizó una función paa poder encontrar los puntos de almacen más cercanos a un punto de entrega.
```python
  x_e, y_e = indexToCoord(p_e, 1000)
  closest_p_a = P_Almacen[0]
  for p_a in P_Almacen:
    x_a, y_a = indexToCoord(p_a, 1000)
    x_closest, y_closest = indexToCoord(closest_p_a, 1000)
    if getDistance(x_a,y_a,x_e,y_e) < getDistance(x_closest,y_closest,x_e,y_e):
      closest_p_a = p_a
  return closest_p_a
```

Para apartir de ello hacer un diccionario que los almacene, y de esta manera poder trabajar fácilmente, cada algoritmo por región.
```python
dict_p_almacen = {}

for p_e in P_Entrega:
    closest_p_a = closest_p_a_to_p_e(p_e)
    if not closest_p_a in dict_p_almacen:
        dict_p_almacen[closest_p_a] = [p_e]
    else:
        dict_p_almacen[closest_p_a].append(p_e)
```

### Solución Grupal: Aplicando el algoritmo Dijkstra

Para la solución grupal, utilizamos el algoritmo Dijkstra. Además este, junto a los futuros algoritmos que se mostratán, fueron adaptados para poder usarse con diccionarios, y de esta manera habilitar y aumentar la velocidad de búsqueda al trabajar en regiones. 
```python 
def dijkstraDict(G, s):
  visited = {}
  path = {}
  cost = {}
  for key in G.keys():
    visited[key] = False
    path[key] = None
    cost[key] = math.inf

  cost[s] = 0
  queue = [(s, 0)]
  while queue:
    u, g_u = hq.heappop(queue)
    if not visited[u]:
      visited[u] = True        
      for v in G[u]:
        f = g_u + 1
        if f < cost[v]:
          cost[v] = f
          path[v] = u
          hq.heappush(queue, (v, f))
  return path
```

##### Resultados
Estos fueron los resultados obtenidos durante la experimentación:

 - [x] El recorrido más cercano para 75 almacenes.
 ![Imagen de los primeros 19 almacenes](https://cdn.discordapp.com/attachments/889235275732111397/911747673529409536/unknown.png)
Se realizó en un tiempo promedio de 4300 ms.

### Solución 1: Aplicando el algoritmo de BellmanFord

Para la primera solución, se empleó el algoritmo BellmanFord, adaptado para el uso de diccionarios.
```python 
def bellmanFordDict(G, p_a):
  n = len(G)
  cost = {}
  path = {}

  for key in G.keys():
    path[key] = None
    cost[key] = math.inf

  cost[p_a] = 0

  for _ in range(n-1):
    for u in G.keys():
      for v in G[u]:
        if cost[u] + 1 < cost[v]:
          cost[v] = cost[u] + 1
          path[v] = u

  # check negative cycle
  for u in G.keys():
    for v in G[u]:
      if cost[u] + 1 < cost[v]:
        return None # negative cycle exists
        
  return path
```

##### Resultados
Estos fueron los resultados obtenidos durante la experimentación:

 - [] El recorrido más cercano para los almacenes 1 al 15.
 ![Imagen de los primeros 19 almacenes](https://cdn.discordapp.com/attachments/889235275732111397/911749508113776671/unknown.png)
No se pudo concluir la búsqueda de la cantidad total de almacenes. Debido a que no es posible realizarlo en un tiempo razonable. Un almacen se realizó en un tiempo promedio de 90400 ms.

### Solución 2: Aplicando el algoritmo de Prim

Para la segunda solución, se empleó el algoritmo Prim, adaptado para el uso de diccionarios.
```python 
def primDict(G,p_a):
  visited = {}
  path = {}
  cost = {}
  for key in G.keys():
    visited[key] = False
    path[key] = None
    cost[key] = math.inf
  cost[p_a] = 0
  q = [(0, p_a)]
  while q:
    _, u = hq.heappop(q)
    if not visited[u]:
      visited[u] = True
      for v in G[u]:
        if not visited[v] and 1 < cost[v]:
          cost[v] = 1
          path[v] = u
          hq.heappush(q, (1, v))

  return path
```

##### Resultados
Estos fueron los resultados obtenidos durante la experimentación:

 - [x] El recorrido más cercano para los almacenes 16 al 30.
 ![Imagen de los primeros 2 almacenes](https://media.discordapp.net/attachments/889235275732111397/911751076712173609/unknown.png?width=1025&height=375)
Se realizó en un tiempo promedio de 1300 ms.

### Solución 3: Aplicando el algoritmo de Kruskal

Para la segunda solución, se empleó el algoritmo Kruskal, adaptado para el uso de diccionarios.
```python 
class DisjointSet:
  S = {}
  def __init__(self,G):
    for key in G.keys(): 
      self.S[key] = -1

  def find(self, x):
    if self.S[x] < 0:
      return x
    p = self.find(self.S[x])
    self.S[x] = p
    return p

  def union(self, x, y):
    Xr = self.find(x)
    Yr = self.find(y)
    if Xr != Yr:
      if self.S[Xr] < self.S[Yr]:
        self.S[Xr] += self.S[Yr]
        self.S[Yr] = Xr
      else:
        self.S[Yr] += self.S[Xr]
        self.S[Xr] = Yr

  def isSameSet(self, x, y):
    return self.find(x) == self.find(y)
  
def kruskal(G):
  n = len(G)
  edges = []
  for u in G:
    for v in G[u]:
      hq.heappush(edges, (1, u, v))

  uf = DisjointSet(G)

  T = []
  path = {}
  for key in G.keys():
    path[key] = -1
    
  while edges and n > 0:
    _, u, v = hq.heappop(edges)
    if not uf.isSameSet(u, v):
      uf.union(u, v)
      T.append((u, v, 1))
      if path[u] < 0:
        path[u] = v
      else:
        path[v] = u
      n -= 1

  return path
```

##### Resultados
Estos fueron los resultados obtenidos durante la experimentación:

 - [x] El recorrido más cercano para los almacenes 31 al 45.
 ![Imagen de los primeros 2 almacenes](https://cdn.discordapp.com/attachments/889235275732111397/911752738482835476/unknown.png)
Se realizó en un tiempo promedio de 1900 ms.







### Solución 4: Aplicando el algoritmo de DLS

Para la segunda solución, se empleó el algoritmo DLS, adaptado para el uso de diccionarios.
```python 
def dfsDict(G, p_a, limit):
  visited = {}
  path = {}
  reached = {}
  for key in G.keys():
    visited[key] = False
    path[key] = None
    reached[key] = False

  def _dfs(u, limit):
    if limit > 0:
        if not visited[u]:
            visited[u] = True
            for v in G[u]:
              if not visited[v]:
                path[v] = u
                reached[v] = True
                _dfs(v, limit-1)
                
  reached[p_a]= True              
  _dfs(p_a, limit)
     
  return path
```

##### Resultados
Estos fueron los resultados obtenidos durante la experimentación:

 - [] El recorrido más cercano para los almacenes 46 al 60.
No se pudo realizar el algoritmo, ya que debido a las propiedades que presenta el algoritmo DFS, al presentar tanta recursividad, y la región al contener tantos nodos, se vuelve imposible hallar el resultado.




### Solución 5: Aplicando el algoritmo de BFS

Para la segunda solución, se empleó el algoritmo BFS, adaptado para el uso de diccionarios.
```python 
def bfs(G, s):              
  visitado = {}
  path = {}
  for key in G.keys():
    visitado[key] = False
    path[key] = None

  queue = [s]
  visitado[s] = True

  while queue:             
    u = queue.pop(0)                  
    for v in G[u]:        
      if not visitado[v]:
        visitado [v] = True
        path[v] = u          
        queue.append(v)
  return path
```

##### Resultados
Estos fueron los resultados obtenidos durante la experimentación:

 - [x] El recorrido más cercano para los almacenes 61 al 75.
 ![Imagen de los primeros 5 almacenes](https://cdn.discordapp.com/attachments/889235275732111397/911754627417002064/unknown.png)
Se realizó en un tiempo promedio de 600 ms.

## Conclusiones

- Tanto los algoritmos Dijkstra, Prim y BFS serían ideales para el problema, ya que nos permiten encontrar el camino más cercano a partir de un nodo, funcianando con mayor eficiencia en gráficos densos, es decir, cuando el número de aristas es alto.
- Tanto los algortimos Bellmand Ford, DLS, DFS y Kruskal no serían ideales, ya que no presentan el suficiente rendimiento para soportar el presente gráfico, ya que estos trabajan mejor en gráficos dispersos y más pequeños.

## Bibliografia:

Algorithms and More (2016). CAMINO MÁS CORTO: ALGORITMO DE BELLMAN-FORD. Recuperado de: https://jariasf.wordpress.com/2013/01/01/camino-mas-corto-algoritmo-de-bellman-ford/

Algorithms and More (2012). ÁRBOL DE EXPANSIÓN MÍNIMA: ALGORITMO DE KRUSKAL. Recuperado de: https://jariasf.wordpress.com/2012/04/19/arbol-de-expansion-minima-algoritmo-de-kruskal/

Algorithms and More (2016). DISJOINT-SET: UNION FIND. Recuperado de: https://jariasf.wordpress.com/2012/04/02/disjoint-set-union-find/

Estructura de Datos II (2016). Algoritmo de Prim. Recuperado de: https://estructurasite.wordpress.com/algoritmo-de-prim/

EcuRed (2018). Algoritmo de Dijkstra - EcuRed. Recuperado de: https://www.ecured.cu/Algoritmo_de_Dijkstra

Kripkit (2021). Búsqueda de Produndidad Limitada. Recuperado de:  https://kripkit.com/bsqueda-de-profundidad-limitada/

