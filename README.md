
![stronghold logo](https://gist.githubusercontent.com/alja/2b7656a65bf8e78a26f1f7e93cbd5282/raw/45e30b390e75381869dce49cc7e2489fae910ce8/logo-fireworks.png)

[![Downloads](http://cmsshow-rels.web.cern.ch/cmsShow-rels/webFireworks/)](http://cmsshow-rels.web.cern.ch/cmsShow-rels/webFireworks/)

`Fireworks2` is server-client implementation of original Fireworks event display

![GIF demo](https://gist.githubusercontent.com/alja/2b7656a65bf8e78a26f1f7e93cbd5282/raw/45e30b390e75381869dce49cc7e2489fae910ce8/demo.gif)

Server client implementation of original Fireworks event display

**Usage**
---

```
Usage: cmsShowWeb [OPTIONS]

  CMS event display.


Options:
  --port  Server port
  --configuration file, -c      Fireworks configuration file
  --geometry-file, -g           Path to reco geomtery file   
  -help, -h  Show this message and exit.
  
```

**Installation Options**
---

1. Compile module [`Fireworks2`](https://github.com/alja/Fireworks2/) with CMSSW project
    + `$ git clone https://github.com/alja/Fireworks2/`
    + `$ scram b`

2. Download the `Fireworks2` tarball from Releases tab.


**Running**
---

1. Supported system

    + Turn on Firewall?
        - This helps protect your Mac from being attacked over the internet.
    + Turn on logging?
        - If there IS an infection, logs are useful for determining the source.
    + Turn on stealth mode?
        - Your Mac will not respond to ICMP ping requests or connection attempts from closed TCP and UDP networks.

2. Local run

    + Enable Gatekeeper?
    	- Defend against malware by enforcing code signing and verifying downloaded applications before allowing them to run.
    + Prevent automatic software whitelisting?
        - Both built-in and downloaded software will require user approval for whitelisting.
    + Disable Captive Portal Assistant and force login through browser on untrusted networks?
        - Captive Portal Assistant could be triggered and direct you to a malicious site WITHOUT any user interaction.

3. Closed firewall problem

    + Clear language modeling metadata?
        - This includes user spelling, typing and suggestion data.
    + Disable language modeling data collection?
    + Clear QuickLook metadata?
    + Clear Downloads metadata?
    + Disable metadata collection from Downloads?
    + Clear SiriAnalytics database?

**User Guide**
---

1.  Collection Dialog
2. Item Dialog
3. Add Collection Dialog
4. Table edit
