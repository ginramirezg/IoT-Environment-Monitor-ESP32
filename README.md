# Sistema de Monitoreo Ambiental con ESP32

Este proyecto utiliza un microcontrolador **ESP32** para monitorizar variables ambientales mediante sensores y gestionar periféricos de salida (LED RGB y buzzer). Fue desarrollado como proyecto académico por **Gina Andrea Ramírez Guerrero** y **Jorge Ferrero de Lara**.

## Objetivo
Combinar la monitorización ambiental básica (luz y temperatura) con la gestión eficiente de energía mediante el modo de *deep sleep* del ESP32.

## Funcionalidades

- Detectar niveles de **luz** y **temperatura**:
  - Presencia de llama o niveles de oscuridad.
  - Indicadores mediante colores del **LED RGB** y activación del **buzzer**.
- Activación del **modo de bajo consumo** mediante botón externo.
  - El sistema entra en *deep sleep* y se reinicia automáticamente tras 10 segundos.
- Visualización de datos a través de mensajes de depuración en consola.

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


