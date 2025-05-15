# Sistema de Detección de Incendios con ESP32

Este proyecto implementa un **sistema de alarma de incendios** utilizando un microcontrolador **ESP32**. Está diseñado para detectar condiciones anómalas como la presencia de una llama o altas temperaturas mediante sensores ambientales, y emitir alertas visuales y sonoras. Fue desarrollado como proyecto académico por **Gina Andrea Ramírez Guerrero** y **Jorge Ferrero de Lara**.

## Objetivo

Desarrollar un sistema embebido de bajo costo y bajo consumo capaz de:
- Detectar condiciones de riesgo de incendio.
- Alertar mediante un **buzzer** y un **LED RGB**.
- Ahorrar energía activando el modo *deep sleep* automáticamente.

## Funcionalidades

- **Monitoreo ambiental** mediante sensores:
  - Sensor de luz (para detectar presencia de llama o cambios bruscos de iluminación).
  - Termoresistor (para detectar aumento de temperatura).
- **Indicadores de alarma**:
  - **LED RGB** cambia de color según la severidad.
  - **Buzzer** se activa ante condiciones críticas.
- **Gestión de energía**:
  - Entrada en modo *deep sleep* al presionar un botón externo.
  - Reinicio automático después de 10 segundos.

## Componentes integrados

| Componente             | Descripción                          |
|------------------------|--------------------------------------|
| ESP32                  | Microcontrolador principal           |
| Sensor de luz (LDR)    | Entrada analógica (ADC)             |
| Termoresistor (NTC)    | Entrada analógica (ADC)             |
| Botón externo          | Activador de modo *deep sleep*      |
| LED RGB                | Indicador visual                    |
| Buzzer                 | Indicador auditivo                  |


## Tecnologías utilizadas

- C/C++
- Plataforma Arduino
- Arduino IDE
- ESP32-S3
- Comunicación serie UART para depuración

## Estado del proyecto

Finalizado – Proyecto académico presentado satisfactoriamente.

> Desarrollado por Gina Andrea Ramírez Guerrero y Jorge Ferrero de Lara.


