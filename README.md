
![stronghold logo](https://gist.githubusercontent.com/alja/2b7656a65bf8e78a26f1f7e93cbd5282/raw/45e30b390e75381869dce49cc7e2489fae910ce8/logo-fireworks.png)

[![Downloads](http://cmsshow-rels.web.cern.ch/cmsShow-rels/webFireworks/)](http://cmsshow-rels.web.cern.ch/cmsShow-rels/webFireworks/)

`Fireworks2` is server-client implementation of original Fireworks event display

![GIF demo](https://gist.githubusercontent.com/alja/2b7656a65bf8e78a26f1f7e93cbd5282/raw/45e30b390e75381869dce49cc7e2489fae910ce8/demo.gif)

Server client implementation of original Fireworks event display

**Usage**
---

```
Usage: fire [OPTIONS]

  CMS event display.


Options:
  --port  Server port
  --configuration file, -c      Fireworks configuration file
  --geometry-file, -g           Path to reco geomtery file   
  -help, -h                     Show this message and exit.
  
```

**Installation Options**
---

1. Compile module [`Fireworks2`](https://github.com/alja/Fireworks2/) with CMSSW project
    + `$ git clone https://github.com/alja/Fireworks2/`
    + `$ scram b`

2. Download the `Fireworks2` tarball from Releases tab.


**Running**
---

1. Supported systems

    + cmsShow server is supported on Linix operating systems.
    + event display client is web browser on any ooperating system. Most test during developement are done in Chrome browser

2. Local run

    + If server is running on your desktop. E.g. have Linux OS, the server prints URL in the terminal that can be pasted to your Chrome browser. E.g. this is how it looks an URL when server is running on port 7777:
    http://localhost:7777/win1/
    

3. Running remotely, when firewall is closed

    + If server is on remote desktop, e.g. lxplus, it is recommened to create a SSH tunnel. Below is an example of a tunnel from port 7777 to local desktop on port 1234:
   ` ssh -f -L 1234:localhost:7777 cms-ed-1 sleep 10000`

    + The URL for event display in this case would be:
  ` http://localhost:1234/win1/`


**User Guide**
---

1.  Collection Dialog
2. Item Dialog
3. Add Collection Dialog
4. Table edit
