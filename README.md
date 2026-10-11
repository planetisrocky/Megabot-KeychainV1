# Megabot-Keychain
A Big Hero 6 inspired figure with a round display depicting its face to show emotions, time, weather, and more! It switches between modes with buttons. Built for Hack Club's Half Life program.

## Current Status
The circular PCB is fully designed using KiCad 7 and ran DRC with no errors. Firmware and 3D printed shell for the project will be in progress shortly.

## Planned Features
-1.28" round display (GC9A01 240x240) as the face
-Time calibration over wifi (NTP), emotion changes switched with one of 3 buttons, and similar features to come
-I2S header for a MAX98357A amp and speaker (for voice lines and UI sounds)
Rechargable Single-cell LiPo, charged over USB-C on the XIAO

## Files
-MegabotPCB.kicad_pro / .kicad_sch / .kicad_pcb: KiCad Files
gerbers/: settings/fabrication files for the PCB
