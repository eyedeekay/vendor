Flash Guides:
=============

STOP:
-----

*Before you attempt this procedure, **at least** make sure that you have a*
*valid backup of a known working firmware, a way of flashing it back*
*externally, and another computer to control the flashing process from.*

m11xr1:
-------

### m11xr1 Chips:

#### Winbond 25Q16 flash chip

This is a 16MBit flash chip that definitely contains at least part of the BIOS,
probably all of it.

#### Macronix MX25L8005 flash chip

This might be the CMOS. But I may have a BIOS stored on two chips too. We'll
just have to see.


### Step 0: Backing up the Vendor BIOS



i1545 Chips:
------------

### This laptop is too busy for me to freely open up right now. Probably next week.

Preliminary research on the internet suggests that it may use a KS24C02 based
flash chip, but other research suggests otherwise. Whatever it is dmidecode
reports it's having a size of 16MB, so there's plenty of room to work with here.
Hopefully when I crack it open and have a look it's an SOIC-8 thing that
Flashrom supports.
