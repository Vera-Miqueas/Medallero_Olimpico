# 🥇 Gestor de Medallero Olímpico en C++

## 📖 Descripción del Proyecto
Este repositorio contiene el código fuente de una aplicación de consola desarrollada en C++ para gestionar un medallero olímpico. El sistema permite a los usuarios registrados crear competencias, registrar la asignación de medallas (oro, plata y bronce) para distintos países y realizar el cálculo avanzado de estadísticas deportivas.

Este desarrollo fue realizado como Trabajo Práctico Integrador para la asignatura **Algoritmos y Estructuras de Datos** de la **UTN - Facultad Regional Santa Fe**.

## ✨ Características Principales

* 🔐 **Sistema de Autenticación Lógico:** Acceso validado mediante número de legajo de estudiante universitario. La contraseña se genera de forma dinámica mediante un algoritmo matemático que calcula el primer número capicúa superior a los dígitos extraídos del legajo.
* 🏅 **Gestión de Competencias y Deportes:** Soporte estructural para administrar la participación de hasta 196 países en 87 disciplinas deportivas (tanto individuales como colectivas).
* 💾 **Persistencia de Datos (Archivos):** Guardado y recuperación del estado completo del sistema mediante archivos binarios y de texto. Los respaldos se generan automáticamente con marcas de tiempo utilizando la librería `<time.h>` bajo el formato `AAAA-MM-DD-HH-MM-SS.bin`.
* 📊 **Módulo de Estadísticas y Reportes:** Generación de métricas en tiempo real, incluyendo el "Top Medallero", la identificación del país con más medallas globales o individuales, y la búsqueda de podios deportivos filtrando por letra inicial.
* 🛡️ **Interfaz Robusta (UI en Consola):** Navegación intuitiva mediante menús jerárquicos con prevención y validación de errores de ingreso de datos para una mejor experiencia de usuario.

## 🛠️ Tecnologías y Conceptos Académicos Aplicados

El proyecto fue construido aplicando buenas prácticas de ingeniería de software y programación estructurada:

* **Lenguaje:** `C++`
* **Arquitectura:** `Estrategia de descomposición modular descendente (Top-Down).`
* **Estructuras de Datos:** `Diseño mediante Tipos de Datos Abstractos (TDA), anidación de estructuras ("struct") y arreglos multidimensionales.`
* **Lógica Core:** `Implementación extensiva de funciones, recursividad y manejo de paso de parámetros.`
* **Persistencia:** `Manejo de archivos de texto y directos para el almacenamiento persistente a largo plazo.`

## 👥 Equipo de Desarrollo
* **Grupo:** `while(milanesa)`
* **Integrantes:** `Berli Silvio y Vera Miqueas`

## 🚀 Cómo ejecutar el proyecto
1. **Clonación:** Clona el repositorio en tu máquina local:
   ```bash
   git clone [https://github.com/tu-usuario/tu-repositorio.git](https://github.com/tu-usuario/tu-repositorio.git)

## 🖥️ Configuración de la Consola
La interfaz de usuario ha sido diseñada con marcos y tablas que requieren un espacio específico. 
* **Dimensiones obligatorias:** La ventana de la consola debe estar configurada en **150 columnas x 40 filas**.
* **Automatización (Windows):** El programa intenta ajustar este tamaño automáticamente mediante la instrucción `system("mode con: cols=150 lines=40");`, pero se recomienda verificarlo manualmente en las propiedades de la terminal si el diseño se ve desbordado.
