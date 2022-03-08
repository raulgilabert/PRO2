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

- Diseño modular
- Estructuras de datos lineales
  - Colas
  - Listas
  - Otros
- Estructuras de datos arborescentes
  - Árboles binarios
  - Árboles n-arios
- Diseño iterativo (verificación)
- Diseño recursivo (verificación)
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

La parte privada (```private```) no es accesible desde el exterior de la clase.
En cambio la pública (```public```) sí.

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

// Mirar splice

Las listas permiten el uso de `push_back()`, `push_front()`, `pop_back()` y
`pop_front()` para añadir o eliminar elementos al inicio o al final, de forma
que no hace falta pasar un iterador.
