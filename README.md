# HijackProcess Proof-of-concept
Hijacking a process to access another process.

Using an injector we can load a dynamic-link library into a trusted process, for example Spotify.exe.

Once our malicious DLL is loaded into Spotify.exe we can run our payload and for example access the memory of another process, pretending to be spotify.exe

#Legal Disclaimer
This software was designed for research purposes only.
The software comes with no warranties of any kind whatsoever, use at own risk!
Using any parts of this code for malicious purposes is strictly forbidden.
If these terms are not acceptable, you aren't allowed to use the code.
