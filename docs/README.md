x86 Firmware Hacking for the Reckless Amateur
=============================================

Finding a similar board
-----------------------

The Alienware M11XR1 is almost the same as the same as the Lenovo Thinkpad X200,
except it has no superIO, and the embedded controller is an ENEKB932. The parts
of this that use enable the ENEKB932 are adapted from the ones that enable the
S230U. The Alienware M11XR1 doesn't have a dock either, to my knowledge, so I
removed all the docking code.

        00:19.0 Ethernet controller [0200]: Intel Corporation 82567LM Gigabit Network Connection [8086:1   <
            Subsystem: Lenovo Device [17aa:20ee]							   <
        --												   <
        00:1a.0 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #4 [80	00:1a.0 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #4 [80
            Subsystem: Lenovo Device [17aa:20f0]							   |		Subsystem: Dell 82801I (ICH9 Family) USB UHCI Controller [1028:0443]
        --												   <
        00:1a.1 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #5 [80   <
            Subsystem: Lenovo Device [17aa:20f0]							   <
        --												   <
        00:1a.2 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #6 [80   <
            Subsystem: Lenovo Device [17aa:20f0]							   <
        --													--
        00:1a.7 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB2 EHCI Controller #2 [8	00:1a.7 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB2 EHCI Controller #2 [8
            Subsystem: Lenovo Device [17aa:20f1]							   |		Subsystem: Dell 82801I (ICH9 Family) USB2 EHCI Controller [1028:0443]
        --													--
        00:1b.0 Audio device [0403]: Intel Corporation 82801I (ICH9 Family) HD Audio Controller [8086:29	00:1b.0 Audio device [0403]: Intel Corporation 82801I (ICH9 Family) HD Audio Controller [8086:29
            Subsystem: Lenovo Device [17aa:20f2]							   |		Subsystem: Dell 82801I (ICH9 Family) HD Audio Controller [1028:0443]
        --													--
        00:1c.0 PCI bridge [0604]: Intel Corporation 82801I (ICH9 Family) PCI Express Port 1 [8086:2940]	00:1c.0 PCI bridge [0604]: Intel Corporation 82801I (ICH9 Family) PCI Express Port 1 [8086:2940]
            Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR+ Fast   |		Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- Fast
        --													--
        00:1c.1 PCI bridge [0604]: Intel Corporation 82801I (ICH9 Family) PCI Express Port 2 [8086:2942]	00:1c.1 PCI bridge [0604]: Intel Corporation 82801I (ICH9 Family) PCI Express Port 2 [8086:2942]
            Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR+ Fast   |		Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- Fast
        --													--
        00:1c.3 PCI bridge [0604]: Intel Corporation 82801I (ICH9 Family) PCI Express Port 4 [8086:2946]   |	00:1c.4 PCI bridge [0604]: Intel Corporation 82801I (ICH9 Family) PCI Express Port 5 [8086:2948]
            Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR+ Fast   |		Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- Fast
        --													--
        00:1d.0 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #1 [80	00:1d.0 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #1 [80
            Subsystem: Lenovo Device [17aa:20f0]							   |		Subsystem: Dell 82801I (ICH9 Family) USB UHCI Controller [1028:0443]
        --													--
        00:1d.1 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #2 [80	00:1d.1 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #2 [80
            Subsystem: Lenovo Device [17aa:20f0]							   |		Subsystem: Dell 82801I (ICH9 Family) USB UHCI Controller [1028:0443]
        --													--
        00:1d.2 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #3 [80	00:1d.2 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB UHCI Controller #3 [80
            Subsystem: Lenovo Device [17aa:20f0]							   |		Subsystem: Dell 82801I (ICH9 Family) USB UHCI Controller [1028:0443]
        --													--
        00:1d.7 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB2 EHCI Controller #1 [8	00:1d.7 USB controller [0c03]: Intel Corporation 82801I (ICH9 Family) USB2 EHCI Controller #1 [8
            Subsystem: Lenovo Device [17aa:20f1]							   |		Subsystem: Dell 82801I (ICH9 Family) USB2 EHCI Controller [1028:0443]
        --													--
        00:1e.0 PCI bridge [0604]: Intel Corporation 82801 Mobile PCI Bridge [8086:2448] (rev 93) (prog-	00:1e.0 PCI bridge [0604]: Intel Corporation 82801 Mobile PCI Bridge [8086:2448] (rev 93) (prog-
            Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR+ Fast   |		Control: I/O+ Mem+ BusMaster+ SpecCycle- MemWINV- VGASnoop- ParErr- Stepping- SERR- Fast
        --													--
        00:1f.0 ISA bridge [0601]: Intel Corporation ICH9M-E LPC Interface Controller [8086:2917] (rev 0	00:1f.0 ISA bridge [0601]: Intel Corporation ICH9M-E LPC Interface Controller [8086:2917] (rev 0
            Subsystem: Lenovo Device [17aa:20f5]							   |		Subsystem: Dell ICH9M-E LPC Interface Controller [1028:0443]
        --													--
        00:1f.2 SATA controller [0106]: Intel Corporation 82801IBM/IEM (ICH9M/ICH9M-E) 4 port SATA Contr	00:1f.2 SATA controller [0106]: Intel Corporation 82801IBM/IEM (ICH9M/ICH9M-E) 4 port SATA Contr
            Subsystem: Lenovo Device [17aa:20f8]							   |		Subsystem: Dell 82801IBM/IEM (ICH9M/ICH9M-E) 4 port SATA Controller [AHCI mode] [1028:04
        --													--
        00:1f.3 SMBus [0c05]: Intel Corporation 82801I (ICH9 Family) SMBus Controller [8086:2930] (rev 0	00:1f.3 SMBus [0c05]: Intel Corporation 82801I (ICH9 Family) SMBus Controller [8086:2930] (rev 0
            Subsystem: Lenovo Device [17aa:20f9]							   |		Subsystem: Dell 82801I (ICH9 Family) SMBus Controller [1028:0443]
        --													--
        03:00.0 Network controller [0280]: Intel Corporation PRO/Wireless 5100 AGN [Shiloh] Network Conn   |	02:00.0 Ethernet controller [0200]: Qualcomm Atheros AR8132 Fast Ethernet [1969:1062] (rev c0)
            Subsystem: Intel Corporation WiFi Link 5100 AGN [8086:1211]				   |		Subsystem: Dell AR8132 Fast Ethernet [1028:0443]
            Physical Slot: 1									   <

A more detailed account of it is forthcoming because it turns out, there may be
a bunch of laptops out there that could become serviceable again with some
reasonably accessible configuration.

m11xr1 BIOS is stored on 2 flash chips
--------------------------------------

### Winbond 25Q16 flash chip

This is a 16MB flash chip that definitely contains at least part of the BIOS,
possibly all of it.

### Macronix MX25L8005 flash chip

This might be the CMOS. But I may have a BIOS stored on two chips too. We'll
just have to see.
