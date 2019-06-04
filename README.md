# HijackProcess-PoC
Hijacking a process to access another process proof-of-concept

Using an injector we can load a dynamic-link library into a trusted process, for example Spotify.exe.

Once our malicious DLL is loaded into Spotify.exe it can access the memory of another processes from there and manipulate it from here.
