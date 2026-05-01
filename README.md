# 🚗 Vehicle Indicator Control Module — Automotive ECU Simulation

<div align="center">

![Arduino](https://img.shields.io/badge/Arduino-Framework-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Embedded C](https://img.shields.io/badge/Embedded_C-Firmware-A8B9CC?style=for-the-badge)
![Automotive ECU](https://img.shields.io/badge/Automotive-ECU_Simulation-E74C3C?style=for-the-badge)
![FSM](https://img.shields.io/badge/FSM-State_Machine-8E44AD?style=for-the-badge)

*An automotive-grade indicator Electronic Control Unit (ECU) simulating real-world vehicle turn signal logic with state-based control flow.*

</div>

---

## 📌 Project Overview

This project simulates a **vehicle indicator Electronic Control Unit (ECU)** on Arduino, implementing complete turn signal logic — left/right indicators, hazard mode, and automatic cancellation — via a **Finite State Machine (FSM)**.

---

## ✨ Features

- 🔴 **Left & Right Turn Indicators** — Standard 1 Hz blink rate
- ⚠️ **Hazard Mode** — Both sides simultaneously
- 🔇 **Auto-cancel Logic** — After configurable timeout
- 🔘 **Debounced Input** — Hardware-quality button debouncing
- 📊 **FSM Architecture** — Clean, maintainable state machine design
- 🧪 **Serial Debug Output** — State transitions for development

---

## 🏗️ FSM State Diagram

```
         ┌─────────┐
BUTTON_L │  IDLE   │ BUTTON_R
┌────────│  STATE  │────────┐
│        └─────────┘        │
▼           │ BTN_H         ▼
┌──────────┐│       ┌──────────┐
│   LEFT   ││       │  RIGHT   │
│INDICATOR ││       │INDICATOR │
└──────────┘▼       └──────────┘
      ┌──────────────┐
      │    HAZARD    │
      │    MODE      │
      └──────────────┘
            │ timeout
            ▼
         IDLE STATE
```

---

## 🛠️ Tech Stack

| Component | Role |
|-----------|------|
| Arduino Uno/Nano (ATmega328P) | Main ECU processor |
| LEDs (x4) | Left, Right, Hazard indicators |
| Push Buttons (x3) | Left, Right, Hazard input |
| Arduino IDE + Embedded C++ | Firmware development |

---

## 📁 Structure

```
indicator-control-module/
├── src/
│   ├── main.ino
│   ├── indicator_fsm.h
│   ├── debounce.h
│   └── timer_util.h
├── hardware/
│   ├── schematic.pdf
│   └── breadboard_layout.png
└── README.md
```

---

## 🔌 Pin Mapping

| Arduino Pin | Function |
|-------------|----------|
| D2 | Left button (interrupt) |
| D3 | Right button (interrupt) |
| D4 | Hazard button |
| D5 | Left indicator LED |
| D6 | Right indicator LED |
| D7–D8 | Hazard LEDs |

---

## ⚙️ How to Run

1. Wire circuit per `hardware/schematic.pdf`
2. Open `src/main.ino` in Arduino IDE
3. Flash to Arduino Uno
4. Test with Left/Right/Hazard buttons
5. Monitor via Serial Monitor @ 9600 baud

---

## 🎯 Automotive Context

This project applies the same foundational patterns used in production automotive ECU development: interrupt-driven inputs, non-blocking timers, FSM control logic, and hardware abstraction layers — skills that scale directly to professional automotive software roles.

---

## 👤 Author

**Pradeep Nalawade** | ECE Student | Embedded Systems & Automotive Electronics

[![Portfolio](https://img.shields.io/badge/Portfolio-Visit-A78BFA?style=flat-square)](https://pradeepnalawade00.github.io/)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0A66C2?style=flat-square&logo=linkedin)](https://www.linkedin.com/in/pradeep-nalawade-950244314/)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-181717?style=flat-square&logo=github)](https://github.com/pradeepnalawade00)
