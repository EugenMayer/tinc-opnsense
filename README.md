# WAT

Eventhough there is a [opnsense tinc](https://github.com/opnsense/plugins/tree/stable/17.1/security/tinc) plugin already, its hard to keep the GUI offering all the options tinc actual offers.
Be it a infinit amount of subnets, specific modes (switch/hub/routed) or anything else specific to your setup.

So as an alternative this plugins offers you all daemon / startup / interface integration and also some starting point for the configuration while letting you doing whatever you want with your configuration.

**BUT NO GUI!!**

Rather you edit the files using ssh, pick your favorite tincd howto / setup or even existing setup on copy it over here.
Utilize the full power of tinc

## Installation

1. use this repo `dist/os-tincdcustom-*` freebsd package and install it as `pkg install os-tincdcustom-*.txz`

### 1. your network

1. copy the `/usr/local/etc/tinc/example` folder to `/usr/local/etc/tinc/yournetwork`
1. enter `yournetwork` into `/usr/local/etc/tinc/nets.boot` to let this network be started on boot
1. create keypairs by runng `tincd -n <yournetwork> -K`


### 2. your network configuration and tun device

1. Edit `/usr/local/etc/tinc/yournetwork/tinc.conf` set the server you want to connect to and how this server is to be named

1. Edit `/usr/local/etc/tinc/yournetwork/tinc-up` and adjust the network/netbitmask

### 3. finally the host configuration

1. enter the `/usr/local/etc/tinc/yournetwork/hosts` folder and rename the files according to what you have chosen for `youservername` and `theotherservername` - they must match!
 
1. enter the public key of the "this server" you find under /usr/local/etc/tinc/yournetwork/ into the according `thisservername` file and adjust the subnet this server offers (or subnets)

1. enter the public key of the "other server" into the according `theotherservername` file and adjust the subnet the other server offers (or subnets)


### 4. Add the interface 

1. Add the tinc0 interface in the interfaces mask in the opnsense GUI to be able to add routes as you need them in the rules

**Thats it .. and surely more to come**


## Service mangement

to restart the service to 

    configctl tincdcustom restart
     
More then that you have those obvious commands

    configctl tincdcustom stop
    configctl tincdcustom start
    configctl tincdcustom reload

## Uninstallation

When you uninstall the plugins, everything you created in `/usr/local/etc/tinc` will kept in place, so you can reinstall it at any time

## Build it yourself / Development
Connect on your opnsense box
 
    cd /usr/ 
    mkdir devel && cd devel
    git clone https://github.com/EugenMayer/tinc-opnsense
    cd tinc-opnsense/security/tincdcustom
    make package
    pkg install work/pkg/os-tincdcustom-*
    
# Credits

Of course credits to the initial author [opnsense tinc](https://github.com/opnsense/plugins/tree/stable/17.1/security/tinc), some of the things in here base on his work straight. Thank you! 