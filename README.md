# K Means Clustering Algorithm in C

This is a simple implementation of the K Means Clustering algorithm in C.

> [!NOTE]
> This implementation isn't meant to be used as a library, but rather it was done to understand the algorithm better.

## Try it out

You can compile the code in your system by running the following command:

```bash
gcc -Iinclude main.c src/matrix.c -o main -lm
```

This will produce an executable named `main` which you can run by executing the following command:

```bash
./main
```

## Other information

- As of now, the test dataset is pretty small, hardcoded in the `/datasets/test-dataset.h` file.
- The dataset is a 2D array, of type `Matrix`, which is a custom data structure defined in the `include/matrix.h` file.


## Other resources

If this interests you, then you would like my other implementations as well:

- [Logistic Regression (the neural network way) in C](https://github.com/inclinedadarsh/logistic-regression-c/)

- [Micrograd - A tiny Autograd engine in C++](https://github.com/inclinedadarsh/incligrad)

- [Custom (PyTorch like) neural network library in Python](https://github.com/inclinedadarsh/inclinet)
