# *philosophers*

## Description
This is a concurrency and synchronization project that challenges students to implement the dining philosophers problem. The goal is to design a program that simulates philosophers sitting at a dining table eating, sleeping, and thinking while avoiding deadlock and starvation.

## Features
- **Concurrency**: Utilizes threads to represent philosophers and mutexes/semaphores for synchronization.
- **Deadlock Avoidance**: Implements a solution to avoid deadlock situations.
- **Starvation Prevention**: Ensures that all philosophers have a fair chance to eat.

## Getting Started

### Installation
1. Clone the repository:

    ```bash
    git clone https://github.com/marzianegro/42-philosophers.git
    ```

2. Navigate to the project directory:

    ```bash
    cd 42-philosophers
    ```

3. Compile the project:

    ```bash
    make
    ```

### Usage

1. Run the program with the specified number of philosophers, time to die, time to eat, time to sleep, and the optional number of times each philosopher must eat:

    ```bash
    ./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_to_eat]
    ```

### Example

```bash
# Run the program with 5 philosophers, time to die = 800ms, time to eat = 200ms, time to sleep = 200ms, and optionally specify that each philosopher must eat at least 7 times
./philosophers 5 800 200 200 7
```
