# tp-AyEdeD

Proyecto de compresión / descompresión Huffman (TP)

Este repositorio contiene una implementación educativa de compresión Huffman en C++.

## Compilar

Requiere g++ con soporte C++11. Desde la raíz del repo:

```bash
make
```

Si querés forzar una compilación limpia:

```bash
make clean && make
```

El binario resultante es `huffman`.

## Uso

- Comprimir:

```bash
./huffman archivo.txt    # genera archivo.txt.huf
```

- Descomprimir:

```bash
./huffman archivo.txt.huf  # genera archivo.txt.desc
```

## Formato del archivo .huf (implementación actual)

El formato utilizado por este proyecto (no estándar) es el siguiente:

- 1 byte: cantidad de símbolos distintos (p)
- Para cada símbolo (repetido p veces):
	- 1 byte: símbolo (valor 0..255)
	- 1 byte: longitud del código en caracteres
	- N bytes: la representación del código como caracteres ASCII '0'/'1'
- 1 byte: separador newline (0x0A)
- 1 byte: pad-info — número de bits válidos (1..8) en el último payload byte (se consume aunque no siempre sea usado)
- 8 bytes: tamaño original del archivo (unsigned long long, little-endian según fwrite de la plataforma)
- restante: payload comprimido (bits empaquetados MSB-first en bytes)

Notas:
- En la implementación actual se escribe también el tamaño original en 8 bytes para evitar ambigüedades con archivos que contienen un único símbolo o problemas de padding.
- El `BitWriter`/`BitReader` usan un buffer de 1 byte + contador de bits, y empacan/leen los bits MSB-first.

## Cambios importantes realizados

- Se resolvieron errores de linking (funciones definidas en headers) marcando funciones inline o moviendo implementaciones.
- Se reescribió la E/S a nivel de bits para usar buffer+contador y evitar conversiones por strings.
- Se añadió metadata (pad-info y tamaño original) para que la descompresión reconozca el número exacto de bytes a generar.
- Se arreglaron warnings de compilación.

## Pruebas rápidas

Hay archivos de prueba incluidos (`prueba.txt`, `prueba2.txt`) — para verificar round-trip:

```bash
./huffman prueba.txt
./huffman prueba.txt.huf
diff -u prueba.txt prueba.txt.desc   # no debe mostrar diferencias
```

Repetir para `prueba2.txt`.

## Recomendaciones / Siguientes pasos

- Refactorizar funciones grandes fuera de headers a `.cpp` para evitar depender de `inline` como parche permanente.
- Añadir tests automáticos (`make test`) que ejecuten round-trips con varios tamaños de fichero.
- Mejorar la especificación binaria del `.huf` (cabecera con campos fijos y endianness explícito) si se desea interoperabilidad externa.


---

Fecha de actualización: 2026-01-31
