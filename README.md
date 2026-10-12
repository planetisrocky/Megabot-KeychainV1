# Megabot Keychain

A Big Hero 6 inspired figure with a round display for a face. It shows emotions, the time, weather, and more, and you switch modes with buttons. Built for Hack Club's **Half Life** program.

![PCB](images/pcb.png)

## Planned Features

- 1.28" round display (GC9A01, 240x240) as the face
- Emotions switched with one of 3 buttons
- Time calibrated over WiFi (NTP)
- Weather and more modes to come
- I2S header for a MAX98357A amp and speaker (voice lines and UI sounds)
- Rechargeable single-cell LiPo, charged over USB-C through the XIAO

## Controls

| Button | What it does |
|---|---|
| BTN1 | Cycles through the emotions |
| BTN2 | Switches between face and time |
| BTN3 | Unused for now (reserved) |

## Hardware

| Part | Notes |
|---|---|
| Seeed XIAO ESP32-C3 | Brain, WiFi, LiPo charger |
| 1.28" GC9A01 round display | SPI, wired to J2 |
| 3x 6 mm tactile switches | Wired to J3 |
| Custom 2-layer round PCB | Files in this repo |
| 10k resistor (R1) | [what it does] |
| LiPo battery (planned) | Soldered to the XIAO's BAT+/BAT- pads |
| MAX98357A amp + speaker (planned) | Spare audio header J1 |

Prices and funding: see [BOM.md](BOM.md).

## Pin Map

| Signal | XIAO pin |
|---|---|
| DC / RST / CS | D1 / D2 / D3 |
| SCK / MOSI | D8 / D10 |
| BTN1 / BTN2 / BTN3 | D4 / D5 / D6 |
| Audio: LRC / BCLK / DIN | D0 / D9 / D7 |

## Simulation

Try the firmware in your browser: [Wokwi link](https://wokwi.com/projects/477629702640173057)

Wokwi has no round display, so a rectangular ILI9341 stands in for it. Colors stand in for the faces, and the clock is a fake one that starts at 12:00.

## Files

- `MegabotPCB.kicad_pro`, `.kicad_sch`, `.kicad_pcb`: KiCad 7 project
- `MegabotPCB-Gerbers.zip`: PCB fabrication files
- `firmware/`: Wokwi simulation code
- `BOM.md`: bill of materials
- `images/`: screenshots

## Opening the KiCad Project

The XIAO symbol and footprint come from Seeed's OPL_Kicad_Library on GitHub. Download it and add it in KiCad's library manager so the project opens without missing parts.

## Notes

Firmware started from an AI-generated sketch, then simplified and modified by me.
