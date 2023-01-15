# PC to Linux Console project (PCBMold)

This is part of a project to try to make PC games run on a custom Linux distro as on the PS4/PS5/Xbox Series.
I thought it was a big shame that physical PC games are considered worthless and thought that maybe we could make some use out of it.
I was especially inspired by the way Microsoft handled backwards compatibility on their Xbox One/Series and it's kind of a shame
there's nothing similar for Win32 games.

To be honest i'm not sure if it's going anywhere.

# Linux Distro

I'm hesitating with either Musl or Glibc but i think i'll end up with Glibc.
Though to be honest if Wine works on either then the choice will hardly matter.
Base distro will most likely be Void Linux.

A list of native games that will be part of it :
- Neverball
- SupertuxKart
- Minetest

3rd party packages for the following :
- Sonic Robo Blast 2
- Sonic Robo Blast 2 Kart
- Sonic Robo Blast 2 Persona

Initially OPK was considered as a format for these but i have decided that OPK will not be used.
Instead each folder is simply going to have a list of expected files that describes what the game/app is etc...
This will avoid issues with I/O decompression speeds not being optimal with OPK/Squashfs.

# Win32

Digital Win32 can also work as is but the focus of this will be on non-packed Win32 games.
We'll take Colin McRally 2.0 as an example.
This disc version of this game has the following problems :
- It's own installer
- Multiple issues (no support for 16:9)
- CD checks

I have created a script that applies a modern patch by a fan (it's remotely downloaded to avoid potential copyright issues), 
extracts the game from the disc and outputs all of that to a directory.

# User interface

I'm thinking of doing something like Xbox One's list all apps interface with just games and apps.
The settings button will be accesible in the top right along with power off.
