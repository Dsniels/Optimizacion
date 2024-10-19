def leer_matriz_desde_txt(ruta_archivo):
    matriz = []

    with open(ruta_archivo, 'r') as archivo:
        lineas = archivo.readlines()
        # Saltar la primera línea con el número de elementos
        for linea in lineas[2:]:
            # Dividir la línea en valores separados por espacio y convertir a float
            valores = list(map(float, linea.split()[1:]))  # Ignorar el primer valor (índice)
            matriz.append(valores)

    return matriz

def convertir_a_formato_cpp(matriz):
    formato_cpp = "vector<vector<double>> matriz76 = {\n"
    for fila in matriz:
        formato_cpp += "    {" + ", ".join(map(str, fila)) + "},\n"
    formato_cpp += "};"
    return formato_cpp

# Ruta del archivo que contiene la matriz
ruta_archivo = 'd:/Repositorios/Optimizacion/matrices/matrix76.txt'

# Leer la matriz desde el archivo y convertirla al formato C++
matriz = leer_matriz_desde_txt(ruta_archivo)
formato_cpp = convertir_a_formato_cpp(matriz)

# Mostrar la matriz en formato C++
print(formato_cpp)
