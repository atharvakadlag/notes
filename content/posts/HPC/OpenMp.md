---
author: "Atharva Kadlag"
title: "Introduction to OpenMP"
date: "2022-08-03"
description: "Understand the basics of OpenMP library used for parallel processing in C, C++ and Fortran"
FAtags: ["intro", "openmp"]
FAcategories: ["high-performance-computing"]
FAseries: ["High Performance Computing"]
ShowToc: true
TocOpen: false
weight: 2
---

# Shared Memory Parallel programming with OpenMP - (Open multi processing)

## Uses forks and join model
Process splits into multiple threads and then can join back to split again if required.

## Example of OpenMP

OpenMP adapts raw OS thread interface to make it more usable.

```c
# include <omp.h>
std::cout << "Hello single";

#pragma omp parallel
{
    do_work(op_get_thread_num(), omp_get_num_threads());
}
```

```bash
gcc -fopenmp filename.c -o exec
export OMP_NUM_THREADS=4  ()
./exec
```

> `omp_get_wtime()` gives you system time. It returns a double object.

It can be used to calculate time taken by the system to execute the program.

## Private variables
Variable belonging to a specific thread is private variable, while one shared by all the threads is called public variable.

## Data Race

### Hello world

```c
#include <stdio.h>
#include <omp.h>
int main(int argc, char argv[]) {
    int omp_rank;
    #pragma omp parallel private(omp_rank)
    {
        omp_rank = omp_get_thread_num();
        printf("Hello world by thread %d", omp_rank);
    }
}
```

### Race condition

Two threads when accessing the same variable can result in disparity among the results in multiple executions.

The result of the execution depends the 

### Reductions
Summing elements of array is an example of reduction operation.

Reduction is merging the data from multiple threads after the execution is completed.

OpenMP provides a `reduction(operator:var_list)`

```
!$ OMP PARALLEL DO SHARED(x, y, n) PRIVATE(i) REDUCTION(+:asum)
do i = 1, n
    asum = asum_x(i)*(yi)
end do
!$OMP END PARALLEL DO
```

Maunally doing the above would look as follows

```
!$ OMP PARALLEL DO SHARED(x, y, n, asum) PRIVATE(i, psum)
    psum = 0.0d
    !$OMP DO
        do i = 1, n
            psum = psum + x(i)*y(i)
        end do
    !$ OMP END DO
    !$ OMP CRITICAL(dosum)
        asum = asum + psum
    !$ EMP END CRITICAL(dosum)
!OMP END PARALLEL DO
```
This is useful when the operation required to be performed is not supported by the reduction.

### Execution Controls

#### `#pragma master`
Specifies a region that should be executed only by the master thread
There is no implicit barrier at the end

#### `#pragma single`
Specifies that a regions that should be executed only by a single (arbitrary) thread.
Other threads wait until this region is executed.

#### `#pragma critical [dosum]`
A section that is executed by only one thread at a time. 
An optional name specifies different critical sections. 
Unnamed critical sections are treated as the same section

### `#pragma flush [dosum]`
Synchronies the memory of all threads.

### `#pragma atomic`
No context switch while the region is being executed.
