# Sistema de gestión de excursiones

Programa de consola en C++ para agregar, listar, filtrar y buscar excursiones, y
separar los registros según su disponibilidad.

## Compilar y ejecutar

Desde PowerShell, en la carpeta del proyecto y con `g++` instalado:

```powershell
g++ -std=c++11 "Main_Menu (1).cpp" -o excursiones.exe
.\excursiones.exe
```

El programa usa `excursiones.txt` en la carpeta desde la que se ejecuta. Cada
registro debe contener, en este orden: fecha (`DD/MM`), tipo (`A`, `B` o `C`),
presupuesto, cantidad de personas y disponibilidad (`1` o `0`).
