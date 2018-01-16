Getting Coreboot to work on the Alienware M11XR1
================================================

This guide is a WORK IN PROGESS. My SPI flasher will arrive in the mail
tomorrow. At best, it's an account of how I removed the lenovo/x200 specific
stuff from the lenovo/x200 config folder and replaced it with alienware/m11xr1
specific stuff.

First, I'd like to point one thing out:
---------------------------------------

I'm fairly certain there are like a gazillion laptops from the 2007-2010 period
which have just one or two little differences with laptops which can use
Coreboot or even Libreboot in lieu of a fully proprietary vendor firmware. Some
of these [are so close to a supported device](https://www.coreboot.org/Developer_Manual#How_to_support_a_new_board)
that it seems a shame not to attempt to port them myself. I mean, I've kind of
always wanted to.

So in this case, the M11XR1 is pretty much a simplified X200
------------------------------------------------------------

As I explained before, I decided to do this becaue my laptops components are all
supported by Coreboot, there's just no board configuration for it. The laptop
that is closest to mine is the X200(But it's also very similar to the Roda RK9)
and so I started by copying src/mainboard/lenovo/x200 to
src/mainboard/alienware/m11xr1. Then I changed to the newly created directory
and replaced references to "Lenovo" with "Alienware" and references to "x200"
to references to "m11xr1" which, if you wanted to take a shortcut, you could do
like this:

        sed -i 's|lenovo|alienware|g' *
        sed -i 's|Lenovo|Alienware|g' *
        sed -i 's|LENOVO|ALIENWARE|g' *
        sed -i 's|thinkpad|alienware|g' *
        sed -i 's|ThinkPad|Alienware|g' *
        sed -i 's|THINKPAD|ALIENWARE|g' *
        sed -i 's|x200|m11xr1|g' *
        sed -i 's|X200|M11XR1|g' *
        sed -i 's|lenovo|alienware|g' */*
        sed -i 's|Lenovo|Alienware|g' */*
        sed -i 's|LENOVO|ALIENWARE|g' */*
        sed -i 's|thinkpad|alienware|g' */*
        sed -i 's|ThinkPad|Alienware|g' */*
        sed -i 's|THINKPAD|ALIENWARE|g' */*
        sed -i 's|x200|m11xr1|g' */*
        sed -i 's|X200|M11XR1|g' */*

But then you'd find in the Kconfig file that you had accidentally changed the
CBFS_SIZE default from 0x200000 to 0m11xr1000. Simply change it back. What you
have at this point is a version of the x200 configuration which can be built
by selecting Alienware-related options instead of Lenovo ones.

Edit the Kconfig to remove the X200 specific components
-------------------------------------------------------

Remove references to the superIO and the x200's EC.

Removing the files related to the X200 specific peripherals
-----------------------------------------------------------

The next pretty easy bit is to remove the code which deals with components
specific to the x200, like the dock and the superIO.

New, remove references to these from Makefile.inc and from any #include
statements where they appear.

In spite of this, you should *not* remove the acpi/superio.asl file, which is
required for it to build. Instead, just make sure it's empty.

Adding the new Embedded Controller to the Kconfig
-------------------------------------------------

Configure the ENEKB932.

Adding the source code for the Embedded Controller
--------------------------------------------------

Examine the most similar board that uses the ENEKB932, the S230U. Adapt it's
EC configuration code.

Initializing the Embedded Controller in mainboard.c
---------------------------------------------------

Configure the new EC code to work with the existing mainboard.c code.

Editing the Device Tree
-----------------------

Correct the addresses and subsystem ID's of the PCI devices. Remove PCI devices
that aren't present.

And back to my original point
-----------------------------
