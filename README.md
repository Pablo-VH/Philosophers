# Philosophers 🇪🇸

Philosophers es un proyecto de la escuela 42 que implementa el clásico problema de los **filósofos comensales** utilizando hilos (threads) y mutexes en C. Este proyecto sirve como introducción a la programación concurrente, sincronización y prevención de condiciones de carrera.


## 🧠 Descripción

El objetivo es simular a varios filósofos sentados alrededor de una mesa que alternan entre pensar, comer y dormir. Para comer, cada filósofo necesita tomar dos tenedores (uno a cada lado), lo que genera problemas de sincronización. El programa debe evitar situaciones como **deadlocks**, **starvation** y asegurar que los filósofos respeten los tiempos definidos.


## ✨ Características principales

- Implementación en C usando **pthreads**
- Simulación precisa con control de tiempos
- Uso de **mutexes** para proteger el acceso a los tenedores
- Prevención de condiciones de carrera
- Modo con número limitado de comidas por filósofo
- Mensajes sincronizados en consola


## ⚙️ Instalación

Clona el repositorio y compílalo con:

```bash
git clone https://github.com/Pablo-VH/Philosophers.git
cd Philosophers/philo
make
```


## ▶️ Uso

Ejecuta el programa con los siguientes argumentos:
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

```bash
./philo 5 800 200 200
```
Or:
```bash
./philo 5 800 200 200 7
```


## 📦 Requisitos

- Sistema UNIX (Linux o macOS)  
- `gcc` y `make`  
- Biblioteca `pthread` (incluida por defecto en sistemas UNIX)


# Philosophers 🇬🇧

Philosophers is a project from School 42 that implements the classic **philosophers dining** problem using threads and mutexes in C. This project serves as an introduction to concurrent programming, synchronisation, and race condition prevention.


## 🧠 Description

The goal is to simulate several philosophers sitting around a table who alternate between thinking, eating, and sleeping. To eat, each philosopher needs to take two forks (one on each side), which creates synchronisation problems. The programme must avoid situations such as deadlocks and starvation and ensure that the philosophers respect the defined times.


## ✨ Main features

- Implementation in C using **pthreads**
- Accurate simulation with time control
- Use of **mutexes** to protect access to forks
- Prevention of race conditions
- Mode with a limited number of meals per philosopher
- Synchronised messages in console


## ⚙️ Installation

Clone the repository and compile it with:

```bash
git clone https://github.com/Pablo-VH/Philosophers.git
cd Philosophers/philo
make
```


## ▶️ Usage

Run the program with the following arguments:
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

```bash
./philo 5 800 200 200
```
Or:
```bash
./philo 5 800 200 200 7
```


## 📦 Requirements

- UNIX system (Linux or macOS)
- `gcc` and `make`
- `pthread` library (included by default on UNIX systems)
