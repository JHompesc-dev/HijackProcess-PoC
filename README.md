# HijackProcess-PoC
Hijacking a process to access another process proof-of-concept

Using an injector we can load a dynamic-link library into a trusted process, for example Spotify.exe.

Once our malicious DLL is loaded into Spotify.exe we can run our payload and for example access the memory of another process, pretending to be spotify.exe
