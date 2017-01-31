# WAT

Eventhough there is a opnsense plugin for tinc already, its hard to keep the GUI to offer anything tinc actual offers.
Be it a infinit amount of subnet, specific modes (switch/hub/routed) or anything else specific.

So as an alternativ this plugins offers you all daemon / startup / interface integration and also some starting point for the configuration while letting you doing whatever you want with your configuration.
So just pick your favorite tincd howto / setup or even existing setup on copy it over here

## Installation

1. Install the plugin

### 1. your network 

1.  copy the `/usr/local/etc/tinc/example` folder to `/usr/local/etc/tinc/yournetwork`
1. enter `yournetwork` into `/usr/local/etc/tinc/net.boot` to let this network be started on boot
1. create keypairs by runng `tincd -n <yournetwork> -K`


### 2. your network configuration and tun device

1. Edit `/usr/local/etc/tinc/yournetwork/tinc.conf` set the server you want to connect to and how this server is to be named

1. Edit `/usr/local/etc/tinc/yournetwork/tinc-up` and adjust the network/netbitmask

### 3. finally the host configuration

1. enter the `/usr/local/etc/tinc/yournetwork/hosts` folder and rename the files according to what you have chosen for `youservername` and `theotherservername` - they must match!
 
1. enter the public key of the "this server" you find under /usr/local/etc/tinc/yournetwork/ into the according `thisservername` file and adjust the subnet this server offers (or subnets)

1. enter the public key of the "other server" into the according `theotherservername` file and adjust the subnet the other server offers (or subnets)


## Add the interface 

1. Add the tinc0 interface in the interfaces mask in the opnsense GUI to be able to add routes as you need them in the rules

**Thats it .. and surely more to come**

