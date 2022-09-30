// g++ act1_1.cpp -o act1_1
//  Iván Alberto Romero Wells A00833623
//  Mariano Barberi Garza A01571226
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#define print std::cout
#define endl std::endl

// Complejidad:
// Tiempo: O(n), Memoria O(1)
int sumaIterativa(int n)
{
    if (n <= 0)
    {
        throw std::invalid_argument("El numero debe ser un entero positivo");
    }
    int suma = 0;
    for (int i = 1; i <= n; i++)
    {
        suma += i;
    }
    return suma;
}

// Complejidad
// Tiempo O(n) Memoria O(n)
int sumaRecursiva(int n)
{
    if (n <= 0)
    {
        throw std::invalid_argument("El numero debe ser un entero positivo");
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sumaRecursiva(n - 1);
    }
}

// Complejidad
// Tiempo O(1) Memoria O(1)
int sumaDirecta(int n)
{
    if (n <= 0)
    {
        throw std::invalid_argument("El numero debe ser un entero positivo");
    }
    return (n * (n + 1)) / 2;
}

// Complejidad
// Tiempo O(n) Memoria O(1)
int fibonacciIterativo(int n)
{
    if (n <= 0)
    {
        throw std::invalid_argument("El numero debe ser un entero positivo");
    }
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Complejidad
// Tiempo O(2^n) Memoria O(2^n)
int fibonacciRecursivo(int n)
{
    if (n <= 0)
    {
        throw std::invalid_argument("El numero debe ser un entero positivo");
    }
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    }
}

int helper(int n, std::vector<int> &memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
    return memo[n];
}

// Complejidad
// Tiempo O(n) Memoria O(n)
int fibonacciDP(int n)
{
    if (n <= 0)
    {
        throw std::invalid_argument("El numero debe ser un entero positivo");
    }
    std::vector<int> memo(n + 1, -1);
    return helper(n, memo);
}

int main()
{
    int casosDePrueba[4] = {20, 50, 100, 1000};
    int (*sumatorias[3])(int) = {sumaIterativa, sumaRecursiva, sumaDirecta};
    std::string nombresSumatorias[3] = {"Sumatoria Iterativa", "Sumatoria Recursiva", "Sumatoria Directa"};
    print << "Sumatorias de 1 a n" << endl;
    for (auto i : casosDePrueba)
    {
        print << "Suma de 1 a " << i << endl;
        for (int j = 0; j < 3; j++)
        {
            print << nombresSumatorias[j] << ": " << sumatorias[j](i) << endl;
        }
    }
    int casosDePruebaFibonacci[4] = {5, 10, 15, 30};
    int (*fibonacci[3])(int) = {fibonacciIterativo, fibonacciRecursivo, fibonacciDP};
    std::string nombresFibonacci[3] = {"Fibonacci Iterativo", "Fibonacci Recursivo", "Fibonacci Programacion Dinamica"};
    print << "Fibonacci" << endl;
    for (auto i : casosDePruebaFibonacci)
    {
        print << "Fibonacci de " << i << endl;
        for (int j = 0; j < 3; j++)
        {
            print << nombresFibonacci[j] << ": " << fibonacci[j](i) << endl;
        }
    }
    return 0;
}