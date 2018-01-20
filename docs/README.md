x86 Firmware Hacking for the Reckless Amateur
=============================================

Finding a similar board
-----------------------

The Alienware M11XR1 is almost the same as the same as the Lenovo Thinkpad X200,
except it has no superIO, and the embedded controller is an ENEKB932. The parts
of this that use enable the ENEKB932 are adapted from the ones that enable the
S230U. The Alienware M11XR1 doesn't have a dock either, to my knowledge, so I
removed all the docking code. An overview of the differences can be seen in
the file [docs/differences-overview-x200-m11xr1.diff](https://github.com/eyedeekay/vendor/blob/master/docs/differences-overview-x200-m11xr1.diff)

The Dell Inspiron 1545 is another laptop which is very similar to an X200,
however in this case it actually has more peripheral hardware available. It is
larger and probably got sold in large amounts. Preliminary investigation
suggests that it has a combined SuperIO+EC, which may present some challenges.
Otherwise, they are almost identical. An overview of the differences can be seen
in the file [docs/differences-overview-x200-i1545.diff](https://github.com/eyedeekay/vendor/blob/master/docs/differences-overview-x200-i1545.diff)

A more detailed account of it is forthcoming because it turns out, there may be
a bunch of laptops out there that could become serviceable again with some
reasonably accessible configuration.

