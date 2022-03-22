# PRO2

## Profesores

### Teoría

Fernando Orejas - Despacho 238 Edificio Omega - orejas@cs.upc.edu

## Evaluación

- 25% Parcial 1
- 25% Parcial 2 (En la fecha del final)
- 25% Práctica
- 10% Control de laboratorio
- 15% Examen de práctica

Los parciales son a papel

## Temario

- [Diseño modular](#diseño-modular)  **OK**
- [Estructuras de datos lineales](#estructuras-lineales)  **OK**
  - [Pilas](#clase-stack)
  - [Colas](#clase-queue)  **OK**
  - [Listas](#clase-list)  **OK**
- [Estructuras de datos arborescentes](#árboles) **OK**
  - [Árboles binarios](#árboles-binarios) **OK**
  - Árboles n-arios **OK**
- [Diseño iterativo (verificación)](#diseño-iterativo-verificación-y-derivación)
**OK**
- [Diseño recursivo (verificación)](#diseño-recursivo) **OK**
- Mejora eficiencia de programas iterativos y recursivos
- Estructuras de datos recursivas (cómo se implementan las estructuras lineales
y arborescentes)

---

Qué se busca en un programa?

- Corrección
- Eficiencia
- Legibilidad

## Diseño modular

Lo importante a tener en cuenta aquí es la descomposición en módulos de un
programa y la abstracción.

Para que un diseño modular sea correcto es necesaria una cohesión fuerte y un
acoplamiento débil:

- Cohesión fuerte: \
    Todas las partes del módulo están relacionadas.
- Acoplamiento débil: \
    La independencia de cada módulo respecto a los demás.

### Clases

Programación orientada a objetos:

- Módulos de datos = clases \
    TAD
- Operaciones = métodos
- Campos = atributos

Declaración:

```c++
class lista_palabras {
    private:
        struct lista {
            ...
        }

    // funciones privadas, datos y todo eso

    public:
        void anadir_palabra(string palabra) {
            ...
        }
        // funciones públicas y lo que surja
}
```

La parte privada (`private`) no es accesible desde el exterior de la clase.
En cambio la pública (`public`) sí.

Una vez declarada puede ser usada como un tipo de datos (uso como operación
constructora) y utlizar las funciones públicas de esta.

```c++
lista_palabras L;

string p;
cin >> p;

L.anadir_palabra(p);
```

Este tipo de implementación permite asegurar la estructura de datos ya que está
declarada en la parte privada de la declaración de la clase y no en la pública.
De esta manera para poder modificarla habrá que hacerlo usando las funciones
públicas de la clase.

#### Métodos de clases

##### Constructoras

Operaciones que construyen los objetos básicos de la clase- Tienen el nombre de
esta y se llaman en la declaración de un objeto. Puden haber varios métodos
constructores.

##### Destructoras

Operaciones que destruyen los objetos y los eliminan de la memoria.

##### Modificadoras

Cambian el valor del parámetro implícito.

##### Consultoras

Dan el valor del parámetro requerido del objeto.

##### Entrada/Salida

Escriben información del objeto.

---

De esta manera una clase llamada `Estudiante` se podría escribir de esta
manera:

```c++
class Estudiante {
    private:

    public:
        // Constructoras
        Estudiante();
        // Post: crea un estudiante con DNI=0 y sin nota

        Estudiante(int dni);
        // Post: crea un estudiante con DNI=dni y sin nota

        // Destructoras
        ~Estudiante();

        // Modificadoras
        void anadir_nota(double nota);
        // Pre: No hay nota; 0 <= nota <= nota_maxima()
        // Post: la nota del parámetro de la nota se actualiza al valor que se
        // ha entregado

        void modificar_nota(double nota);
        // Pre: Hay nota; 0 <= nota <= nota_maxima()
        // Post: la nota del parámetro de la nota se actualiza al valor que se
        // ha entregado

        // Consultoras
        int consultar_dni() const;
        // Post: Devuelve la nota

        bool tiene_nota() const;
        // Post: Verdadero si hay nota, falso si no

        double consultar_nota() const;
        // Post: Devuelve la nota

        static nota_maxima();
        // Post: Nota máxima de los elementos de la clase

        // Lectura/Escritura
        void leer();
        // Pre: Entero y doble por el canal estándar
        // Post: Añadido dentro de los datos de la clase

        void escribir();
        // Post: Escribe los datos de la clase
```

La implementación de la clase en el archivo .cc se realiza escribiendo el tipo
de la clase, seguido de dos : y la función a modificar.

```c++
void Estudiante::leer() {
    ...
}
```

#### Uso de `this`

La utilidad de usar `this->` es poder diferenciar entre un parámetro y una
variable de la parte privada de la clase. Si no pasa esto no es necesario su
uso.

### Mecanismos para añadir funcionalidades

- Modificar la clase:
  - Consiste en modificar las cabezeras del `.hh` e implementar los nuevos
  módulos en el `.cc`. Suele ser más eficiente pero tiene el inconveniente de
  requerir el acceso a la clase y entender su implementación original.
- Enriquecimiento
  - Consiste en añadir las nuevas funcionalidades en un módulo externo. Esta no
  modifica la implementación original. El inconveniente que tiene es que no son
  métodos de la clase, sino que son acciones y funciones convencionales. No
  es necesario el acceso a la clase original, por lo que esta no crece. El
  problema es que trae cierta ineficiencia y contradice un poco al diseño
  orientado a objetos.

### Bibliotecas

Es un conjunto de módulos que aplían el lenguaje, por ejemplo `iostream` o
`string`.

### Plantillas

Son clases y fuines genéricas con tipos como parámetros. Por ejemplo:
`vector<T>`, `queue<T>`, `stack<T>`, etc.

Se declaran de la siguiente manera:

```c++
template <typename T>

T minimo(const vector<T>& v) {
    ...
}
```

Al momento de llamar a la plantilla C++ cambia automáticamente `T` por el tipo
del dato que se está usando.

## Estructuras lineales

### Clase `stack`

Las pilas tienen tres operaciones básicas:

- Añadir un elemento
- Eliminar el último elemento añadido
- Mirar el último elemento añadido

```c++
template <class T> class stack {
public:
...
}
```

### Clase `queue`

Las colas tienen tres operaciones básicas:

- Añadir un elemento
- Eliminar el primer elemento añadido
- Mirar el primer elemento añadido

### Clase `list`

Premiten recorrer toda la secuencia de los elementos, insertar un elemento en
cualquier punto de la lista, eliminar cualquier elemento y la concatenación de
listas. Todas estas operaciones son muy eficientes.

#### Iteradores

Un iterador es un objeto que apunta a un elemento de una lista o cualquier otro
tipo de contenedor de elementos. Las listas y los iteradores trabajan en
conjunto. Las listas permiten diferentes operaciones usando iteradores:

- `L.insert(it, x)`: Añade el elemento `x` en la lista `L` en la posición `it`,
moviendo todos los elementos desde `it` hasta el final una posición a la
derecha.
- `itsuc = L.erase(it)`: ELimina el elemento en `it` y devulve `itsuc` que
apunta al siguiente elemento de la lista que no ha sido eliminado.

Las listas tienen también operaciones que devuelven iteradores:

- `L.begin()` devuelve un iterador apuntando al primer elemento de la lista.
- `L.end()`: devuelve un iterador apuntaod a un elemento ficticio de la lista
al final de esta.

En caso de que la lista esté vacía, `L.begin() == L.end() -> true`.

Los iteradores se definen como subclase de la clase que lo contiene:

```c++
list<Estudiante> l;
list<string> lp;

list<Estudiante>::interator it = l.begin();
list<Estudiante>::interator it2 = l.end();
list<string>::iterator i3 = lp.begin();
```

##### Recorridos con iteradores

```c++
list<T> L;

list<T>::iterator it = L.begin();

while (it != L.end() and not -condición sobre *it-) {
    // acceder a *it
    it;
}
```

---

##### Iteradores constantes

Permiten el acceso a los elementos de la lista pero no su modificación.

```c++
list<T> L;
list<T>::const_iterator it, it2;

it = it2;  // ta bien
++it;      // tambien bien
v = *it;   // sigue bien

*it = v+3; // prohibido
```

Las listas también tienen ina función `splice` a la que se le da un iterador y
una lista de elementos e inserta en la lista en la que se llama la función los
elementos de la lista que se le pasa hasta la posición marcada por el iterador.

Las listas permiten el uso de `push_back()`, `push_front()`, `pop_back()` y
`pop_front()` para añadir o eliminar elementos al inicio o al final, de forma
que no hace falta pasar un iterador.

## Árboles

Un árbol es una estructura de datos en la que los elementos están organizados
en forma de nodos en un sistema de padres e hijos. Entre estos elementos se
cumple la propiedad de haber un único camino entre dos nodos específicos y que
el coste de las operaciones es constante.

Un árbol n-arios es una estructura arborescente en la que cada nodo tiene n
hijos.

### Árboles binarios

Es un árbol n-ario de 2 hijos por elemento. Un árbol binario no tiene
operaciones modificadoras, de forma que si se quiere modificar uno, hay que
crear uno nuevo.

#### Calcular el tamaño de un árbol

(Lo escribiré después)

```C++
int size(const BinTree& tree) { 
}
```

#### Recorrudo en profundidad

##### Preorden

1. Se visita la raíz
2. Se visita el hijo izquierdo
3. Se visita el hijo derecho

##### Inorden

1. Se visita el hijo izquierdo
2. Se visita la raíz
3. Se visita el hijo derecho

##### Postorden

1. Visita el hijo izquierdo
2. Visita el hijo derecho
3. Visita la raíz

##### Por niveles/en anchura

La visita se da por niveles, visitando todos los nodos de un nivel i y al
acabar se pasa al nivel i + 1.

## Diseño iterativo: verificación y derivación

### Corrección de un programa

El estado de un programa en un punto determinado es el valor de las variables
activas en ese mismo punto.

Si el estado inicial del programa satisface la precondición entonces este
acaba en un número finito de pasos y el estado final satisface la
postcondición.

Para que un programa sea correcto este tiene que, primero de todo, acabar.

#### Razonamiento sobre los programas

Lo que hacer es comentar el programa con aserciones que describan los
diferentes puntos de este.

##### Bucles

Hay que razonar si el bucle termina. Esto se demuestra con una función *f* de
cota que da la cantidad máxima de iteraciones que queda.

0. Se inventa un invariante y una función de cota.
1. Se inicializa el bucle con el invarainte
2. Se comprueba que si se cumple el invariante en la entrada y la salida, al
acabar cada iteración también pasa.
3. El invariante y la negación de la condición de entrada implican la
postcondición.
4. La función de cota decrece en cada iteración.
5. Si se entra una vez más al bucle la función de cota es estríctamente
positiva.

// Ver el temario del grupo 30 del tema




## Diseño recursivo

La idea básica de una definición inductiva es es que para algunos casos básicos
se define la función directamente y para el resto de los casos se define en
base a elementos **más pequeños**. Hay funciones de descomposición que permiten
obtener esos elementos más pequeños.

Ejemplo:

```
Factorial: n! = 1*2*...*(n-1)*n

1. Caso base: n = 0
2. El factorial se define a partir del factorial de n-1
3. La función se descompone en n-1
```

// Ver terminación de funciones recursivas

### Inmersión

#### Inmersión de una función en otra

Una inmersión de una función *f* es la definición de una función *g* con más
parámetros y que generaliza *f*
