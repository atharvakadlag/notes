---
author: "Atharva Kadlag"
title: "Motivation for High Performance Computing"
date: "2022-08-04"
description: "Study the motivation and reasoning for using high performance computers."
FAtags: ["", ""]
FAcategories: ["high-performance-computing"]
FAseries: ["High Performance Computing"]
ShowToc: true
TocOpen: false
weight: 3
---

## Solving large scale problems: (tera-scale / peta-scale)

High performance computing can be used to solve problems on a large scale.
For eg.
1. Getting weather data from a large number of cities and process it to forecast the weather.
2. Predicting the number of active cases at the peak of pandemic or predicting the curve.

## Measuring the speed of a processor

Process speeds are measured in Gigahertz (hertz = cycles/sec)
A average operation in a processor takes several cycles to complete.  

| Unit | 10 power | 2 power |
|:----:|:--------:|:-------:|
| Kilo | 10^3     | 2^10    |
| Mega | 10^6     | 2^20    |
| GHz  | 10^9     | 2^30    |
| THz  | 10^12    | 2^40    |
| PHz  | 10^15    | 2^50    |
| EHz  | 10^18    | 2^60    |
| ZHz  | 10^21    | 2^70    |

## How long does it take to solve a linear system?

Solving a linear $nxn$ linear system $Ax = b$ takes $\frac{n^3}{3}$ flops assuming we are using faussian elimination for a dense matrix.

therefore for $n=10^4$ we need $\frac{10^7}{3}$ flops.