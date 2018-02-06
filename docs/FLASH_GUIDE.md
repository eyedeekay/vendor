Flash Guides:
=============

STOP:
-----

*Before you attempt this procedure, **at least** make sure that you have a*
*valid backup of a known working firmware, a way of flashing it back*
*externally, and another computer to control the flashing process from.*

NO REALLY, STOP
---------------

*Seriously, I haven't even flashed it long-term yet. I'm going to do it again*
*in a couple of weeks, when I can borrow a high-resolution camera, so I can*
*thoroughly document the procedure. For realsies.*

m11xr1:
-------

### m11xr1 Chips:

#### Winbond 25Q16 flash chip

This is a 16MBit flash chip that definitely contains at least part of the BIOS,
probably all of it.

#### Macronix MX25L8005 flash chip

This might be the CMOS. But I may have a BIOS stored on two chips too. We'll
just have to see.


### Step 0[s0]: Backing up the Vendor BIOS

#### s0.1: Minimal Disassembly

#### s0.2: Battery Disconnection

##### s0.2.a Travel Battery Disconnection

##### s0.2.b CMOS Battery Disconnection

#### s0.3: SOIC-8 Clip Attachment

#### s0.4: Initial read the Vendor BIOS

#### s0.5: Verification of the Vendor BIOS

### Step 1[s1]: Flashing coreboot externally

#### s1.1: COMPLETE STEP 0

    After ensuring that the backup works, leave the batteries disconnected and
    repeat SOIC-8 Clip Attachment.

#### s1.2: Use Flashrom to flash coreboot externally

### Step 2[s2]: Flash an internal update:

### Emergency Step 3[s3]: Recovering a brick with the Vendor BIOS

i1545:
------

###i1545 Chips:

#### This laptop is too busy for me to freely open up right now. Probably next week.

Preliminary research on the internet suggests that it may use a KS24C02 based
flash chip, but other research suggests otherwise. Whatever it is dmidecode
reports it's having a size of 16MB, so there's plenty of room to work with here.
Hopefully when I crack it open and have a look it's an SOIC-8 thing that
Flashrom supports.

### SuperIO


