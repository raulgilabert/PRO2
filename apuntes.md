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
	// Post: 


}
```





