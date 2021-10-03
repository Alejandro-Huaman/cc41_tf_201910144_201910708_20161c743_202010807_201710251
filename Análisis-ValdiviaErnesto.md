## Analisis Preliminar de posible Algoritmo

En primer lugar, para cada almacen se tendria que conseguir los puntos de entrega mas cercanos,esto se puede hallar
comparando por teorema de Pitagoras,a las hipotenusas que se generen con respecto a cada almacen, esta distancia se
comenzaria abarcando el 25% del tamaño del dataset.
Luego a todos los puntos rojos(entrega) recolectados por cada almacen, se añadiran a una nueva lista.

En caso quede algun punto de entrega(rojo) excluido, se aumentara el tamaño de la busqueda en un 25% partiendo del primer
almacen nuevamente, y asi hasta que no quede ningun punto rojo afuera.



Dentro del "Area de alcance" de un almacen con todos sus puntos rojos, se procede a buscar el punto de entrega mas 
cercano de su lista, por lo que para hallarlo se identifica a traves de la hipotenusa de cada punto rojo y 
se les compara para hallar el menor. A continuacion, se crearia otra lista para registrar el orden del recorrido del
vehiculo(listCamino), 

Luego de crear otra lista que registre el costo de la distancia(listaCosto), que se hallaria con una funcion que calcule 
la diferencia de los pares de coordenadas entre el almacen y el punto rojo , y deacuerdo a los
resultados, las coordenadas para el recorrido del vehiculo aumentarian(irse para arriba), o disminuirian(irse hacia
abajo), a su vez que un contador va dando seguimiento de cada avance singular del eje "x" y del eje "y". 
Esta logica se efectuaria hasta que la diferencia de ambos pares sea igual a 0, para que finalmente el contador se
multiplique por el costo y se halle el costo total hasta ese punto rojo, cuyo valor sera ingresado en listaCosto.



Despues, se eliminaria este punto rojo de la primera lista  y se procederia a buscar el siguiente mas cercano de esta
lista, comparando las hipotenusas de los puntos restantes y escogiendo el menor de estos nuevamente. Se procede a 
agregarlo a listCamino y registrar su costo en listCosto tomando referencia el punto rojo anterior como distancia, 
posteriormente se elimina este punto tambien y continua asi el ciclo hasta que la primera lista este sin elementos.

Este algoritmo se aplica para cada almacen(punto azul), el tiempo asintotico se puede decir que es de Big(O^2) por las 
iteraciones que existen por cada almacen, y luego por cada punto de entrega para hallar el mas cercano
