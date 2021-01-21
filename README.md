# Pifetch

A custom fetch script to dsiplay some Raspberry related information and Docker stats

Example:

![Awesome Example Image](https://github.com/mikeanth-dvlp/pifetch/blob/master/assets/example.png)

## Prerequisites

For this piece of code to work, you need to have `docker`, `lshw` and `vcgencmd` available on your Raspberry Pi.

For `docker`, you can follow [this guide](https://phoenixnap.com/kb/docker-on-raspberry-pi).
However, with the volatility of the interwebs, I'll provide a short summary here.

``` bash
curl -fsSL https://get.docker.com -o get-docker.sh  # download the official install script
sudo sh get-docker.sh                               # run it
sudo usermod -aG docker $(whoami)                   # add the current user to the docker group
exit                                                # you need to log out and log back in for the change to take effect

# log back in

docker version                                      # to test the installation
```

For `lshw`, a basic `apt-get install` is sufficient: `sudo apt-get install lshw`

As for `vcgencmd`, it comes preinstalled in Raspbian, so I suggest you use that. For other distros, you have to look it up yourself.

## How to install

### Download the precompiled binaries

``` bash
wget https://github.com/mikeanth-dev/pifetch/releases/download/v1.0.0/pifetch
chmod +x ./pifetch;                 # make the file executable
sudo mv ./pifetch /bin/pifetch;     # add it to path
```

### Build from source

Prerequisites: `g++` & `make`

Clone this repository and compile the project via the makefile:

``` bash
git clone https://github.com/mikeanth-dev/pifetch.git;
cd pifetch;
make;
```

You should now have a new file called `pifetch` in that directory. You can execute it by running `./pifetch`. However, it would be more convenient to have it readily available at all times, so i recommend copying it to `/bin/` via : `sudo mv ./pifetch /bin/pifetch`.

## How to uninstall

Assuming you follwed the steps mentioned above, simply remove the binary you copied to `/bin` by `sudo rm /bin/pifetch`.

## Feedback, suggestions and help

For feedback, suggestions, bug reports etc., feel free to e-mail me at 'mike.anth99@gmail.com'.

---

_a project by Mircea-Pavel Anton (Mike Anthony)_
