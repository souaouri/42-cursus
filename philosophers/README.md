# Philosophers

A simulation of the classic dining philosophers problem, exploring threading, mutexes, and synchronization in C.

## Description

This project implements the famous dining philosophers problem, where philosophers alternate between eating, thinking, and sleeping. The challenge is to prevent deadlocks and ensure all philosophers can eat without starving.

## Problem Statement

- N philosophers sit around a circular table
- Each philosopher needs two forks to eat
- There are N forks on the table (one between each pair of philosophers)
- Philosophers must avoid deadlock and starvation
- The simulation ends when a philosopher dies of starvation

## Features

- Multi-threaded simulation using pthreads
- Mutex-based synchronization to prevent race conditions
- Configurable parameters (number of philosophers, timing)
- Real-time status logging with timestamps
- Death detection and simulation termination

## Usage

```bash
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters
- `number_of_philosophers`: Number of philosophers (and forks)
- `time_to_die`: Time in milliseconds before a philosopher dies without eating
- `time_to_eat`: Time in milliseconds it takes to eat
- `time_to_sleep`: Time in milliseconds spent sleeping
- `number_of_times_each_philosopher_must_eat`: (Optional) Simulation stops when all philosophers have eaten this many times

### Example
```bash
./philo 5 800 200 200    # 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 4 410 200 200 3  # Same as above but simulation stops after each philosopher eats 3 times
```

## Output Format

Each action is logged with a timestamp:
```
[timestamp_ms] [philosopher_id] has taken a fork
[timestamp_ms] [philosopher_id] is eating
[timestamp_ms] [philosopher_id] is sleeping
[timestamp_ms] [philosopher_id] is thinking
[timestamp_ms] [philosopher_id] died
```