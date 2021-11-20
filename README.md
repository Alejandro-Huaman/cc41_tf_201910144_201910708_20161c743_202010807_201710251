# cc41_tf_201910144_201910708_20161c743_202010807_201710251
Trabajo Final para el curso de Complejidad Algorítmica.

### Integrantes
- Alejandro Sebastián Huamán Ruiz
- Giusen Eduardo Rebaza Maticorena
- Jose Eduardo Peralta Saravia
- Franco Galindo Alvarez
- Ernesto Valdivia

## Reporte de Actividades

### Trabajo Parcial
En el presente trabajo, como equipo hemos coordinado cada una de las actividades necesarias para alcanzar los objetivos de esta primera entrega. Por lo que cada uno de los intregantes es reesponsble de una o varias actividades. Estas se ven a continuación:

- Crear los dataset de los puntos de entrega y almacenes: 
    - Franco Galindo Alvarez
- Plasmar el espacio de búsqueda del problema: 
    - Alejandro Sebastián Huamán Ruiz 
    - Giusen Eduardo Rebaza Maticorena
    - Jose Eduardo Peralta Saravia
- Realizar análisis preliminar de la complejidad de los algoritmos a realizar: Cada integrante realizó el suyo.
- Generar descripción de datos de vehículos de entrega:
    - Ernesto Valdivia
- Reporte de actividades:
    - Franco Galindo Alvarez
- Realizar video explicativo
    - Jose Eduardo Peralta Saravia

Además de las presentadas actividades, podemos encontrar más que no estamos mencionaodo, debido a que fueron realizadas en conjunto o simplemente porque uno tuvo la iniciativa de hacerla.

**URL DEL VIDEO:** [Exposición](https://drive.google.com/file/d/1JGNe2cjLAb1-nN8RWJ33b-QWkVfLnSam/view?usp=sharing)


## Introducción
...

## Objetivos

• Desarrollar la competencia general de razonamiento cuantitativo y la competencia específica de uso de técnicas y herramientas acorde a los objetivos del curso.

• Desarrollar un algoritmo que permita resolver completa o parcialmente el problema de enrutamiento de vehículos (VRP).

• Determinar la importancia de la aplicación de algoritmos eficientes a la hora de resolver un problema.

• Analizar la eficiencia y complejidad de los algoritmos planteados.

• Buscar un balance entre el tiempo y costo de entrega.

## Marco Teorico

### Algoritmo Bellman Ford


## Experimentación

### Solución 1: Aplicando el algoritmo ?
Para esta solución utilizaremos el algoritmo de kruskal para hallar árboles de expansión mínima. En primer lugar, se obtendrán los datos de todos los centros poblados desde un archivo con extensión csv. Para ello definimos el siguiente modelo:
```python 
	#Clase CentroPoblado
	class  CentroPoblado:
		def  __init__(self,codigo,nombre,departamento,provincia,distrito,capital,coordX, coordY):
			self.codigo = codigo
			self.nombre = nombre
			self.departamento = departamento
			self.provincia = provincia
			self.distrito = distrito
			self.capital = capital
			self.coordX = coordX
			self.coordY = coordY
		def  __str__(self):
			return  "%s D: %s P: %s D: %s Cap: %d Cod: %s X: %f Y: %f"  % (self.nombre, self.departamento, self.provincia, self.distrito, self.capital, self.codigo,self.coordX,self.coordY)
```
##### Resultados
Estos fueron los resultados obtenidos durante la experimentación:


## Conclusiones
...
